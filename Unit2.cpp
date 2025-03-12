//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#include <string>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
using namespace std;


extern Byte * MemA;

int ProcNum = 4; // количество методов обработки
string ProcName[8] = {"Исходное","А1","С1","D1"};
int BarsNum[5]={0,0,0,0,0};

int postProcNum =3;
string PostProcName[6] = {"Как есть","Гистограммный","Негатив"};

int ParsPos[3][8]={{10,20,50,40,50,60,70,80},{10,20,30,40,50,60,70,80},{10,20,30,40,50,60,70,80}} ;

char* GetNames(int conv) {
	if(conv < ProcNum) {
		return (char*)ProcName[conv].c_str();
	} else {
		return NULL;
	}
}

char* GetPostNames(int postIndex) {
	if(postIndex < postProcNum) {
		return (char*)PostProcName[postIndex].c_str();
	} else {
		return NULL;
	}
}

int GetBarsNum(int conv) // после выбора конкретной функции обработки запросить количество параметров
{
	if(conv<ProcNum) return BarsNum[conv];
	else return 0;
}

int GetParsPos(int conv, int Bar) // для каждого активного параметра запросить позицию трэк-бара
{
	if(conv<ProcNum) {
	   if(Bar<BarsNum[conv]) return ParsPos[Bar][conv];

	}
	return 0;
}

void converter(int conv, Byte * Mem0, Byte * Mem1, int H, int W, int* PosK, int* PosM, int PostProcId, int Par1, int Par2, int Par3,int Chan) // Chan - выбор канала : 0 - все, 1 - R, 2- G, 3-B.
{

	switch (conv) {
	case 1:
		EntrA1(Chan, Mem0,  MemA,  H,  W);
		if(PostProcId==0) { *PosK=3; *PosM=6;  }
		if(PostProcId==1) { *PosK=3; *PosM=4;  }
		if(PostProcId==2) { *PosK=2; *PosM=3;  }
		break;
	case 2:
		EntrС1(Chan, Mem0,  MemA,  H,  W);
		if(PostProcId==0) { *PosK=8; *PosM=10; }
		if(PostProcId==1) { *PosK=8; *PosM=4;  }
		if(PostProcId==2) { *PosK=6; *PosM=1;  }
		break;
	case 3:
		EntrD1(Chan, Mem0,  MemA,  H,  W);
		if(PostProcId==0) { *PosK=9; *PosM=3; }
		if(PostProcId==1) { *PosK=10; *PosM=9;  }
		if(PostProcId==2) { *PosK=9; *PosM=12;  }
		break;
	default:
         *PosK=3; *PosM=10;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++)
			{
				int k = (i * W + j) * 3;
				if(Chan==0) {
				 MemA[k] = Mem0[k];
				 MemA[k + 1] = Mem0[k + 1];
				 MemA[k + 2] = Mem0[k + 2];
				}
				else {
				 MemA[k] = Mem0[k+Chan-1];
				 MemA[k + 1] = MemA[k];
				 MemA[k + 2] = MemA[k];
				}
			}
			MoveProgress(i, H);
		}
		break;
	}
	PostProcess(PostProcId, MemA, Mem1, H, W, Par1, Par2, Par3);
}

void PostProcess(int ProcID, Byte * MemIn, Byte * MemOut, int H, int W, int Par1, int Par2, int Par3)
{

  int gist[256]; int N;
  int outmap[256];
  int i,j,k,m,n;
	double Max;

	switch (ProcID) {
	  case 0:
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++)
			{
				int k = (i * W + j) * 3;
				 MemOut[k] = MemIn[k];
				 MemOut[k + 1] = MemIn[k + 1];
				 MemOut[k + 2] = MemIn[k + 2];
			}
			MoveProgress(i, H);
		}
	  break;
	  case 1:
		n=0; for(i=0;i<256;i++) gist[i]=0;
		for (i = 0; i < H; i++) {
			for ( j = 0; j < W; j++)
			{
				int k = (i * W + j) * 3;
				 gist[MemIn[k]]++;
			}
			MoveProgress(i, H);
		}

		for(i=1;i<256;i++) gist[i]+=gist[i-1];
		Max=gist[255]/256;
		for(i=0;i<256;i++) gist[i]=gist[i]/Max;
		for(i=0;i<256;i++) {
			outmap[i]=gist[i];
		}

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++)
			{
				int k = (i * W + j) * 3;
				 MemOut[k] = outmap[MemIn[k]];
				 MemOut[k + 1] = outmap[MemIn[k + 1]];
				 MemOut[k + 2] = outmap[MemIn[k + 2]];
			}
			MoveProgress(i, H);
		}
	  break;
	  case 2:
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++)
			{
				int k = (i * W + j) * 3;
				 MemOut[k] = 255-MemIn[k];
				 MemOut[k + 1] = 255-MemIn[k + 1];
				 MemOut[k + 2] = 255-MemIn[k + 2];
			}
			MoveProgress(i, H);
		}
	  break;

	}

}
   double egist[256][256];
   double Hgist[256][256];
   int gist1[256][256];
   int outmap1[256][256];

void EntrA1(int chan, Byte * Mem0, Byte * Mem1, int H, int W)
{

   int gist[256];
   int outmap[256];

   int i,j,k;
   int i1,j1,k1,m,M,N;
   int M0,MC,M1,M2,M3;
   int Lev;

   int gist2[256];
   int gist3[256];

   int outmap2[256];
   int outmap3[256];

		for(i=0;i<256;i++) gist2[i]=gist3[i]=0; N=0;
		for(i=0;i<256;i++) for(j=0;j<256;j++) gist1[i][j]=0;

		 for ( i = 1; i < H-1; i++) {
			for ( j = 1; j < W-1; j++)
			{
				k = (i * W + j) * 3;
				m=1; M1=M2=M3=0;
				for(i1=i-1;i1<i+2;i1++)
				for(j1=j-1;j1<j+2;j1++)
				{
					if((i1==i)&&(j1==j)) continue;
					k1 = (i1 * W + j1) * 3;
					M1+=Mem0[k1];
					M2+=Mem0[k1+1];
					M3+=Mem0[k1+2];
				}

				M1/=8; M2/=8; M3/=8;
				switch(chan){
				case 0:
				  MC=(M1+M2+M3)/3;
				  M0=(Mem0[k]+Mem0[k+1]+Mem0[k+2])/3;
				break;
				case 1:
				  MC=M1;
				  M0=Mem0[k];
				break;
				case 2:
				  MC=M2;
				  M0=Mem0[k+1];
				break;
				case 3:
				  MC=M3;
				  M0=Mem0[k+2];
				break;
				}

				gist1[MC][M0]++;

				N++;

			}
			MoveProgress(i, H);
		}
		for(i=0;i<256;i++) for(j=0;j<256;j++) egist[i][j]=gist1[i][j]/(double)N;
		for(i=0;i<256;i++) for(j=0;j<256;j++)
		   if(egist[i][j]>0) Hgist[i][j]=-1*log(egist[i][j]);
		   else Hgist[i][j]=0;

		for(i=0;i<256;i++) for(j=0;j<256;j++) {
		   outmap1[i][j]= 20*Hgist[i][j]; if(outmap1[i][j]<0) outmap1[i][j]=0; else if(outmap1[i][j]>255) outmap1[i][j]=255;
		}

		for ( i = 1; i < H-1; i++) {
			for ( j = 1; j < W-1; j++)
			{
				k = (i * W + j) * 3;
				m=1; M1=M2=M3=0;
				for(i1=i-1;i1<i+2;i1++)
				for(j1=j-1;j1<j+2;j1++)
				{
					if((i1==i)&&(j1==j)) continue;
					k1 = (i1 * W + j1) * 3;
					M1+=Mem0[k1];
					M2+=Mem0[k1+1];
					M3+=Mem0[k1+2];
				}
				M1/=8; M2/=8; M3/=8;
				switch(chan){
				case 0:
					MC=(M1+M2+M3)/3;
					M0=(Mem0[k]+Mem0[k+1]+Mem0[k+2])/3;
				break;
				case 1:
					MC=M1;
					M0=Mem0[k];
				break;
				case 2:
					MC=M2;
					M0=Mem0[k+1];
				break;
				case 3:
					MC=M3;
					M0=Mem0[k+2];
				break;
				}

				Lev = outmap1[MC][M0];
				Mem1[k] = Lev;
				Mem1[k+1] = Lev;
				Mem1[k+2] = Lev;
			}
			MoveProgress(i, H);
		}
}

void EntrD1(int chan, Byte * Mem0, Byte * Mem1, int H, int W)
{

   int gist[512];
   double egist[512];
   int outmap[512];
   double Hgist[512];

   int i,j,k;
   int i1,j1,k1,m,M,N;
   int M0,MC,M1,M2,M3;
   int Lev;

   int gist2[256];
   int gist3[256];

   int outmap2[256];
   int outmap3[256];

		for(i=0;i<256;i++) gist[i]=0; N=0;

		 for ( i = 1; i < H-1; i++) {
			for ( j = 1; j < W-1; j++)
			{
				k = (i * W + j) * 3;
				m=1; M1=M2=M3=0;
				for(i1=i-1;i1<i+2;i1++)
				for(j1=j-1;j1<j+2;j1++)
				{
					if((i1==i)&&(j1==j)) continue;
					k1 = (i1 * W + j1) * 3;
					M1+=Mem0[k1];
					M2+=Mem0[k1+1];
					M3+=Mem0[k1+2];
				}

				M1/=8; M2/=8; M3/=8;
				switch(chan){
				case 0:
					MC=(M1+M2+M3)/3;
					M0=(Mem0[k]+Mem0[k+1]+Mem0[k+2])/3;
				break;
				case 1:
					MC=M1;
					M0=Mem0[k];
				break;
				case 2:
					MC=M2;
					M0=Mem0[k+1];
				break;
				case 3:
					MC=M3;
					M0=Mem0[k+2];
				break;
				}

				gist[256+MC-M0]++;
				N++;
			}
			MoveProgress(i, H);
		}
		for(i=0;i<512;i++) egist[i]=gist[i]/(double)N;
		for(i=0;i<512;i++)
			if(egist[i]>0) Hgist[i]=-1*log(egist[i]);
			else Hgist[i]=0;
		for(i=0;i<512;i++) {
			outmap[i]= 80*Hgist[i]; if(outmap[i]<0) outmap[i]=0; else if(outmap[i]>255) outmap[i]=255;
		}


		for ( i = 1; i < H-1; i++) {
			for ( j = 1; j < W-1; j++)
			{
				k = (i * W + j) * 3;
				m=1; M1=M2=M3=0;
				for(i1=i-1;i1<i+2;i1++)
				for(j1=j-1;j1<j+2;j1++)
				{
					if((i1==i)&&(j1==j)) continue;
					k1 = (i1 * W + j1) * 3;
					M1+=Mem0[k1];
					M2+=Mem0[k1+1];
					M3+=Mem0[k1+2];
				}
				M1/=8; M2/=8; M3/=8;
				switch(chan){
				case 0:
					MC=(M1+M2+M3)/3;
					M0=(Mem0[k]+Mem0[k+1]+Mem0[k+2])/3;
				break;
				case 1:
					MC=M1;
					M0=Mem0[k];
				break;
				case 2:
					MC=M2;
					M0=Mem0[k+1];
				break;
				case 3:
					MC=M3;
					M0=Mem0[k+2];
				break;
				}



				Lev = outmap[256+MC-M0];
				Mem1[k] = Lev;
				Mem1[k+1] = Lev;
				Mem1[k+2] = Lev;


			}
			MoveProgress(i, H);
		}
}

void EntrС1(int chan, Byte * Mem0, Byte * Mem1, int H, int W)
{

   int gist[256];
   int outmap[256];
   double egist[256];
   double Hgist[256];
   int i,j,k;
   int i1,j1,k1,m,M,N;
   int M1,M2,M3;
   int Lev;
   int gist1[256];
   int gist2[256];
   int gist3[256];
   int outmap1[256];
   int outmap2[256];
   int outmap3[256];

		for(i=0;i<256;i++) gist1[i]=gist2[i]=gist3[i]=0; N=0;

		 for ( i = 1; i < H-1; i++) {
			for ( j = 1; j < W-1; j++)
			{
				k = (i * W + j) * 3;
				m=1; M1=M2=M3=0;
				for(i1=i-1;i1<i+2;i1++)
				for(j1=j-1;j1<j+2;j1++)
				{
					if((i1==i)&&(j1==j)) continue;
					k1 = (i1 * W + j1) * 3;
					if(chan==0) {
					  if((Mem0[k]+Mem0[k+1]+Mem0[k+2])>(Mem0[k1]+Mem0[k1+1]+Mem0[k1+2])) M1+=m;
					}
					else if(Mem0[k+chan-1]>Mem0[k1+chan-1]) M1+=m;
					m<<=1;
				}
				gist1[M1]++;
				N++;

			}
			MoveProgress(i, H);
		}
		for(i=0;i<256;i++) egist[i]=gist1[i]/(double)N;
		for(i=0;i<256;i++)
		   if(egist[i]>0) Hgist[i]=-1*log(egist[i]);
		   else Hgist[i]=0;
		   double eh=0; for(i=0;i<256;i++) eh += Hgist[i];

		for(i=0;i<256;i++) {
		   outmap1[i]= 40*Hgist[i]; if(outmap1[i]<0) outmap1[i]=0; else if(outmap1[i]>255) outmap1[i]=255;
		}

		for ( i = 1; i < H-1; i++) {
			for ( j = 1; j < W-1; j++)
			{
				k = (i * W + j) * 3;
				m=1; M1=M2=M3=0;
				for(i1=i-1;i1<i+2;i1++)
				for(j1=j-1;j1<j+2;j1++)
				{
					if((i1==i)&&(j1==j)) continue;
					k1 = (i1 * W + j1) * 3;
					if(chan==0) {
					  if((Mem0[k]+Mem0[k+1]+Mem0[k+2])>(Mem0[k1]+Mem0[k1+1]+Mem0[k1+2])) M1+=m;
					}
					else if(Mem0[k+chan-1]>Mem0[k1+chan-1]) M1+=m;
					m<<=1;
				}
				Lev = outmap1[M1];
				Mem1[k] = Lev;
				Mem1[k+1] = Lev;
				Mem1[k+2] = Lev;


			}
			MoveProgress(i, H);
		}
}



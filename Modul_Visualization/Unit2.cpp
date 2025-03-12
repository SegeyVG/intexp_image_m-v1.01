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
string ProcName[8] = {"Исходное","ФНЧ","ФВЧ","Автоконтраст"};
int BarsNum[5]={0,1,1,1};

int postProcNum =3;
string PostProcName[6] = {"Как есть","Гистограммный","Негатив"};

int ParsPos[3][8]={{10,75,75,10,10,10,10,10},{10,20,30,40,50,60,70,80},{10,20,30,40,50,60,70,80}} ;

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

int GetBarsNum(int conv) // после выбора конкретной функции обработки запрсить количество параметров, ненужные скрыть
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
		LowPass(Chan, Mem0,  MemA,  H,  W, Par1);

		break;
	case 2:
		HighPass(Chan, Mem0,  MemA,  H,  W, Par1);

		break;
	case 3:
		AutoContrast(Chan, Mem0,  MemA,  H,  W, Par1);

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
	 //	for(i=0;i<256;i++)  gist[i]/=Max;
		for(i=0;i<256;i++) gist[i]=gist[i]/Max;
		for(i=0;i<256;i++) {
			outmap[i]=gist[i];
		   //	for(j=0;j<256;j++) if(gist[j]>= i) {outmap[i]=j; break;}
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




int YGist[52];
void AutoContrast(int chan, Byte * Mem0, Byte * Mem1, int H, int W, int Par1)
{

   int i,j,k;
   int i1, i2, e;
   int ViewLevel= Par1*2.55;


   for(i=0;i<52;i++) YGist[i]=0;

		 for ( i = 0; i < H; i++) {
			for ( j = 0; j < W; j++)
			{
				 k = (i * W + j) * 3;
				 e= Mem0[k] + Mem0[k+1] + Mem0[k+2]; e/=3; YGist[e/5]++;

				 Mem1[k] = e; Mem1[k+1] = e; Mem1[k+2] = e;
			}
			MoveProgress(i, H);
		}
   int max=0; int imax=12;
   for(i=1;i<52;i++) if(YGist[i]>max) {max=YGist[i]; imax=i;} imax*=5;

		 for ( i = 0; i < H; i++) {
			for ( j = 0; j < W; j++)
			{
			  k = (i * W + j) * 3;
			  Mem1[k]= ViewLevel+5*(Mem1[k]-imax);
			  if( Mem1[k]>255)  Mem1[k]=255; if( Mem1[k]<0)  Mem1[k]=0;
			  Mem1[k+1] = Mem1[k]; Mem1[k+2] = Mem1[k];
			}
			MoveProgress(i, H);
		}


}

void LowPass(int chan, Byte * Mem0, Byte * Mem1, int H, int W, int Par1)
{



   int i,j,k;

   double Alfa=Par1/101.;
   double x;


		 for ( i = 0; i < H; i++) {
			for ( j = 0; j < W; j++)
			{
				 k = (i * W + j) * 3;
				 if(j<3) x=Mem0[k];
				 else x=Alfa*x+(1-Alfa)*Mem0[k];
				 Mem1[k] = x; Mem1[k+1] = x; Mem1[k+2] = x;
			}
			MoveProgress(i, H);
		}
		 for ( j = 0; j < W; j++) {
			for ( i = 0; i < W; i++)
			{
				 k = (i * W + j) * 3;
				 if(i<3) x=Mem1[k];
				 else x=Alfa*x+(1-Alfa)*Mem1[k];
				 Mem1[k] = x; Mem1[k+1] = x; Mem1[k+2] = x;
			}
			MoveProgress(i, H);
		}
}

void HighPass(int chan, Byte * Mem0, Byte * Mem1, int H, int W, int Par1)
{



   int i,j,k;

   double Alfa=0.85+0.15*(100-Par1)/101.;
   double x;

		 for ( i = 0; i < H; i++) {
			for ( j = 0; j < W; j++)
			{
				 k = (i * W + j) * 3;
				 Mem0[k] -= 128;
				 Mem0[k+1] = Mem0[k];
				 Mem0[k+2] = Mem0[k];			}
			MoveProgress(i, H);
		}


		 for ( i = 0; i < H; i++) {
			for ( j = 0; j < W; j++)
			{
				 k = (i * W + j) * 3;
				 if(j<3) x=Mem0[k];
				 else x=Alfa*x+(1-Alfa)*Mem0[k];
				 Mem1[k] = x; Mem1[k+1] = x; Mem1[k+2] = x;
			}
			MoveProgress(i, H);
		}
		 for ( j = 0; j < W; j++) {
			for ( i = 0; i < W; i++)
			{
				 k = (i * W + j) * 3;
				 if(i<3) x=Mem1[k];
				 else x=Alfa*x+(1-Alfa)*Mem1[k];
				 Mem1[k] = x; Mem1[k+1] = x; Mem1[k+2] = x;
			}
			MoveProgress(i, H);
		}
		 for ( i = 0; i < H; i++) {
			for ( j = 0; j < W; j++)
			{
				 k = (i * W + j) * 3;
				 Mem1[k] = Mem1[k]-Mem0[k];  if(Mem1[k]<0) Mem1[k]=0; else if(Mem1[k]>255) Mem1[k]=255;
				 Mem1[k+1] = Mem1[k];
				 Mem1[k+2] = Mem1[k];
			}
			MoveProgress(i, H);
		}

   		 for ( i = 0; i < H; i++) {
			for ( j = 0; j < W; j++)
			{
				 k = (i * W + j) * 3;
				 Mem0[k] += 128;
				 Mem0[k+1] = Mem0[k];
				 Mem0[k+2] = Mem0[k];
				 Mem1[k] += 128;
				 Mem1[k+1] = Mem1[k];
				 Mem1[k+2] = Mem1[k];			}
			MoveProgress(i, H);
		}
}



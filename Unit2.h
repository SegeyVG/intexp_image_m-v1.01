//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H

void converter(int, Byte *, Byte *, int, int, int*, int*, int, int Par1, int Par2, int Par3,int Chan);
void PostProcess(int , Byte *, Byte *, int, int, int Par1, int Par2, int Par3);
char *GetNames(int conv); // ��������� ����� ������� � ��������� �� � ������
char* GetPostNames(int postIndex); // ��������� ����� ������������� � ��������� �� � ������
int GetBarsNum(int conv); // ����� ������ ���������� ������� ��������� �������� ���������� ����������, �������� ������
int GetParsPos(int conv, int Bar); // ��� ������� ��������� ��������� ��������� ������� "���������

void EntrA1(int chan, Byte * Mem0, Byte * Mem1, int H, int W);
void EntrD1(int chan, Byte * Mem0, Byte * Mem1, int H, int W);
void Entr�1(int chan, Byte * Mem0, Byte * Mem1, int H, int W);

//---------------------------------------------------------------------------
#endif


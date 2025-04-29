//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H

void converter(int, Byte *, Byte *, int, int, int*, int*, int, int Par1, int Par2, int Par3,int Chan);
void PostProcess(int , Byte *, Byte *, int, int, int Par1, int Par2, int Par3);
char *GetNames(int conv); // запросить имена функций и отправить их в список
char* GetPostNames(int postIndex); // запросить имена постобработок и отправить их в список
int GetBarsNum(int conv); // после выбора конкретной функции обработки запрсить количество параметров, ненужные скрыть
int GetParsPos(int conv, int Bar); // дл€ каждого активного параметра запросить позицию "ползункаЁ

void EntrA1(int chan, Byte * Mem0, Byte * Mem1, int H, int W);
void EntrD1(int chan, Byte * Mem0, Byte * Mem1, int H, int W);
void Entr—1(int chan, Byte * Mem0, Byte * Mem1, int H, int W);

//---------------------------------------------------------------------------
#endif


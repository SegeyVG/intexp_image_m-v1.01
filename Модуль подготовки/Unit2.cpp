//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm2 *Form2;
//---------------------------------------------------------------------------
void TForm2::getParamMsk(AnsiString name, AnsiString count, int ext){
	Edit1->Text = name;
	Edit2->Text = count;
	ComboBox1->ItemIndex = ext;
}
//-------------------------------------------------------------------

__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	AnsiString name = Edit1->Text;
	AnsiString count = Edit2->Text;
	AnsiString ext = ComboBox1->Text;
	int id_ext = ComboBox1->ItemIndex;
	Form1->setParamMsk(name, count, ext, id_ext);
	Form2->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{
    Form2->Close();
}
//---------------------------------------------------------------------------


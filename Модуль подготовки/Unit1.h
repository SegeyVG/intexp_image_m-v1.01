//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TGroupBox *GroupBox2;
	TButton *Button1;
	TEdit *Edit1;
	TLabel *Label1;
	TEdit *Edit2;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TEdit *Edit3;
	TLabel *Label2;
	TEdit *Edit4;
	TLabel *Label3;
	TEdit *Edit5;
	TLabel *Label4;
	TEdit *Edit6;
	TButton *Button5;
	TOpenPictureDialog *OpenPictureDialog1;
	TFileOpenDialog *FileOpenDialog1;
	TEdit *Edit7;
	TButton *Button6;
	TEdit *Edit8;
	TLabel *Label5;
	TComboBox *ComboBox1;
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Edit1Change(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Edit2Change(TObject *Sender);
	void __fastcall Edit4Change(TObject *Sender);
	void __fastcall Edit5Change(TObject *Sender);
	void __fastcall Edit3Change(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Edit7Change(TObject *Sender);
	void __fastcall Edit6Change(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Edit8Change(TObject *Sender);
	void __fastcall ComboBox1Change(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
	AnsiString lfname, ldir, lmsk;
	AnsiString rfname, rdir_v, rmsk, fps, rdir_i, rf_ext;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

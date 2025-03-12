//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	lmsk = "image%6d.jpg";
	rmsk = "image%6d.jpg";
	Edit2->Text= lmsk;
	Edit5->Text= rmsk;
	fps = "30";
    rf_ext = "mp4";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	FileOpenDialog1->Options << fdoPickFolders; // Устанавливаем опцию выбора папок
	if (FileOpenDialog1->Execute())
	{
		ldir = FileOpenDialog1->FileName;
		Edit8->Text = ldir;
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	if (OpenPictureDialog1->Execute()) {
		lfname = OpenPictureDialog1->FileName;
		Edit1->Text = lfname;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1Change(TObject *Sender)
{
	Edit1->Text = lfname;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	FileOpenDialog1->Options << fdoPickFolders; // Устанавливаем опцию выбора папок
	if (FileOpenDialog1->Execute())
	{
		rdir_i = FileOpenDialog1->FileName;
		Edit3->Text = rdir_i;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit2Change(TObject *Sender)
{
    lmsk = Edit2->Text;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit4Change(TObject *Sender)
{
	fps = Edit4->Text;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit5Change(TObject *Sender)
{
    rmsk = Edit5->Text;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit3Change(TObject *Sender)
{
	Edit3->Text = rdir_i;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
	FileOpenDialog1->Options << fdoPickFolders; // Устанавливаем опцию выбора папок
	if (FileOpenDialog1->Execute())
	{
		rdir_v = FileOpenDialog1->FileName;
		Edit7->Text = rdir_v;
		//ShowMessage(rdir_i);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit7Change(TObject *Sender)
{
     Edit7->Text = rdir_v;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit6Change(TObject *Sender)
{
     rfname = Edit6->Text;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	//ffmpeg -i "D:\\Works\\RS_Projects\\sample-5s.mp4" "D:\\Works\\RS_Projects\\output_frame%04d.jpg"

	UnicodeString command = L"ffmpeg -i";
	AnsiString argsAS = AnsiString("\"") + lfname + "\"" + " \"" + ldir + "\\" + lmsk +"\"";
	UnicodeString argsUS = argsAS;

	// Преобразуем аргументы в C-строку
	wchar_t* commandLine = (command + L" " + argsUS).w_str();

	STARTUPINFO si = { sizeof(si) };
	PROCESS_INFORMATION pi;
	if (CreateProcess(nullptr,   // Имя модуля (nullptr значит использовать командную строку)
		commandLine,             // Командная строка
		nullptr,                 // Процесс безопасности
		nullptr,                 // Поток безопасности
		FALSE,                   // Не наследовать дескрипторы
		0,                       // Флаги создания
		nullptr,                 // Переменные окружения
		nullptr,                 // Текущая директория
		&si,                     // Структура информации о запуске
		&pi       ))
	{
		WaitForSingleObject(pi.hProcess, INFINITE);

		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
	ShowMessage("Процесс извлечения кадров успешно завершен.");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	//ffmpeg -framerate 30 -i  "D:\Works\RS_Projects\output_frame%04d.jpg" "D:\Works\RS_Projects\sample-5s.mp4"

	UnicodeString command = L"ffmpeg -framerate " + fps + L" -i";
	AnsiString argsAS = AnsiString("\"") + rdir_i + "\\" + rmsk +"\" \"" + rdir_v + "\\" + rfname + "."+ rf_ext+ "\"";
	UnicodeString argsUS = argsAS;

	// Преобразуем аргументы в C-строку
	wchar_t* commandLine = (command + L" " + argsUS).w_str();
	
	STARTUPINFO si = { sizeof(si) };
	PROCESS_INFORMATION pi;
	if (CreateProcess(nullptr,   // Имя модуля (nullptr значит использовать командную строку)
		commandLine,             // Командная строка
		nullptr,                 // Процесс безопасности
		nullptr,                 // Поток безопасности
		FALSE,                   // Не наследовать дескрипторы
		0,                       // Флаги создания
		nullptr,                 // Переменные окружения
		nullptr,                 // Текущая директория
		&si,                     // Структура информации о запуске
		&pi       ))
	{
		WaitForSingleObject(pi.hProcess, INFINITE);

		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
	ShowMessage("Процесс сборки кадров успешно завершен. Файл с видеорядом получен.");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit8Change(TObject *Sender)
{
    Edit8->Text = ldir;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
	rf_ext = ComboBox1->Text;
}
//---------------------------------------------------------------------------


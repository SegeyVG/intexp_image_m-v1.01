//---------------------------------------------------------------------------

#include <vcl.h>
#include <Windows.h>
#include <System.IOUtils.hpp>
#include <System.SysUtils.hpp>
#include <Vcl.Dialogs.hpp>
#include <regex>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

enum NPanel {
	left,
	right
};

NPanel panel;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	lmsk = "image%6d.jpg";
	rmsk = "image%6d.jpg";
	lm_name = "image";
	l_count = "6";
	l_ext = 1;
	rm_name = "image";
	r_count = "6";
	r_ext = 1;
	Edit2->Text= lmsk;
	Edit5->Text= rmsk;
	fps = "30";
    rf_ext = "mp4";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	FileOpenDialog1->Options << fdoPickFolders; // ������������� ����� ������ �����
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
	FileOpenDialog1->Options << fdoPickFolders; // ������������� ����� ������ �����
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
	FileOpenDialog1->Options << fdoPickFolders; // ������������� ����� ������ �����
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
//-------------------------------------------------------------------------

void MoveFilesAndDeleteTemp(AnsiString& ldir){
	// �������� ������ ���� ������ � ����������
	DynamicArray<UnicodeString> files = TDirectory::GetFiles(ldir + "\\Temp");

	for (const AnsiString& fileName : files) {
		AnsiString fname = TPath::GetFileName(fileName);
		AnsiString fnameDest = ldir + "\\" + fname;
		TFile::Copy(fileName, fnameDest, true);
	}
	TDirectory::Delete(ldir + "\\Temp", true);
}
//---------------------------------------------------------------------------

bool CheckExistFiles(AnsiString& ldir)  {
	// �������� ������ ���� ������ � ����������
	DynamicArray<UnicodeString> files = TDirectory::GetFiles(ldir + "\\Temp");

	bool fileFound = false;
	for (const AnsiString& fileName : files) {
		// �������� ��� ����� ��� ����������
		AnsiString fileBaseName = TPath::GetFileNameWithoutExtension(fileName);
		AnsiString fileExtension = TPath::GetExtension(fileName);
		UnicodeString ffname = ldir + "\\" + fileBaseName + fileExtension;
		if (TFile::Exists(ffname.w_str())) {
			fileFound = true;
			break;
		}
	}

	if(fileFound) {
	// �������� ������ � �������� � ����� ����������: "��" � "���"
		UnicodeString errorText = "� ����� ��� ����������� ������� �����, ����������� � ������� ������ ��� ��������� ������. � ������ ����������� ��� ����� ������������. ����������?";
		int result = MessageDlg(errorText, mtCustom, mbYesNo,0);
		if (result == IDYES)
			return true;
		else
		   return false;
	} else
        return true;
}

//----------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	if(lfname.IsEmpty()) {
		ShowMessage("�������� �� ����� ���������. �������� �������� ���������.");
		return;
	}

	if(ldir.IsEmpty()) {
		ShowMessage("�������� �� ����� ���������. �������� ����� ��� ���������� ������.");
		return;
	}
	//ffmpeg -i "D:\\Works\\RS_Projects\\sample-5s.mp4" "D:\\Works\\RS_Projects\\output_frame%04d.jpg"

	UnicodeString dirTemp = AnsiString(ldir) + "\\Temp"; // ���� �� ����������
	CreateDirectory(dirTemp.w_str(), NULL);

	UnicodeString command = L"ffmpeg -i";
	AnsiString argsAS = AnsiString("\"") + lfname + "\"" + " \"" + ldir + "\\Temp" + "\\" + lmsk +"\"";
	UnicodeString argsUS = argsAS;

	// ����������� ��������� � C-������
	wchar_t* commandLine = (command + L" " + argsUS).w_str();

	STARTUPINFO si = { sizeof(si) };
	PROCESS_INFORMATION pi;
	if (CreateProcess(nullptr,   // ��� ������ (nullptr ������ ������������ ��������� ������)
		commandLine,             // ��������� ������
		nullptr,                 // ������� ������������
		nullptr,                 // ����� ������������
		FALSE,                   // �� ����������� �����������
		0,                       // ����� ��������
		nullptr,                 // ���������� ���������
		nullptr,                 // ������� ����������
		&si,                     // ��������� ���������� � �������
		&pi       ))
	{
		WaitForSingleObject(pi.hProcess, INFINITE);

		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
	bool go = CheckExistFiles(ldir);
	if(!go) {
		ShowMessage("������� ���������� ������ ������� �������������.");
		return;
	}
	MoveFilesAndDeleteTemp(ldir);
	ShowMessage("������� ���������� ������ ������� ��������.");
}
//---------------------------------------------------------------------------

bool CheckFileFormat(AnsiString& rdir_i, AnsiString& sname, AnsiString& format, AnsiString& ext)
{
	bool ret = true;
	int fileIndex = 1; // ������ ��� �������� ������������ ������
	int count = 0;     //������� ������� ��������� ������ ������ �����������

	// �������� ������ ���� ������ � ����������
	DynamicArray<UnicodeString> files = TDirectory::GetFiles(rdir_i);

	while (true) {
		AnsiString expectedFileName = sname + AnsiString().sprintf(format.c_str(), fileIndex); // ��������� ��������� ��� �����
		bool fileFound = false;

		for (const AnsiString& fileName : files) {
			// �������� ��� ����� ��� ����������
			AnsiString fileBaseName = TPath::GetFileNameWithoutExtension(fileName);
			AnsiString fileExtension = TPath::GetExtension(fileName);
			fileExtension = fileExtension.SubString(2, fileExtension.Length() - 1);

			// ���������, ������������� �� ��� ����� � ��� ����������
			if (fileBaseName == expectedFileName && fileExtension == ext) {
				fileFound = true;
				count++;
				break; // ���� ������, ������� �� �����
			}

			if (fileBaseName == expectedFileName && fileExtension != "." + ext) {
				ShowMessage("������: ���� � ������ " + expectedFileName + " ����� ������ ����������� " + fileExtension + " ������ ���������� "
					+ ext +". �������� ������ �� ����� ���� ��������� ���������."		);
				ret = false;
				break; // ���� ������, ������� �� �����
			}


		}

		if (!fileFound) {
			// ���� ���� �� ������, ����� ���������� ��������
			if (count<1) {
				ShowMessage("������: �� ������� �� ������ �����, ���������������� �������� �����, � ��������� �����. �������� ������ �� ����� ���� ��������� ���������.");
				return false;
			}
			if(count>=1 && !ret)
				return false;
			return ret; // ������������� ����������
		}

		fileIndex++; // ����������� ������ ��� ���������� �����
	}

}

//------------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
	if(rdir_i.IsEmpty()) {
		ShowMessage("�������� �� ����� ���������. �������� ����� ��� ����� �����  ��� �����.");
		return;
	}

	if(fps.IsEmpty()) {
		ShowMessage("�������� �� ����� ���������. ������� ����������� ������/�.");
		return;
	}

	if(rdir_v.IsEmpty()) {
		ShowMessage("�������� �� ����� ���������. �������� ����� ��� ���������� ����������.");
		return;
	}

	if(rfname.IsEmpty()) {
		ShowMessage("�������� �� ����� ���������. ������� ��� ���������� ��� ������� ���� � �������� ����������.");
		return;
	}

	AnsiString format = "%";
	if (r_count!="0" && r_count!=NULL) {
		format = format + "0" + r_count;
	}
	format += "d";
	AnsiString extension = TPath::GetExtension(rmsk);
	extension = extension.SubString(2, extension.Length() - 1);

	if(!CheckFileFormat(rdir_i, rm_name, format, extension))
		return;

	//ffmpeg -framerate 30 -i  "D:\Works\RS_Projects\output_frame%04d.jpg" "D:\Works\RS_Projects\sample-5s.mp4"

	UnicodeString command = L"ffmpeg -framerate " + fps + L" -i";
	AnsiString argsAS1 = AnsiString("\"") + rdir_i + "\\" + rmsk +"\" ";
	AnsiString argsAS3 = AnsiString("\"") + rdir_v + "\\" + rfname + "."+ rf_ext+ "\"";
	AnsiString argsAS2 = AnsiString();
	if(rf_ext=="avi")
		argsAS2 += "-c:v rawvideo -pix_fmt yuv420p ";
	else if(rf_ext=="mov")
		argsAS2 += "-c:v prores -pix_fmt yuv420p ";
	else
		argsAS2 += " ";
	AnsiString argsAS = argsAS1 + argsAS2 + argsAS3;
	UnicodeString argsUS = argsAS;

	// ����������� ��������� � C-������
	wchar_t* commandLine = (command + L" " + argsUS).w_str();

	STARTUPINFO si = { sizeof(si) };
	PROCESS_INFORMATION pi;
	if (CreateProcess(nullptr,   // ��� ������ (nullptr ������ ������������ ��������� ������)
		commandLine,             // ��������� ������
		nullptr,                 // ������� ������������
		nullptr,                 // ����� ������������
		FALSE,                   // �� ����������� �����������
		0,                       // ����� ��������
		nullptr,                 // ���������� ���������
		nullptr,                 // ������� ����������
		&si,                     // ��������� ���������� � �������
		&pi       ))
	{
		WaitForSingleObject(pi.hProcess, INFINITE);

		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
	ShowMessage("������� ������ ������ ������� ��������.");
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

void TForm1::setParamMsk(AnsiString name, AnsiString count, AnsiString ext, int id_ext) {
	AnsiString msk = name + "%";
	msk = msk + count + "d." + ext;
	switch (panel) {
		case left:
			lmsk = msk;
			lm_name = name; l_count = count;
			l_ext = id_ext;
			Edit2->Text = msk;
			break;
		default:
			rmsk = msk;
			rm_name = name; r_count = count;
			r_ext = id_ext;
			Edit5->Text = msk;
			break;
	}
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
	Form2->getParamMsk(lm_name, l_count, l_ext);
	panel = left;
	Form2->ShowModal();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
	Form2->getParamMsk(rm_name, r_count, r_ext);
	panel = right;
	Form2->ShowModal();
}
//---------------------------------------------------------------------------


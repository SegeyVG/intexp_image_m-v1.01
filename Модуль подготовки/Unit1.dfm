object Form1: TForm1
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 
    #1055#1050' "'#1040#1090#1083#1072#1089'-'#1060#1086#1090#1086'". '#1052#1086#1076#1091#1083#1100' '#1087#1086#1076#1075#1086#1090#1086#1074#1082#1080' '#1080#1079#1086#1073#1088#1072#1078#1077#1085#1080#1081' '#1082' '#1086#1073#1088#1072#1073#1086#1090#1082#1077'. '#1042#1077#1088#1089 +
    #1080#1103' 1.01 '
  ClientHeight = 318
  ClientWidth = 838
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 9
    Top = 8
    Width = 393
    Height = 281
    Caption = #1056#1072#1089#1082#1072#1076#1088#1086#1074#1082#1072' '#1074#1080#1076#1077#1086
    TabOrder = 0
    object Label1: TLabel
      Left = 24
      Top = 112
      Width = 121
      Height = 13
      Caption = #1052#1072#1089#1082#1072' '#1076#1083#1103' '#1080#1084#1077#1085' '#1092#1072#1081#1083#1086#1074
    end
    object Button1: TButton
      Left = 120
      Top = 24
      Width = 121
      Height = 34
      Caption = #1042#1099#1073#1088#1072#1090#1100' '#1074#1080#1076#1077#1086
      TabOrder = 0
      OnClick = Button1Click
    end
    object Edit1: TEdit
      Left = 8
      Top = 64
      Width = 385
      Height = 21
      TabOrder = 1
      OnChange = Edit1Change
    end
    object Edit2: TEdit
      Left = 151
      Top = 109
      Width = 98
      Height = 21
      Enabled = False
      TabOrder = 2
      OnChange = Edit2Change
    end
    object Button2: TButton
      Left = 24
      Top = 144
      Width = 185
      Height = 33
      Caption = #1042#1099#1073#1088#1072#1090#1100' '#1087#1072#1087#1082#1091' '#1076#1083#1103' '#1082#1072#1076#1088#1086#1074
      TabOrder = 3
      OnClick = Button2Click
    end
    object Button3: TButton
      Left = 232
      Top = 144
      Width = 97
      Height = 33
      Caption = #1053#1072#1095#1072#1090#1100
      TabOrder = 4
      OnClick = Button3Click
    end
    object Edit8: TEdit
      Left = 8
      Top = 192
      Width = 382
      Height = 21
      TabOrder = 5
      OnChange = Edit8Change
    end
  end
  object GroupBox2: TGroupBox
    Left = 408
    Top = 8
    Width = 412
    Height = 281
    Caption = #1057#1073#1086#1088#1082#1072' '#1074#1080#1076#1077#1086' '#1080#1079' '#1082#1072#1076#1088#1086#1074
    TabOrder = 1
    object Label2: TLabel
      Left = 24
      Top = 112
      Width = 112
      Height = 13
      Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1082#1072#1076#1088#1086#1074'/'#1089' '
    end
    object Label3: TLabel
      Left = 24
      Top = 139
      Width = 121
      Height = 13
      Caption = #1052#1072#1089#1082#1072' '#1076#1083#1103' '#1080#1084#1077#1085' '#1092#1072#1081#1083#1086#1074
    end
    object Label4: TLabel
      Left = 26
      Top = 236
      Width = 113
      Height = 13
      Caption = #1048#1084#1103' '#1092#1072#1081#1083#1072' '#1074#1080#1076#1077#1086#1088#1103#1076#1072
    end
    object Label5: TLabel
      Left = 255
      Top = 241
      Width = 4
      Height = 13
      Caption = '.'
    end
    object Button4: TButton
      Left = 144
      Top = 24
      Width = 161
      Height = 34
      Caption = #1042#1099#1073#1088#1072#1090#1100' '#1087#1072#1087#1082#1091' '#1089' '#1082#1072#1076#1088#1072#1084#1080
      TabOrder = 0
      OnClick = Button4Click
    end
    object Edit3: TEdit
      Left = 8
      Top = 64
      Width = 401
      Height = 21
      TabOrder = 1
      OnChange = Edit3Change
    end
    object Edit4: TEdit
      Left = 168
      Top = 109
      Width = 49
      Height = 21
      TabOrder = 2
      Text = '30'
      OnChange = Edit4Change
    end
    object Edit5: TEdit
      Left = 167
      Top = 136
      Width = 106
      Height = 21
      Enabled = False
      TabOrder = 3
      OnChange = Edit5Change
    end
    object Edit6: TEdit
      Left = 145
      Top = 233
      Width = 104
      Height = 21
      TabOrder = 4
      OnChange = Edit6Change
    end
    object Button5: TButton
      Left = 295
      Top = 130
      Width = 97
      Height = 33
      Caption = #1053#1072#1095#1072#1090#1100
      TabOrder = 5
      OnClick = Button5Click
    end
    object Edit7: TEdit
      Left = 24
      Top = 206
      Width = 289
      Height = 21
      TabOrder = 6
      OnChange = Edit7Change
    end
    object Button6: TButton
      Left = 24
      Top = 176
      Width = 289
      Height = 24
      Caption = #1042#1099#1073#1088#1072#1090#1100' '#1087#1072#1087#1082#1091' '#1076#1083#1103' '#1074#1080#1076#1077#1086
      TabOrder = 7
      OnClick = Button6Click
    end
    object ComboBox1: TComboBox
      Left = 265
      Top = 233
      Width = 49
      Height = 21
      Style = csDropDownList
      ItemIndex = 0
      TabOrder = 8
      Text = 'mp4'
      OnChange = ComboBox1Change
      Items.Strings = (
        'mp4'
        'avi'
        'mkv'
        'mov'
        'wmv'
        'flv'
        'mpg'
        'mpeg')
    end
  end
  object OpenPictureDialog1: TOpenPictureDialog
    Filter = 'Video|*.mpg;*.mp4;*.mov;*.flv;*.aiff;*.avi'
    Left = 297
    Top = 24
  end
  object FileOpenDialog1: TFileOpenDialog
    FavoriteLinks = <>
    FileTypes = <>
    Options = []
    Left = 304
    Top = 104
  end
end

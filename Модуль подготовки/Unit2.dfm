object Form2: TForm2
  Left = 0
  Top = 0
  Caption = #1060#1086#1088#1084#1072#1090' '#1084#1072#1089#1082#1080
  ClientHeight = 163
  ClientWidth = 404
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 12
    Width = 161
    Height = 13
    Caption = #1057#1080#1084#1074#1086#1083#1100#1085#1072#1103' '#1095#1072#1089#1090#1100' '#1080#1084#1077#1085#1080' '#1092#1072#1081#1083#1072
  end
  object Label2: TLabel
    Left = 8
    Top = 43
    Width = 203
    Height = 13
    Caption = #1052#1072#1082#1089#1080#1084#1072#1083#1100#1085#1086#1077' '#1082#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1094#1080#1092#1088' '#1085#1086#1084#1077#1088#1072
  end
  object Label3: TLabel
    Left = 8
    Top = 79
    Width = 96
    Height = 13
    Caption = #1056#1072#1089#1096#1080#1088#1077#1085#1080#1077' '#1092#1072#1081#1083#1072
  end
  object Button1: TButton
    Left = 96
    Top = 122
    Width = 81
    Height = 25
    Caption = #1055#1088#1080#1084#1077#1085#1080#1090#1100
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 224
    Top = 122
    Width = 81
    Height = 25
    Caption = #1047#1072#1082#1088#1099#1090#1100
    TabOrder = 1
    OnClick = Button2Click
  end
  object Edit1: TEdit
    Left = 183
    Top = 8
    Width = 210
    Height = 21
    TabOrder = 2
  end
  object Edit2: TEdit
    Left = 232
    Top = 40
    Width = 161
    Height = 21
    TabOrder = 3
  end
  object ComboBox1: TComboBox
    Left = 119
    Top = 78
    Width = 49
    Height = 21
    ItemIndex = 1
    TabOrder = 4
    Text = 'jpg'
    Items.Strings = (
      'bmp'
      'jpg'
      'tif'
      'tiff')
  end
end

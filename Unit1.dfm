object Form1: TForm1
  Left = 137
  Top = 77
  AutoSize = True
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #1055#1050' "'#1040#1090#1083#1072#1089' - '#1060#1086#1090#1086'", '#1052#1086#1076#1091#1083#1100' '#1086#1073#1088#1072#1073#1086#1090#1082#1080' '#1080#1079#1086#1073#1088#1072#1078#1077#1085#1080#1081'. '#1042#1077#1088#1089#1080#1103' 1.01'
  ClientHeight = 1039
  ClientWidth = 1691
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Padding.Left = 1
  Padding.Top = 1
  Padding.Right = 6
  Padding.Bottom = 1
  OldCreateOrder = False
  Position = poDesigned
  DesignSize = (
    1691
    1039)
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 1
    Top = 1
    Width = 1474
    Height = 1037
    Anchors = [akLeft, akTop, akBottom]
    OnClick = Image1Click
    OnMouseLeave = Image1MouseLeave
    OnMouseMove = Image1MouseMove
    ExplicitHeight = 849
  end
  object OpenImage1: TButton
    Left = 1497
    Top = 10
    Width = 88
    Height = 25
    Caption = #1054#1090#1082#1088#1099#1090#1100
    TabOrder = 0
    OnClick = OpenImage1Click
  end
  object GroupBox1: TGroupBox
    Left = 1481
    Top = 86
    Width = 201
    Height = 150
    Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1080#1079#1086#1073#1088#1072#1078#1077#1085#1080#1103
    Enabled = False
    TabOrder = 1
    object Label1: TLabel
      Left = 32
      Top = 107
      Width = 138
      Height = 13
      Caption = #1069#1092#1092#1077#1082#1090#1080#1074#1085#1072#1103' '#1088#1072#1079#1088#1103#1076#1085#1086#1089#1090#1100
    end
    object Label2: TLabel
      Left = 16
      Top = 24
      Width = 39
      Height = 13
      Caption = #1064#1080#1088#1080#1085#1072
    end
    object Label3: TLabel
      Left = 16
      Top = 54
      Width = 38
      Height = 13
      Caption = #1042#1099#1089#1086#1090#1072
    end
    object Label4: TLabel
      Left = 18
      Top = 81
      Width = 37
      Height = 13
      Caption = #1069#1082#1088#1072#1085': '
    end
    object NBitWin: TEdit
      Left = 32
      Top = 126
      Width = 145
      Height = 21
      Enabled = False
      TabOrder = 0
    end
    object WWin: TEdit
      Left = 61
      Top = 24
      Width = 89
      Height = 21
      Enabled = False
      TabOrder = 1
    end
    object HWin: TEdit
      Left = 61
      Top = 54
      Width = 89
      Height = 21
      Enabled = False
      TabOrder = 2
    end
  end
  object GroupBox2: TGroupBox
    Left = 1481
    Top = 242
    Width = 201
    Height = 111
    Caption = #1060#1080#1083#1100#1090#1088
    TabOrder = 2
    object ComboBox1: TComboBox
      Left = 32
      Top = 18
      Width = 145
      Height = 21
      TabOrder = 0
      Text = #1048#1089#1093#1086#1076#1085#1086#1077
      OnChange = ComboBox1Change
    end
    object Button1: TButton
      Left = 56
      Top = 78
      Width = 89
      Height = 25
      Caption = #1055#1088#1080#1085#1103#1090#1100
      Enabled = False
      TabOrder = 1
      OnClick = Button1Click
    end
    object ComboBox2: TComboBox
      Left = 32
      Top = 45
      Width = 145
      Height = 21
      ItemIndex = 0
      TabOrder = 2
      Text = '0 - '#1074#1089#1077
      OnChange = ComboBox2Change
      Items.Strings = (
        '0 - '#1074#1089#1077
        '1 - R'
        '2- G'
        '3-B')
    end
  end
  object ProgressBar1: TProgressBar
    Left = 1484
    Top = 1018
    Width = 201
    Height = 17
    Step = 20
    TabOrder = 3
    Visible = False
  end
  object GroupBox4: TGroupBox
    Left = 1481
    Top = 647
    Width = 201
    Height = 57
    Caption = #1052#1072#1089#1096#1090#1072#1073
    Enabled = False
    TabOrder = 4
    object Button2: TButton
      Left = 16
      Top = 20
      Width = 25
      Height = 25
      Enabled = False
      ImageAlignment = iaCenter
      ImageIndex = 1
      Images = ImageList1
      TabOrder = 0
      OnClick = Button2Click
    end
    object Button3: TButton
      Left = 47
      Top = 20
      Width = 26
      Height = 25
      Enabled = False
      ImageAlignment = iaCenter
      ImageIndex = 0
      Images = ImageList1
      TabOrder = 1
      OnClick = Button3Click
    end
    object Button4: TButton
      Left = 96
      Top = 20
      Width = 33
      Height = 25
      Enabled = False
      ImageAlignment = iaCenter
      ImageIndex = 2
      Images = ImageList1
      TabOrder = 2
      OnClick = Button4Click
    end
    object Button5: TButton
      Left = 143
      Top = 20
      Width = 34
      Height = 25
      Caption = '1:1'
      Enabled = False
      TabOrder = 3
      OnClick = Button5Click
    end
  end
  object GroupBox5: TGroupBox
    Left = 1481
    Top = 710
    Width = 201
    Height = 105
    TabOrder = 5
    object RadioGroup1: TRadioGroup
      Left = 3
      Top = 3
      Width = 195
      Height = 65
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100':'
      ItemIndex = 0
      Items.Strings = (
        #1090#1086', '#1095#1090#1086' '#1074#1080#1076#1085#1086' '#1085#1072' '#1092#1086#1088#1084#1077
        #1087#1086' '#1092#1072#1082#1090#1080#1095#1077#1089#1082#1086#1080#1084#1091' '#1088#1072#1079#1084#1077#1088#1091)
      TabOrder = 0
    end
    object SaveImg: TButton
      Left = 64
      Top = 72
      Width = 75
      Height = 25
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
      Enabled = False
      TabOrder = 1
      OnClick = SaveImgClick
    end
  end
  object GroupBox7: TGroupBox
    Left = 1481
    Top = 821
    Width = 202
    Height = 148
    Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099
    TabOrder = 6
    object TrackBar3: TTrackBar
      Left = 16
      Top = 16
      Width = 45
      Height = 129
      Max = 100
      Orientation = trVertical
      TabOrder = 0
      Visible = False
      OnChange = TrackBar3Change
    end
    object TrackBar4: TTrackBar
      Left = 88
      Top = 16
      Width = 45
      Height = 129
      Max = 100
      Orientation = trVertical
      TabOrder = 1
      Visible = False
      OnChange = TrackBar4Change
    end
    object TrackBar5: TTrackBar
      Left = 160
      Top = 16
      Width = 45
      Height = 129
      Max = 100
      Orientation = trVertical
      TabOrder = 2
      Visible = False
      OnChange = TrackBar5Change
    end
  end
  object GroupBox9: TGroupBox
    Left = 1481
    Top = 359
    Width = 201
    Height = 274
    Caption = #1055#1086#1089#1090#1086#1073#1088#1072#1073#1086#1090#1082#1072
    TabOrder = 7
    object GroupBox3: TGroupBox
      Left = 0
      Top = 53
      Width = 201
      Height = 53
      Caption = #1071#1088#1082#1086#1089#1090#1100
      Enabled = False
      TabOrder = 0
      object TrackBar1: TTrackBar
        Left = 3
        Top = 16
        Width = 198
        Height = 25
        Max = 100
        TabOrder = 0
        OnChange = TrackBar1Change
      end
    end
    object GroupBox6: TGroupBox
      Left = 0
      Top = 107
      Width = 201
      Height = 89
      Caption = #1050#1086#1085#1090#1088#1072#1089#1090#1085#1086#1089#1090#1100
      TabOrder = 1
      object TrackBar2: TTrackBar
        Left = 3
        Top = 16
        Width = 198
        Height = 33
        Max = 12
        ParentShowHint = False
        ShowHint = True
        TabOrder = 0
        OnChange = TrackBar2Change
      end
      object TrackBar6: TTrackBar
        Left = 3
        Top = 52
        Width = 198
        Height = 32
        Max = 12
        ParentShowHint = False
        ShowHint = True
        TabOrder = 1
        OnChange = TrackBar6Change
      end
    end
    object Button6: TButton
      Left = 48
      Top = 246
      Width = 113
      Height = 25
      Caption = #1082#1072#1082' '#1074' '#1086#1088#1080#1075#1080#1085#1072#1083#1077
      TabOrder = 2
      OnClick = Button6Click
    end
    object GroupBox8: TGroupBox
      Left = 3
      Top = 197
      Width = 201
      Height = 46
      Caption = #1055#1088#1086#1079#1088#1072#1095#1085#1086#1089#1090#1100
      TabOrder = 3
      object TrackBar7: TTrackBar
        Left = 0
        Top = 18
        Width = 198
        Height = 25
        Max = 100
        TabOrder = 0
        OnChange = TrackBar7Change
      end
    end
    object ComboBox3: TComboBox
      Left = 32
      Top = 24
      Width = 145
      Height = 21
      TabOrder = 4
      Text = #1053#1077#1090
      OnChange = ComboBox3Change
    end
  end
  object ComboBox4: TComboBox
    Left = 1600
    Top = 14
    Width = 82
    Height = 21
    ItemIndex = 0
    TabOrder = 8
    Text = #1048#1089#1093#1086#1076#1085'oe'
    OnChange = ComboBox4Change
    Items.Strings = (
      #1048#1089#1093#1086#1076#1085'oe'
      #1060#1086#1088#1084#1072#1090' A'
      #1060#1086#1088#1084#1072#1090' B'
      #1060#1086#1088#1084#1072#1090' C'
      #1060#1086#1088#1084#1072#1090' D')
  end
  object GroupBox10: TGroupBox
    Left = 1481
    Top = 41
    Width = 201
    Height = 32
    TabOrder = 9
    object Button7: TButton
      Left = 35
      Top = 3
      Width = 30
      Height = 21
      Caption = '<<'
      Enabled = False
      TabOrder = 0
      OnClick = Button7Click
    end
    object Button8: TButton
      Left = 136
      Top = 3
      Width = 30
      Height = 21
      Caption = '>>'
      Enabled = False
      TabOrder = 1
      OnClick = Button8Click
    end
    object Edit1: TEdit
      Left = 64
      Top = 3
      Width = 74
      Height = 21
      Enabled = False
      TabOrder = 2
    end
  end
  object OpenPictureDialog1: TOpenPictureDialog
    DefaultExt = 'bmp'
    Filter = 'Images|*.bmp;*jpg;*tif'
    Left = 1304
    Top = 624
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = 'csv'
    FileName = 'Result.csv'
    Filter = 'Excel|*.csv'
    Left = 1168
    Top = 672
  end
  object ApplicationEvents1: TApplicationEvents
    OnMinimize = ApplicationEvents1Minimize
    OnRestore = ApplicationEvents1Restore
    Left = 1184
    Top = 480
  end
  object Timer1: TTimer
    Interval = 800
    OnTimer = Timer1Timer
    Left = 1288
    Top = 136
  end
  object ImageList1: TImageList
    Left = 1256
    Top = 312
    Bitmap = {
      494C010103000800040010001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000001000000001002000000000000010
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000AAAAAA00AAAAAA00AAAA
      AA00AAAAAA00AAAAAA00AAAAAA00AAAAAA00AAAAAA00AAAAAA00AAAAAA00AAAA
      AA00AAAAAA00AAAAAA00AAAAAA00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000BFBFBF00A6A6A600DDDDDD00DDDD
      DD00DDDDDD00DDDDDD00DDDDDD00DDDDDD00DDDDDD00DDDDDD00DDDDDD00DDDD
      DD00DDDDDD00DDDDDD00A6A6A600BFBFBF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000BFBFBF00BFBFBF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00BFBFBF00BFBFBF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000BFBFBF00BFBFBF00FFFFFF008E8E
      8E00F2F2F200FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FEFE
      FE0084848400FAFAFA00BFBFBF00BFBFBF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000747474007575750000000000000000000000
      000000000000000000000000000000000000BFBFBF00BFBFBF00FFFFFF00ECEC
      EC006B6B6B00F2F2F200B6B6B600F9F9F900FFFFFF00B0B0B000FEFEFE007B7B
      7B00D1D1D100FFFFFF00BFBFBF00BFBFBF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000555555005555550000000000000000000000
      000000000000000000000000000000000000BFBFBF00BFBFBF00FFFFFF00FFFF
      FF00EEEEEE006E6E6E007D7D7D00F4F4F400FFFFFF007F7F7F007B7B7B00CCCC
      CC00FFFFFF00FFFFFF00BFBFBF00BFBFBF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000555555005555550000000000000000000000
      000000000000000000000000000000000000BFBFBF00BFBFBF00FFFFFF00FFFF
      FF00BDBDBD00868686000C0C0C00F5F5F500FFFFFF00323232006B6B6B00A8A8
      A800FFFFFF00FFFFFF00BFBFBF00BFBFBF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000545454005454540054545400545454005454540054545400545454005454
      5400000000000000000000000000000000000000000000000000000000000000
      00007575750055555500555555001C1C1C001C1C1C0055555500555555007575
      750000000000000000000000000000000000BFBFBF00BFBFBF00FFFFFF00FFFF
      FF00F6F6F600EEEEEE00EFEFEF00FFFFFF00FFFFFF00F3F3F300EEEEEE00F2F2
      F200FFFFFF00FFFFFF00BFBFBF00BFBFBF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000545454005454540054545400545454005454540054545400545454005454
      5400000000000000000000000000000000000000000000000000000000000000
      00007474740055555500555555001C1C1C001C1C1C0055555500555555007575
      750000000000000000000000000000000000BFBFBF00BFBFBF00FFFFFF00FFFF
      FF00F2F2F200EEEEEE00F3F3F300FFFFFF00FFFFFF00EFEFEF00EEEEEE00F6F6
      F600FFFFFF00FFFFFF00BFBFBF00BFBFBF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000555555005555550000000000000000000000
      000000000000000000000000000000000000BFBFBF00BFBFBF00FFFFFF00FFFF
      FF00A7A7A7006B6B6B0032323200FFFFFF00F5F5F5000C0C0C0086868600BDBD
      BD00FFFFFF00FFFFFF00BFBFBF00BFBFBF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000555555005555550000000000000000000000
      000000000000000000000000000000000000BFBFBF00BFBFBF00FFFFFF00FFFF
      FF00D6D6D6007B7B7B007E7E7E00FFFFFF00F4F4F400808080006F6F6F00EBEB
      EB00FFFFFF00FFFFFF00BFBFBF00BFBFBF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000747474007474740000000000000000000000
      000000000000000000000000000000000000BFBFBF00BFBFBF00FFFFFF00D1D1
      D1007A7A7A00FEFEFE00B0B0B000FFFFFF00F9F9F900B6B6B600F2F2F2006B6B
      6B00ECECEC00FFFFFF00BFBFBF00BFBFBF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000BFBFBF00BFBFBF00F9F9F9008383
      8300FEFEFE00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00F2F2
      F20089898900FFFFFF00BFBFBF00BFBFBF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000BFBFBF00BFBFBF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00BFBFBF00BFBFBF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000BFBFBF00A6A6A600DDDDDD00DDDD
      DD00DDDDDD00DDDDDD00DDDDDD00DDDDDD00DDDDDD00DDDDDD00DDDDDD00DDDD
      DD00DDDDDD00DDDDDD00A6A6A600BFBFBF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000AAAAAA00AAAAAA00AAAA
      AA00AAAAAA00AAAAAA00AAAAAA00AAAAAA00AAAAAA00AAAAAA00AAAAAA00AAAA
      AA00AAAAAA00AAAAAA00AAAAAA00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000424D3E000000000000003E000000
      2800000040000000100000000100010000000000800000000000000000000000
      000000000000000000000000FFFFFF00FFFFFFFF80010000FFFFFFFF00000000
      FFFFFFFF00000000FFFFFFFF00000000FFFFFE7F00000000FFFFFE7F00000000
      FFFFFE7F00000000F00FF00F00000000F00FF00F00000000FFFFFE7F00000000
      FFFFFE7F00000000FFFFFE7F00000000FFFFFFFF00000000FFFFFFFF00000000
      FFFFFFFF00000000FFFFFFFF8001000000000000000000000000000000000000
      000000000000}
  end
  object SavePictureDialog1: TSaveDialog
    DefaultExt = 'bmp'
    Filter = 'Bitmap (*.bmp)|*.bmp'
    Left = 1304
    Top = 688
  end
end

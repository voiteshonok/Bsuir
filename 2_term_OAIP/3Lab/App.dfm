object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Trains'
  ClientHeight = 401
  ClientWidth = 629
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 23
    Top = 139
    Width = 67
    Height = 16
    Caption = 'destination:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 23
    Top = 177
    Width = 74
    Height = 16
    Caption = 'day of week:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 23
    Top = 223
    Width = 19
    Height = 16
    Caption = 'hh:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 23
    Top = 261
    Width = 27
    Height = 16
    Caption = 'mm:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label5: TLabel
    Left = 23
    Top = 301
    Width = 35
    Height = 16
    Caption = 'seats:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label6: TLabel
    Left = 32
    Top = 83
    Width = 15
    Height = 16
    Caption = 'id:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object ComboBox1: TComboBox
    Left = 48
    Top = 40
    Width = 217
    Height = 21
    TabOrder = 0
    Text = 'Choose an option'
    OnChange = ComboBox1Change
  end
  object Memo1: TMemo
    Left = 355
    Top = 64
    Width = 233
    Height = 257
    Enabled = False
    Lines.Strings = (
      'Memo1')
    TabOrder = 1
  end
  object ListBox1: TListBox
    Left = 323
    Top = 8
    Width = 286
    Height = 37
    ItemHeight = 13
    TabOrder = 2
  end
  object IdEdit: TEdit
    Left = 64
    Top = 82
    Width = 81
    Height = 21
    TabOrder = 3
  end
  object DestinationEdit: TEdit
    Left = 96
    Top = 138
    Width = 111
    Height = 21
    TabOrder = 4
  end
  object DayEdit: TEdit
    Left = 103
    Top = 176
    Width = 104
    Height = 21
    TabOrder = 5
  end
  object HHEdit: TEdit
    Left = 64
    Top = 222
    Width = 64
    Height = 21
    TabOrder = 6
  end
  object MMEdit: TEdit
    Left = 64
    Top = 262
    Width = 64
    Height = 21
    TabOrder = 7
  end
  object SeatsEdit: TEdit
    Left = 64
    Top = 300
    Width = 81
    Height = 21
    TabOrder = 8
  end
  object OK: TButton
    Left = 167
    Top = 347
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 9
    OnClick = OKClick
  end
  object Show: TButton
    Left = 409
    Top = 347
    Width = 75
    Height = 25
    Caption = 'Show'
    TabOrder = 10
    OnClick = ShowClick
  end
end

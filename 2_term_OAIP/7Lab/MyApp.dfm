object App: TApp
  Left = 0
  Top = 0
  Caption = 'App'
  ClientHeight = 372
  ClientWidth = 699
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
  object Label: TLabel
    Left = 438
    Top = 24
    Width = 31
    Height = 16
    Caption = 'Size:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Memo: TMemo
    Left = 8
    Top = 0
    Width = 321
    Height = 329
    Enabled = False
    Lines.Strings = (
      'Memo')
    TabOrder = 0
  end
  object EditSize: TEdit
    Left = 475
    Top = 23
    Width = 121
    Height = 21
    TabOrder = 1
  end
  object ButtonRandom: TButton
    Left = 475
    Top = 50
    Width = 98
    Height = 41
    Caption = 'Random Table'
    TabOrder = 2
    OnClick = ButtonRandomClick
  end
  object ButtonFind: TButton
    Left = 375
    Top = 160
    Width = 98
    Height = 41
    Caption = 'Find'
    TabOrder = 3
    OnClick = ButtonFindClick
  end
  object ButtonDelete: TButton
    Left = 479
    Top = 160
    Width = 98
    Height = 41
    Caption = 'Delete'
    TabOrder = 4
    OnClick = ButtonDeleteClick
  end
  object ButtonFindMin: TButton
    Left = 583
    Top = 160
    Width = 98
    Height = 41
    Caption = 'Find Min'
    TabOrder = 5
    OnClick = ButtonFindMinClick
  end
  object EditFindOrDelete: TEdit
    Left = 469
    Top = 119
    Width = 121
    Height = 21
    TabOrder = 6
    Text = 'To find/delete'
  end
end

object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'App'
  ClientHeight = 479
  ClientWidth = 701
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
  object LabelPrint: TLabel
    Left = 144
    Top = 264
    Width = 37
    Height = 18
    Caption = 'Print'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object TreeView: TTreeView
    Left = 8
    Top = 8
    Width = 303
    Height = 249
    Indent = 19
    TabOrder = 0
  end
  object StringGrid: TStringGrid
    Left = 336
    Top = 8
    Width = 201
    Height = 457
    ColCount = 2
    FixedCols = 0
    RowCount = 2
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 1
    ColWidths = (
      89
      82)
  end
  object ButtonPreOrder: TButton
    Left = 8
    Top = 288
    Width = 97
    Height = 33
    Caption = 'PreOrder'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = ButtonPreOrderClick
  end
  object ButtonSimmetric: TButton
    Left = 111
    Top = 288
    Width = 97
    Height = 33
    Caption = 'Simmetric'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = ButtonSimmetricClick
  end
  object ButtonPostOrder: TButton
    Left = 214
    Top = 288
    Width = 97
    Height = 33
    Caption = 'PostOrder'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = ButtonPostOrderClick
  end
  object Memo: TMemo
    Left = 8
    Top = 327
    Width = 303
    Height = 144
    Lines.Strings = (
      'Memo1')
    TabOrder = 5
  end
  object ButtonNewRow: TButton
    Left = 560
    Top = 8
    Width = 121
    Height = 41
    Caption = 'New Row'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
    OnClick = ButtonNewRowClick
  end
  object ButtonCarry: TButton
    Left = 560
    Top = 64
    Width = 121
    Height = 41
    Caption = 'Carry over'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 7
    OnClick = ButtonCarryClick
  end
  object EditAddKey: TEdit
    Left = 560
    Top = 167
    Width = 121
    Height = 21
    TabOrder = 8
    Text = 'Key'
  end
  object EditAddName: TEdit
    Left = 560
    Top = 194
    Width = 121
    Height = 21
    TabOrder = 9
    Text = 'Name'
  end
  object ButtonAdd: TButton
    Left = 560
    Top = 120
    Width = 121
    Height = 41
    Caption = 'Add'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 10
    OnClick = ButtonAddClick
  end
  object ButtonFindDeep: TButton
    Left = 560
    Top = 232
    Width = 121
    Height = 41
    Caption = 'Find max deep'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 11
    OnClick = ButtonFindDeepClick
  end
  object ButtonBalance: TButton
    Left = 560
    Top = 317
    Width = 121
    Height = 41
    Caption = 'Balance'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 12
    OnClick = ButtonBalanceClick
  end
  object EditFindOrDelete: TEdit
    Left = 560
    Top = 372
    Width = 121
    Height = 21
    TabOrder = 13
    Text = 'to find/delete by key'
  end
  object ButtonFind: TButton
    Left = 560
    Top = 399
    Width = 65
    Height = 41
    Caption = 'Find'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 14
    OnClick = ButtonFindClick
  end
  object ButtonDelete: TButton
    Left = 628
    Top = 399
    Width = 65
    Height = 41
    Caption = 'Delete'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 15
    OnClick = ButtonDeleteClick
  end
  object EditDeep: TEdit
    Left = 560
    Top = 290
    Width = 121
    Height = 21
    Enabled = False
    TabOrder = 16
  end
end

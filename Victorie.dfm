object fVictorie: TfVictorie
  Left = 0
  Top = 0
  Caption = 'Ecran Victorie'
  ClientHeight = 90
  ClientWidth = 255
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
  object tVictorie: TLabel
    AlignWithMargins = True
    Left = 0
    Top = 0
    Width = 257
    Height = 65
    Alignment = taCenter
    AutoSize = False
    Caption = 'tVictorie'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    Layout = tlCenter
    WordWrap = True
  end
  object Button1: TButton
    Left = 96
    Top = 57
    Width = 75
    Height = 25
    Caption = 'Ok'
    TabOrder = 0
    OnClick = Button1Click
  end
end

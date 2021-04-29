//---------------------------------------------------------------------------

#include <vcl.h>

#pragma hdrstop

#include "MyMap.h"
#include "MyApp.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TApp *App;
MyMap *map = NULL;

//---------------------------------------------------------------------------
__fastcall TApp::TApp(TComponent *Owner)
        : TForm(Owner) {
    Memo->Clear();
    //Memo->Lines->Add("asd");
    //ShowMessage("FATAL: Wrong hash table size");
}

//---------------------------------------------------------------------------
void __fastcall TApp::FormClose(TObject *Sender, TCloseAction &Action) {
    delete map;
}

//---------------------------------------------------------------------------
void __fastcall TApp::ButtonRandomClick(TObject *Sender) {
    try {
        delete map;
        map = new MyMap(StrToInt(EditSize->Text));
        map->random();
        Memo->Clear();
        map->print(Memo);
    } catch (...) {
        ShowMessage("Invalid input");
    }
}
//---------------------------------------------------------------------------


void __fastcall TApp::ButtonDeleteClick(TObject *Sender) {
    try {
        map->deleteNode(StrToInt(EditFindOrDelete->Text));
        Memo->Clear();
        map->print(Memo);
    } catch (...) {}
}
//---------------------------------------------------------------------------

void __fastcall TApp::ButtonFindMinClick(TObject *Sender) {
    try {
        ShowMessage(map->getMin());
    } catch (...) {
        ShowMessage("No elements");
    }
}
//---------------------------------------------------------------------------

void __fastcall TApp::ButtonFindClick(TObject *Sender) {
    try {
        if (map->findNode(StrToInt(EditFindOrDelete->Text))) {
            ShowMessage("Contains");
        } else {
            ShowMessage("Doesn't contain");
        }
    } catch (...) {}
}
//---------------------------------------------------------------------------


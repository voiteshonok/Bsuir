//---------------------------------------------------------------------------

#include <vcl.h>

#pragma hdrstop

#include "MyApp.h"
#include "Tree.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
node *tree = NULL;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent *Owner)
        : TForm(Owner) {
    Memo->Clear();
    StringGrid->Cells[0][0] = "PassportInt";
    StringGrid->Cells[1][0] = "Name";
}

void makeClear(TMemo *mem, TTreeView *view) {
    mem->Clear();
    view->Items->Clear();
}

void print(node *tree, int kl, TTreeView *view) {
    if (!tree) return;
    if (kl == -1) {
        view->Items->AddFirst(NULL, tree->key);
    } else
        view->Items->AddChildFirst(view->Items->Item[kl], tree->key);
    kl++;
    print(tree->left, kl, view);
    print(tree->right, kl, view);
}

//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action) {
    tree->deleteTree(tree);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonPreOrderClick(TObject *Sender) {
    Memo->Clear();
    tree->preOrderPrint(tree, Memo);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonSimmetricClick(TObject *Sender) {
    Memo->Clear();
    tree->simmetricPrint(tree, Memo);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonPostOrderClick(TObject *Sender) {
    Memo->Clear();
    tree->postOrderPrint(tree, Memo);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonFindClick(TObject *Sender) {
    try {
        tree->findNode(tree, EditFindOrDelete);
    } catch (...) {}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonDeleteClick(TObject *Sender) {
    try {
        tree->deleteNode(&tree, StrToInt(EditFindOrDelete->Text));
        TreeView->Items->Clear();
        print(tree, -1, TreeView);
    } catch (...) {}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonBalanceClick(TObject *Sender) {
    tree->balance(&tree);
    TreeView->Items->Clear();
    print(tree, -1, TreeView);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonFindDeepClick(TObject *Sender) {
    EditDeep->Text = tree->getDeep(tree);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonAddClick(TObject *Sender) {
    try {
        tree->add(&tree, StrToInt(EditAddKey->Text), EditAddKey->Text);
        makeClear(Memo, TreeView);
        print(tree, -1, TreeView);
    } catch (...) {}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonCarryClick(TObject *Sender) {
    for (int i = 1; i < StringGrid->RowCount; i++) {
        StringGrid->Cells[0][i] = StringGrid->Cells[0][i].Trim();
        try {
            tree->add(&tree, StrToInt(StringGrid->Cells[0][i]), StringGrid->Cells[0][i].Trim());
        }
        catch (...) {
            return;
        }
    }
    makeClear(Memo, TreeView);
    print(tree, -1, TreeView);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonNewRowClick(TObject *Sender) {
    StringGrid->RowCount++;
}
//---------------------------------------------------------------------------



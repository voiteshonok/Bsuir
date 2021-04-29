//---------------------------------------------------------------------------

#pragma hdrstop

#include <vcl.h>
#include "Stack.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void Stack::deleteNode(int t) {
    Node *temp = beginList;
    if (beginList->value == t) {
        beginList = beginList->next;
        delete temp;
        return;
    }
    while (temp->next && temp->next->value != t) {
        temp = temp->next;
    }
    if (temp->next) {
        Node *tmp = temp->next;
        temp->next = temp->next->next;
        delete tmp;
    }
}

bool Stack::findNode(int t) {
    Node *temp = beginList;
    while (temp && t != temp->value) {
        temp = temp->next;
    }
    return temp;
}

AnsiString Stack::print() {
    Node *temp = beginList;
    AnsiString str = "";
    while (temp) {
        //std::cout << temp->value << " ";
        //mem->Lines->Add(IntToStr(temp->value)+ " ");
        str += IntToStr(temp->value) + " ";
        temp = temp->next;
    }
    return str;
}

void Stack::add(int t) {
    Node *temp = new Node;
    temp->value = t;
    temp->next = beginList;
    beginList = temp;
}

Stack::Stack() {
    beginList = nullptr;
}

Stack::~Stack() {
    while (beginList) {
        Node *temp = beginList;
        beginList = beginList->next;
        delete temp;
    }
}

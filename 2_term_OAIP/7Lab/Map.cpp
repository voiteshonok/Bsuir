//---------------------------------------------------------------------------

#pragma hdrstop

#include "Map.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Map::Map(int t) : n(t) {
    if (n < 0) {
        throw "InvalidSizeExepion";
    }
    arr = new Stack *[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = new Stack;
    }
}

Map::~Map() {
    for (int i = 0; i < n; ++i) {
        delete arr[i];
    }
    delete arr;
}

void Map::add(int t) {
    arr[t % n]->add(t);
}

void Map::print(TMemo *mem) {
    for (int i = 0; i < n; ++i) {
        //std::cout << i << ": ";
        mem->Lines->Add(IntToStr(i) + ": " + arr[i]->print());
        //arr[i]->print(mem);
        //std::cout << "\n";
        //mem->Lines->Add("\n");
    }
}

void Map::deleteNode(int t) {
    arr[t % n]->deleteNode(t);
}

bool Map::findNode(int t) {
    return arr[t % n]->findNode(t);
}
//---------------------------------------------------------------------------

#pragma hdrstop

#include "MyMap.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

MyMap::MyMap(int t) : Map(t) {}

void MyMap::random() {
    for (int i = 0; i < n; ++i) {
        delete arr[i];
    }
    delete arr;
    arr = new Stack *[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = new Stack;
    }
    for (int j = 0; j < 5 * n; ++j) {
        int tmp = 1 + rand() % (5 * n);
        arr[tmp % n]->add(tmp);
    }
}

int MyMap::min(int a, int b) {
    return (a > b ? b : a);
}

int MyMap::getMin() {
    if (!arr[0]) {
        throw "NoElementsExeption";
    }
    int m = arr[0]->beginList->value;
    for (int i = 0; i < n; ++i) {
        Node *tmp = arr[i]->beginList;
        while (tmp) {
            m = min(m, tmp->value);
            tmp = tmp->next;
        }
    }
    return m;
}

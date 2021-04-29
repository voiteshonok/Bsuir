//---------------------------------------------------------------------------
#include "Stack.h"

#ifndef MapH
#define MapH

//---------------------------------------------------------------------------
class Map {
public:
    int n;
    Stack **arr;

    Map(int t);

    ~Map();

    void add(int t);

    void print(TMemo *mem);

    void deleteNode(int t);

    bool findNode(int t);

};

#endif

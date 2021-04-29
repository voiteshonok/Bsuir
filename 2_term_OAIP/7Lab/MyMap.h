//---------------------------------------------------------------------------
#include "Map.h"
#include <iostream>

#ifndef MyMapH
#define MyMapH

//---------------------------------------------------------------------------
class MyMap : public Map {
public:
    MyMap(int t);

    void random();

    int getMin();

private:
    static int min(int a, int b);
};

#endif

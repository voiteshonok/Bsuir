//---------------------------------------------------------------------------

#ifndef StackH
#define StackH

//---------------------------------------------------------------------------
class Node {
public:
    int value;
    Node *next;
};

class Stack {
public:
    Node *beginList;

    Stack();

    ~Stack();

    void add(int t);

    AnsiString print();

    void deleteNode(int t);

    bool findNode(int t);
};

#endif

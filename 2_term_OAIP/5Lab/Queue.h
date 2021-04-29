//---------------------------------------------------------------------------

#ifndef QueueH
#define QueueH
//---------------------------------------------------------------------------
#endif
class Node
{
	public:
  int data;
  Node *next;
  Node *prev;

  Node();
  ~Node();
};

class Queue
{
   public:
   Node *head;
   Node *tail;

   Queue();
   ~Queue();

   void pop();

   void push(int x);



};

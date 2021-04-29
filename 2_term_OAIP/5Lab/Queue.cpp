//---------------------------------------------------------------------------

#pragma hdrstop

#include "Queue.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
Node::Node(){
	next=nullptr;
	prev=nullptr;
}
Node::~Node(){}

Queue::Queue(){
	head=nullptr;
	tail=nullptr;
}

Queue::~Queue()
{
	while(head!=NULL)
	{
	 Node *tmp=head;
	 head=head->prev;
	 delete tmp;
	}

}

void Queue::pop()
{
	Node *tmp=head;
	if(head==tail)
	{
	   head=NULL;
	   tail=NULL;
	}else
	{
		head->prev->next=NULL;
		head=head->prev;
	}
	delete tmp;
}

void Queue::push(int x)
{
	Node *tmp = new Node;
	tmp->data=x;
	if(tail==NULL)
	{
		tail=tmp;
        head=tmp;
	}else
	{
		tail->prev=tmp;
		tmp->next=tail;
		tail=tmp;
    }

}

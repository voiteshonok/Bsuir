//---------------------------------------------------------------------------

#pragma hdrstop

#include "List.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
Node::Node(){
	next=nullptr;
}

Node::~Node(){}

void Node::setDay(String s)
{
	String arr[7]={"monday","tuesday","wednesday","thursday","friday","saturday","sunday"};
	for(int i=0;i<7;i++)
	{
		if(s==arr[i])
		{
			day=s;
			return;
        }
	}
	throw String("Invalid name of day");
}

String Node::getDay()
{
	return day;
}

void Node::setDestination(String s)
{
	destination=s;
}

String Node::getDestination()
{
	 return destination;
}

void Node::setHH(int h)
{
	if(h<24 && h>=0)
	{
		hh=h;
		return;
	}
	throw String("Invalid hours");
}

int Node::getHH()
{
	return hh;
}

void Node::setMM(int m)
{
	if(m<60 && m>=0)
	{
		mm=m;
		return;
	}
	throw String("Invalid minutes");
}
int Node::getMM()
{
	return mm;
}

void Node::setSeats(int s)
{
	if(s>=0)
	{
		seats=s;
		return;
	}
	throw String("Seats are less than 0");
}

int Node::getSeats()
{
	return seats;
}

void Node::setId(int d)
{
	id=d;
}

int Node::getId()
{
    return id;
}

List::List()
{
    head=NULL;
}

 List::~List()
 {
	while(head!=NULL)
	{
	 Node *tmp=head;
	 head=head->next;
	 delete tmp;
	}

 }

 void List::Push(Node *tmp)
 {
	tmp->next=head;
	head=tmp;
 }


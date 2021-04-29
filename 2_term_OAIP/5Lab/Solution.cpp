//---------------------------------------------------------------------------

#pragma hdrstop

#include "Solution.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
void Solution::swap(Node *i,Node *j)
{
	 i->next=j->next;
	 j->next=i;
	 if(i->next!=NULL)
	 {
		 i->next->prev=i;
	 }else
	 {
		 head=i;
	 }
	 j->prev=i->prev;
	 i->prev=j;
	 if(j->prev!=NULL)
	 {
		j->prev->next=j;
	 }else
	 {
		 tail=j;
	 }
}

 void Solution::sort()
{
	for(Node *i=head;i!=NULL;i=i->prev)
	{
		for(Node *j=head;j!=tail;j=j->prev)
		{
			if(j->prev->data<j->data)
			{
				swap(j->prev,j);
				j=j->next;
			}
		}
	}
}

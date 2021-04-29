//---------------------------------------------------------------------------

#ifndef SolutionH
#define SolutionH
#include "Queue.h"
//---------------------------------------------------------------------------
 class Solution  : public Queue
 {
    void swap(Node *i,Node *j);
	public:
    void sort();
 };
#endif


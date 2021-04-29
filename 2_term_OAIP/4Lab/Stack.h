//---------------------------------------------------------------------------

#ifndef StackH
#define StackH
//---------------------------------------------------------------------------
template <class T>
class Node {
public:
	T value;
	Node<T> *next;
};

template <class T>
class Stack {
public:
	Node<T> *beginList;

	Stack();

	~Stack();

	void add(T t);

	void pop();

	T top();

    bool notEmpty();
};

template <class T>
void Stack<T>::add(T t) {
	Node<T> *temp = new Node<T>;
	temp->value = t;
	temp->next = beginList;
	beginList = temp;
}

template <class T>
void Stack<T>::pop() {
	Node<T> *temp = beginList;
	beginList = beginList->next;
	delete temp;
}

template <class T>
T Stack<T>::top() {
	return beginList->value;
}

template <class T>
bool Stack<T>::notEmpty() {
	if(beginList == nullptr){
	   return 0;
   }else{
	   return 1;
   }
}

template <class T>
Stack<T>::Stack() {
	beginList = nullptr;
}

template <class T>
Stack<T>::~Stack() {
	while (beginList) {
		Node<T> *temp = beginList;
		beginList = beginList->next;
		delete temp;
	}
}
#endif

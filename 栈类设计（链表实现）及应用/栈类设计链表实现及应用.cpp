#include"stdafx.h"
#include<iostream>  
using namespace std;
struct node
{
	int data;
	node *next;
};

class stack{

public:
	node *ttop;
	stack (): ttop(NULL) {};                           
	~stack();                       
	void push(int x);                    
	int pop();                       
	bool empty(); 
	int top();

};
int stack::top(){
	return ttop->data;
}
stack::~stack() {
	node *p;
	while (ttop!=NULL) {
		p = ttop;
		ttop = ttop->next;
		delete p;
	}
}

void stack::push(int t)
{
	node *n = new node;
	n->data = t;
	n->next = ttop;
	ttop = n;
}
int stack::pop()
{
	node *p;
	int x;
	x = ttop->data;
	p = ttop;
	ttop = p->next;
	delete p;
	return x;
}
bool stack::empty() {
	if (ttop == NULL)return 1;
	else return 0;
}

int main()
{
	stack s1;
	stack s2;
	int i, x;
	while (cin >> i >> x) {
		if (i == 1) {
			s1.push(x);
		}
		else if (i == 2) {
			s2.push(x);
		}
	}
		while (!s1.empty()) {
			cout << s1.pop()<<" ";
	}
		cout << endl;
		while (!s2.empty()) {
			cout << s2.pop()<<" ";
		}
		cout << endl;
	return 0;
}
#include<iostream>
#include<string>
using namespace std;
template<class T>
class Queue {
private:
	struct Node {
		T data;
		Node *next;
	};
	Node *front;
	int size;
public:
	Queue() :size(0) {
		front = new Node;
		front->next = NULL;
	
	}
	//¿½±´¹¹Ôì
	Queue(const Queue &rhs) :size(rhs.size) {
		front = new Node;
		front->data = rhs.front->data;
		front->next = NULL;
		Node *p = rhs.front;
		Node *q = front;
		while (p->next) {
			p = p->next;
			q->next = new Node;
			q = q->next;
			q->data = p->data;
		}
	}
	~Queue() {
		if (front) {
			Node *p = front;
			while (p) {
				Node *q = p;
				p = p->next;
				delete q;
			}
			front = NULL;
		}
	}
	T DeQueue() {		
			T tmp = front->data;
			Node *p = front->next;
			delete front;
			front = p;
			size--;
			if (size == 0) {
				front = new Node;
				front->next = NULL;
			}
			return tmp;
		
	}
	void EnQueue(T rhs) {
		Node *q = new Node;
		q->data = rhs;
		q->next = NULL;
		Node *p = front;
		if (size==0) {
			front->data = rhs;
			size++;
			return;
		}
		if (size == 1) {
			if (rhs > front->data) {
				front->next = q;
			}
			else {
				q->next = front;
				front = q;
			}
			size++;
			return;
		}
		while ((p )&& (p->next )&&(rhs>p->next->data))
		{
			p = p->next;
		}
		if (p == front) {
			if (rhs > front->data) {
				q->next = front->next;
				front->next = q;
			}
			else {
				q->next = front;
				front = q;
			}
			size++;
			return;
		}
		q->next = p->next;
		p->next = q;
		size++;

	}
	bool IsEmpty() {
		if (size == 0) return true;
		else return false;
	}
	/*Queue(Queue &&rhs) {
	front = rhs.front;
	rhs.front = NULL;
	size = rhs.size;
	}*/
};
template <class T>
void Order(T &Order) {
	int n, i;
	string cmd;
	Queue<T> Q[3];
	T x;
	cin >> n;
	for (int j = 0; j<n; j++) {
		cin >> cmd;
		if (cmd == "E") {
			cin >> i >> x;
			Q[i].EnQueue(x);
		}
		else if (cmd == "D") {
			cin >> i;
			x = Q[i].DeQueue();
			cout << x << ' ';
		}
		else if (cmd == "A") {
			cin >> i; 
			while (!Q[i].IsEmpty()) {
				x = Q[i].DeQueue();
				cout << x << ' ';
			}
		}
	}
	cout << endl;
}
int main()
{
	string order;
	int n;
	while (cin >> order) {
		if (order == "int")
			Order<int>(n);
		if (order == "string")
			Order<string>(order);
	}
	return 0;
}

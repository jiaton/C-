#include<iostream>
#include<string>
using namespace std;
template<class T>
class Queue {
private:
	struct Node{
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
	//��������
	Queue(const Queue &rhs) :size(rhs.size) {
		front = new Node;
		front->data = rhs.front->data;
		front -> next = NULL;
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
		front = q;
		size--;
		return tmp;
	}
	void EnQueue(T rhs) {
		Node *q = new Node;
		q->data = rhs;
		Node *p = head;
		while (p->next&&rhs > p->next->data)
		{
			p = p->next;
		}
		q->next = p->next;
		p->next = q;
		size++;

	}
	bool IsEmpty() {
		return(head == NULL);
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
			cin >> i; i--;
			x = v[i].front();
			v[i].pop();
			cout << x << ' ';
		}
		else if (cmd == "A") {
			cin >> i; i--;
			while (!v[i].empty()) {
				x = v[i].front();
				v[i].pop();
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
			Order(n);
		if (order == "string")
			Order(order);
	}
	return 0;
}

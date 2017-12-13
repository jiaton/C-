#include<iostream>
#include<string>
using namespace std;
template<class elemtype>
class p_queue {
	struct Node {
		elemtype data;
		Node *next;
	};
private:
	Node *head;
	int length;
public:
	p_queue() :length(0) {
		head = new Node;
		head->next = NULL;
	}
	p_queue(const p_queue &rsh) :length(rsh.length) {
		head = new Node;
		head->next = NULL;
		Node *last = head;
		Node *p = rsh.head->next;
		while (p) {
			Node *q = new Node;
			q->data = p->data;
			last->next = q;
			last = q;
			p = p->next;
		}
	}
	~p_queue() {
		while (head) {
			Node *p = head->next;
			delete head;
			head = p;
		}
	}
	void pop() {
		Node *q = head->next;
		delete head;
		head = q;
		length--;
	}
	bool push(elemtype x) {
		Node *q = new Node;
		q->data = x;
		Node *p = head;
		while (p->next&&x>p->next->data)
			p = p->next;
		q->next = p->next;
		p->next = q;
		length++;
		return true;
	}
	elemtype front() {
		return head->next->data;
	}
	bool empty() const {
		return(head->next == NULL);
	}
	/*	p_queue (p_queue &&rsh){
	head=rsh.head;
	rsh.head=NULL;
	length=rsh.length;
	}
	*/
	/* p_queue &operator =(const p_queue &rsh){
	if(this==&rsh)//特殊处理
	return *this;
	delete [] head;

	length=rsh.length;
	head = new Node ;
	head=rsh.head;
	return *this;
	}*/
	/* p_queue &operator =(const  &&rsh){  移动赋值运算符重载
	char *t = head;
	head=rsh.head;
	rsh.head=t;
	length=rsh.length;
	return *this;
	}
	*/
};
template <typename elemtype>
void Order(elemtype &Order) {
	int n, i;
	string cmd;
	p_queue<elemtype> v[2];
	elemtype x;
	cin >> n;
	for (int j = 0; j<n; j++) {
		cin >> cmd;
		if (cmd == "E") {
			cin >> i >> x; i--;
			v[i].push(x);
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
//int main()
//{
//	string order;
//	int n;
//	while (cin >> order) {
//		if (order == "int")
//			Order(n);
//		if (order == "string")
//			Order(order);
//	}
//	return 0;
//}

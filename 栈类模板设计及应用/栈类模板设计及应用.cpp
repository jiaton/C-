#include<iostream>
#include<string>
using namespace std;
template <class T>
class stack {
private:
	struct Node
	{
		T data;
		Node* next;
	};
public:
	Node* top;
	stack() {
		top = NULL;
		
	}
	void push(T &rhs) {
		Node *p = new Node;
		p->data = rhs;
		p->next = top;
		top = p;
	}
	T pop() {
		if (top == NULL) return NULL;
		T tmp = top->data;
		top = top->next;
		return tmp;
	}
};
int main() {
	int n, v, x1;
	string order;
	string x2;
	while (cin >> order) {
		if (order == "int") {
			cin >> n;
			stack<int> s[3];
			while (n--)
			{
				cin >> v >> x1;
				s[v].push(x1);
			}
			while (s[1].top) {
				cout << s[1].pop()<<" ";
			}
			cout << endl;
			while (s[2].top) {
				cout << s[2].pop() << " ";
			}
			cout << endl;
		}
		else if (order == "string") {
			cin >> n;
			stack<string> s[3];
			while (n--) {
				cin >> v >> x2;
				s[v].push(x2);
			}
			while (s[1].top) {
				cout << s[1].pop() << " ";
			}
			cout << endl;
			while (s[2].top) {
				cout << s[2].pop() << " ";
			}
			cout << endl;
		}
	}
}
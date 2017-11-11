#include<iostream>
using namespace std;
class Set {
private:
	struct Node {
		int data;
		Node* next;
	}p;
public:
	Node* head;
	Set() {
		head = new Node;
		head->next = NULL;
		//head->data = -INFINITY;
	}
	Set(const Set &s1);
	Set &operator =(const Set &s1);
	void Add(int e);
	void Insert(int e, Node* p);
	void Delete(int e);//删除元素e
	bool Refer(int e) const;
	Set Bing(const Set &s1, const Set &s2);
	Set Jiao(const Set &s1, const Set &s2);
	Set Cha(const Set &s1, const Set &s2);
	void Display();
};

Set::Set(const Set &s1) {
	head = new Node;
	head->next = NULL;
	Node *p = s1.head->next;
	while (p) {
		this->Add(p->data);
		p = p->next;
	}
}
Set & Set::operator=(const Set &s1) {
	head = new Node;
	head->next = NULL;
	Node *p = s1.head;
	while (p) {
		this->Add(p->data);
		p = p->next;
	}
	return *this;
}
void Set::Insert(int e, Node* p) {//把e插入到p后面
	Node *t = new Node;
	t->data = e;
	t->next = p->next;
	p->next = t;
}
void Set::Add(int e) {
	if (Refer(e) == true)return;//如果存在则返回
	Node *p = head;
	while (p->next&&p->next->data<e) {
		p = p->next;
	}
	Insert(e, p);//把e插入到p后面


}
void Set::Delete(int e) {
	Node *p = head;
	while (p->next) {
		if (p->next->data == e) {
			Node * q = p->next;
			p->next = q->next;
			delete(q);
		}
		p = p->next;
	}
}
bool Set::Refer(int e) const {
	Node *p = this->head->next;
	while (p) {
		if (p->data == e) { return true; } 
		p = p->next;
	}
	return false;
}
Set Set::Bing(const Set &s1, const Set &s2) {
	Set s3;
	Node *p;
	p = s1.head->next;
	while (p) {
		s3.Add(p->data);
		p = p->next;
	}
	p = s2.head->next;
	while (p) {
		s3.Add(p->data);
		p = p->next;
	}
	s3.Display();
	return s3;
}
Set Set::Jiao(const Set &s1, const Set &s2) {
	Set s3;
	Node *p;
	p = s1.head->next;
	while (p) {
		if (s2.Refer(p->data)) {
			s3.Add(p->data);
		}
		p = p->next;
	}
	s3.Display();
	return s3;
}
Set Set::Cha(const Set &s1, const Set &s2) {
	Set s3;
	Node *p;
	p = s1.head->next;
	while (p) {
		if (s2.Refer(p->data)==false) {
			s3.Add(p->data);
		}
		p = p->next;
	}
	s3.Display();
	return s3;
}
void Set::Display() {
	Node *p = head->next;
	cout << "{";
	while (p) {
		cout << p->data;
		if (p->next) cout << ",";
		p = p->next;
	}
	cout << "}" << endl;
}
int main() {
	int m, n, e;
	Set s1, s2, s3;
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		cin >> e;
		s1.Add(e);
	}
	for (int i = 0; i < n; i++) {
		cin >> e;
		s2.Add(e);
	}
	s1.Display();
	s2.Display();
	s3 = s3.Bing(s1, s2);
//	s3.Display();
	s3 = s3.Jiao(s1, s2);
//	s3.Display();
	s3 = s3.Cha(s1, s2);
//	s3.Display();

}
#include<iostream>
#include<cstring>
using namespace std;
class Node {
public:
	int id;
	Node *next;
};
class Circle {
private :
//	class Node;
	Node* head;//头指针
	Node* curp;//最后一个节点指针
public:
	Circle() :head(NULL), curp(NULL) {};//构造一个空序列
	Circle(int n){//构造一个初始号码为n的序列
		curp = new Node;
		head = curp;
		curp->id = n;
		curp->next = head;
	}
	Circle(Circle &rhs);//拷贝构造
	Circle& operator=(const Circle&rhs);//拷贝赋值
	void Add(int n);//在尾部添加一个号码为n的节点，当前序列不能为空
	Node* DeleteNext(Node *p);//删除p的下一个节点
	void AddNode(Node* p);//在尾部添加一个现有的节点
	friend Circle& Suicide(Circle rhs,int N);//start gaming 传入一个序列 和 密码
	void Display();//显示序列
};
Circle& Circle::operator=(const Circle &rhs) {
	Node*p = head;
	while (p) {
		Node*q = p;
		p = p->next;
		delete(q);
	}
	curp = head = new Node;
	head->id = rhs.head->id;
	p = head;
	Node* q = rhs.head->next;
	do {
		p->next = new Node;
		p->next->id = q->id;
		p = p->next;
		q = q->next;
		curp = p;
	} while (q&&q != rhs.head);
	curp->next = head;
	return *this;
}
Circle::Circle(Circle &rhs) {//拷贝构造
	curp= head = new Node;
	head->id = rhs.head->id;
	Node* p=head;
	Node* q = rhs.head->next;
	do {
		p->next = new Node;
		p->next->id = q->id;
		p = p->next;
		curp = p;
	} while (q&&q != rhs.head);
	curp->next = head;
}
void Circle::Display() {
	Node *p = head;
	do {
		cout << p->id;
		p = p->next;
	} while (p&&p != head);
}
void Circle::Add(int n) {
	curp->next = new Node;
	curp->next->id = n;
	curp->next->next = head;//新加的尾部节点指向开头
	curp = curp->next;
}
Node* DeleteNext(Node *p){//删除p的下一个节点
	Node* q = p->next;
	p->next = q->next;
	return q;//返回被删除的节点指针以便插入到新的序列
}
void Circle::AddNode(Node* p) {
	if (!head) {//如本身不存在节点则新建
		head = p;
		curp = p;
	
		p->next=head;
	}
	else{
		curp->next = p;
	
		p->next = head;
		curp = p;
	}
}
Node* Circle::DeleteNext(Node *p) {
	if (p->next == p) {//如果只剩一个节点
		head = NULL;
		curp = NULL;
		return p;
	}
	Node *q = p->next;
	p->next = q->next;
	return q;
}
Circle& Suicide(Circle rhs,int N) {
	Node* p = rhs.curp;//p指向最后一个节点便于删除下一个节点
	Circle tmp;
	while (p) {
		int j = 1;//出列的人的新序号
		for (int i = 1; i < N; i++) {
			p = p->next;
		}
		tmp.AddNode(rhs.DeleteNext(p));//将出列的节点删除并加入tmp序列
		j++;
	}
	return tmp;//返回新tmp序列
}

int main() {
	int M, N;
	while (cin >> M) {
		Circle c1(1);
		//Circle c2(1);
		for (int i = 2; i <= M; i++)
			c1.Add(i);
		while (cin >> N) {
			Circle c2(Suicide(c1, N));
		}
	}
}
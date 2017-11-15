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
	Node* head;//ͷָ��
	Node* curp;//���һ���ڵ�ָ��
public:
	Circle() :head(NULL), curp(NULL) {};//����һ��������
	Circle(int n){//����һ����ʼ����Ϊn������
		curp = new Node;
		head = curp;
		curp->id = n;
		curp->next = head;
	}
	Circle(Circle &rhs);//��������
	Circle& operator=(const Circle&rhs);//������ֵ
	void Add(int n);//��β�����һ������Ϊn�Ľڵ㣬��ǰ���в���Ϊ��
	Node* DeleteNext(Node *p);//ɾ��p����һ���ڵ�
	void AddNode(Node* p);//��β�����һ�����еĽڵ�
	friend Circle& Suicide(Circle rhs,int N);//start gaming ����һ������ �� ����
	void Display();//��ʾ����
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
Circle::Circle(Circle &rhs) {//��������
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
	curp->next->next = head;//�¼ӵ�β���ڵ�ָ��ͷ
	curp = curp->next;
}
Node* DeleteNext(Node *p){//ɾ��p����һ���ڵ�
	Node* q = p->next;
	p->next = q->next;
	return q;//���ر�ɾ���Ľڵ�ָ���Ա���뵽�µ�����
}
void Circle::AddNode(Node* p) {
	if (!head) {//�籾�����ڽڵ����½�
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
	if (p->next == p) {//���ֻʣһ���ڵ�
		head = NULL;
		curp = NULL;
		return p;
	}
	Node *q = p->next;
	p->next = q->next;
	return q;
}
Circle& Suicide(Circle rhs,int N) {
	Node* p = rhs.curp;//pָ�����һ���ڵ����ɾ����һ���ڵ�
	Circle tmp;
	while (p) {
		int j = 1;//���е��˵������
		for (int i = 1; i < N; i++) {
			p = p->next;
		}
		tmp.AddNode(rhs.DeleteNext(p));//�����еĽڵ�ɾ��������tmp����
		j++;
	}
	return tmp;//������tmp����
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
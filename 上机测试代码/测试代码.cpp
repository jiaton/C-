#include <iostream>
using	namespace std;

class	CStack {
	struct Node {
		int	data;
		Node *next;
	};
private:
	Node	*m_sp;

public:
	CStack() :m_sp(NULL) { //���캯��
	}
	~CStack();				 //��������
	void	push(int x);	 //��ջ
	bool	empty() const;  //��ջ��
	int		top() const;    //ȡջ��Ԫ��
	void	pop();			 //��ջ
};

CStack::~CStack()
{
	while (m_sp != NULL) {
		Node *p = m_sp;
		m_sp = m_sp->next;
		delete p;
	}
}

void	CStack::push(int x)
{
	Node *p = new Node;
	p->data = x;
	p->next=m_sp;
	m_sp = p;
}

bool	CStack::empty() const
{
	return (!m_sp);
}
int		CStack::top() const
{
	return m_sp->data;
}

void	CStack::pop()
{
	Node *p = m_sp;
	m_sp=m_sp->next;
	delete p;
}

int main()
{
	CStack	S1, S2;
	int	x;

	cin >> x;
	while (x != 0) {
		if (x > 0)
			S1.push(x);
		else
			S2.push(x);
		cin >> x;
	}

	while (!S1.empty()) {
		x = S1.top();
		cout << x << "\t";
		S1.pop();
	}
	cout << endl;

	while (!S2.empty()) {
		x = S2.top();
		cout << x << "\t";
		S2.pop();
	}
	cout << endl;

	return 0;
}
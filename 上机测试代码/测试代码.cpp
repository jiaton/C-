#include <iostream>
#include <string>
using	namespace	std;
class	CQueue {
	struct Node {
		int	data;
		Node *next;
	};//������ṹ
private:
	Node *m_pFront, *m_pRear;//�����׽���β���ָ��
public:
	CQueue();   //���й���
	CQueue(const	CQueue &rhs);//���п�������
	~CQueue();   //����������
	bool	push(int x); //X�����
	void	pop();  //������
	int		front();  //ȡ����Ԫ��
	bool	empty() const;   //�жӿ�
	int		GetLength() const; //ȡ���г���
};

CQueue::CQueue()
{
	this->m_pFront = this->m_pRear = new Node; //�����ͷ���򻯳����С�����в���
	this->m_pRear->next = NULL;
}
CQueue::CQueue(const	CQueue &rhs)  //���ƶ���
{
	this->m_pFront = this->m_pRear = new Node;
	this->m_pFront->next = NULL;
	Node *p = rhs.m_pFront->next;
	while (p) { //��ԭ����Ԫ�����������
		this->push(p->data);
		p = p->next;
	}
}

CQueue::~CQueue()
{
	while (m_pFront != NULL) {//�ͷ����������н��
		m_pRear = m_pFront;
		m_pFront = m_pFront->next;
		delete m_pRear;
	}
}

bool	CQueue::push(int x)//X�����
{
	Node *p = new Node;//������
	p->data = x;
	p->next = NULL;
	//���ڶ�β
	this->m_pRear->next = p;
	this->m_pRear = p;
	return true;
}

//���зǿ�
void	CQueue::pop()//������
{
	Node *p = m_pFront;
	this->m_pFront = p->next;//��һ����Ϊͷ���
	delete p;
}
//���зǿ�
int	CQueue::front()
{
	return this->m_pFront->next->data; //����Ԫ�ش����ͷ������һ���
}
bool	CQueue::empty() const
{
	return (this->m_pFront == this->m_pRear); //�Ƿ�ֻ��ͷ���
}

int		CQueue::GetLength() const
{
	int	count = 0;
	Node *p = this->m_pFront->next;//ͷ��㲻��
	while (p != NULL) {
		count++;
		p = p->next;
	}
	return count;
}


int	main()
{
	CQueue	Queue[2];

	int	x;

	cin >> x;
	while (x != 0) {
		if (x > 0)
			Queue[0].push(x);//�����
		else
			Queue[1].push(x);
		cin >> x;
	}

	while (!Queue[0].empty()) {//����Ԫ�س�����
		x = Queue[0].front();//������
		Queue[0].pop();
		cout << x << ' ';
	}
	cout << endl;

	while (!Queue[1].empty()) {//����Ԫ�س�����
		x = Queue[1].front();//������
		Queue[1].pop();
		cout << x << ' ';
	}
	cout << endl;

	return 0;
}
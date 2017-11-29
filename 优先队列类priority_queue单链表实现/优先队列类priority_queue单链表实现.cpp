#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#define MAXSIZE 10000      
using namespace std;
typedef int ElemType;
class Queue {
private:
	ElemType a[MAXSIZE];
	int front, rear;
public:
	Queue() {
		front = 0;
		rear = 0;
		for (int i = 0; i < MAXSIZE; i++) {
			a[i] = 0;
		}
	}
	Queue(Queue &Q) {//拷贝构造
		front = Q.front;
		rear = Q.rear;
		for (int i = 0; i < MAXSIZE; i++) {
			a[i] = Q.a[i];
		}
	}
	Queue & operator = (Queue &Q) {
		front = Q.front;
		rear = Q.rear;
		for (int i = 0; i < MAXSIZE; i++) {
			a[i] = Q.a[i];
		}
	}
	bool IsEmpty() {
		if (front == rear)
			return true;
		else return false;
	}
	void EnQueue(ElemType e) {
		if ((rear + 1) % MAXSIZE == front) {
			return;
		}
		else
		{
			a[rear] = e;
			rear = (rear + 1) % MAXSIZE;
		}
	}
	void AllOutQueue() {
		if (front == rear) {
			return;//队列空
		}
		else {
			int length = (rear + MAXSIZE-front) % MAXSIZE;
			for (int i = 0; i < (length);i++) {
				cout << DeQueue()<<" ";
			}
			//cout << endl;
			
			/*for (int i = front; (i + MAXSIZE) % MAXSIZE < rear; i = (i + 1 + MAXSIZE) % MAXSIZE) {
				cout << a[i] << " ";
			}
			cout << endl;*/
			front = rear;
		}
	}
	ElemType DeQueue() {
		if (rear == front) return 19980418;
		else {
			//寻找最小元素
			ElemType MinElem=a[front];
			int Min_pos=front;
			for (int i = front; (i + MAXSIZE) % MAXSIZE < rear; i = (i + 1 + MAXSIZE) % MAXSIZE) {
				if (a[i] < MinElem) {
					MinElem = a[i];
					Min_pos = i;
				}
			}
			for (int j = Min_pos; (j+MAXSIZE)%MAXSIZE > front; j = (j - 1 + MAXSIZE) % MAXSIZE) {
				a[j] = a[(j - 1 + MAXSIZE) % MAXSIZE];
			}
			front = (front + 1) % MAXSIZE;
			return MinElem;
		}
	}
};
int main() {
	int n;
	cin >> n;
	Queue Q[3];
	while (n > 0) {
		char order;
		int arg1, arg2;
		cin >> order;
		if (order == 'E') {
			cin >> arg1 >> arg2;
			Q[arg1].EnQueue(arg2);
		}
		else if (order == 'D') {
			cin >> arg1;
			int tmp;
			tmp = Q[arg1].DeQueue();
			if (tmp != 19980418)
				cout << tmp << " ";
		}
		else if (order == 'A') {
			cin >> arg1;
			Q[arg1].AllOutQueue();
		}
		n--;
	}
	cout << endl;
	return 0;
}


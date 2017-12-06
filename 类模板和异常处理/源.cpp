#include <iostream>
#include <string>
using namespace std;
template <class T>
class CVector {
private:
	int size;
	T *data;
	int capacity;
	void resize(int capacity);
public:
	CVector() :size(0), capacity(0) { data = NULL; }
	CVector(int n) :size(n), capacity(n) {
		data = new T[size];
	}
	~CVector() {
		delete[] data;
		size = capacity = 0;
	}
	void push(const T & n) {
		if (size == capacity) {
			resize(2 * capacity);
			push(n);
		}
		else {
			data[size++] = n;
		}
	}
	void put(int pos,const T &n) {
		if (pos<0 || pos>size) return;
		else {
			data[size] = n;
		}
	}
	T fetch(int pos) {
		if (pos<0 || pos>size) {
			throw	 CException("fetch wrong", pos);
			return 0;
		}

		else {
			cout << data[pos] << endl;
			return data[pos];
		}
	}

};
class CException {
private:
	string msg;
public:
	CException(string	msg, int i) : msg(msg) {
		cout << "invalid index" << ":" << i;
		msg = "invalid index";
	}
	string	GetErrorMsg() {
		return msg;
	}
};
template <class T>
void CVector<T>::resize(int newcapacity) {
	T* b = new T[newcapacity];
	for (int i = 0; i < size; i++) {
		b[i] = data[i];
	}
	delete[] data;
	data = b;
	b = NULL;
}

template	<class T>
void order(int size)
{
	CVector<T>	V(size);
	string	cmd;
	T		x;
	int		index;
	while (cin >> cmd) {
		try {
			if (cmd == "quit")
				break;
			else if (cmd == "push") {
				cin >> x;
				V.push(x);
			}
			else if (cmd == "fetch") {
				cin >> index;
				x = V.fetch(index);

			}
			else if (cmd == "put") {
				cin >> index >> x;
				V.put(index,x);
			}
		}
		catch (CException ex) {
			cout << "invalid index:" << endl;
		}
	}
	cout << endl;
}

int main() {
	string type;
	while (cin >> type) {
		int size;
		cin >> size;
		if (type == "string") {
			order<string>(size);
		}
		else if (type == "int") {
			order<int>(size);
		}
	}
}
//#include <iostream>
//#include <string>
//#include <sstream>
//using	namespace	std;
//
//class	CException {
//	string	m_errMsg;
//public:
//	CException(string	errMsg, int i) : m_errMsg(errMsg) {
//		stringstream	stream;
//		stream << i;
//		string	str;
//		stream >> str;
//		m_errMsg += str;
//	}
//	string	GetErrorMsg() {
//		return m_errMsg;
//	}
//};
//template <class	T>
//class	CMyVector {
//private:
//	T	*m_pBuffer;
//	int	m_size, m_bufferSize;
//public:
//
//	CMyVector() : m_size(0), m_bufferSize(0), m_pBuffer(NULL) {}
//	CMyVector(int n) : m_size(n), m_bufferSize(n) {
//		if (m_bufferSize > 0)
//			m_pBuffer = new T[m_bufferSize];
//		else
//			m_pBuffer = NULL;
//	}
//
//	~CMyVector() {
//		delete[] m_pBuffer;
//	}
//
//	void	push_back(const T &rhs);
//
//	T  & operator [] (int i) {
//		if (i < 0 || i >= m_size) {
//			string	errMsg("invalid index:");
//
//			throw	CException(errMsg, i);
//		}
//		return m_pBuffer[i];
//	}
//	int	size() const {
//		return m_size;
//	}
//};
//
//template <class T>
//void	CMyVector<T>::push_back(const T &rhs)
//{
//	if (m_bufferSize <= m_size) {
//		T	*p = new T[m_bufferSize + 10];
//		for (int i = 0; i < m_size; i++)
//			p[i] = m_pBuffer[i];
//
//		delete[] m_pBuffer;
//		m_pBuffer = p;
//		m_bufferSize += 10;
//	}
//	m_pBuffer[m_size++] = rhs;
//}
//
//template	<class T>
//void Parse(int size)
//{
//	CMyVector<T>	V(size);
//	string	cmd;
//	T		x;
//	int		index;
//	while (cin >> cmd) {
//		try {
//			if (cmd == "quit")
//				break;
//			else if (cmd == "push") {
//				cin >> x;
//				V.push_back(x);
//			}
//			else if (cmd == "fetch") {
//				cin >> index;
//				x = V[index];
//				cout << ' ' << x;
//
//			}
//			else if (cmd == "put") {
//				cin >> index >> x;
//				V[index] = x;
//			}
//		}
//		catch (CException ex) {
//			cout << ' ' << ex.GetErrorMsg();
//		}
//	}
//	cout << endl;
//}
//
//int	main()
//{
//	string	typeStr;
//	while (cin >> typeStr) {
//		int	size;
//		cin >> size;
//		if (typeStr == "int")
//			Parse<int>(size);
//		else
//			Parse<string>(size);
//	}
//
//	return 0;
//}

#define _CRT_SECURE_NO_WARNINGS
#include<cstring>
#include<iostream>
using namespace std;
class String {
private:
	char * str;
public:	
	String(char *a) {
		str = new char[201];
		for (int i = 0; i < 201; i++)
			str[i] = '\0';

		strcpy(str, a);
	}
	String(char *a, int i) {
		str = new char[201];
		for (int i = 0; i < 201; i++)
			str[i] = '\0';
		for (int j = 0; j < i; j++) {
			str[j] = a[j];
		}
	}
	String(const String &str) {
		this->str = new char[201];
		for (int i = 0; i < 201; i++)
			this->str[i] = '\0';
		for (int j = 0; j < 201; j++) {
			this->str[j] = str.str[j];
		}
	}
	String() {
		this->str = new char[201];
		for (int i = 0; i < 201; i++)
			str[i] = '\0';
	}
	~String() {
		if(str){
		delete[] this->str;
		this->str = NULL;
		}
	}
	void Add(const String &str1) {
		strcat(this->str, str1.str);
	}
	String operator+(const String &str1) {
		String str;
		strcpy(str.str, this->str);
		strcat(str.str, str1.str);
		return str;
	}
	String& operator =(const String &str1) {
		for (int i = 0; i < 201; i++)
			this->str[i] = '\0';
		strcpy(this->str, str1.str);
		return *this;
	}
	String & operator = (char* const &a) {
		for (int i = 0; i < 201; i++)
			this->str[i] = '\0';
		strcpy(this->str, a);
	}

	void Display();
	void Init() {
		for (int i = 0; i < 201; i++)
			str[i] = '\0';
	}
	String GetSub(int i, int l);//从i位置开始长度为l的子串
};
void String::Display() {
	int i = 0;
	while (str[i]) {
		cout << this->str[i];
		i++;
	}
	cout << endl;
}
String String::GetSub(int i, int l) {
	String sub(this->str + i, l);//构造子串sub
	return sub;
}
int main() {
	int i, k, j, l, s;
	char tmp[201];
	String str[5];
	String tmpstring;
	cin >> tmp;
	str[1] = String(tmp);
	cin >> tmp;
	str[2] = String(tmp);
	char order;

	while (cin >> order) {
		switch (order) {
		case 'P':
			cin >> i;
			str[i].Display();
			break;
		case 'A':
			cin >> i >> j;
			
			str[j] = str[i];
			break;
		case 'C':
			cin >> i >> j >> k;
			/*str[k].Init();
			str[k].Add(str[i]);
			str[k].Add(str[j]);*/
			str[k]=str[i] + str[j];
			break;
		case 'F':
		{
			cin >> i >> s >> l >> k;
			str[k].Init();
			tmpstring=str[i].GetSub(s, l);
			str[k].Add(tmpstring);
			break;
		}
		default: 
			break;
		}
	}
	return 0;
}
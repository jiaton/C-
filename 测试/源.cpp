#include<cstring>
#include<iostream>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
class String {
private:
	char * strValue;
public:
	String(char *s = "") {
		if (s == NULL)s = "";
		strValue = new char[strlen(s) + 1];
		strcpy(strValue, s);
	}
	String(const String &copy) {
		strValue = new char[strlen(copy.strValue) + 1];
		strcpy(strValue, copy.strValue);
	}
	~String() { delete[] strValue; }
	void Show() { cout << strValue << endl; }
};
int main() {
	String s1("test");
	String s2(s1);
	s1.Show();
	s2.Show();
}
#include<iostream>
#include<cstring>
using namespace std;
class BigInteger {
private:
	int data[400];
	int k;

public:
	BigInteger(char *data) {
		int i = 0;
		for (int j = 0; j < 400; j++) this->data[j] = 0;
		while (data[i] != NULL) {
			this->data[i] = data[i] - '0';
			i++;
		}
		data[i] = 0;
		k = i - 1;
	}
	BigInteger() :k(0) {};
	void show() const;
	friend class signedBigInteger;
	friend BigInteger operator +(const BigInteger &B1, const BigInteger &B2);
	friend BigInteger operator -(const BigInteger &B1, const BigInteger &B2);
	friend BigInteger operator *(const BigInteger &B1, const BigInteger &B2);
	friend signedBigInteger operator +(const signedBigInteger &B1, const signedBigInteger &B2);
	friend signedBigInteger operator -(const signedBigInteger &B1, const signedBigInteger &B2);
	friend signedBigInteger operator *(const signedBigInteger &B1, const signedBigInteger &B2);
};
void BigInteger::show() const {
	for (int i = 0; i <= k; i++)
		cout << data[i];
	cout << endl;
}

BigInteger operator +(const BigInteger &B1, const BigInteger&B2) {
	BigInteger tmp;
	int i = B1.k, j = B2.k, flag = 0;
	tmp.k = B1.k + 1;
	while ((i + 1) && (j + 1)) {
		tmp.data[i + 1] = B1.data[i] + B2.data[j] + flag;
		if (tmp.data[i + 1] >= 10) {
			tmp.data[i + 1] %= 10;
			flag = 1;
		}
		else {
			flag = 0;
		}
		i--; j--;
	}

	while (i + 1) {
		tmp.data[i + 1] = B1.data[i] + flag;
		if (flag == 1) flag = 0;
		if (tmp.data[i + 1] >= 10) {
			tmp.data[i + 1] %= 10;
			flag = 1;
		}
		i--;
	}
	tmp.data[0] = flag;

	if (tmp.data[0] == 0) {
		for (int k = 0; k < tmp.k; k++) tmp.data[k] = tmp.data[k + 1];//向前移位	
		tmp.data[tmp.k] = 0;//最后一位置0
		tmp.k--;//长度-1
	}
	return tmp;
}
BigInteger operator-(const BigInteger &B1, const BigInteger &B2) {
	int i = B1.k, j = B2.k, flag = 0;
	BigInteger tmp;
	tmp.k = i > j ? i : j;
	while ((i + 1) && (j + 1)) {
		if (B1.data[i] + flag < B2.data[j]) {//退位以后减不过，加10
			tmp.data[i] = B1.data[i] + flag - B2.data[j] + 10;
			flag = -1;
		}
		else {
			tmp.data[i] = B1.data[i]+flag - B2.data[j];
			flag = 0;
		}
		i--; j--;
	}
	while (i + 1) {
		tmp.data[i] = B1.data[i];
		i--;
	}
	return tmp;
}
BigInteger operator*(const BigInteger &B1, const BigInteger &B2) {
	int a = 0, flag = 0;
	BigInteger tmp;
	tmp.k = B1.k + B2.k + 1;
	for (int k = B2.k; k >= 0; k--) {
		for (int j = B1.k; j >= 0; j--) {
			a = B1.data[j] * B2.data[k];//临时存储
			tmp.data[k + j + 1] += a % 10 + flag;
			flag = a / 10;//进位的数字
			if (tmp.data[k + j + 1] >= 10) {
				flag += tmp.data[k + j + 1] / 10;
				tmp.data[k + j + 1] %= 10;
			}
		}
		tmp.data[k] = flag;
		flag = 0;
	}
	return tmp;
}
class signedBigInteger{
private :
	char sign;
	BigInteger B;
public:
	signedBigInteger(char *data):sign('+') {
		
		if (data[0] == '-')
		{
			sign = '-';
			int i = 1;
			while (data[i] != NULL) {
				B.data[i - 1] = data[i] - '0';
				i++;
			}
			B.k = i-2 ;
		}
		else if (data[0] == '+' || data[0] == ' ')
		{

			int i = 1;
			while (data[i] != NULL) {
				B.data[i - 1] = data[i] - '0';
				i++;
			}
			B.k = i - 2;
		}
		else
		{
			
			int i = 0;
			while (data[i] != NULL) {
				B.data[i] = data[i] - '0';
				i++;
			}
			B.k = i - 1;
		}
	};
	signedBigInteger() :sign('+') {
		BigInteger B;
	}
	void show() {
		if (sign == '+') B.show();
		else {
			cout << '-';
			B.show();
		}
	}
	friend signedBigInteger operator +(const signedBigInteger &B1, const signedBigInteger &B2);
	friend signedBigInteger operator -(const signedBigInteger &B1, const signedBigInteger &B2);
	friend signedBigInteger operator *(const signedBigInteger &B1, const signedBigInteger &B2);
};
signedBigInteger operator +(const signedBigInteger &B1, const signedBigInteger &B2) {
	signedBigInteger tmp;
	if (B1.sign == B2.sign) {
		tmp.sign = B1.sign;
		tmp.B = B1.B + B2.B;
	}
	else if (B1.sign == '+'&&B2.sign == '-') {
		char data1[200], data2[200];
	
		for (int i = 0; i < 200; i++) {
			data1[i] = B1.B.data[i];
		}
		for (int i = 0; i < 200; i++) {
			data2[i] = B1.B.data[i];
		}
		if (B1.B.k<B2.B.k|| strcmp(data1, data2) < 0 ) {//正的小
			tmp.B = B2.B - B1.B;
			tmp.sign = '-';
		}
		else {//正的大或相等
			tmp.sign = '+';
			tmp.B = B1.B - B2.B;
		}
	}
	else {//第一个是负 第二个是正
		char data1[200], data2[200];
		for (int i = 0; i < 200; i++) {
			data1[i] = B1.B.data[i];
		}
		for (int i = 0; i < 200; i++) {
			data2[i] = B1.B.data[i];
		}
		if (strcmp(data1, data2) < 0) {//负数绝对值小
			tmp.B = B2.B - B1.B;
			tmp.sign = '+';
		}
		else {//负数绝对值大或相等
			tmp.B = B1.B - B2.B;
			tmp.sign = '-';
		}
	}
	return tmp;
	}
signedBigInteger operator -(const signedBigInteger &B1, const signedBigInteger &B2) {
	signedBigInteger tmp;
	//同正
	if (B1.sign == B2.sign&&B1.sign == '+') {
		char data1[200], data2[200];
		for (int i = 0; i < 200; i++) {
			data1[i] = B1.B.data[i];
		}
		for (int i = 0; i < 200; i++) {
			data2[i] = B1.B.data[i];
		}
		if (strcmp(data1, data2) < 0) {//第二个大，则data2-data1，sign为-
			tmp.B = B2.B - B1.B;
			tmp.sign = '-';
		}
		else {//第一个大或相等
			tmp.B = B1.B - B2.B;
			tmp.sign = '+';
		}
	}
	//同负 对应正数相减的相反数
	else if (B1.sign == B2.sign&&B1.sign == '-') {
		char data1[200], data2[200];
		for (int i = 0; i < 200; i++) {
			data1[i] = B1.B.data[i];
		}
		for (int i = 0; i < 200; i++) {
			data2[i] = B1.B.data[i];
		}
		if (strcmp(data1, data2) < 0) {//第二个大
			tmp.B = B2.B - B1.B;
			tmp.sign = '+';//相反数
		}
		else {//第一个大或相等
			tmp.B = B1.B - B2.B;
			tmp.sign = '-';//相反数
		}
	}
	//正-负：结果为正，两数相加
	else if (B1.sign == '+'&&B2.sign == '-') {
		tmp.B = B1.B + B2.B;
		tmp.sign = '+';
	}
	//负-正：结果为负，两数相加
	else if (B1.sign == '-'&&B2.sign == '+') {
		tmp.B = B1.B + B2.B;
		tmp.sign = '-';
	}
	return tmp;

}
signedBigInteger operator *(const signedBigInteger &B1, const signedBigInteger &B2) {
	signedBigInteger tmp;
	if (B1.sign == B2.sign) {//符号相同
		tmp.sign = '+';
		tmp.B = B1.B*B2.B;
	}
	else {//符号不同
		tmp.sign = '-';
		tmp.B = B1.B*B2.B;
	}
	return tmp;
}
int main() {
	char data1[200] = { '\0' };
	char data2[200] = { '\0' };
	cin >> data1 >> data2;
	signedBigInteger B1(data1);
	signedBigInteger B2(data2);
	signedBigInteger result = B1 + B2;
	result.show();
	result = B1 - B2;
	result.show();
	/*result = B1*B2;
	result.show();*/
}
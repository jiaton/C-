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
		for (int k = 0; k < tmp.k; k++) tmp.data[k] = tmp.data[k + 1];//��ǰ��λ	
		tmp.data[tmp.k] = 0;//���һλ��0
		tmp.k--;//����-1
	}
	return tmp;
}
BigInteger operator-(const BigInteger &B1, const BigInteger &B2) {
	int i = B1.k, j = B2.k, flag = 0;
	BigInteger tmp;
	tmp.k = i > j ? i : j;
	while ((i + 1) && (j + 1)) {
		if (B1.data[i] + flag < B2.data[j]) {//��λ�Ժ����������10
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
			a = B1.data[j] * B2.data[k];//��ʱ�洢
			tmp.data[k + j + 1] += a % 10 + flag;
			flag = a / 10;//��λ������
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
		if (B1.B.k<B2.B.k|| strcmp(data1, data2) < 0 ) {//����С
			tmp.B = B2.B - B1.B;
			tmp.sign = '-';
		}
		else {//���Ĵ�����
			tmp.sign = '+';
			tmp.B = B1.B - B2.B;
		}
	}
	else {//��һ���Ǹ� �ڶ�������
		char data1[200], data2[200];
		for (int i = 0; i < 200; i++) {
			data1[i] = B1.B.data[i];
		}
		for (int i = 0; i < 200; i++) {
			data2[i] = B1.B.data[i];
		}
		if (strcmp(data1, data2) < 0) {//��������ֵС
			tmp.B = B2.B - B1.B;
			tmp.sign = '+';
		}
		else {//��������ֵ������
			tmp.B = B1.B - B2.B;
			tmp.sign = '-';
		}
	}
	return tmp;
	}
signedBigInteger operator -(const signedBigInteger &B1, const signedBigInteger &B2) {
	signedBigInteger tmp;
	//ͬ��
	if (B1.sign == B2.sign&&B1.sign == '+') {
		char data1[200], data2[200];
		for (int i = 0; i < 200; i++) {
			data1[i] = B1.B.data[i];
		}
		for (int i = 0; i < 200; i++) {
			data2[i] = B1.B.data[i];
		}
		if (strcmp(data1, data2) < 0) {//�ڶ�������data2-data1��signΪ-
			tmp.B = B2.B - B1.B;
			tmp.sign = '-';
		}
		else {//��һ��������
			tmp.B = B1.B - B2.B;
			tmp.sign = '+';
		}
	}
	//ͬ�� ��Ӧ����������෴��
	else if (B1.sign == B2.sign&&B1.sign == '-') {
		char data1[200], data2[200];
		for (int i = 0; i < 200; i++) {
			data1[i] = B1.B.data[i];
		}
		for (int i = 0; i < 200; i++) {
			data2[i] = B1.B.data[i];
		}
		if (strcmp(data1, data2) < 0) {//�ڶ�����
			tmp.B = B2.B - B1.B;
			tmp.sign = '+';//�෴��
		}
		else {//��һ��������
			tmp.B = B1.B - B2.B;
			tmp.sign = '-';//�෴��
		}
	}
	//��-�������Ϊ�����������
	else if (B1.sign == '+'&&B2.sign == '-') {
		tmp.B = B1.B + B2.B;
		tmp.sign = '+';
	}
	//��-�������Ϊ�����������
	else if (B1.sign == '-'&&B2.sign == '+') {
		tmp.B = B1.B + B2.B;
		tmp.sign = '-';
	}
	return tmp;

}
signedBigInteger operator *(const signedBigInteger &B1, const signedBigInteger &B2) {
	signedBigInteger tmp;
	if (B1.sign == B2.sign) {//������ͬ
		tmp.sign = '+';
		tmp.B = B1.B*B2.B;
	}
	else {//���Ų�ͬ
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
#include<iostream>
using namespace std;
class BigInteger {
private:
	int data[401];
	int k;

public:
	BigInteger(char *data) {
		int i = 0;
		for (int j = 0; j < 401; j++) this->data[j] = 0;
		while (data[i] != NULL) {
			this->data[i] = data[i] - '0';
			i++;
		}
		k = i - 1;
	}
	BigInteger() :k(0) {
		for (int j = 0; j < 401; j++) this->data[j] = 0;
	}
	void show() const;

	friend BigInteger operator +(const BigInteger &B1, const BigInteger &B2);
	friend BigInteger operator -(const BigInteger &B1, const BigInteger &B2);
	friend BigInteger operator *(const BigInteger &B1, const BigInteger &B2);
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
		if (B1.data[i] + flag < B2.data[j]) {
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
		tmp.data[i] = B1.data[i] + flag;
		if (flag != 0 ) flag = 0;
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
	if (tmp.data[0] == 0) {
		for (int k = 0; k < tmp.k; k++) tmp.data[k] = tmp.data[k + 1];//向前移位	
		tmp.data[tmp.k] = 0;//最后一位置0
		tmp.k--;//长度-1
	}
	return tmp;
}
int main() {
	char data1[200] = { '\0' };
	char data2[200] = { '\0' };
	cin >> data1 >> data2;
	BigInteger B1(data1);
	BigInteger B2(data2);
	BigInteger result = B1 + B2;
	result.show();
	result = B1 - B2;
	result.show();
	result = B1*B2;
	result.show();

}
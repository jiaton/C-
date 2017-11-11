#include<iostream>
#include<cmath>
using namespace std;
class RationalNumber {
private:
	char sign;
	int numerator;
	int denominator;
public:
	RationalNumber(int n, int d) :numerator(abs(n)), denominator(abs(d)),sign('\0') {
		if (n*d < 0)  sign = '-';
		Reduction(); }
	RationalNumber(int n, int d,char sign) :numerator(n), denominator(d), sign(sign) {
		Reduction();
	}
	void Display();
	void Reduction();
	int  GCD(int a,int b);
	RationalNumber operator -()const {
		if (this->sign == '-')return RationalNumber(this->numerator, this->denominator);
		else return RationalNumber(this->numerator, this->denominator, '-');
	}
	RationalNumber operator +(const RationalNumber &n2);
	RationalNumber operator -(const RationalNumber &n2);
	RationalNumber operator *(const RationalNumber &n2);
	RationalNumber operator /(const RationalNumber &n2);
	RationalNumber& operator =(const RationalNumber &n2);
	RationalNumber reverse() const{
		return RationalNumber(this->denominator, this->numerator, sign);
	}
};
void RationalNumber::Reduction() {//约分
	int gcd = GCD(this->numerator,this->denominator);//最大公因数
	this->numerator /= gcd;
	this->denominator /= gcd;
}
int RationalNumber::GCD(int a , int b ) {
	if (a%b == 0) return b;
	GCD(b, a%b);
}
void RationalNumber::Display() {
	if (sign == '\0') {
		if (denominator == 1) cout  << numerator;
		else cout << numerator << "/" << denominator;
	}
	else {
		if (denominator == 1) cout << sign << numerator;
		else cout << sign << numerator << "/" << denominator;
	}
}
RationalNumber RationalNumber:: operator +(const RationalNumber &n2) {
	if (this->sign == n2.sign) {
		if (this->denominator == n2.denominator)
			return RationalNumber(this->numerator + n2.numerator, denominator,this->sign);
		else {
			return RationalNumber(this->numerator*n2.denominator + this->denominator * n2.numerator, this->denominator*n2.denominator,this->sign);
		}
	}
	else {//符号不同
		if (n2.sign == '-')
			return RationalNumber(this->numerator*n2.denominator - this->denominator * n2.numerator, this->denominator*n2.denominator);
		else return RationalNumber(this->denominator * n2.numerator- this->numerator*n2.denominator, this->denominator*n2.denominator);
	}
}
RationalNumber RationalNumber:: operator -(const RationalNumber &n2) {
	return (*this+ (-n2));
};
RationalNumber RationalNumber::operator*(const RationalNumber &n2) {
	if (this->sign == n2.sign) {
		return RationalNumber(this->numerator*n2.numerator, this->denominator*n2.denominator);
	}
	else {
		return RationalNumber(this->numerator*n2.numerator, this->denominator*n2.denominator, '-');
	}
}
RationalNumber RationalNumber::operator /(const RationalNumber &n2) {
	return (*this *n2.reverse());
}
RationalNumber& RationalNumber::operator =(const RationalNumber &n2) {
	this->denominator = n2.denominator;
	this->numerator = n2.numerator;
	this->sign = n2.sign;
	return *this;
}
int main() {
	int n, d;
	cin >> n >> d;
	RationalNumber n1(n,d);
	cin >> n >> d;
	RationalNumber n2(n, d);
	n1.Display();
	cout << endl;
	n2.Display();
	cout << endl;
	RationalNumber n3(1,1);
	n3 = n1 + n2;
	n3.Display();
	cout << '\t';
	n3 = n1 - n2;
	n3.Display();
	cout << '\t';
	n3 = n1*n2;
	n3.Display();
	cout << '\t';
	n3 = n1 / n2;
	n3.Display();
	cout << '\t';
	
	
}

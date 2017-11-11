#include<iostream>
using namespace std;
class RationalNumber {
private:
	int numerator;
	int denominator;
public:
	RationalNumber(int n, int d) :numerator(n), denominator(d) { Reduction(); };
	void Display();
	void Reduction();
	int  GCD();
	RationalNumber operator +(const RationalNumber &n2);
	RationalNumber operator -(const RationalNumber &n2);
	RationalNumber operator *(const RationalNumber &n2);
	RationalNumber operator /(const RationalNumber &n2);
	RationalNumber& operator =(const RationalNumber &n2);
};
void RationalNumber::Reduction() {
	int gcd = GCD();
	this->numerator /= gcd;
	this->denominator /= gcd;
}
int RationalNumber::GCD() {

}
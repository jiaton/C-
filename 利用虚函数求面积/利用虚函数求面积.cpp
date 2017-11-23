#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
#define PI 3.1416
class Shape {
public:
		virtual double Area()=0;
};
class Circle :public Shape{
private:
	double r;
public:
	Circle(double  r) :r(r) {}
	double Area() {
		return PI*r*r;
	}
};
class Rectangle:public Shape {
private:
	double a, b;
public:
	Rectangle(double a,double b):a(a),b(b){}
	double Area() {
		return a*b;
	}
};
	
class Triangle :public Shape{
private:
	double a, b, c;
public :
	Triangle(double a, double b, double c) :a(a), b(b), c(c) {};
	double Area() {
		double p = (a + b + c) / 2;
		return sqrt(p*(p - a)*(p - b)*(p - c));
	}
};
int main() {
	char a[10];
	Shape *p[100];
	double sum=0;
	int k;//¼ÇÂ¼Ö¸ÕëÎ»ÖÃ
	k = 0;
	int n = 0;
	while (cin >> a) {
		if (a[0] == 'c') {
			double r;
			cin >> r;
			p[k++]=new Circle(r);			
		}
		else if (a[0] == 'r') {
			double a, b;
			cin >> a >> b;
			p[k++] = new Rectangle(a, b);
		}
		else if (a[0] == 't') {
			double a, b, c;
			cin >> a >> b >> c;
			p[k++] = new Triangle(a, b, c);
		}
	}
	for (int i = 0; i < k; i++) {
		sum+=p[i]->Area();
	}
	cout <<fixed<<setprecision(4)<< sum << endl;
	return 0;
}
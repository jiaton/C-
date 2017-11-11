#include<iostream>
using namespace std;
int main() {
	int C;
	cin >> C;
	for (int i = 0; i < C; i++) {
		int N;
		cin >> N;
		int Si[60];
		for (int i = 0; i < N; i++) {
			cin >> Si[i];
		}
		float ave=0;
		for (int i = 0; i < N; i++) {
			ave += Si[i];
		}
		ave /= N;
		int count=0;
		for (int i = 0; i < N; i++) {
			if (Si[i] >= ave) count++;
		}
		printf("%.2f", ave);
		cout << " ";
		cout << count << endl;
	}
}
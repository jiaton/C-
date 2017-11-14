#include<iostream>
#include<cstring>
using namespace std;
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		char *a = (char*)malloc(51 * sizeof(char));
		cin >> a;
		for (int j = strlen(a)-1; i >= 0; j--) {
			cout << a[j];
		}
	}
}
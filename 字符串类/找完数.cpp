#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class CFunctor {
public:
	bool operator() (int x) {
		int iSum = 0;
		for (int i = 1; i <= x / 2; i++) {
			if (x%i == 0)
				iSum += i;
		}
		return iSum == x;
	}
};
int main() {
	vector<int> V;
	int x;
	while (cin >> x)
		V.push_back(x);
	int iNumber = count_if(V.begin(), V.end(), CFunctor());
	cout << iNumber << endl;
	vector<int>::iterator it = find_if(V.begin(), V.end(), CFunctor());
	if (it != V.end()) {
		cout << it - V.begin() + 1 << "\t" << *it << endl;
	}
	else {
		cout << "none" << endl;
	}
	return 0;

}

#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Matrix {
private:
	vector<vector<int> > matrix;
	int w, h;//宽 高
	int s;//连通块个数
public:
	Matrix(int w,int h):w(w),h(h),s(0) {
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				cin >> matrix[i][j];
			}
		}
		for (int j = 0; j < w; j++) matrix[0][j] = 0;
		for (int j = 0; j < w; j++) matrix[h][j] = 0;
		for (int i = 0; i < h; i++) matrix[i][0] = 0;
		for (int i = 0; i < h; i++) matrix[i][w] = 0;
	}
	void count() {
		//stack<vector<int> > rec;
		int i = 1, j = 1;
		while (matrix[i][j] != 0) {
			j++;
			
		}

		
	}
};
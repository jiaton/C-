#include <iostream>
#include<vector>
using namespace std;
 
template<typename T>
T &val(T *matrix, int w, int h, int i, int j)
{
    return *(matrix + j * w + i);
}
 
int unguarded_count_area_size(int *matrix, bool *visit, int w, int h, int i, int j, int value)
{
    if (i < 0 || i >= w) return 0;
    if (j < 0 || j >= h) return 0;
 
    if (val(visit, w, h, i, j) == true || val(matrix, w, h, i, j) != value)
    {
        return 0;
    }
 
    val(visit, w, h, i, j) = true;
 
    const int left = unguarded_count_area_size(matrix, visit, w, h, i - 1, j, value);
    const int right = unguarded_count_area_size(matrix, visit, w, h, i + 1, j, value);
    const int top = unguarded_count_area_size(matrix, visit, w, h, i, j - 1, value);
    const int bottom = unguarded_count_area_size(matrix, visit, w, h, i, j + 1, value);
 
    return left + right + top + bottom + 1;
}
 
int count_area(int *matrix, int w, int h)
{
    if (matrix == NULL || w <= 0 || h <= 0)
    {
        return 0;
    }
 
    bool *visit = new bool[w * h];
    int sum = 0;
 
    memset(visit, 0, sizeof(bool) * w * h);
 
    for (int j = 0; j < h; ++j)
    {
        for (int i = 0; i < w; ++i)
        {
            const int size = 
                unguarded_count_area_size(matrix, visit, w, h, i, j, val(matrix, w, h, i, j));
 
            if (size >= 1) ++sum;
        }
    }
 
    delete[] visit;
    return sum;
}
 
 
int main(int argc, char **argv)
{
	int a[1][1];
	int ww, hh;
	cin >> hh >> ww;
	int** data;
	data = new int*[hh];
	data[0] = new int[hh*ww];
	for (int i = 1; i < hh; i++) {
		data[i] = data[i - 1] + ww;
	}
	/*for (int i = 0; i < hh; i++) {
		data[i] = new int[ww];
	}*/

	for (int i = 0; i < hh; i++) {
		for (int j = 0; j < ww; j++) {
			cin >> data[i][j];
		}
	}
	/*for (int i = 0; i < hh; i++) {
		for (int j = 0; j < ww; j++) {
			cout<< data[i][j]<<" ";
		}
		cout << endl;
	}*/
    cout << count_area(&data[0][0], ww,hh) ;
    return 0;
}
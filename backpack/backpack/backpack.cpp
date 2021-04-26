#include <iostream>
#include <chrono>
using namespace std;

int optimisation(int** w_v, int* sum_v, int i,  int n) {
	int v_0 = 0;
	for (int j = 0;j < n;++j) {
		if (i - w_v[j][0] >= 0) {
			v_0 = v_0 < sum_v[i - w_v[j][0]] + w_v[j][1] ? sum_v[i - w_v[j][0]] + w_v[j][1] : v_0;
		}
	}
	return v_0;
}

int main()
{
	int w,n;
	cout << "Input capacity of the backpack and number of items" << endl;
	cin >> w >> n;
	cout << "Input weight and prices of items" << endl;
	int** w_v = (int**)malloc(n*sizeof(int*));
	for (int i = 0; i < n;++i) {
		int* curr = (int*)malloc(2 * sizeof(int));
		cin >> curr[0] >> curr[1];
		w_v[i] = curr;
	}

	int* sum_v = (int*)malloc((w + 1) * sizeof(int));
	sum_v[0] = 0;
	for (int i = 1;i < w+1;++i) {
		sum_v[i] = optimisation(w_v,sum_v, i, n);
	}
	cout << sum_v[w]<<" ";
}
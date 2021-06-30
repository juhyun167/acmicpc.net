#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

#define MAX		1000000

int n, t, arr[MAX];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	int max;
	double sum = 0.0;

	setup();
	cin >> n;
	for (int i = 0; i < n; i++)	{
		cin >> arr[i];
	}

	max = *max_element(arr, arr + n);
	for (int i = 0; i < n; i++) {
		sum += (double) arr[i] / max * 100;
	}
	cout.precision(10);
	cout << sum / n << "\n";
	return 0;
}

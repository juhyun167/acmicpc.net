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
	setup();
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
	}
	auto max = max_element(arr, arr + 9);
	cout << *max << "\n";
	cout << distance(arr, max) + 1 << "\n";
	return 0;
}

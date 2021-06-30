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
	int a, b, c;
	setup();

	cin >> a >> b >> c;
	n = a * b * c;
	while (n != 0) {
		arr[n % 10] += 1;
		n = (n - n % 10) / 10;
	}
	for (int i = 0; i <= 9; i++) {
		cout << arr[i] << "\n";
	}
	return 0;
}

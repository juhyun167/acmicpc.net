#include <iostream>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;

#define MAX		1000000

int n, t;
bool arr[MAX + 1];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

int generate(int n) {
	int retval = n;

	while (n != 0) {
		retval += n % 10;
		n = (n - n % 10) / 10;
	}
	return retval;
}

int main() {
	setup();
	for (int i = 1; i < 10000; i++) {
		if (!arr[i]) {
			int res = i;

			while (res < 10000) {
				res = generate(res);
				arr[res] = true;
			}
		}
	}
	for (int i = 1; i < 10000; i++) {
		if (!arr[i]) {
			cout << i << "\n";
		}
	}
	return 0;
}

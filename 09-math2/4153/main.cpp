#include <iostream>
#include <sstream>
#include <cctype>
#include <locale>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <vector>
#include <iomanip>
using namespace std;

#define MAX		1000000

unsigned long long m, n, t;
int arr[MAX + 1];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

int main() {
	vector<int> v(3);

	setup();
	while (true) {
		cin >> v[0] >> v[1] >> v[2];
		if (v[0] * v[1] * v[2] == 0) {
			break;
		}
		sort(v.begin(), v.end());
		if (v[0] * v[0] + v[1] * v[1] == v[2] * v[2]) {
			cout << "right\n";
		} else {
			cout << "wrong\n";
		}
	}
	return 0;
}

#include <iostream>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;

#define MAX		1000000

int n, t, arr[MAX + 1];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

int main() {
	string s;
	int sum = 0;

	setup();
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		sum += (char) s[i] - '0';
	}
	cout << sum << "\n";
	return 0;
}

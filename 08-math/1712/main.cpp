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

int n, t, arr[MAX + 1];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

int main() {
	int a, b, c;

	setup();
	cin >> a >> b >> c;
	if (c <= b) {
		cout << "-1\n";
	} else {
		cout << (int) floor((double) a / (c - b)) + 1 << "\n";
	}
	return 0;
}

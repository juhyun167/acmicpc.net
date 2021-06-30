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

unsigned long long n, t;
int arr[MAX + 1];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

int main() {
	int x, y;

	setup();
	cin >> n;
	x = n / 5;
	while (x >= 0) {
		if ((n - 5 * x) % 3 != 0) {
			x--;
			continue;	
		} else {
			y = (n - 5 * x) / 3;
			cout << x + y << "\n";
			return 0;
		}
	}
	cout << "-1\n";
	return 0;
}

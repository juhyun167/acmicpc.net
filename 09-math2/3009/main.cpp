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
	int x1, x2, x3, x4;
	int y1, y2, y3, y4;

	setup();
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;
	if (x1 == x2) {
		x4 = x3;
	} else if (x1 == x3) {
		x4 = x2;
	} else {
		x4 = x1;
	}
	if (y1 == y2) {
		y4 = y3;
	} else if (y1 == y3) {
		y4 = y2;
	} else {
		y4 = y1;	
	}
	cout << x4 << " " << y4 << "\n";
	return 0;
}

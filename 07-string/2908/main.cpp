#include <iostream>
#include <sstream>
#include <cctype>
#include <locale>
#include <algorithm>
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
	string a, b;

	setup();
	cin >> a >> b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	if (stoi(a) > stoi(b)) {
		cout << a << "\n";
	} else {
		cout << b << "\n";
	}
	return 0;
}

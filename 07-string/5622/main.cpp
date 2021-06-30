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
	string s;
	int sum = 0;

	setup();
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		if ('A' <= s[i] && s[i] < 'D') {
			sum += 3;
		} else if ('D' <= s[i] && s[i] < 'G') {
			sum += 4;
		} else if ('G' <= s[i] && s[i] < 'J') {
			sum += 5;
		} else if ('J' <= s[i] && s[i] < 'M') {
			sum += 6;
		} else if ('M' <= s[i] && s[i] < 'P') {
			sum += 7;
		} else if ('P' <= s[i] && s[i] < 'T') {
			sum += 8;
		} else if ('T' <= s[i] && s[i] < 'W') {
			sum += 9;
		} else {
			sum += 10;
		}
	}
	cout << sum << "\n";
	return 0;
}

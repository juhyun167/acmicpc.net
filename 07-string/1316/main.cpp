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

bool test(string s) {
	char c, cc;

	fill_n(arr + 'a', 'z' - 'a' + 1, 0);
	for (int i = 0; i < s.length(); i++) {
		if (i > 0 && s[i] != s[i - 1] && arr[s[i]] > 0) {
			return false;
		}
		arr[s[i]] += 1;
	}
	return true;
}

int main() {
	int cnt = 0;

	setup();
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;

		cin >> s;
		if (test(s)) {
			cnt += 1;
		}
	}
	cout << cnt << "\n";
	return 0;
}

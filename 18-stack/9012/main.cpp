#include <iostream>
#include <sstream>
#include <cctype>
#include <locale>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <climits>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <stack>
#include <queue>
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

void test(string str) {
	stack<char> s;

	for (const auto &c : str) {
		if (c == '(') {
			s.push(c);
		} else {
			if (s.size() == 0) {
				cout << "NO\n";
				return;
			}
			s.pop();
		}
	}
	if (s.size() == 0) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}

int main() {
	setup();
	cin >> t;
	while (t--) {
		string s;
		
		cin >> s;
		test(s);
	}
	return 0;
}

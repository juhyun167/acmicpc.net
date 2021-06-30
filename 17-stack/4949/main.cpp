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
		if (c == '(' || c == '[') {
			s.push(c);
		} else if (c == ')') {
			if (s.size() == 0 || s.top() != '(') {
				cout << "no\n";
				return;
			}
			s.pop();
		} else if (c == ']') {
			if (s.size() == 0 || s.top() != '[') {
				cout << "no\n";
				return;
			}
			s.pop();
		} 
	}
	if (s.size() == 0) {
		cout << "yes\n";
	} else {
		cout << "no\n";
	}
}

int main() {
	setup();
	while (true) {
		string s;

		getline(cin, s);
		if (s == ".") {
			break;
		}
		test(s);
	}
	return 0;
}

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
#include <iomanip>
using namespace std;

#define MAX		1000000

unsigned long long m, n, t;
vector<int> v;
vector<char> op;

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

int main() {
	string s;
	int pos = 0, len = 0;

	setup();
	cin >> s;
	if (s[0] != '-') {
		s = '+' + s;
	}
	// Parsing
	v.emplace_back(0);
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '+' || s[i] == '-') {
			if (pos > 0) {
				string ss = s.substr(pos, len);
				v.emplace_back(stoi(ss));
				len = 0;
			}
			op.emplace_back(s[i]);
			pos = i + 1;
		} else {
			len += 1;
		}
	}
	string ss = s.substr(pos, len);
	v.emplace_back(stoi(ss));

	// Evaluation
	int res = v[0];
	bool found = false;

	for (int i = 1; i < v.size(); i++) {
		if (!found && op[i - 1] == '+') {
			res += v[i];
		} else {
			found = true;
			res -= v[i];
		}
	}
	cout << res << "\n";
	return 0;
}

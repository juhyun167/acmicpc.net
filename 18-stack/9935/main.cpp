#include <iostream>
#include <sstream>
#include <cctype>
#include <cstdint>
#include <locale>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <climits>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <stack>
#include <queue>
#include <list>
#include <utility>
#include <iomanip>
using namespace std;

#define MAX		(1000000 + 1)

int m, n, t, k, v;
string s, bomb;

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

string top_n(stack<char>& st, int n) {
	string result;

	if (n > st.size()) {
		return "";
	}
	for (int i = 0; i < n; i++) {
		result += st.top();
		st.pop();
	}

	reverse(result.begin(), result.end());
	for (const char& c : result) {
		st.push(c);
	}

	return result;
}

string pop_n(stack<char>& st, int n) {
	string result;

	if (n > st.size()) {
		return "";
	}
	for (int i = 0; i < n; i++) {
		result += st.top();
		st.pop();
	}

	reverse(result.begin(), result.end());

	return result;
}

string explode() {
	stack<char> st;
	string result;

	for (const char& c : s) {
		string top_n_chars;

		st.push(c);
		top_n_chars = top_n(st, n);
		if (top_n_chars == bomb) {
			pop_n(st, n);
		}
	}

	while (!st.empty()) {
		result += st.top();
		st.pop();
	}
	reverse(result.begin(), result.end());
	if (result.length() == 0) {
		result = "FRULA";
	}

	return result;
}

int main() {
	setup();
	cin >> s >> bomb;
	n = bomb.length();
	cout << explode() << "\n";

	return 0;
}

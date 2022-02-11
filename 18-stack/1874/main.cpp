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

void test() {
	stack<int> st;
	vector<char> v;
	int idx = 0;

	for (int i = 1; i <= n; i++) {
		st.push(i);
		v.emplace_back('+');

		while (!st.empty() && st.top() == arr[idx]) {
			st.pop();
			v.emplace_back('-');
			idx++;
		}
	}
	if (!st.empty()) {
		cout << "NO\n";
		return;
	}
	for (const auto &c : v) {
		cout << c << "\n";
	}
}

int main() {
	setup();
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	test();
	return 0;
}

#include <iostream>
#include <sstream>
#include <cctype>
#include <locale>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <climits>
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

bool compare(string& lh, string& rh) {
	if (lh.length() == rh.length()) {
		return lh < rh;
	} else {
		return lh.length() < rh.length();
	}
}

int main() {
	vector<string> v;

	setup();
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;

		cin >> s;
		if (find(v.begin(), v.end(), s) == v.end()) {
			v.emplace_back(s);
		}
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
	return 0;
}

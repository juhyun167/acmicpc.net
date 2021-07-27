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
#include <iomanip>
using namespace std;

#define MAX		1000000

uint64_t m, n, t, k;
int arr[MAX + 1];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

bool check(string s) {
	for (int i = 0, j = s.length() - 1; i <= s.length() / 2;
			i++, j--) {
		if (s[i] != s[j]) {
			return false;
		}
	} 
	return true;
}

int main() {
	string s;

	setup();
	while (true) {
		cin >> s;
		
		if (s == "0") {
			break;
		}
		if (check(s)) {
			cout << "yes\n";
		} else {
			cout << "no\n";
		}
	}
	return 0;
}

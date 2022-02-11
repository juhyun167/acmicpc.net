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

	int main() {
		int k, sum = 0;
		stack<int> s;

		setup();
		cin >> k;
		while (k--) {
			cin >> n;
			if (n != 0) {
				sum += n;
				s.push(n);
			} else {
				sum -= s.top();
				s.pop();
			}
		}
		cout << sum << "\n";
		return 0;
	}

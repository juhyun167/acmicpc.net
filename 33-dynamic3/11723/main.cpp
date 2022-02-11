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
#define N		20

uint64_t m, n, t, k;

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

class BitSet {
	int bs = 1 << N;

public:
	void add(int x) {
		bs |= 1 << x;
	}

	void remove(int x) {
		bs &= ~(1 << x);
	}

	bool check(int x) {
		return (bs >> x) & 1;
	}

	void toggle(int x) {
		bs ^= 1 << x;
	}

	void all() {
		bs |= ~(~0 << N);
	}

	void empty() {
		bs &= 0;
	}
};

int main() {
	BitSet bs;

	setup();
	cin >> t;
	while (t--) {
		string s;
		int x;

		cin >> s;
		if (s[0] == 'a' && s[1] == 'l') {
			bs.all();
		} else if (s[0] == 'e') {
			bs.empty();
		} else {
			cin >> x;
			if (s[0] == 'a') {
				bs.add(x);
			} else if (s[0] == 'r') {
				bs.remove(x);
			} else if (s[0] == 'c') {
				cout << (int) bs.check(x) << "\n";
			} else {
				bs.toggle(x);
			}
		}
	}
	return 0;
}

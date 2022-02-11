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

int m, t, k, v;
const long long p = 1000000007;

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

long long mod(long long a, long long b) {
    long long ret;

    if (b < 0) {
        return -mod(-a, -b);
    }
    ret = (a % b < 0) ? a % b + b : a % b;

    return ret;
}

tuple<long long, long long, long long> euclid(long long a, long long b) {
    long long d, x, y, x2, y2;

    if (b == 0) {
        return make_tuple(a, 1, 0);
    }
    tie(d, x2, y2) = euclid(b, mod(a, b));
    x = y2;
    y = x2 - (a / b) * y2;

    return make_tuple(d, x, y);
}

long long solver(long long a, long long b, long long n) {
    long long d, x, y, sol;

    tie(d, x, y) = euclid(a, n);
    if (mod(b, d) != 0) {
        // no solution
        return -1;
    }
    sol = mod(x * (b / d), n);

    return sol;
}

inline long long get_inv(long long x) {
	return solver(x, 1, p);
}

int main() {
	vector<long long> n, s;
	long long result = 0;

	setup();
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		
		cin >> x >> y;
		n.emplace_back(x);
		s.emplace_back(y);

		result = mod(result + s[i] * get_inv(n[i]), p);
	}
	cout << result << "\n";

	return 0;
}

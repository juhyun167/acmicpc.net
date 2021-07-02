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

unsigned long long m, n, t, k;

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

void modmul(vector<vector<unsigned long long>> &a, 
			vector<vector<unsigned long long>> &b,
			vector<vector<unsigned long long>> &result, int modulus) {
	vector<vector<unsigned long long>> _a = a, _b = b;

	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result.size(); j++) {
			result[i][j] = 0;
		}
	}

	for (int i = 0; i < _a.size(); i++) {
		for (int j = 0; j < _b[0].size(); j++) {
			for (int t = 0; t < _b.size(); t++) {
				result[i][j] += _b[t][j] * _a[i][t] % modulus;
			}
		}
	}
}

vector<vector<unsigned long long>> &modpow(
							vector<vector<unsigned long long>> &base, 
                            unsigned long long exp, int modulus,
							vector<vector<unsigned long long>> &result) {
    for (int i = 0; i < base.size(); i++) {
        for (int j = 0; j < base[0].size(); j++) {
            base[i][j] %= modulus;
            result[i][j] = (i == j) ? 1 : 0;
        }
    }

    while (exp > 0) {
        if (exp & 1) {
            modmul(result, base, result, modulus);
        }
        modmul(base, base, base, modulus);
        exp >>= 1;
    }

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[0].size(); j++) {
            result[i][j] %= modulus;
        }
    }
    return result;
}

unsigned long long fibo(unsigned long long n) {
	vector<vector<unsigned long long>> f(
		2, vector<unsigned long long>(2, 1)
	);
	vector<vector<unsigned long long>> result(
		2, vector<unsigned long long>(2)
	);

	f[1][1] = 0;
	if (n == 0) {
		return 0;
	}
	result = modpow(f, n, 1000000007, result);
	return result[0][1];
}

int main() {
	setup();
	cin >> n;
	cout << fibo(n) << "\n";
	return 0;
}

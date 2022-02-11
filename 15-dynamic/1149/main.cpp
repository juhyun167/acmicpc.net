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

#define MAX		1000

unsigned long long m, n, t;
int R[MAX + 1], G[MAX + 1], B[MAX + 1];
int dpR[MAX + 1], dpG[MAX + 1], dpB[MAX + 1];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

int recursion(int k) {
	for (int i = 1; i < n; i++) {
		dpR[i] = R[i] + min(dpG[i - 1], dpB[i - 1]);
		dpG[i] = G[i] + min(dpR[i - 1], dpB[i - 1]);
		dpB[i] = B[i] + min(dpR[i - 1], dpG[i - 1]);
	}
	return min({dpR[n - 1], dpG[n - 1], dpB[n - 1]});
}

int main() {
	setup();
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> R[i] >> G[i] >> B[i];
	}
	dpR[0] = R[0], dpG[0] = G[0], dpB[0] = B[0];
	cout << recursion(n) << "\n";
	return 0;
}

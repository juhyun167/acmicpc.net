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
#include <iomanip>
using namespace std;

#define MAX		(1000000 + 1)

uint64_t m, n, t, k, v;
int arr[MAX];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

int main() {
	unordered_map<string, string> umap;
	string s1, s2;

	setup();
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> s1 >> s2;
		umap[s1] = s2;
	}
	for (int i = 0; i < m; i++) {
		cin >> s1;
		cout << umap[s1] << "\n";
	}

	return 0;
}

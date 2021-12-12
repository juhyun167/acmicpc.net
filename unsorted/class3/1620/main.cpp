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

int main() {
	unordered_map<string, string> umap;
	string s;

	setup();
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		umap.insert(make_pair(to_string(i), s));
		umap.insert(make_pair(s, to_string(i)));
	}
	while (m--) {
		unordered_map<string, string>::iterator iter;

		cin >> s;
		if ((iter = umap.find(s)) != umap.end()) {
			cout << iter->second << "\n";
		}
	}

	return 0;
}

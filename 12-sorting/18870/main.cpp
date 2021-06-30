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
	unordered_set<int> visited;
	unordered_map<int, int> map;
	vector<int> v, sorted;

	setup();
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;

		cin >> x;
		v.emplace_back(x);
		if (visited.find(x) == visited.end()) {
			sorted.emplace_back(x);
			visited.insert(x);
		}
	}
	sort(sorted.begin(), sorted.end());
	for (int i = 0; i < sorted.size(); i++) {
		map.insert(make_pair(sorted[i], i));
	}
	for (int i = 0; i < v.size(); i++) {
		cout << map[v[i]] << " ";
	}
	cout << "\n";
	return 0;
}

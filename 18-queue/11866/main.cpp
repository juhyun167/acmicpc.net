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
	queue<int> qu;
	int k;

	setup();
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		qu.push(i);
	}

	cout << "<";
	while (!qu.empty()) {
		for (int i = 0; i < k - 1; i++) {
			qu.push(qu.front());
			qu.pop();
		}
		cout << qu.front();
		qu.pop();
		if (!qu.empty()) {
			cout << ", ";
		}
	}
	cout << ">\n";
	return 0;
}

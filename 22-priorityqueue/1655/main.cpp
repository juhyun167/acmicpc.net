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
	priority_queue<int> pq;
	priority_queue<int, vector<int>, greater<int>> pq2;

	setup();
	cin >> n;

	pq.push(INT_MIN);
	pq2.push(INT_MAX);
	for (int i = 0; i < n; i++) {
		int x;

		cin >> x;
		if (x < pq.top()) {
			if (pq.size() > pq2.size()) {
				pq2.push(pq.top());
				pq.pop();
			}
			pq.push(x);
		} else {
			if (pq.size() > pq2.size()) {
				pq2.push(x);
			} else {
				if (x < pq2.top()) {
					pq.push(x);
				} else {
					pq.push(pq2.top());
					pq2.pop();
					pq2.push(x);
				}
			}
		}
		cout << pq.top() << "\n";
	}
	return 0;
}

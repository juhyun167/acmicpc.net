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

int getidx(deque<int> &dq, int x) {
	auto it = find(dq.begin(), dq.end(), x);
	return distance(dq.begin(), it);
}

int main() {
	deque<int> dq;
	int cnt = 0;

	setup();
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}
	for (int i = 0; i < m; i++) {
		int idx = getidx(dq, arr[i]);

		if (idx <= dq.size() / 2) {
			while (dq.front() != arr[i]) {
				dq.push_back(dq.front());
				dq.pop_front();
				cnt++;	
			}
		} else {
			while (dq.front() != arr[i]) {
				dq.push_front(dq.back());
				dq.pop_back();
				cnt++;
			}
		}
		dq.pop_front();
	}
	cout << cnt << "\n";
	return 0;
}

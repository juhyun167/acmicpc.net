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

struct Doc {
	int idx, priority;

	Doc(int idx, int priority) : idx(idx), priority(priority) {};
};

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

bool check(queue<Doc *> &qu) {
	queue<Doc *> qu2(qu);
	int idx = qu2.front()->idx;
	int priority = qu2.front()->priority;

	qu2.push(qu2.front());
	qu2.pop();
	while (idx != qu2.front()->idx) {
		if (qu2.front()->priority > priority) {
			return false;
		}
		qu2.push(qu2.front());
		qu2.pop();
	}
	return true;
}

int main() {
	setup();
	cin >> t;
	while (t--) {
		queue<Doc *> qu;
		int k, cnt = 0;

		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			int priority;

			cin >> priority;
			qu.push(new Doc(i, priority));
		}

		do {
			if (check(qu)) {
				Doc *d = qu.front();
				
				qu.pop();
				cnt++;
				if (d->idx == k) {
					cout << cnt << "\n";
					break;
				}
			} else {
				qu.push(qu.front());
				qu.pop();
			}
		} while (!qu.empty());
	}
	return 0;
}

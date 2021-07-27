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

class PQ {
	vector<int> vec;
	bool (*compare)(int x, int y);

private:
	inline int parent(int i) { return i >> 1; }
	inline int left(int i) { return i << 1; }
	inline int right(int i) { return i << 1 | 1; }

	void heapify(int i) {
		int l = left(i), r = right(i), x;

		x = (l < vec.size() && compare(vec[l], vec[i])) ? l : i;
		x = (r < vec.size() && compare(vec[r], vec[x])) ? r : x;
		if (x != i) {
			swap(vec[x], vec[i]);
			heapify(x);
		}
	}

	void replace(int i, int key) {
		vec[i] = key;
		while (i > 1 && !compare(vec[parent(i)], vec[i])) {
			swap(vec[parent(i)], vec[i]);
			i = parent(i);
		}
	}

public:
	PQ(bool (*compare)(int x, int y)) : compare(compare) {
		vec.emplace_back(0);			// dummy node
	}

	void push(int x) {
		vec.emplace_back(0);
		replace(vec.size() - 1, x);
	}

	int pop() {
		int x;

		if (vec.size() == 1) {
			return 0;
		}
		x = vec[1];
		vec[1] = vec.back();
		vec.pop_back();
		heapify(1);

		return x;
	}
};

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

bool __less__(int x, int y) {
	return x < y;
}

int main() {
	PQ pq(__less__);

	setup();
	cin >> n;
	while (n--) {
		int x;

		cin >> x;
		if (x != 0) {
			pq.push(x);
		} else {
			cout << pq.pop() << "\n";
		}
	}
	return 0;
}

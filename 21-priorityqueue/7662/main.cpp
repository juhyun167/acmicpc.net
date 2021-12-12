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

bool __greater(int x, int y);
bool __less(int x, int y);

struct Node {
	int key, idx;
	Node *pair;

	Node(int x) : key(x) {
		idx = 0;
		pair = NULL;
	}
};

class DPQ {
	vector<Node *> vec;		// descending
	vector<Node *> vec2;	// ascending
	
private:
	inline int parent(int i) { return i >> 1; }
	inline int left(int i) { return i << 1; }
	inline int right(int i) { return i << 1 | 1; }

	void heapify(vector<Node *> &vec, int i,
					bool (*compare)(int x, int y)) {
		int l = left(i), r = right(i), x;

		x = (l < vec.size() && compare(vec[l]->key, vec[i]->key))
				? l : i;
		x = (r < vec.size() && compare(vec[r]->key, vec[x]->key))
				? r : x;
		if (x != i) {
			// update index before actual swap
			vec[x]->idx = i;
			vec[i]->idx = x;

			swap(vec[x], vec[i]);
			heapify(vec, x, compare);
		}
	}

	void replace(vector<Node *> &vec, int i, Node *newnode,
					bool (*compare)(int x, int y)) {
		vec[i]->idx = i;			// initial index of newnode

		while (i > 1 && !compare(vec[parent(i)]->key, vec[i]->key)) {
			// update index before actual swap
			vec[parent(i)]->idx = i;
			vec[i]->idx = parent(i);

			swap(vec[parent(i)], vec[i]);
			i = parent(i);
		}
	}

public:
	DPQ() {
		vec.emplace_back(new Node(0));
		vec2.emplace_back(new Node(0));
	}

	~DPQ() {
		vector<Node *>::iterator iter;
		for (iter = vec.begin(); iter != vec.end(); iter++) { delete *iter; }
		for (iter = vec2.begin(); iter != vec2.end(); iter++) { delete *iter; }
	}

	void push(int x) {
		Node *newnode = new Node(x);
		Node *newnode2 = new Node(x);

		vec.emplace_back(newnode);
		vec2.emplace_back(newnode2);

		replace(vec, vec.size() - 1, newnode, __greater);
		replace(vec2, vec2.size() - 1, newnode2, __less);

		newnode->pair = newnode2;
		newnode2->pair = newnode;
	}

	int pop_front() {
		int x, idx, pidx;
		Node *pair;

		if (vec.size() == 1) {
			return 0;
		}
		// deallocate node to be popped
		x = vec[1]->key;
		idx = vec[1]->idx;
		pair = vec[1]->pair;
		delete vec[1];

		// restore heap property of the original vector
		if (idx != vec.size() - 1) {
			vec[1] = vec.back();
			vec[1]->idx = 1;
			vec.pop_back();
			heapify(vec, 1, __greater);
		} else {
			vec.pop_back();
		}

		// deallocate node from the pair vector
		pidx = pair->idx;
		delete pair;

		// restore heap propery of the pair vector
		if (pidx != vec2.size() - 1) {
			vec2[pidx] = vec2.back();
			vec2[pidx]->idx = pidx;
			vec2.pop_back();
			replace(vec2, pidx, vec2[pidx], __less);
		} else {
			vec2.pop_back();
		}
		
		return x;
	}

	int pop_back() {
		int x, idx, pidx;
		Node *pair;

		if (vec2.size() == 1) {
			return 0;
		}
		// deallocate node to be popped
		x = vec2[1]->key;
		idx = vec2[1]->idx;
		pair = vec2[1]->pair;
		delete vec2[1];

		// restore heap property of the original vector
		if (idx != vec.size() - 1) {
			vec2[1] = vec2.back();
			vec2[1]->idx = 1;
			vec2.pop_back();
			heapify(vec2, 1, __less);
		} else {
			vec2.pop_back();
		}

		// deallocate node from the pair vector
		pidx = pair->idx;
		delete pair;

		// restore heap propery of the pair vector
		if (pidx != vec.size() - 1) {
			vec[pidx] = vec.back();
			vec[pidx]->idx = pidx;
			vec.pop_back();
			replace(vec, pidx, vec[pidx], __greater);
		} else {
			vec.pop_back();
		}
		
		return x;
	}
	
	int peek_front() {
		if (vec.size() == 1) {
			return 0;
		}
		
		return vec[1]->key;
	}

	int peek_back() {
		if (vec2.size() == 1) {
			return 0;
		}
		
		return vec2[1]->key;
	}

	int size() { return vec.size() - 1; }

	// debug
	void print() {
		vector<Node *>::iterator iter;
		
		cout << "dpq.vec\n";
		for (iter = vec.begin(); iter != vec.end(); iter++) {
			cout << "[" << (*iter)->idx << "] " << (*iter)->key << "\n";
		}
		cout << "dpq.vec2\n";
		for (iter = vec2.begin(); iter != vec2.end(); iter++) {
			cout << "[" << (*iter)->idx << "] " << (*iter)->key << "\n";
		}
	}
};

bool __greater(int x, int y) { return x > y; }
bool __less(int x, int y) { return x < y; }

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

int main() {
	setup();
	cin >> t;
	while (t--) {
		DPQ dpq;
		int x;
		char c;

		cin >> n;
		while (n--) {
			cin >> c >> x;
			switch (c) {
				case 'I':
					dpq.push(x);
					break;
				case 'D':
					if (x == 1) {
						dpq.pop_front();
					} else {
						dpq.pop_back();
					}
					break;
				default:
					break;
			}
		}

		if (dpq.size() == 0) {
			cout << "EMPTY\n";
		} else {
			cout << dpq.peek_front() << " " << dpq.peek_back() << "\n";
		}
	}

	return 0;
}

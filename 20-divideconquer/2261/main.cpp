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

unsigned long long m, n, t, k;

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

struct Coord {
	int x, y;

	Coord(int x, int y) : x(x), y(y) {}
};

bool compare_x(Coord *l, Coord *r) {
	return l->x < r->x;
}

bool compare_y(Coord *l, Coord *r) {
	return l->y < r->y;
}

int dist(Coord *a, Coord *b) {
	return (a->x - b->x) * (a->x - b->x) + 
			(a->y - b->y) * (a->y - b->y);
}

int bruteforce(vector<Coord *> &vec) {
	int __min = INT_MAX;

	for (int i = 0; i < vec.size(); i++) {
		for (int j = i + 1; j < vec.size(); j++) {
			__min = min(__min, dist(vec[i], vec[j]));
		}
	}
	return __min;
}

int merge(vector<Coord *> strip, int d) {
	int __min = d;

	for (int i = 0; i < strip.size(); i++) {
		for (int j = i + 1; j < strip.size(); j++) {
			if ((strip[j]->y - strip[i]->y) * 
				(strip[j]->y - strip[i]->y) < __min) {
				__min = min(__min, dist(strip[i], strip[j]));
			} else {
				break;
			}
		}
	}
	return __min;
}

int split(vector<Coord *> &vec_x, vector<Coord *> &vec_y) {
	vector<Coord *> left_x, left_y;
	vector<Coord *> right_x, right_y;
	vector<Coord *> strip;
	Coord *mid;
	int d, min_l = INT_MAX, min_r = INT_MAX;

	// base case
	if (vec_x.size() <= 3) {
		return bruteforce(vec_x);
	}

	// construct left_x, left_y and right_x, right_y
	mid = vec_x[vec_x.size() / 2];
	for (Coord *c : vec_x) {
		if (c->x < mid->x) {
			left_x.emplace_back(c);
		} else {
			right_x.emplace_back(c);
		}
	}
	for (Coord *c : vec_y) {
		if (c->x < mid->x) {
			left_y.emplace_back(c);
		} else {
			right_y.emplace_back(c);
		}
	}
	
	// recursive call
	if (left_x.size() >= 2 && right_x.size() >= 2) {
		min_l = split(left_x, left_y);
		min_r = split(right_x, right_y);
	}
	d = min(min_l, min_r);

	// construct strip 
	for (Coord *c : vec_y) {
		if (abs(c->x - mid->x) < d) {
			strip.emplace_back(c);
		}
	}

	// merge
	return merge(strip, d);
}

struct pair_hash {
	inline size_t operator()(const pair<int, int> &v) const {
		return v.first * 10007 + v.second;
	}
};

int main() {
	vector<Coord *> vec_x, vec_y;
	unordered_set<pair<int, int>, pair_hash> us;
	
	setup();
	cin >> n;
	for (int i = 0; i < n; i++) {
		Coord *c;
		int x, y;

		cin >> x >> y;
		if (us.find(make_pair(x, y)) == us.end()) {
			us.insert(make_pair(x, y));
			c = new Coord(x, y);
			vec_x.emplace_back(c);
			vec_y.emplace_back(c);
		}
	}
	sort(vec_x.begin(), vec_x.end(), compare_x);	// sorted in x coordinate
	sort(vec_y.begin(), vec_y.end(), compare_y);	// sorted in y coordinate
	
	if (vec_x.size() == 1) {
		cout << "0\n";
	} else {
		cout << split(vec_x, vec_y) << "\n";
	}
	return 0;
}

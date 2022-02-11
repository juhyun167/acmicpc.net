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
#include <iomanip>
using namespace std;

#define MAX		100000

unsigned long long m, n, t;

class Schedule {
public:
	int start, end;
	Schedule(int start, int end) : start(start), end(end)
	{}

	bool operator<(Schedule &other) {
		if (end == other.end) {
			return start < other.start;
		}
		return end < other.end;
	}
};
vector<Schedule> v;

void setup() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fixed;
    cout << setprecision(10);
}

int main() {
	int cnt = 1, curEnd;

	setup();
	cin >> n;
	for (int i = 0; i < n; i++) {
		int start, end;

		cin >> start >> end;
		v.emplace_back(Schedule(start, end));
	}
	sort(v.begin(), v.end());
	curEnd = v[0].end;
	for (int i = 1; i < n; i++) {
		if (v[i].start >= curEnd) {
			curEnd = v[i].end;
			cnt += 1;
		}
	}
	cout << cnt << "\n";
	return 0;
}

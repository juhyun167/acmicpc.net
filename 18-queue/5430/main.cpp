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

template<typename Out>
void split(const string &s, char delim, Out result) {
    stringstream ss(s);
    string item;

    while (getline(ss, item, delim)) {
        *(result++) = item;
    }
}

vector<string> split(const string &s, const char delim) {
    vector<string> elems;

    split(s, delim, back_inserter(elems));
    return elems;
}

void print(deque<int> &dq) {
	cout << "[";
	while (!dq.empty()) {
		cout << dq.front();
		if (dq.size() != 1) {
			cout << ",";
		}
		dq.pop_front();
	}
	cout << "]\n";
}

int main() {
	setup();
	cin >> t;
	while (t--) {
		string f, s;
		vector<string> v;
		deque<int> dq, rdq;
		bool revmode = false, error = false;

		// input parsing
		cin >> f >> n >> s;
		s = s.substr(1, s.length() - 2);
		v = split(s, ',');
		for (const string &s : v) {
			dq.push_back(stoi(s));
		}
		rdq = dq;
		reverse(rdq.begin(), rdq.end());

		// command execution
		for (int i = 0; i < f.length(); i++) {
			if (f[i] == 'R') {
				revmode = !revmode;
			} else {
				if (dq.size() == 0) {
					error = true;
					break;
				}
				if (!revmode) {
					dq.pop_front();
					rdq.pop_back();
				} else {
					rdq.pop_front();
					dq.pop_back();
				}
			}
		}

		// output
		if (error) {
			cout << "error\n";
		} else {
			if (revmode) {
				print(rdq);
			} else {
				print(dq);
			}
		}
	}
	return 0;
}

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
#include <list>
#include <utility>
#include <iomanip>
using namespace std;

#define MAX     (100 + 1)

int m, n, t, k, v;

void setup() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fixed;
    cout << setprecision(10);
}

inline bool is_num(char c) {
    return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}


int main() {
    string s, result;
	stack<char> op;
    unordered_map<char, int> pri({
                { '+', 1 }, { '-', 1 },
                { '*', 2 }, { '/', 2 },
            });

    cin >> s;
	for (const char& c : s) {
		if (is_num(c)) {
			result += c;
		} else if (c == '(') {
			op.push(c);
		} else if (c == ')') {
			while (!op.empty() && op.top() != '(') {
				result += op.top();
				op.pop();
			}
			op.pop();
		} else {
			if (c == '*' || c == '/') {
				while (!op.empty()
						&& (op.top() == '*' || op.top() == '/')) {
					result += op.top();
					op.pop();
				}

			} else {
				while (!op.empty() && op.top() != '(') {
					result += op.top();
					op.pop();
				}
			}
			op.push(c);
		}
	}
	while (!op.empty()) {
		result += op.top();
		op.pop();
	}
	cout << result << "\n";

	return 0;
}

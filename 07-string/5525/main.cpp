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
#include <iomanip>
using namespace std;

#define MAX		(1000000 + 1)

uint64_t m, n, t, k, v;
int arr[MAX];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

int main() {
	string s, p;
	int cnt = 0, num = 0;

	setup();
	cin >> n >> m >> s;

	for (int i = 0; i < m - 2; i++) {
		if (s[i] == 'I' && s[i + 1] == 'O'
				&& s[i + 2] == 'I') {
			num++;
			if (num == n) {
				cnt++;
				num--;
			}
			i++;
		} else {
			num = 0;
		}
	}
	cout << cnt << "\n";

	return 0;
}

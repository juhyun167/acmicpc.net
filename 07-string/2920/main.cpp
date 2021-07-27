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
	string s;

	setup();
	getline(cin, s);
	if (s == "1 2 3 4 5 6 7 8") {
		cout << "ascending\n";
	} else if (s == "8 7 6 5 4 3 2 1") {
		cout << "descending\n";
	} else {
		cout << "mixed\n";
	}
	return 0;
}

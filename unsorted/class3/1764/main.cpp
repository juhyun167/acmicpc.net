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
	unordered_set<string> us;
	set<string> os;
	string s;

	setup();
	cin >> n >> m;
	while (n--) {
		cin >> s;
		us.insert(s);
	}
	while (m--) {
		cin >> s;
		if (us.find(s) != us.end()) {
			os.insert(s);
		}
	}
	
	set<string>::iterator iter;
	cout << os.size() << "\n";
	for (iter = os.begin(); iter != os.end(); iter++) {
		cout << *iter << "\n";
	}

	return 0;
}

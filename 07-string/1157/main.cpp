#include <iostream>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;

#define MAX		1000000

int n, t, arr[MAX + 1];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

int main() {
	int max = -1, maxcnt = 0, most;
	string s;

	setup();
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'a') {
			arr[s[i] - ('a' - 'A')] += 1;
		} else {
			arr[s[i]] += 1;
		}
	}
	for (int i = 'A'; i <= 'Z'; i++) {
		max = (arr[i] > max) ? arr[i] : max;
	}
	for (int i = 'A'; i <= 'Z'; i++) {
		if (arr[i] == max) {
			most = i;
			maxcnt += 1;
		}
	}
	if (maxcnt > 1) {
		printf("?\n");
	} else {
		printf("%c\n", most);
	}
	return 0;
}

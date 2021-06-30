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
	setup();
	cin >> t;

	for (int i = 0; i < t; i++) {
		string s;
		int r;

		cin >> r >> s;
		for (int j = 0; j < s.length(); j++) {
			for (int k = 0; k < r; k++) {
				printf("%c", s[j]);
			}
		}
		printf("\n");
	}
	return 0;
}

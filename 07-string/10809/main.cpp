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
	string s;

	setup();
	cin >> s;
	fill_n(arr, 'z' + 1, -1);
	for (int i = 0; i < s.length(); i++) {
		if (arr[s[i]] == -1) {
			arr[s[i]] = i;
		}
	}
	for (int i = 'a'; i <= 'z'; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}

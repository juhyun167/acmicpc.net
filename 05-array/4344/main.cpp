#include <iostream>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;

#define MAX		1000000

int n, t, arr[MAX];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(3);
}

int main() {
	setup();
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, cnt = 0;
		double avg;
		
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> arr[j];
		}
		avg = (double) accumulate(arr, arr + n, 0) / n;
		for (int j = 0; j < n; j++) {
			if (arr[j] > avg) {
				cnt += 1;
			}
		}
		cout << (double) cnt / n * 100 << "%\n";
	}
	return 0;
}

#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

#define MAX		1000000

int n, t, arr[MAX];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	setup();
	cin >> n;
	for (int i = 0; i < n; i++) {
		int score = 0, sum = 0;
		string s;
		
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == 'O') {
				sum += 1;
				score += sum;
			} else {
				sum = 0;
			}
		}
		cout << score << "\n";
	}
	return 0;
}

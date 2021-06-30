#include <iostream>
#include <sstream>
#include <cctype>
#include <locale>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <vector>
#include <iomanip>
using namespace std;

#define MAX		2200

unsigned long long m, n, t;
bool arr[MAX + 1][MAX + 1];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

void draw(int y, int x, int n) {
	if (n == 1) {
		arr[y][x] = true;
		return;
	}
	for (int i = y - n / 3; i <= y + n / 3; i += n / 3) {
		for (int j = x - n / 3; j <= x + n / 3; j += n / 3) {
			if (!(i == y && j == x)) {
				draw(i, j, n / 3);
			}
		}
	}
}

int main() {
	setup();
	cin >> n;
	draw(n / 2, n / 2, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j]) {
				printf("*");
			} else {
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}

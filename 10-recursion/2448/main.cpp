#include <iostream>
#include <sstream>
#include <cctype>
#include <locale>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <climits>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
using namespace std;

#define MAX		10000

unsigned long long m, n, t;
bool arr[MAX + 1][MAX + 1];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

void draw(int y, int x, int k) {
	int y1, y2, y3, x1, x2, x3;

	if (k == 0) {
		int dy[8] = { -1, 0, 0, 1, 1, 1, 1, 1 };
		int dx[8] = { -1, -1, 1, -1, 0, 1, 2, 3 };

		for (int i = 0; i < 8; i++) {
			arr[y + dy[i]][x + dx[i]] = true;
		}
		return;
	}
	int dy[3], dx[3];

	if (k == 1) {
		dy[0] = -4, dy[1] = dy[2] = -1;
		dx[0] = dx[1] = -4, dx[2] = 2;
	} else {
		dy[0] = -3 * pow(2, k - 1), dy[1] = dy[2] = 0;
		dx[0] = dx[1] = dy[0], dx[2] = -dy[0];
	}
	for (int i = 0; i < 3; i++) {
		draw(y + dy[i], x + dx[i], k - 1);
	}
}

void print(int l, int size) {
	int pad = (size - (2 * l + 1)) / 2;

	for (int i = 0; i < pad; i++) {
		printf(" ");
	}
	for (int j = 0; j < 2 * l + 1; j++) {
		if (arr[l][j]) {
			printf("*");
		} else {
			printf(" ");
		}
	}
	for (int i = 0; i < pad; i++) {
		printf(" ");
	}
	printf("\n");
}

int main() {
	int k, size;

	setup();
	cin >> n;
	k = (int) log2(n / 3);
	if (k == 0) {
		draw(n / 2, n / 2, k);
	} else {
		draw(n - 1, n - 1, k);
	}
	
	size = 2 * n - 1;
	for (int l = 0; l < n; l++) {
		print(l, size);
	}
	return 0;
}

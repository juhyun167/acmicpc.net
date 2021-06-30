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

#define MAX		8

unsigned long long m, n, t;
int arr[MAX + 1];
bool visited[MAX + 1];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

void backtrack(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[k] = i;
			backtrack(k + 1);
			visited[i] = false;
		}
	}
}

int main() {
	setup();
	cin >> n >> m;
	backtrack(0);
	return 0;
}

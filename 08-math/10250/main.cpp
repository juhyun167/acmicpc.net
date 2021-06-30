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

#define MAX		1000000

unsigned long long n, t;
int arr[MAX + 1];

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
		int h, w, n;
		
		cin >> h >> w >> n;
		printf("%d", (n - 1) % h + 1);
		printf("%02d\n", (n - 1) / h + 1);
	}
	return 0;
}

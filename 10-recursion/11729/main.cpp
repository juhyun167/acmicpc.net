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

unsigned long long m, n, t;
int arr[MAX + 1];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

void move(int from, int to, int through, int n) {
	if (n == 1) {
		printf("%d %d\n", from, to);
		return;
	}
	move(from, through, to, n - 1);
	printf("%d %d\n", from, to);
	move(through, to, from, n - 1);
}

int main() {
	setup();
	scanf("%d", &n);
	printf("%d\n", (int) pow(2, n) - 1);
	move(1, 3, 2, n);
	return 0;
}

#include <iostream>
using namespace std;

int n;

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	setup();
	cin >> n;

	for (int i = 1; i <= 9; i++) {
		printf("%d * %d = %d\n", n, i, n * i);
	}
	return 0;
}

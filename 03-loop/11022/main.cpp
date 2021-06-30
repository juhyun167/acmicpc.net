#include <iostream>
using namespace std;

int n, t;

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	setup();
	cin >> t;

	for (int i = 1; i <= t; i++) {
		int a, b;
		
		cin >> a >> b;
		printf("Case #%d: %d + %d = %d\n", i, a, b, a + b);
	}
	return 0;
}

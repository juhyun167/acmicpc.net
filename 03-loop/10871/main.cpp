#include <iostream>
using namespace std;

#define MAX		10000

int n, t, arr[MAX];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	int x;

	setup();
	cin >> n >> x;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] < x) {
			printf("%d ", arr[i]);
		}
	}
	printf("\n");
	return 0;
}

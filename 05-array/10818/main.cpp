#include <iostream>
#include <algorithm>
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
		cin >> arr[i];
	}
	printf("%d %d\n",
		*min_element(arr, arr + n), *max_element(arr, arr + n));
	return 0;
}

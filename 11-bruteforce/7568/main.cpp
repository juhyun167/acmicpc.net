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

class Mass {
public:
	int weight;
	int height;

	bool operator<(Mass &other) {
		return weight < other.weight && height < other.height;
	}
};

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

int main() {
	vector<Mass> v;

	setup();
	cin >> n;
	for (int i = 0; i < n; i++) {
		Mass m;
		
		cin >> m.weight >> m.height;
		v.emplace_back(m);
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (v[i] < v[j]) {
				arr[i]++;
			} else if (v[j] < v[i]) {
				arr[j]++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] + 1 << " ";
	}
	cout << "\n";
	return 0;
}

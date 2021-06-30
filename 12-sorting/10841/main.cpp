#include <iostream>
#include <sstream>
#include <cctype>
#include <locale>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <climits>
#include <vector>
#include <iomanip>
using namespace std;

#define MAX		1000000

unsigned long long m, n, t;
int arr[MAX + 1];

class Member {
public:
	int age, idx;
	string name;

	Member(int idx) : idx(idx) {}

	bool operator<(Member &other) {
		if (age == other.age) {
			return idx < other.idx;
		} else {
			return age < other.age;
		}
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
	vector<Member> v;

	setup();
	cin >> n;
	for (int i = 0; i < n; i++) {
		Member m(i);

		cin >> m.age >> m.name;
		v.emplace_back(m);
	}
	sort(v.begin(), v.end());
	for (auto it = v.begin(); it != v.end(); it++) {
		Member m = (Member) *it;

		cout << m.age << " " << m.name << "\n";
	}
	return 0;
}

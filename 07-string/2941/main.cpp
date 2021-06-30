#include <iostream>
#include <sstream>
#include <cctype>
#include <locale>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iomanip>
using namespace std;

#define MAX		1000000

int n, t, arr[MAX + 1];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

int main() {
	string s;
	int cnt = 0;

	setup();
	cin >> s;

	for (int i = 0; i < s.length(); ) {
		if (s[i] == 'c' && s[i + 1] == '=' ||
			s[i] == 'c' && s[i + 1] == '-' ||
			s[i] == 'd' && s[i + 1] == '-' ||
			s[i] == 'l' && s[i + 1] == 'j' ||
			s[i] == 'n' && s[i + 1] == 'j' ||
			s[i] == 's' && s[i + 1] == '=' ||
			s[i] == 'z' && s[i + 1] == '='
		) {
			i += 2;
		} else if (s[i] == 'd' && s[i + 1] == 'z' && s[i + 2] == '=') {
			i += 3;
		} else {
			i++;
		}
		cnt += 1;
	}
	cout << cnt << "\n";
	return 0;
}

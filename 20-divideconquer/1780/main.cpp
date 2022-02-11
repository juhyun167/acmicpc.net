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
#include <tuple>
#include <stack>
#include <queue>
#include <iomanip>
using namespace std;

#define MAX     3000

unsigned long long m, n, t;
int arr[MAX + 1][MAX + 1], cnt = 0, cnt2 = 0, cnt3 = 0;

void setup() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fixed;
    cout << setprecision(10);
}

bool check(int k, int y, int x) {
    int type = -2;

    for (int i = y; i < y + k; i++) {
        for (int j = x; j < x + k; j++) {
            if (type == -2) {
                type = arr[i][j];
            } else if (type != arr[i][j]) {
                return false;
            }
        }
    }
    if (type == -1) {
        cnt++;
    } else if (type == 0) {
        cnt2++;
    } else {
		cnt3++;
	}
    return true;
}

void recursion(int k, int y, int x) {
    if (k == 0) {
        return;
    }
    if (!check(k, y, x)) {
        recursion(k / 3, y, x);
        recursion(k / 3, y + k / 3, x);
		recursion(k / 3, y + k / 3 * 2, x);
		recursion(k / 3, y, x + k / 3);
        recursion(k / 3, y + k / 3, x + k / 3);
		recursion(k / 3, y + k / 3 * 2, x + k / 3);
		recursion(k / 3, y, x + k / 3 * 2);
        recursion(k / 3, y + k / 3, x + k / 3 * 2);
		recursion(k / 3, y + k / 3 * 2, x + k / 3 * 2);
    }
}

int main() {
    setup();
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    recursion(n, 0, 0);
    cout << cnt << "\n" << cnt2 << "\n" << cnt3 << "\n";
    return 0;
}

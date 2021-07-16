#include <iostream>
#include <sstream>
#include <cctype>
#include <cstdint>
#include <locale>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <climits>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <stack>
#include <queue>
#include <iomanip>
using namespace std;

#define MAX        1000000

uint64_t m, n, t, k;
int arr[MAX + 1];

void setup() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fixed;
    cout << setprecision(10);
}

int main() {
    vector<int> tail;

    setup();
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    tail.emplace_back(arr[0]);
    for (int i = 1; i < n; i++) {
        auto iter = lower_bound(tail.begin(), tail.end(), arr[i]);

        if (iter == tail.end()) {
            tail.emplace_back(arr[i]);
        } else {
            *iter = arr[i];
        }
    }
    cout << tail.size() << "\n";
    return 0;
}
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

#define MAX    1000000

uint64_t m, n, t, k;
int arr[MAX + 1][2], dp[MAX + 1][2];

void setup() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   cout << fixed;
   cout << setprecision(10);
}

int main() {
   setup();
   cin >> t;
   while (t--) {
      cin >> n;
      for (int j = 0; j < 2; j++) {
         for (int i = 1; i <= n; i++) {
            cin >> arr[i][j];
         }
      }
      
      dp[1][0] = arr[1][0], dp[1][1] = arr[1][1];
      for (int i = 2; i <= n; i++) {
         dp[i][0] = arr[i][0] + max({dp[i - 1][1], dp[i - 2][0], dp[i - 2][1]});
         dp[i][1] = arr[i][1] +max({dp[i - 1][0], dp[i - 2][0], dp[i - 2][1]});
      }
      cout << max({dp[n - 1][0], dp[n - 1][1], dp[n][0], dp[n][1]}) << "\n";
   }
   return 0;
}

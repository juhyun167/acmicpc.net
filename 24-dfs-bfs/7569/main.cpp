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
#include <list>
#include <iomanip>
using namespace std;

#define MAX     (100 + 1)

uint64_t m, n, t, k, v, h;
int arr[MAX][MAX][MAX];

void setup() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fixed;
    cout << setprecision(10);
}

inline bool check(int z, int y, int x) {
    return 0 <= z && z < h && 0 <= y && y < n
				&& 0 <= x && x < m;
}

void bfs(queue<int> &qz, queue<int> &qy, queue<int> &qx) {
    const int dz[6] = { 0, 0, 0, 0, 1, -1 };
    const int dy[6] = { 0, 0, 1, -1, 0, 0 };
    const int dx[6] = { 1, -1, 0, 0, 0, 0 };

    while (!qz.empty()) {
        int uz = qz.front();
        int uy = qy.front();
        int ux = qx.front();

		qz.pop();
		qy.pop();
		qx.pop();
        for (int i = 0; i < 6; i++) {
            int wz = uz + dz[i];
            int wy = uy + dy[i];
			int wx = ux + dx[i];

            if (check(wz, wy, wx) && (
                    arr[wz][wy][wx] == 0 
                )
            ) {
                arr[wz][wy][wx] = arr[uz][uy][ux] + 1;
                qz.push(wz);
                qy.push(wy);
                qx.push(wx);
            }
        }
    }
}

int main() {
	queue<int> qz, qy, qx;

    setup();
    cin >> m >> n >> h;

    // clear 0s in arr
    fill_n(&arr[0][0][0], MAX * MAX * MAX, -2);

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> arr[i][j][k];
				if (arr[i][j][k] == 1) {
					qz.push(i);
					qy.push(j);
					qx.push(k);
				}
			}
		}
	}

    // case when bfs is not needed
    if (find(&arr[0][0][0], &arr[MAX][0][0], 0)
            == &arr[MAX][0][0]) {
        cout << "0\n";
        return 0;
    }

    bfs(qz, qy, qx);

    // case when unreachable node is present
    if (find(&arr[0][0][0], &arr[MAX][0][0], 0)
            != &arr[MAX][0][0]) {
        cout << "-1\n";
        return 0;
    }

    cout << *max_element(&arr[0][0][0],
				&arr[MAX][0][0]) - 1 << "\n";

    return 0;
}

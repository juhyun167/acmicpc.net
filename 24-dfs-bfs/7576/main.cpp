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

#define MAX     (1000 + 1)

uint64_t m, n, t, k, v;
int arr[MAX][MAX];

// circular queue using array
class Queue {
    short arr[MAX * MAX];
    int head = 0, tail = 0, length = MAX * MAX;

public:
    void push(short x) {
        arr[tail] = x;
        if (tail == length - 1) { tail = 0; }
        else { tail++; }
    }

    short pop() {
        short x = arr[head];

        if (head == length - 1) { head = 0; }
        else { head++; }

        return x;
    }

    bool empty() {
        return head == tail;
    }
};

void setup() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fixed;
    cout << setprecision(10);
}

inline bool check(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

void bfs(Queue &qy, Queue &qx) {
    const int dy[4] = { 0, 0, 1, -1 };
    const int dx[4] = { 1, -1, 0, 0 };

    while (!qy.empty()) {
        int uy = qy.pop();
        int ux = qx.pop();

        for (int i = 0; i < 4; i++) {
            int wy = uy + dy[i];
			int wx = ux + dx[i];

            if (check(wy, wx) && (
                    arr[wy][wx] == 0 
                )
            ) {
                arr[wy][wx] = arr[uy][ux] + 1;
                qy.push(wy);
                qx.push(wx);
            }
        }
    }
}

int main() {
	Queue qy, qx;

    setup();
    cin >> m >> n;

    // clear 0s in arr
    fill_n(&arr[0][0], MAX * MAX, -2);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                qy.push(i);
                qx.push(j);
            }
        }
    }

    // case when bfs is not needed
    if (find(&arr[0][0], &arr[MAX][0], 0)
            == &arr[MAX][0]) {
        cout << "0\n";
        return 0;
    }

    bfs(qy, qx);

    // case when unreachable node is present
    if (find(&arr[0][0], &arr[MAX][0], 0)
            != &arr[MAX][0]) {
        cout << "-1\n";
        return 0;
    }

    cout << *max_element(&arr[0][0], &arr[MAX][0]) - 1 << "\n";

    return 0;
}

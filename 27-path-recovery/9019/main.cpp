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

#define MAX		(10000)

uint64_t m, n, t, k, v;
int parent[MAX];
bool visited[MAX];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

int dbl(int n) {
	return (n * 2) % MAX;
}

int sub(int n) {
	return (n + MAX - 1) % MAX;
}

int shl(int n) {
	return (n % (MAX / 10) * 10) + n / (MAX / 10);
}

int shr(int n) {
	return (n / 10) + (n % 10) * (MAX / 10);
}

int (*alu[4])(int) = { dbl, sub, shl, shr };

void search(int a, int b) {
	queue<int> q;

	visited[a] = true;
	q.push(a);
	while (!q.empty()) {
		int u = q.front();

		q.pop();
		if (u == b) {
			break;
		}
		for (int i = 0; i < 4; i++) {
			int w = alu[i](u);

			if (!visited[w]) {
				visited[w] = true;
				parent[w] = u;
				q.push(w);
			}
		}
	}
}

string print(int x, int a) {
	int p = parent[x];
	const char aluop[4] = { 'D', 'S', 'L', 'R' };
	char curop;

	for (int i = 0; i < 4; i++) {
		if (alu[i](p) == x) {
			curop = aluop[i];
			break;
		}
	}
	if (p == a) {
		return string() + curop;
	}
	return print(parent[x], a) + curop;
}

int main() {
	setup();
	cin >> t;
	while (t--) {
		int a, b;

		fill_n(&parent[0], MAX, 0);
		fill_n(&visited[0], MAX, false);

		cin >> a >> b;
		search(a, b);
		cout << print(b, a) << "\n";
	}

	return 0;
}

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
#include <iomanip>
using namespace std;

#define MAX     1000000

unsigned long long m, n, t;
int arr[MAX + 1];

void setup() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fixed;
    cout << setprecision(10);
}

template<typename Out>
void split(const string &s, char delim, Out result) {
    stringstream ss(s);
    string item;

    while (getline(ss, item, delim)) {
        *(result++) = item;
    }
}

vector<string> split(const string &s, const char delim) {
    vector<string> elems;

    split(s, delim, back_inserter(elems));
    return elems;
}

int main() {
    setup();
    cin >> t;
    while (t--) {
        unordered_map<string, int> umap;
        int result = 1;

        cin >> n;
        for (int i = 0; i < n; i++) {
            string s;
            vector<string> v;

            cin.ignore();
            getline(cin, s);
            v = split(s, ' ');
            if (umap.find(v[1]) == umap.end()) {
                umap.insert(make_pair(v[1], 1));
            } else {
                umap[v[1]] += 1;
            }
        }
        unordered_map<string, int>::iterator it;
        for (it = umap.begin(); it != umap.end(); it++) {
            result *= it->second + 1;
        }
        result -= 1;
        cout << result << "\n";
    }
    return 0;
}

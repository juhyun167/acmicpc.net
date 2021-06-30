#include <iostream>
#include <sstream>
#include <cctype>
#include <locale>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iomanip>
using namespace std;

#define MAX             1000000

int n, t, arr[MAX + 1];

void setup() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fixed;
    cout << setprecision(10);
}

static inline void ltrim(string &s) {
	s.erase(s.begin(), find_if(
		s.begin(), s.end(), [](unsigned char ch) {
			return !isspace(ch);
		}
	));
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
    string s;
    vector<string> v;

    setup();
    getline(cin, s);
	ltrim(s);
    v = split(s, ' ');
    cout << v.size() << "\n";
    return 0;
}
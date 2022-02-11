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

#define MAX		1000000

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

struct Node {
	int data;
	Node *prev, *next;

	Node(int x) : data(x) {
		prev = NULL;
		next = NULL;
	}
};

class Stack {
	int __size;
	Node *head;

public:
	Stack() : __size(0) {
		head = new Node(0);
	}

	void push(int x) {
		Node *newnode = new Node(x);

		newnode->prev = head;
		head->next = newnode;
		head = newnode;
		__size++;
	}

	void pop() {
		Node *delnode = head;
		int data = delnode->data;

		if (__size == 0) {
			cout << "-1\n";
		} else {
			head = delnode->prev;
			head->next = NULL;
			delete delnode;
			__size--;
			cout << data << "\n";
		}
	}

	void size() {
		cout << __size << "\n";
	}

	void empty() {
		if (__size == 0) {
			cout << "1\n";
		} else {
			cout << "0\n";
		}
	}

	void top() {
		if (__size == 0) {
			cout << "-1\n";
		} else {
			cout << head->data << "\n";
		}
	}
};

int main() {
	Stack stack;

	setup();
	cin >> n;
	cin.ignore();
	while (n--) {
		string s;
		vector<string> v;

		getline(cin, s);
		v = split(s, ' ');
		if (v[0] == "push") {
			stack.push(stoi(v[1]));
		} else if (v[0] == "pop") {
			stack.pop();
		} else if (v[0] == "size") {
			stack.size();
		} else if (v[0] == "empty") {
			stack.empty();
		} else {
			stack.top();
		}
	}
	return 0;
}

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

class Queue {
	int __size;
	Node *head, *tail;

public:
	Queue() : __size(0) {
		Node *newnode = new Node(0);
		newnode->prev = newnode->next = newnode;
		head = tail = newnode;
	}

	void push(int x) {
		Node *newnode = new Node(x);

		// insert
		newnode->prev = tail;
		newnode->next = tail->next;
		tail->next->prev = newnode;
		tail->next = newnode;

		tail = newnode;
		__size++;
	}

	void pop() {
		Node *delnode = head->next;
		int data = delnode->data;

		if (__size == 0) {
			cout << "-1\n";
		} else {
			// unlink
			if (tail == delnode) {
				tail = tail->prev;
			}
			head->next = delnode->next;
			delnode->next->prev = head;

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

	void front() {
		if (__size == 0) {
			cout << "-1\n";
		} else {
			cout << head->next->data << "\n";
		}
	}

	void back() {
		if (__size == 0) {
			cout << "-1\n";
		} else {
			cout << tail->data << "\n";
		}
	}
};

int main() {
	Queue queue;

	setup();
	cin >> n;
	cin.ignore();
	while (n--) {
		string s;

		cin >> s;
		if (s[0] == 'p' && s[1] == 'u') {
			int x;

			cin >> x;
			queue.push(x);
		} else if (s[0] == 'p') {
			queue.pop();
		} else if (s[0] == 's') {
			queue.size();
		} else if (s[0] == 'e') {
			queue.empty();
		} else if (s[0] == 'f') {
			queue.front();
		} else {
			queue.back();
		}
	}
	return 0;
}

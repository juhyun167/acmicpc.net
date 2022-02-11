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

struct Node {
    int data;
    Node *prev, *next;

    Node(int x) : data(x) {
        prev = NULL;
        next = NULL;
    }
};

class Deque {
    int __size;
    Node *head, *tail;

public:
    Deque() : __size(0) {
        Node *newnode = new Node(0);
        newnode->prev = newnode->next = newnode;
        head = tail = newnode;
    }

	void push_front(int x) {
		Node *newnode = new Node(x);

		// insert
		newnode->prev = head;
		newnode->next = head->next;
		head->next->prev = newnode;
		head->next = newnode;

		if (head == tail) {
			tail = newnode;
		}
		__size++;
	}

    void push_back(int x) {
        Node *newnode = new Node(x);

        // insert
        newnode->prev = tail;
        newnode->next = tail->next;
        tail->next->prev = newnode;
        tail->next = newnode;

        tail = newnode;
        __size++;
    }

    void pop_front() {
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

	void pop_back() {
		Node *delnode = tail;
		int data = delnode->data;

		if (__size == 0) {
			cout << "-1\n";
		} else {
			// unlink
			tail->prev->next = delnode->next;
			delnode->next->prev = tail->prev;
			tail = delnode->prev;

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
    Deque deque;

    setup();
    cin >> n;
    cin.ignore();
    while (n--) {
        string s;

        cin >> s;
        if (s[0] == 'p' && s[1] == 'u') {
            int x;

            cin >> x;
			if (s[5] == 'f') {
            	deque.push_front(x);
			} else {
				deque.push_back(x);
			}
        } else if (s[0] == 'p') {
            if (s[4] == 'f') {
				deque.pop_front();
			} else {
				deque.pop_back();
			}
        } else if (s[0] == 's') {
            deque.size();
        } else if (s[0] == 'e') {
            deque.empty();
        } else if (s[0] == 'f') {
            deque.front();
        } else {
            deque.back();
        }
    }
    return 0;
}

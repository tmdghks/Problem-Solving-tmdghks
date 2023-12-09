// 10866 덱
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;

int main() {
    ll i, j, n, x;
    cin >> n;
    string tmp;
    deque<ll> dq;
    for (i = 0; i < n; i++) {
        cin >> tmp;
        if (tmp == "push_front") {
            cin >> x;
            dq.push_front(x);
        } else if (tmp == "push_back") {
            cin >> x;
            dq.push_back(x);
        } else if (tmp == "pop_front") {
            if (dq.empty()) {
                cout << "-1\n";
            } else {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        } else if (tmp == "pop_back") {
            if (dq.empty()) {
                cout << "-1\n";
            } else {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        } else if (tmp == "size") {
            cout << dq.size() << '\n';
        } else if (tmp == "empty") {
            if (dq.empty()) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        } else if (tmp == "front") {
            if (dq.empty()) {
                cout << "-1\n";
            } else {
                cout << dq.front() << '\n';
            }
        } else if (tmp == "back") {
            if (dq.empty()) {
                cout << "-1\n";
            } else {
                cout << dq.back() << '\n';
            }
        }
    }
}
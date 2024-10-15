// boj 7662
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<long long>;
using vvll = vector<vector<ll>>;
using ld = long double;
const ll mod = 1000000007;

struct dt {
    ll t;
    ll p;
};

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin >> t;

    while (t--) {
        solve();
    }
}

void solve() {
    priority_queue<ll, vll, greater<ll>> min_heap;
    priority_queue<ll, vll, less<ll>> max_heap;
    map<ll, ll> cnt;

    ll length = 0, query_number;

    char op;
    ll data;
    cin >> query_number;

    for (ll i = 0; i < query_number; ++i) {
        cin >> op >> data;

        if (length == 0) {
            while (!max_heap.empty()) {
                max_heap.pop();
            }

            while (!min_heap.empty()) {
                min_heap.pop();
            }

            cnt.clear();
        }

        if (op == 'I') {
            length++;
            max_heap.push(data);
            min_heap.push(data);
            if (cnt.find(data) == cnt.end()) {
                cnt.insert({data, 1});
            } else {
                cnt[data]++;
            }
        } else {
            if (length == 0) {
                continue;
            }

            length--;
            if (data == 1) {
                while (!max_heap.empty() && cnt[max_heap.top()] == 0) {
                    max_heap.pop();
                }
                cnt[max_heap.top()]--;
                max_heap.pop();
            } else {
                while (!min_heap.empty() && cnt[min_heap.top()] == 0) {
                    min_heap.pop();
                }
                cnt[min_heap.top()]--;
                min_heap.pop();
            }
        }
    }

    while (!max_heap.empty() && cnt[max_heap.top()] == 0) {
        max_heap.pop();
    }

    while (!min_heap.empty() && cnt[min_heap.top()] == 0) {
        min_heap.pop();
    }

    if (length == 0) {
        cout << "EMPTY\n";
    } else {
        cout << max_heap.top() << " " << min_heap.top() << "\n";
    }
}
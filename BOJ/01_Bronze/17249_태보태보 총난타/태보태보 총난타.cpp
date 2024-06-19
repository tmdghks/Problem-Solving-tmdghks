#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

int main() {
    ll t;
    t = 1;
    while (t--) {
        solve();
    }
}

void solve() {
    string input;
    cin >> input;

    ll flag = 0;
    vector<ll> v(2, 0);
    for (char k : input) {
        if (k == '(') {
            flag = 1;
        } else if (k == '@') {
            v[flag]++;
        }
    }

    cout << v[0] << " " << v[1];
}
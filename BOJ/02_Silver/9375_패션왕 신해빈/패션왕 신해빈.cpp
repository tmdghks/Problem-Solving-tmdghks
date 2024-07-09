#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<long long>;
using ld = long double;
const ll mod = 1000000007;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll T;
    cin >> T;
    while (T--) {
        solve();
    }
}

void solve() {
    ll n;
    cin >> n;

    unordered_map<string, ll> um;

    for (int i = 0; i < n; ++i) {
        string str1, str2;
        cin >> str1 >> str2;

        if (um.find(str2) == um.end()) { 
            um[str2] = 1;
        } else {
            um[str2] = um[str2] + 1;
        }
    }

    ll ans = 1;

    for (auto it = um.begin(); it != um.end(); ++it) {
        ans *= (it->second + 1);
    }

    cout << ans - 1 << "\n";
}
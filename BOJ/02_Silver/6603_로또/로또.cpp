#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

void solve();
vll S;

void dfs(int dep, int n, int m, int maxIndex, vector<ll> v) {
    if (dep == m) {
        for (auto num : v) {
            cout << num << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = maxIndex + 1; i < n; i++) {
        // cout << "maxIndex: " << i << '\n';
        v.push_back(S[i]);
        dfs(dep + 1, n, m, i, v);
        v.pop_back();
    }
}   

int main() {
    ll k;
    cin >> k;
    while (k != 0) {
        S.resize(k, 0);
        for (auto& iter : S) cin >> iter;

        dfs(0, k, 6, -1, vll(0));

        cout << '\n';
        cin >> k;
    }
}
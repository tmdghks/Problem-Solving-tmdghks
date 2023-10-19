#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll i, j;

    vector<ll> DP(31, 0);
    DP[0] = 1;
    for (i = 1; i <= 30; i++) {
        for (j = 0; j < i; j++) {
            DP[i] += DP[j] * DP[i - j - 1];
        }
    }

    ll n;
    cin >> n;
    while (n != 0) {
        cout << DP[n] << '\n';
        cin >> n;
    }

}
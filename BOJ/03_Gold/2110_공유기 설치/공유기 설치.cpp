// 2110 공유기 설치
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n, c, i, j, ans;
    cin >> n >> c;

    vector<ll> g(n, 0);
    for (auto &k : g) {
        cin >> k;
    }

    stable_sort(g.begin(), g.end());

    ll low = 0;
    ll top = g[n-1] - g[0];
    ll mid = (low + top) / 2;

    while (low <= top) {
        ll cnt = 1;
        i = 0, j = 0;
        for (i = 1; i < n; i++) {
            if (g[i] - g[j] >= mid) {
                cnt++;
                j = i;
            }
        }

        if (cnt < c) {
            top = mid - 1;
        } else {
            ans = mid;
            low = mid + 1;
        }
        mid = (top + low) / 2;
    }

    cout << ans << '\n';
}
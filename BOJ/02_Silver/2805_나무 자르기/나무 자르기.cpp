// BOJ 2805 나무 자르기
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll high, low, ans = 0;
    int i, j;
    int n, m;
    cin >> n >> m;

    vector<ll> v(n, 0);
    for (i = 0; i < n; i++) {
        cin >> v[i];
    }

    stable_sort(v.begin(), v.end());
    low = 0; high = 1000000000;

    while (low <= high) {
        ll mid = (low + high) / 2;
        ll cnt = 0;
        for (auto a : v) {
            cnt += max((ll)0, a - mid);
        }  
        if (cnt < m) {
            high = mid - 1;
        } else {
            low = mid + 1;
            if (ans < mid) ans = mid;
        }
    }

    cout << ans << '\n';
}
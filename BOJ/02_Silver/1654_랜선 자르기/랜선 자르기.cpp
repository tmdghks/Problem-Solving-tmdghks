// BOJ 1654 랜선자르기
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll high, low, ans = 0;
    int i, j;
    int k, n;
    cin >> k >> n;

    vector<int> v(k, 0);
    for (i = 0; i < k; i++) {
        cin >> v[i];
    }

    stable_sort(v.begin(), v.end());
    low = 1; high = v.back();

    while (low <= high) {
        ll mid = (low + high) / 2;
        ll cnt = 0;
        for (auto a : v) {
            cnt += a / mid;
        }  
        if (cnt < n) {
            high = mid - 1;
        } else {
            low = mid + 1;
            if (ans < mid) ans = mid;
        }
    }

    cout << ans << '\n';
}
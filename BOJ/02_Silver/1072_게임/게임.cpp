// BOJ 1072 게임
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll high, low, ans = __LONG_LONG_MAX__;
    int i, j;
    int x, y, z;
    cin >> x >> y;

    z = int((double) y * 100 / x);

    low = 0; high = __LONG_LONG_MAX__;
    
    if (z >= 99) {
        cout << -1 << '\n';
        return 0;
    }

    while (low <= high) {
        ll mid = (low + high) / 2;

        if (int((double) 100 * (y + mid) / (x + mid)) <= z) {
            low = mid + 1;
        } else {
            high = mid - 1;
            if (ans > mid) ans = mid;
        }
    }


    cout << ans << '\n';
}
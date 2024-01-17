// 1024 수열의 합
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll i, j, n, l;
    cin >> n >> l;

    bool f = true;
    for (i = l; i <= 100; i++) {
        if (i % 2 == 0) {
            if (n % i != 0 && 2 * n % i == 0 && n / i - i / 2 + 1 >= 0) {
                f = false;
                for (j = n / i - i / 2 + 1; j <= n / i + i / 2; j++) {
                    cout << j << " ";
                }
                break;
            } else {
                continue;
            }
        } else {
            if (n % i == 0 && n / i - i / 2 >= 0) {
                f = false;
                for (j = n / i - i / 2; j <= n / i + i / 2; j++) {
                    cout << j << " ";
                }
                break;
            }
        }
    }

    if (f) cout << -1;

    return 0;
}
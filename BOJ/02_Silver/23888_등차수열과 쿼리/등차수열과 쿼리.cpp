#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll gcd(int a, int b) {
    if (b == 0) return a;

    if (a < b) {
        ll tmp = b;
        b = a;
        a = tmp;
    }

    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    ll i, j;
    ll a, d;
    cin >> a >> d;
    ll q;
    cin >> q;

    ll tmp = gcd(a, d);
    ll t, l, r;
    for (i = 0; i < q; i++) {
        cin >> t >> l >> r;
        if (t == 1) {
            cout << (2 * a + (r + l - 2) * d) * (r - l + 1) / 2 << '\n';
        } else {
            if (l == r)
                cout << a + (l - 1) * d << '\n';
            else
                cout << tmp << '\n';
        }
    }
}
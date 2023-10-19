#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll mod = 1000;

struct Matrix22 {
    ll a, b, c, d;
    void rem(ll mod) {
        a %= mod;
        b %= mod;
        c %= mod;
        d %= mod;
    }

    /**
     * a b
     * c d
     */

    Matrix22 operator*(const Matrix22 &r) const {
        Matrix22 ret;
        ret.a = (a * r.a + b * r.c) % mod;
        ret.b = (a * r.b + b * r.d) % mod;
        ret.c = (c * r.a + d * r.c) % mod;
        ret.d = (c * r.b + d * r.d) % mod;
        return ret;
    }

    Matrix22 operator^(ll r) const {
        Matrix22 ret({1, 0, 0, 1});
        Matrix22 base({a, b, c, d});
        while (r > 0) {
            if (r & 1) {
                ret = ret * base;
            }
            base = base * base;
            base.rem(mod);
            r >>= 1;
        }
        ret.rem(mod);
        return ret;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll i, j;
    ll n, t;
    cin >> t;
    for (i = 1; i <= t; i++) {
        cin >> n;
        Matrix22 mat({6, -4, 1, 0}), temp({6, 0, 2, 0});
        mat = mat ^ (n-1);
        mat = mat * temp;
        if (mat.a == 0) mat.a = 999;
        else mat.a -= 1;

        if (mat.a < 0) mat.a += 1000;
        std::cout << "Case #" << i << ": " << std::setfill('0') << std::setw(3) << mat.a << "\n";
    }
}
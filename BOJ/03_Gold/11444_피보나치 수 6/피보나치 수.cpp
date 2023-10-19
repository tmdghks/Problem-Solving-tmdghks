#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll mod = 1000000007;

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
    ll n;
    cin >> n;
    Matrix22 mat({1, 1, 1, 0}), temp({1, 0, 0, 0});
    mat = mat ^ (n-1);
    mat = mat * temp;
    cout << mat.a;
}
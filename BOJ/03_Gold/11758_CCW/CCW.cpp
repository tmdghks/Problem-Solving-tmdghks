// 11758 CCW
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using LL = unsigned long long;

// pair
struct dt {
    ll a;  // current
    ll b;  // sum
};

// vector<pair>
using vdt = vector<dt>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll a1, b1, a2, b2, a3, b3;
    cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;

    ll ans = a1 * b2 + a2 * b3 + a3 * b1 - a2 * b1 - a3 * b2 - a1 * b3;
    if (ans < 0) {
        cout << -1;
    } else if (ans > 0) {
        cout << 1;
    } else {
        cout << 0;
    }
}
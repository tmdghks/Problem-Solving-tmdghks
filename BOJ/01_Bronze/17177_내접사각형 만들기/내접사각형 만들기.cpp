#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;

struct dt {
    ll x;
    ll y;
    ll depth;
};

ll dx[4] = {0, 0, 1, -1};
ll dy[4] = {1, -1, 0, 0};

int main() {
    ll a, b, c;
    cin >> a >> b >> c;

    ll ans = -1;

    for (int i = 1; i <= a; i++) {
        ll tmp1 = (a * i + b * c) * (a * i + b * c) - (a * a - b * b) * (a * a - c * c);

        ll tmp2 = (a * c + b * i) * (a * c + b * i) - (a * a - i * i) * (a * a - b * b);

        if (tmp1 == 0 || tmp2 == 0) {
            ans = i;
            break;
        }
    }

    cout << ans;
}
// 9663 N-Queen
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using LL = unsigned long long;

// 3-pair
struct dt {
    ll a;
    ll b;
    ll w;
};

bool dt_cmp(dt lhs, dt rhs) {
    return lhs.w < rhs.w;
}

// vector<pair>
using vdt = vector<dt>;

ll ans;
vll v(0);
bool line_check(ll x) {
    for (auto k : v) {
        if (x == k) return false;
    }
    return true;
}

bool cross_line_check(ll x) {
    ll size = v.size();
    for (ll i = 0; i < v.size(); i++) {
        if ((v[i] - x == i - size) || (v[i] - x == size - i)) return false;
    }
    return true;
}

void n_queen_tracking(ll x, ll n) {
    if (x == n) {
        ans++;
        return;
    }

    for (ll i = 0; i < n; i++) {
        if (line_check(i) && cross_line_check(i)) {
            v.push_back(i);
            n_queen_tracking(x+1, n);
            v.pop_back();
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    n_queen_tracking(0, n);
    cout << ans;
}

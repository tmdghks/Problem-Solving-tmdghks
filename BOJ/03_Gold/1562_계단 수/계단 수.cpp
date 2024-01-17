// 1562 계단 수
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using LL = unsigned long long;
const ll mod = 1'000'000'000;

// pair
struct dt {
    ll a;  // current
    ll b;  // sum
};

// vector<pair>
using vdt = vector<dt>;

vvvll v;
ll n;

ll back_tracking(ll depth, ll last_num, ll state) {
    if (depth == n) {
        if (state == 1023) return 1;
        else return 0;
    }

    ll& ret = v[depth][last_num][state];
    if (ret != -1) return ret; // memorization

    ret = 0;
    if (last_num - 1 >= 0) {
        ret += back_tracking(depth + 1, last_num - 1, state | (1 << (last_num - 1)));
        ret %= mod;
    }
    if (last_num + 1 <= 9) {
        ret += back_tracking(depth + 1, last_num + 1, state | (1 << (last_num + 1)));
        ret %= mod;
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll i, j;
    cin >> n;

    v.resize(n + 1, vvll(10, vll(1024, -1)));
    
    ll ans = 0;
    for (i = 1; i <= 9; i++) {
        ans += back_tracking(1, i, 1 << i);
        ans %= mod;
    }

    cout << ans;
}
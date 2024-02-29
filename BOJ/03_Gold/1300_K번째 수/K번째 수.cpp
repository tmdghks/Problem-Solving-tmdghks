// 1300 K번째 수
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using LL = unsigned long long;
using lll = __int128_t;
using LLL = __uint128_t;  // 128비트 정수는 cout, printf 등으로 출력할 수 없음에 유의

ll INF = 100'000'000'000;

// 3-pair
struct dt {
    ll a;
    ll b;
};

// vector<pair>
using vdt = vector<dt>;
bool dt_cmp(dt lhs, dt rhs) {
    return lhs.a < rhs.a;
}

ll n;
ll check_index(ll x);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ll k; cin >> k;
    ll low = 1, top = n * n;
    while (low <= top) {
        ll mid = (low + top) / 2;
        ll tmp = check_index(mid);
        if (tmp >= k) {
            top = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << low;
}

ll check_index(ll x) {
    ll cnt = 0;
    for (ll i = 1; i <= n; i++) {
        cnt += ((x / i > n) ? n:(x / i));
    }
    return cnt;
}
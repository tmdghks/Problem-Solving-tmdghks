// 14888 연산자 끼워 넣기
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

vll v;
ll ans_max = -INF, ans_min = INF, n, a, b, c, d;

void back_tracking(ll depth, ll current) {
    if (depth == n) {
        if (current > ans_max) ans_max = current;
        if (current < ans_min) ans_min = current;
        return;
    }

    if (a != 0) {
        a--;
        back_tracking(depth + 1, current + v[depth]);
        a++;
    }
    if (b != 0) {
        b--;
        back_tracking(depth + 1, current - v[depth]);
        b++;
    }
    if (c != 0) {
        c--;
        back_tracking(depth + 1, current * v[depth]);
        c++;
    }
    if (d != 0) {
        d--;
        back_tracking(depth + 1, current / v[depth]);
        d++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    v.resize(n);
    for (auto& k : v) {
        cin >> k;
    }
    cin >> a >> b >> c >> d;

    back_tracking(1, v[0]);

    cout << ans_max << '\n' << ans_min;
}

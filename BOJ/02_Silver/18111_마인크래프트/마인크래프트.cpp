// 18111 마인크래프트
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using LL = unsigned long long;
using lll = __int128_t;
using LLL = __uint128_t;  // 128비트 정수는 cout, printf 등으로 출력할 수 없음에 유의

ll INF = 100'000'000;

// 3-pair
struct dt {
    ll time;
    ll block;

    bool operator<(const dt& rhs) {
        if (time == rhs.time) {
            return block < rhs.block;
        }
        return time > rhs.time;
    }
};

// vector<pair>
using vdt = vector<dt>;
// bool dt_cmp(dt lhs, dt rhs) {
//     return lhs.b < rhs.b;
// }

struct cmp {
    bool operator()(const dt& lhs, const dt& rhs) {
        if (lhs.time == rhs.time) {
            return lhs.block > rhs.block;
        }
        return lhs.time < rhs.time;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll N, M, B;
    cin >> N >> M >> B;

    vll v(N * M, 0);
    for (auto& k : v) {
        cin >> k;
    }
    vdt dp;
    for (ll i = 0; i <= 256; i++) {
        ll time = 0, block = B;
        for (ll j = 0; j < N * M; j++) {
            if (i < v[j]) {
                time += 2 * (v[j] - i);
                block += (v[j] - i);
            } else if (i > v[j]) {
                time += i - v[j];
                block -= (i - v[j]);
            } else {
                continue;
            }
        }
        if (block >= 0) {
            dp.push_back({time, i});
        }
    }
    dt max_dt = *max_element(dp.begin(), dp.end());
    cout << max_dt.time << " " << max_dt.block;
}
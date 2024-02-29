// 1966 프린터 큐
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
    ll a;
    ll b;
};

// vector<pair>
using vdt = vector<dt>;
bool dt_cmp(dt lhs, dt rhs) {
    return lhs.b < rhs.b;
}

struct cmp {
    bool operator()(const dt& lhs, const dt& rhs) {
        return lhs.b > rhs.b;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll T;
    cin >> T;
    for (ll i = 0; i < T; i++) {
        ll N, M, cnt = 0;
        cin >> N >> M;
        vll v(N);
        vll priority(10, 0);
        for (ll j = 0; j < N; j++) {
            cin >> v[j];
            priority[v[j]]++;
        }
        queue<dt> q;
        ll max_priority = *max_element(v.begin(), v.end());
        for (ll j = 0; j < N; j++) {
            q.push({v[j], ((j == M) ? 1 : 0)});
        }

        bool f = true;
        while (f) {
            ll a = q.front().a, b = q.front().b;
            q.pop();
            if (a == max_priority) {
                cnt++;
                priority[a]--;
                if (priority[a] == 0) {
                    for (ll k = a - 1; k >= 1; k--) {
                        if (priority[k] != 0) {
                            max_priority = k;
                            break;
                        }
                    }
                }
                if (b == 1) {
                    cout << cnt << '\n';
                    f = false;
                }
            } else {
                q.push({a, b});
            }
        }
    }
}
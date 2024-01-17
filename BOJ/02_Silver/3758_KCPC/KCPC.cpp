// 3758 KCPC
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;

struct team_data {
    vector<ll> score;
    ll score_sum;
    ll solve_time;
    ll last_solve;

    team_data() : score(100, 0), solve_time(0), score_sum(0), last_solve(0) {}
};

ll sum(vector<ll> &v) {
    ll tmp = 0;
    for (auto k : v) {
        tmp += k;
    } 
    return tmp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll i, j, n, k, t, m; 
    ll T;
    cin >> T;
    for (i = 0; i < T; i++) {
        cin >> n >> k >> t >> m;
        ll a, b, s;
        vector<team_data> v(n);
        for (j = 0; j < m; j++) {
            cin >> a >> b >> s;
            if (v[a - 1].score[b - 1] < s) {
                v[a - 1].score[b - 1] = s;
            }
            v[a - 1].solve_time++;
            v[a - 1].last_solve = j;
        }
        for (j = 0; j < n; j++) {
            v[j].score_sum = sum(v[j].score);
        }
        ll ans = 1;
        t--;
        for (j = 0; j < n; j++) {
            if (j == t) continue;

            if (v[j].score_sum > v[t].score_sum) {
                ans++;
            } else if (v[j].score_sum == v[t].score_sum) {
                if (v[j].solve_time < v[t].solve_time || v[j].solve_time == v[t].solve_time && v[j].last_solve < v[t].last_solve) {
                    ans++;
                }
            } else {
                continue;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
// 1005 ACM Craft
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using LL = unsigned long long;
using lll = __int128_t;
using LLL = __uint128_t;  // 128비트 정수는 cout, printf 등으로 출력할 수 없음에 유의

ll INF = 999'999'999;

// 3-pair
struct dt {
    ll a;
    ll b;
};

// vector<pair>
using vdt = vector<dt>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll T, N, K, X, Y, W;
    cin >> T;
    for (ll i = 0; i < T; i++) {
        queue<ll> q;
        cin >> N >> K;
        vvll g(N, vll(0));
        vll cost(N, 0), ans(N, 0), inDegree(N, 0);
        ll visited = 0;
        for (auto& k : cost) {
            cin >> k;
        }
        for (ll j = 0; j < K; j++) {
            cin >> X >> Y;
            X--, Y--;
            g[X].push_back(Y);
            inDegree[Y]++;
        }
        cin >> W;
        W--;
        for (ll j = 0; j < N; j++) {
            if (inDegree[j] == 0) {
                q.push(j);
                ans[j] = cost[j];
            }
        }
        while (!q.empty()) {
            ll front = q.front();
            q.pop();
            for (auto k : g[front]) {
                inDegree[k]--;
                ans[k] = max(ans[k], ans[front] + cost[k]);
                if (inDegree[k] == 0) {
                    q.push(k);
                }
            }
        }
        cout << ans[W] << '\n';
    }
}
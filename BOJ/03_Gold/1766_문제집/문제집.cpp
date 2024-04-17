// 1766 문제집
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
    ll node;
};

// vector<pair>
using vdt = vector<dt>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, m;
    cin >> n >> m;

    priority_queue<ll, vll, greater<ll>> pq;
    vvll g(n + 1);
    vll inDegree(n + 1, 0);
    for (ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        inDegree[b]++;
        g[a].push_back(b);
    }

    for (ll i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            pq.push(i);
        }
    }
    while (!pq.empty()) {
        ll top = pq.top();
        cout << top << " ";
        pq.pop();
        for (auto k : g[top]) {
            inDegree[k]--;
            if (inDegree[k] == 0) {
                pq.push(k);
            }
        }
    }
}
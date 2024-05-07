// 2252 줄 세우기
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using LL = unsigned long long;
using lll = __int128_t;
using LLL =
    __uint128_t;  // 128비트 정수는 cout, printf 등으로 출력할 수 없음에 유의

struct dt {
    ll price;
    ll weight;
};
using vdt = vector<dt>;

struct cmp {
    bool operator()(const dt& a, const dt& b) { return a.weight > b.weight; }
};

bool cmpWeights(const dt& a, const dt& b) { return a.weight > b.weight; }

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, m;
    cin >> n >> m;

    vll inDegree(n + 1, 0);
    vvll g(n + 1);

    for (ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        g[a].emplace_back(b);
        inDegree[b]++;
    }

    queue<ll> que;
    for (ll i = 1; i <= n; i++) {
        if (inDegree[i] == 0) que.push(i);
    }

    while (!que.empty()) {
        auto front = que.front();
        que.pop();
        cout << front << " ";
        for (auto k : g[front]) {
            inDegree[k]--;
            if (inDegree[k] == 0) {
                que.push(k);
            }
        }
    }
}
s
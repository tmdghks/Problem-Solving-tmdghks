// 13579 숨바꼭질 3
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
    ll node;
    ll weight;
};
using vdt = vector<dt>;

struct cmp {
    bool operator()(const dt& a, const dt& b) { return a.weight > b.weight; }
};

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll a, b;
    cin >> a >> b;

    deque<dt> deq;

    vll distance(200'001, 100'000'000'000);
    priority_queue<dt, vdt, cmp> pq;
    pq.push({a, 0});
    distance[a] = 0;

    while (!pq.empty()) {
        auto [node, weight] = pq.top();
        pq.pop();

        if (weight > distance[node]) continue;

        if (node <= 200'000) {
            if (distance[node + 1] > weight + 1) {
                distance[node + 1] = weight + 1;
                pq.push({node + 1, weight + 1});
            }
        }

        if (node > 0) {
            if (distance[node - 1] > weight + 1) {
                distance[node - 1] = weight + 1;
                pq.push({node - 1, weight + 1});
            }
        }

        if (node * 2 <= 200'000) {
            if (distance[node * 2] > weight) {
                distance[node * 2] = weight;
                pq.push({node * 2, weight});
            }
        }
    }

    cout << distance[b];

    pq.push({a, 0});
}

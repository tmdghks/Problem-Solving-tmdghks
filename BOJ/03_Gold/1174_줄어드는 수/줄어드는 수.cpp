// 1174 줄어드는 수
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
    ll m;
    ll v;
};

void backTracking(ll n, ll dep, vll &visited, priority_queue<ll, vll, greater<ll>> &pq) {
    if (dep > 10) return;
    // cout << n << '\n';
    pq.push(n);

    for (int i = 0; i < n % 10; i++) {
        if (visited[i] == 0) {
            visited[i] = 1;
            backTracking(n * 10 + i, dep + 1, visited, pq);
            visited[i] = 0;
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll N;
    cin >> N;

    priority_queue<ll, vll, greater<ll>> pq;
    vll visited(10, 0);

    for (int i = 0; i < 10; i++) {
        backTracking(i, 1, visited, pq);
    }

    if (pq.size() >= N) {
        for (int i = 1; i < N; i++) pq.pop();
        cout << pq.top();
    } else {
        cout << -1;
    }
    return 0;
}
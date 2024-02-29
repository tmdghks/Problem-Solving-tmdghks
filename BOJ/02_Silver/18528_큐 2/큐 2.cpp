// 18528 큐 2
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

    ll N;
    cin >> N;

    queue<ll> q;
    ll tmp;
    string s;
    for (ll i = 0; i < N; i++) {
        cin >> s;
        if (s == "push") {
            cin >> tmp;
            q.push(tmp);
        } else if (s == "pop") {
            if (q.empty()) {
                cout << -1 << '\n';
            } else {
                cout << q.front() << '\n';
                q.pop();
            }
        } else if (s == "size") {
            cout << q.size() << '\n';
        } else if (s == "empty") {
            cout << ((q.empty()) ? 1 : 0) << '\n';
        } else if (s == "front") {
            if (q.empty()) {
                cout << -1 << '\n';
            } else {
                cout << q.front() << '\n';
            }
        } else {
            if (q.empty()) {
                cout << -1 << '\n';
            } else {
                cout << q.back() << '\n';
            }
        }
    }
}
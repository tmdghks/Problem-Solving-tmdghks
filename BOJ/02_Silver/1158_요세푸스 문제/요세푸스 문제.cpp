#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;

struct dt {
    ll x;
    ll y;
    ll depth;
};

ll dx[4] = {0, 0, 1, -1};
ll dy[4] = {1, -1, 0, 0};

int main() {
    ll N, K;
    cin >> N >> K;

    queue<ll> que;

    for (int i = 1; i <= N; i++) {
        que.push(i);
    }

    cout << "<";

    while (!que.empty()) {
        for (int i = 1; i < K; i++) {
            ll front = que.front();
            que.pop();
            que.push(front);
        }

        ll front = que.front();
        que.pop();
        if (!que.empty()) {
            cout << front << ", ";
        } else {
            cout << front << ">";
        }
    }
}

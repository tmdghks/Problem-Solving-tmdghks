//1697 숨바꼭질
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;

struct dt {
    ll n;
    ll dep;
};

int main() {
    ll i, j, n, k;
    cin >> n >> k;

    queue<dt> que;
    que.push({n, 0});

    vector<bool> visited(100'001, false);

    ll dep, x, ans;
    while (!que.empty()) {
        dep = que.front().dep;
        x = que.front().n;

        if (x < 0 || x > 100'000 || visited[x] == true) {
            que.pop();
            continue;
        }

        if (x == k) {
            ans = dep;
            break;
        }

        visited[x] = true;
        que.push({x+1, dep+1});
        que.push({x-1, dep+1});
        que.push({2*x, dep+1});
        que.pop();
    }

    cout << ans;
}
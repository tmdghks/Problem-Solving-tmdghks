// 2206 : 벽 부수고 이동하기
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using LL = unsigned long long;
using lll = __int128_t;
using LLL =
    __uint128_t;  // 128비트 정수는 cout, printf 등으로 입출력할 수 없음에 유의

struct dt {
    ll node1;
    ll node2;
    ll weight;
};
using vdt = vector<dt>;

struct coordinate_3d {
    ll x;
    ll y;
    ll z;
};

struct coordinate_2d {
    ll x;
    ll y;
};

double find_distance(const coordinate_3d& c1, const coordinate_3d& c2);

struct cmp {
    bool operator()(const dt& a, const dt& b) { return a.weight < b.weight; }
};

bool cmp_weights(const dt& a, const dt& b) { return a.weight < b.weight; }

ll union_find(ll n, vll& root);

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll T = 1;
    while (T--) solve();
}

struct wallStruct {
    ll x;
    ll y;
    ll brokenWall;
    ll depth;
};

void solve() {
    ll n, m;
    cin >> n >> m;

    vvll g(n, vll(m, 0));
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < m; j++) {
            g[i][j] = tmp[j] - '0';
        }
    }

    ll ans = INT_MAX;

    queue<wallStruct> que;
    que.push({0, 0, 1, 1});

    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(2, false)));
    while (!que.empty()) {
        auto [x, y, brokenWall, dep] = que.front();
        que.pop();
        if (visited[x][y][brokenWall] || x < 0 || x >= n || y < 0 || y >= m ||
            brokenWall < 0) {
            continue;
        }

        if (x == n - 1 && y == m - 1) {
            ans = (ans > dep) ? dep : ans;
        }
        visited[x][y][brokenWall] = true;

        if (x > 0) {
            que.push(
                {x - 1, y, brokenWall - ((g[x - 1][y] == 1) ? 1 : 0), dep + 1});
        }
        if (x < n - 1) {
            que.push(
                {x + 1, y, brokenWall - ((g[x + 1][y] == 1) ? 1 : 0), dep + 1});
        }
        if (y > 0) {
            que.push(
                {x, y - 1, brokenWall - ((g[x][y - 1] == 1) ? 1 : 0), dep + 1});
        }
        if (y < m - 1) {
            que.push(
                {x, y + 1, brokenWall - ((g[x][y + 1] == 1) ? 1 : 0), dep + 1});
        }
    }

    cout << ((ans >= INT_MAX) ? -1 : ans);
}

ll union_find(ll n, vll& root) {
    if (root[n] == n)
        return n;
    else {
        return root[n] = union_find(root[n], root);
    }
}

double find_distance(const coordinate_3d& c1, const coordinate_3d& c2) {
    return min({abs(c1.x - c2.x), abs(c1.y - c2.y), abs(c1.z - c2.z)});
}
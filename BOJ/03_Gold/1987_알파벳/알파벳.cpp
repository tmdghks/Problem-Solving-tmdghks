// 1987 : 알파벳
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

struct coordinate {
    ll x;
    ll y;
    ll z;
};

double find_distance(const coordinate& c1, const coordinate& c2);

struct cmp {
    bool operator()(const dt& a, const dt& b) { return a.weight < b.weight; }
};

bool cmp_weights(const dt& a, const dt& b) { return a.weight < b.weight; }

ll union_find(ll n, vll& root);


void backTracking(ll x, ll y, vector<vector<ll>>& g, vector<vector<bool>>& visited, vector<bool>& visitedAlphabetList, ll& max_len, ll current_len);

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll T = 1;
    while (T--) solve();
}

void solve() {
    ll r, c;
    cin >> r >> c;

    vector<vector<ll>> g(r, vector<ll>(c, 0));
    for (ll i = 0; i < r; i++) {
        for (ll j = 0; j < c; j++) {
            char tmp; cin >> tmp;
            g[i][j] = tmp - 'A';
        }
    }

    vector<vector<bool>> visited(r, vector<bool>(c, false));
    vector<bool> visitedAlphabetList(26, false);
    
    ll max_len = 0;
    backTracking(0, 0, g, visited, visitedAlphabetList, max_len, 0);

    cout << max_len;
}

ll union_find(ll n, vll& root) {
    if (root[n] == n)
        return n;
    else {
        return root[n] = union_find(root[n], root);
    }
}

double find_distance(const coordinate& c1, const coordinate& c2) {
    return min({abs(c1.x - c2.x), abs(c1.y - c2.y), abs(c1.z - c2.z)});
}

void backTracking(ll x, ll y, vector<vector<ll>>& g, vector<vector<bool>>& visited, vector<bool>& visitedAlphabetList, ll& max_len, ll current_len) {
    ll r = g.size();
    ll c = g[0].size();
    
    if (x < 0 || x >= r || y < 0 || y >= c || visited[x][y] || visitedAlphabetList[g[x][y]])
        return;
    
    visited[x][y] = true;
    visitedAlphabetList[g[x][y]] = true;
    current_len++;
    max_len = max(max_len, current_len);

    backTracking(x + 1, y, g, visited, visitedAlphabetList, max_len, current_len);
    backTracking(x - 1, y, g, visited, visitedAlphabetList, max_len, current_len);
    backTracking(x, y + 1, g, visited, visitedAlphabetList, max_len, current_len);
    backTracking(x, y - 1, g, visited, visitedAlphabetList, max_len, current_len);
    
    visited[x][y] = false;
    visitedAlphabetList[g[x][y]] = false;
    current_len--;
}

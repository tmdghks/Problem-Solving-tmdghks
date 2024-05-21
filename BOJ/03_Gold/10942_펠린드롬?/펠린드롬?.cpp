// 10942 : 펠린드롬?
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

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll T = 1;
    while (T--) solve();
}

void solve() {
    ll n;
    cin >> n;

    vll v(n, 0); for(auto& k : v) cin>>k;
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    for (int k = 0; k < n; k++) {
        for (int i = 0; i + k < n; i++) {
            int j = i + k;
            if (i == j) dp[i][j] = true;
            else if (i + 1 == j && v[i] == v[j]) dp[i][j] = true;
            else if (dp[i+1][j-1] && v[i] == v[j]) dp[i][j] = true;
        }
    }

    ll k; cin >> k;
    for (int i = 0; i < k; i++) {
        ll a, b;
        cin >> a >> b;
        cout << dp[--a][--b] << '\n';
    }
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
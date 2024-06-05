// 10026 적록색약
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;

struct dt {
    ll weight;
    ll value;
};

using vdt = vector<dt>;

void solve();
void checkArea(ll i, ll j, vector<string>& g, vector<vector<bool>>& visited);

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    ll t = 1;
    while (t--) solve();
}

void solve() {
    ll n;
    cin >> n;

    vector<string> g(n);

    for (auto& k : g) cin >> k;
    vector<vector<bool>> visited1(n, vector<bool>(n, false));

    ll cnt1 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited1[i][j])
                checkArea(i, j, g, visited1), cnt1++;
        }
    }

    ll cnt2 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            switch (g[i][j]) {
                case 'R':
                    g[i][j] = 'G';
                    break;
            }
        }
    }

    vector<vector<bool>> visited2(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited2[i][j]) {
                checkArea(i, j, g, visited2), cnt2++;
            
            }
        }
    }

    cout << cnt1 << " " << cnt2 << "\n";
}

void checkArea(ll i, ll j, vector<string>& g, vector<vector<bool>>& visited) {
    if (i < 0 || j < 0 || i >= g.size() || j >= g.size() || visited[i][j]) return;

    auto c = g[i][j];

    visited[i][j] = true;

    if (j < g.size() - 1 && g[i][j+1] == c) checkArea(i, j+1, g, visited);
    if (j > 0 && g[i][j-1] == c) checkArea(i, j-1, g, visited);
    if (i < g.size() - 1 && g[i+1][j] == c) checkArea(i+1, j, g, visited);
    if (i > 0 && g[i-1][j] == c) checkArea(i-1, j, g, visited);
}
// 1080: 행렬
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<long long>;
using vvll = vector<vector<ll>>;
using ld = long double;
const ll mod = 1000000007;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, m;
    cin >> n >> m;

    vvll original(m, vll(n)), togo(m, vll(n));

    for (int y = 0; y < n; ++y) {
        string str;
        cin >> str;
        for (int x = 0; x < m; ++x) {
            original[x][y] = str[x] - '0';
        }
    }

    for (int y = 0; y < n; ++y) {
        string str;
        cin >> str;
        for (int x = 0; x < m; ++x) {
            togo[x][y] = str[x] - '0';
        }
    }

    ll ans = 0;

    for (int y = 0; y < n - 2; ++y) {
        for (int x = 0; x < m - 2; ++x) {
            if (original[x][y] != togo[x][y]) {
                ans++;
                for (int i = x; i < x + 3; i++) {
                    for (int j = y; j < y + 3; j++) {
                        original[i][j] = (original[i][j] == 1) ? 0 : 1;
                    }
                }
            }
        }
    }
    
    bool f = true;

    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < m; ++x) {
            f = f && (original[x][y] == togo[x][y]);
        }
    }

    if (f) {
        cout << ans;
    } else {
        cout << -1;
    }

    return 0;
}
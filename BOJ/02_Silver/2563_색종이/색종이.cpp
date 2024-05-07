#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using LL = unsigned long long;
using lll = __int128_t;
using LLL =
    __uint128_t;  // 128비트 정수는 cout, printf 등으로 출력할 수 없음에 유의

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<vector<bool>> g(100, vector<bool>(100, false));

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x;
        cin >> y;
        for (int j = x; j < x + 10; j++) {
            for (int k = y; k < y + 10; k++) {
                g[j][k] = true;
            }
        }
    }

    ll ans = 0;
    for (const auto& k1 : g) {
        for (auto k2 : k1) {
            if (k2) ans++; 
        }
    }

    cout << ans;
}
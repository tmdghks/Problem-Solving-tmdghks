2467 용액
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using LL = unsigned long long;
using lll = __int128_t;
using LLL =
    __uint128_t;  // 128비트 정수는 cout, printf 등으로 출력할 수 없음에 유의

struct dt {
    ll node;
    ll part;
};

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;

    vll g(n, 0);

    for (auto& k:g) {
        cin >> k;
    }

    ll i = 0, j = n - 1;
    
    ll ans1 = g[i], ans2 = g[j];
    ll ans = abs(ans1 + ans2);
    while (i < j) {
        if (abs(g[i] + g[j]) < ans) {
            ans1 = g[i];
            ans2 = g[j];
            ans = abs(ans1 + ans2);
        }

        if (g[i] + g[j] < 0) {
            i++;
        } else {
            j--;
        }
    }

    cout << ans1 << " " << ans2;
}

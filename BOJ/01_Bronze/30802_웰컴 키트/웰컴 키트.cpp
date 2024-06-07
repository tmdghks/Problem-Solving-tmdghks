// 30802 웰컴 키트
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

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    ll t = 1;
    while (t--) solve();
}

void solve() {
    ll N;
    vll size(6, 0);
    ll T, P;

    cin >> N;
    for (auto& k : size) cin >> k;
    cin >> T >> P;

    ll ans = 0;
    for (auto k : size) {
        if (k % T == 0) {
            ans += k / T;
        } else {
            ans += k / T + 1;
        }
    }

    cout << ans << '\n';
    cout << N / P << " " << N % P;
}
// 31229 또 수열 문제야
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
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << i * 2 + 1 << " ";
    }
}

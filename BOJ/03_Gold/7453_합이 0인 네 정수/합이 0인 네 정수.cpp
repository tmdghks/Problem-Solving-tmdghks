// 7453 합이 0인 네 정수
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
    ll n;
    cin >> n;

    vll a(n), b(n), c(n), d(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    vll ab, cd;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ab.push_back(a[i] + b[j]);
            cd.push_back(c[i] + d[j]);
        }
    }

    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());

    ll szTmp = ab.size();
    ll i = 0, j = cd.size() - 1;

    ll ans = 0;
    while (i < szTmp && j >= 0) {
        auto tmp = ab[i] + cd[j];

        if (tmp < 0) {
            i++;
        } else if (tmp > 0) {
            j--;
        } else {
            ll ab_cnt = 1, cd_cnt = 1;
            while (i + 1 < szTmp && ab[i] == ab[i+1]) {
                i++;
                ab_cnt++;
            }

            while (j > 0 && cd[j] == cd[j-1]) {
                j--;
                cd_cnt++;
            }

            ans += ab_cnt * cd_cnt;
            i++;
            j--;
        }
    }

    cout << ans;
}

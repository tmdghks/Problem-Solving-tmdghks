#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using LL = unsigned long long;
using lll = __int128_t;
using LLL = __uint128_t;  // 128비트 정수는 cout, printf 등으로 출력할 수 없음에 유의

ll INF = 999'999'999;

// 3-pair
struct dt {
    ll a;
    ll b;
};

// vector<pair>
using vdt = vector<dt>;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     ll w, h;
//     cin >> w >> h;
//     ll n, d;
//     cin >> n >> d;
//     vll a(n), p(n);
//     ll ans = 0, tmp = n - 1;
//     for (auto& k : a) {
//         cin >> k;
//     }
//     for (auto& k : p) {
//         cin >> k;
//     }
//     for (ll i = 1; i <= n; i++) {
//         if (a[i - 1] < d && a[i] >= d) {
//             tmp = i;
//         }
//     }
//     if (a[0] >= d) {
//         tmp = 0;
//     }

//     for (ll i = 0; i < tmp; i++) {
//         ans += p[i] * (a[i] - (i > 0 ? a[i - 1] : 0));
//         // cout << ans << ' ';
//     }
//     ans += p[tmp] * (d - (tmp > 0 ? a[tmp - 1] : 0));
//     // cout << ans << ' ';
//     ans += w * p[tmp];
//     vll ans_vector;
//     ans_vector.push_back(ans);
//     for (ll j = tmp + 1; j < n; j++) {
//         ans = 0;
//         for (ll i = 0; i <= j; i++) {
//             ans += p[i] * (a[i] - (i > 0 ? a[i - 1] : 0));
//             // cout << ans << ' ';
//         }
//         ans += w * p[j];
//         for (ll i = j - 1; i > tmp; i--) {
//             ans += p[i] * (a[i] - a[i - 1]);
//         }
//         ans += p[tmp] * (a[tmp + 1] - d);
//         ans_vector.push_back(ans);
//     }

//     cout << *min_element(ans_vector.begin(), ans_vector.end());
// }

vll a, p, ans_vector;

ll verticalTime(ll i, ll j) {
    if (i > j) swap(i, j);

    ll ans = 0;
    for (ll k = i; k < j; k++) {
        ans += p[k + 1] * (a[k + 1] - a[k]);
    }
    
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll w, h, n, d;
    cin >> w >> h >> n >> d;
    a.resize(n + 1), p.resize(n + 1);

    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (ll i = 1; i <= n; i++) {
        cin >> p[i];
    }
    ll tmp = 0;
    for (ll i = 1; i <= n; i++) {
        if (a[i] >= d) {
            tmp = i;
            break;
        }
    }

    ll ans = 0;
    ans += verticalTime(0, tmp - 1);
    ans += w * p[tmp];
    ans += (d - a[tmp - 1]) * p[tmp];
    ans_vector.push_back(ans);

    for (ll j = tmp; j <= n; j++) {
        ll ans = 0;
        ans += verticalTime(0, j);
        ans += verticalTime(tmp, j);
        ans += (j < n ? p[j + 1] : p[n]) * w;
        ans += (a[j] - d) * p[tmp];
        ans_vector.push_back(ans);
    }
    
    // for (auto k : ans_vector) {
    //     cout << k << ' ';
    // }  

    cout << *min_element(ans_vector.begin(), ans_vector.end());
}
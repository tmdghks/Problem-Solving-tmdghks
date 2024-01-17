// 11055 가장 큰 증가하는 부분 수열
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using LL = unsigned long long;

// pair
struct dt {
    ll a; // current
    ll b; // sum
};

// vector<pair>
using vdt = vector<dt>;

vll v, dp;  
int find_lower_bound(ll n) {
    ll low = 0, high = dp.size() - 1;
    ll mid = (low + high) / 2; 
    while (low <= high) {
        mid = (low + high) / 2;
        if (dp[mid] < n) {
            low = mid + 1;
        } else if (dp[mid] > n) {
            high = mid - 1;
        } else {
            high--;
        }
    }
    return low;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll i, n, current_max = -1'000'000'000, ans = 0;

    cin >> n;
    v.resize(n, 0);
    for (auto &k : v) cin >> k;
    
    dp.push_back(-1'000'000'000);

    for (auto k : v) {
        if (dp.back() < k) {
            dp.push_back(k);
            ans++;    
        } else {
            ll tmp = find_lower_bound(k);
            dp[tmp] = k;
        }
    }

    cout << ans;

    return 0;
}
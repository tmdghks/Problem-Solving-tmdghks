// 부분수열의 합
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    ll i, j, n, m;
    cin >> n;
    vector<ll> arr(n);
    for (auto &k : arr) cin >> k;
    
    vector<bool> bs(2000000, false);
    ll cnt = 0;
    for (i = 1; i < (1 << n); i++) {
        ll sum = 0;
        for (j = 0; j < n; j++) {
            if (i >> j & 1) {
                sum += arr[j];
            }
        }
        bs[sum] = true;
    }
    
    for (i = 1; i < 2000000; i++) {
        if (!bs[i]) {
            cout << i;
            break;
        }
    }

}
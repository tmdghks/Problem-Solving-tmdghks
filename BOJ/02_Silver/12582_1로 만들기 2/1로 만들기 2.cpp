// 12582 - 1로 만들기 2
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
    ll dep;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;

    vll dp(n+1, 1000000);
    dp[n] = 0;
    vll dp_path(n+1, 0);
    for (ll i = 1; i <= n; i++) {
        dp_path[i] = i;
    }
    for (ll i = n; i > 0; --i) {
        if (dp[i-1] >= dp[i] + 1) {
            dp[i-1] = dp[i] + 1;
            dp_path[i-1] = i;
        } 
        if (i % 2 == 0) {
            if (dp[i/2] >= dp[i] + 1) {
                dp[i/2] = dp[i] + 1;
                dp_path[i/2] = i;
            }
        }
        if (i % 3 == 0) {
            if (dp[i/3] >= dp[i] + 1) {
                dp[i/3] = dp[i] + 1;
                dp_path[i/3] = i;   
            }
        }
    }

    stack<ll> st;

    cout << dp[1] << '\n';

    ll t = 1;
    while (t < n) {
        st.push(t);
        t = dp_path[t];
    }

    cout << n << " ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

}
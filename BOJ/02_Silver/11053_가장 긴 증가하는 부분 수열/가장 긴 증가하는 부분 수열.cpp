// 1167 트리의 지름
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    vector<int> A(1000, 0);
    vector<pair<int, int>> dp(1000, make_pair(0, 0));

    int i, j, n, tmp;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> A[i];
    }

    dp[0] = make_pair(1, A[0]);

    int max_no;
    for (i = 1; i < n; i++) {
        max_no = 0;
        for(j = 0; j < i; j++) {
            if (dp[j].first > max_no && A[i] > A[j]) {
                max_no = dp[j].first;
            }
        }
        dp[j] = make_pair(max_no + 1, A[i]);
    }

    max_no = 0;
    for (i = 0; i < n; i++) {
        if (dp[i].first > max_no) {
            max_no = dp[i].first;
        }
    }

    // for (i = 0; i < n; i++) {
    //     cout << dp[i].first << " " << dp[i].second << '\n';
    // }

    cout << max_no;

    return 0;
}
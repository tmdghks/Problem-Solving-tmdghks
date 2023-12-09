// 1167 트리의 지름
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    vector<int> A(1000, 0);
    vector<int> B(1000, 0);
    vector<pair<int, int>> dp1(1000, make_pair(0, 0));
    vector<pair<int, int>> dp2(1000, make_pair(0, 0));

    int i, j, n, tmp;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> tmp;
        A[i] = tmp;
        B[n - i - 1] = tmp;
    }

    dp1[0] = make_pair(1, A[0]);

    int max_no;
    for (i = 1; i < n; i++) {
        max_no = 0;
        for (j = 0; j < i; j++) {
            if (dp1[j].first > max_no && A[i] > A[j]) {
                max_no = dp1[j].first;
            }
        }
        dp1[j] = make_pair(max_no + 1, A[i]);
    }

    dp2[0] = make_pair(1, B[0]);
    for (i = 1; i < n; i++) {
        max_no = 0;
        for (j = 0; j < i; j++) {
            if (dp2[j].first > max_no && B[i] > B[j]) {
                max_no = dp2[j].first;
            }
        }
        dp2[j] = make_pair(max_no + 1, B[i]);
    }

    max_no = 0;
    for (i = 0; i < n; i++) {
        if (dp1[i].first + dp2[n - i - 1].first > max_no) {
            max_no = dp1[i].first + dp2[n - i - 1].first;
        }
    }

    cout << max_no - 1;

    return 0;
}
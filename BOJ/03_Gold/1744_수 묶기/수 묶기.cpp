#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    priority_queue<int> v_positive;
    priority_queue<int, vector<int>, greater<int>> v_negative;

    int i, j, n, tmp, ans = 0, cnt0 = 0, cnt1 = 0;
    int tmp1, tmp2;
    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> tmp;
        if (tmp > 1) {
            v_positive.push(tmp);
        }
        else if (tmp < 0) {
            v_negative.push(tmp);
        }
        else if (tmp == 0) {
            cnt0++;
        } else {
            cnt1++;
        }
    }

    int v_positive_size = v_positive.size() / 2;
    for (i = 0; i < v_positive_size; i++) {
        tmp1 = v_positive.top();
        v_positive.pop();
        tmp2 = v_positive.top();
        v_positive.pop();
        ans += tmp1 * tmp2;
    }

    int v_negative_size = v_negative.size() / 2;
    for (i = 0; i < v_negative_size; i++) {
        tmp1 = v_negative.top();
        v_negative.pop();
        tmp2 = v_negative.top();
        v_negative.pop();
        ans += tmp1 * tmp2;
    }

    if (!v_positive.empty()) {
        ans += v_positive.top();
    }

    if (!v_negative.empty()) {
        if (cnt0 == 0) {
            ans += v_negative.top();
        }
    }

    ans += cnt1;

    cout << ans;
}
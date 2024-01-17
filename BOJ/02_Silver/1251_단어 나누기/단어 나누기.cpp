// 1251 단어 나누기
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<string> v;
    string s, tmp, ans;
    cin >> s;
    ans = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";

    ll n = s.length();
    ll i, j, k;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n - 1; j++) {
            tmp = "";
            for (k = 0; k < n; k++) {
                if (k <= i) {
                    tmp += s[i - k];
                } else if (k <= j) {
                    tmp += s[j + i + 1 - k];
                } else {
                    tmp += s[j + n - k];
                }
            }
            if (tmp < ans) ans = tmp;
        }
    }

    cout << ans;

    return 0;
}
// 9935 문자열 폭발
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s1, s2;
    vector<char> v;
    ll i, j, l1, l2, l3;
    cin >> s1;
    cin >> s2;
    l1 = s1.length();
    l2 = s2.length();

    for (i = 0; i < l1; i++) {
        v.push_back(s1[i]);
        l3 = v.size();
        bool f = true;
        while (l3 >= l2) {
            for (j = l2 - 1; j >= 0; j--) {
                if (v[j + l3 - l2] != s2[j]) {
                    f = false;
                    break;
                }
            }
            if (f) {
                for (j = 0; j < l2; j++) {
                    v.pop_back();
                }
            } else {
                break;
            }
            l3 = v.size();
        }
    }

    if (v.size() == 0) {
        cout << "FRULA";
    } else {
        for (auto k : v) {
            cout << k;
        }
    }

    return 0;
}
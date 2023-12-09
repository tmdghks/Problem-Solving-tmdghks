// 2630 색종이 만들기
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;

int ans0, ans1;
vvll g;

void check_paper(int size, int x, int y) {
    if (size == 1) {
        if (g[x][y] == 1) {
            ans1++;
        } else {
            ans0++;
        }
        return;
    }

    ll tmp_color = g[x][y];
    bool tmp = true;
    ll i, j;

    for (i = y; i < y + size; i++) {
        for (j = x; j < x + size; j++) {
            if (g[j][i] != tmp_color) {
                tmp = false;
                break;
            }
        }
    }

    if (tmp) {
        if (tmp_color == 1) ans1++;
        else ans0++;
    } else {
        check_paper(size / 2, x, y); 
        check_paper(size / 2, x + size / 2, y);
        check_paper(size / 2, x, y + size / 2);
        check_paper(size / 2, x + size / 2, y + size / 2);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll i, j;
    ll n;
    cin >> n;
    g.resize(n, vll(n, 0));

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> g[j][i];
        }
    }

    check_paper(n, 0, 0);
    cout << ans0 << '\n' << ans1;
}
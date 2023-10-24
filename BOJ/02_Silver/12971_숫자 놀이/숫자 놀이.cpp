// 12971 숫자 놀이
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll p1, p2, p3, x1, x2, x3;

    cin >> p1 >> p2 >> p3 >> x1 >> x2 >> x3;

    int num = -1;
    for (int i = 0; i <= p1 * p2 * p3; i++) {
        if (i % p1 == x1 && i % p2 == x2 && i % p3 == x3) {
            num = i;
            break;
        }
    }

    cout << num;
}
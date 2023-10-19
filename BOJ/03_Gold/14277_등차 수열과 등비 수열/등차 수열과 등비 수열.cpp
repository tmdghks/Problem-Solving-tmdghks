#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    long long a, b, c, d, u, cnt = 0;
    cin >> a >> b >> c >> d >> u;

    if (a <= u) {
        cnt += (u - a) / b  + 1;
    }

    while (c <= u) {
        if ((c - a) % b != 0 || c < a) {
            cnt++;
        }

        c *= d;

        if (d == 1) break;
    }
    

    cout << cnt;
}
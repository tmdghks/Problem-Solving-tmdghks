#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, k, cnt = 0;
    
    cin >> n >> k;

    vector<int> v(n);
    for (int i = n - 1; i >= 0; i--) {
        cin >> v[i];
    }

    int i = 0;
    while (k > 0) {
        if (v[i] <= k) {
            cnt += k / v[i];
            k %= v[i];
        }

        i++;
    }

    cout << cnt;
}
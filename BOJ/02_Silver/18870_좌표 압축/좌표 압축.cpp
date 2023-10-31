// 좌표압축

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    ll n;
    cin >> n;
    
    vector<ll> v(n, 0);
    vector<ll> u(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        u[i] = v[i];
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for (int i = 0; i < n; i++) {
        cout << lower_bound(v.begin(), v.end(), u[i]) - v.begin() << " ";
    }   
}
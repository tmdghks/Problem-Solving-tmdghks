// 26517 연속인가??
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
    
    ll k, a, b, c, d;
    cin >> k >> a >> b >> c >> d;

    if (a * k + b == c * k + d) cout << "Yes " << a * k + b;
    else cout << "No";
}
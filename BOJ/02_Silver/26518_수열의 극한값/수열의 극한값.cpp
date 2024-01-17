// 26518 수열의 극한값  
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
    
    ll b, c, a1, a2;
    cin >> b >> c >> a1 >> a2;
    double tmp, k1 = a2 / a1, k2 = (b * a2 + c * a1) / a2;


    for (ll i = 0; i <= 10'000'000; i++) {
        tmp = b + c / k2;
        k2 = tmp;
    }

    printf("%lf", tmp);
}
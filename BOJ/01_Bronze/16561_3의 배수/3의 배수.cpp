// 16561: 3의 배수
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<long long>;
using vvll = vector<vector<ll>>;
using ld = long double;
const ll mod = 1000000007;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll a; cin >> a;
    a /= 3;

    cout << (a - 1) * (a - 2) / 2;   
}
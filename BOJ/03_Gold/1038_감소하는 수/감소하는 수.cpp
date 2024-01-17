// 1038 감소하는 수
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using LL = unsigned long long;

// pair
struct dt {
    ll a;  // current
    ll b;  // sum
};

// vector<pair>
using vdt = vector<dt>;

vll v;

void backtracking(ll a, ll x) {
    if (x == 11) return;
    
    v.push_back(a);
    for (ll i = a % 10 - 1; i >= 0; i--) {
        backtracking(a * 10 + i, x + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;

    v.push_back(0);
    for (ll i = 1; i < 10; i++) {
        backtracking(i, 1);
    }
    
    stable_sort(v.begin(), v.end());
    if (n >= v.size()) {
        cout << -1;
    } else {
        cout << v[n];
    }
}
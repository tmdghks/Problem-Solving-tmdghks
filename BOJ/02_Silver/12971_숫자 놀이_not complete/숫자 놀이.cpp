#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll fast_power(ll base, ll power, ll mod) {
    if (power == 0) return 1;
    else if (power == 1) return base;
    else {
        if (power % 2 == 1) {
            return fast_power(base * base % mod, power / 2, mod) * base % mod;
        } else {
            return fast_power(base * base % mod, power / 2, mod);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
        
}
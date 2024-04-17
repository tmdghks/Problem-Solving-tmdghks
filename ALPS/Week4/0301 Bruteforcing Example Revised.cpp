#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using LL = unsigned long long;

// 3-pair
struct dt {
    ll a;
    ll b;
};

// vector<pair>
using vdt = vector<dt>;

vector<ll> arr;
vector<bool> sum;

void bs(ll i, ll current_sum, ll n) {
    sum[current_sum] = true;
    sum[current_sum + arr[i]] = true;
    bs(i + 1, current_sum, n);
    bs(i + 1, current_sum + arr[i], n); 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    ll n;
    cin >> n;

    arr.resize(n);
    sum.resize(2'000'000, false);

    for (auto& k : arr) {
        cin >> k;
    }


    bs(0, 0, n);
}

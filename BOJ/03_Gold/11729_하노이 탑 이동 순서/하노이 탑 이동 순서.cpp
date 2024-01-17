// 11729 하노이 탑 이동 순서
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
    ll w;
};

void print_hanoi(ll n, ll a, ll b, ll c);
bool dt_cmp(dt lhs, dt rhs) {
    return lhs.w < rhs.w;
}

// vector<pair>
using vdt = vector<dt>;

vll root;
vdt g;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll i, j, n, a, b, ans = 0;
    
    cin >> n;

    cout << (1 << n) - 1 << '\n';

    print_hanoi(n, 1, 2, 3);
}

void print_hanoi(ll n, ll a, ll b, ll c) {
    if (n == 1) {
        cout << a << " " << c << '\n';
        return;
    } else if (n == 0) {
        return;
    }
    
    print_hanoi(n-1, a, c, b);
    cout << a << " " << c << '\n';
    print_hanoi(n-1, b, a, c);
}
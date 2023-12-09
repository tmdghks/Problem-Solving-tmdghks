// 2193 이친수
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;

vector<ll> powerOf3(8, 1);
void isStar(ll a, ll b, ll n);

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    ll i, j;
    ll n;
    cin >> n;
    vector<pll> v(n, make_pair(0, 0));

    v[0].first = 0;
    v[0].second = 1;

    for (i = 1; i < n; i++) {
        v[i].first = v[i - 1].first + v[i - 1].second;
        v[i].second = v[i - 1].first;
    }

    cout << v[n - 1].first + v[n - 1].second;
}
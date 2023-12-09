// 2447 별 찍기 - 10
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
    ll n, tmp = 1, logn = 0;
    cin >> n;

    for (i = 1; i <= 7; i++) {
        tmp *= 3;
        powerOf3[i] = tmp;
    }

    for (i = 1; i <= 7; i++) {
        if (n == powerOf3[i]) logn = i;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            isStar(j, i, logn);
        }
        cout << '\n';
    }
}

void isStar(ll a, ll b, ll n) {
    if (n == 1) {
        if (a == 1 && b == 1) {
            cout << ' ';
        } else {
            cout << '*';
        }
        return;
    }

    if (a / powerOf3[n - 1] == 1 && b / powerOf3[n - 1] == 1) {
        cout << ' ';
        return;
    } else {
        isStar(a % powerOf3[n - 1], b % powerOf3[n - 1], n - 1);
    }
}
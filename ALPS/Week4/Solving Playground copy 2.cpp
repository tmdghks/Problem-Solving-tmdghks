// 2263 트리의 순회
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using vll = vector<ll>;

ll mod;

double fastPower (double a, ll n) {
    if (n == 0) return 1;
    else if (n == 1) return a;
    else if (n % 2) {
        return a * fastPower(a * a, n / 2);
    } else {
        return fastPower(a * a, n / 2);
    }
}

// ull euler(ll n) {
//     ll euler = n;
//     for (ll i = 2; i * i< n; i++) {
//         i++;
//     }
// }

vll inOrder, postOrder;

auto toPreorder(ll i1, ll j1) {
    if (i1 == j1) {
        cout << i1 << " ";
        return;
    }

    ll tmp1 = i1, tmp2;
    while (tmp1 <= j1 && tmp2 <= j2) {
        if (inOrder[tmp1] != postOrder[tmp2]) {
            
            // Todo: root 출력
            for (ll i = i1; i < tmp1; i++) {
                cout << inOrder[i] << " ";
            }
            // Todo: right 출력
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n;
    inOrder.resize(n, 0);
    postOrder.resize(n, 0);
    for (auto &k : inOrder) {
        cin >> k;
    }
    for (auto &k : postOrder) {
        cin >> k;
    }


}
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;

struct dt {
    ll x;
    ll y;
    ll depth;
};

ll dx[4] = {0, 0, 1, -1};
ll dy[4] = {1, -1, 0, 0};

int main() {
    ll N;
    cin >> N;

    vector<bool> v(2'001, false);

    for (int i = 0; i < N; i++) {
        ll tmp;
        cin >> tmp;
        v[tmp + 1000] = true;
    }

    for (int i = -1000; i <= 1000; ++i) {
        if (v[i + 1000]) cout << i << " ";
    }

    return 0;
}

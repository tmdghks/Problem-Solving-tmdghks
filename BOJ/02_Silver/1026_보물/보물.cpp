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

    vll A(N, 0), B(N, 0);

    for (auto& k : A) {
        cin >> k;
    }

    for (auto& k : B) {
        cin >> k;
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        ans += A[i] * B[N - 1 - i];
    }

    cout << ans;
}

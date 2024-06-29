// 1O815 숫자 카드
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
    vll toFind(N, 0);
    for (auto& k : toFind) {
        cin >> k;
    }

    ll M;
    cin >> M;
    vll sanggeun(M, 0);
    for (auto& k : sanggeun) {
        cin >> k;
    }

    sort(toFind.begin(), toFind.end());

    for (auto k : sanggeun) {
        if (binary_search(toFind.begin(), toFind.end(), k)) {
            cout << 1 << " ";
        } else {
            cout << 0 << " ";
        }
    }

    return 0;
}

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
    int N;
    cin >> N;
    vll v(N, 0);
    for (auto& k : v) {
        cin >> k;
    }    

    cout << *min_element(v.begin(), v.end()) * (*max_element(v.begin(), v.end()));
}

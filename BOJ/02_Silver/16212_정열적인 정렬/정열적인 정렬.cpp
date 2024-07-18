// 16212: 정열적인 정렬
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<long long>;
using vvll = vector<vector<ll>>;
using ld = long double;
const ll mod = 1000000007;

void coutWithStuff(string& stuff, string toPrint) {
    cout << stuff << toPrint << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll N;
    cin >> N;

    vll v(N, 0);
    for (auto& k : v) {
        cin >> k;
    }

    sort(v.begin(), v.end());

    for (auto k : v) {
        cout << k << " ";
    }
}
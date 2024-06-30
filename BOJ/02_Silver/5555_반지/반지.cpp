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
    string toFind;
    cin >> toFind;

    ll N;
    cin >> N;

    ll length = toFind.size();
    vector<string> v;

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < length - 1; j++) {
            str += str[j];
        }
        v.push_back(str);
    }

    ll ans = 0;

    for (string k : v) {
        for (int i = 0; i < 10; i++) {
            if(k.substr(i, length).compare(toFind) == 0) {
                ans++;
                break;
            }
        }
    }

    cout << ans;
}
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
    string str;
    cin >> str;
    if (str == "SONGDO") {
        cout << "HIGHSCHOOL";
    } else if (str == "CODE") {
        cout << "MASTER";
    } else if (str == "2023") {
        cout << "0611";
    } else {
        cout << "CONTEST";
    }
}

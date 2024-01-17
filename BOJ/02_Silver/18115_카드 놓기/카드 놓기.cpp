// 18115 카드 놓기
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using LL = unsigned long long;

// pair
struct dt {
    ll a;  // current
    ll b;  // sum
};

// vector<pair>
using vdt = vector<dt>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, i, j, tmp1, tmp2, tmp3;
    cin >> n;

    deque<ll> dq1, dq2;
    for (i = 1; i <= n; i++) {
        cin >> tmp1;
        dq1.push_back(tmp1);
    }

    for (i = 1; i <= n; i++) {
        tmp1 = dq1.back();
        switch (tmp1) {
            case 1:
                dq2.push_front(i);
                break;

            case 2:
                tmp3 = dq2.front();
                dq2.pop_front();
                dq2.push_front(i);
                dq2.push_front(tmp3);
                break;

            default:
                dq2.push_back(i);
                break;
        }
        dq1.pop_back();
    }

    for (i = 0; i < n; i++) {
        cout << dq2.front() << " ";
        dq2.pop_front();
    }
}
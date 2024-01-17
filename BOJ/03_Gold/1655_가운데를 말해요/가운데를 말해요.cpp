// 1655 가운데를 말해요
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    priority_queue<ll, vll, greater<ll>> high;
    priority_queue<ll, vll> low;
    
    ll n, tmp, tmp2, i, j;
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> tmp;
        switch (i) {
            case 1:
                cout << tmp << '\n';
                high.push(tmp);
                break;
            case 2:
                if (high.top() < tmp) {
                    low.push(high.top());
                    high.pop();
                    high.push(tmp);
                } else {
                    low.push(tmp);
                }
                cout << low.top() << '\n';
                break;
            default:
                if (i % 2) {
                    if (high.top() < tmp) {
                        tmp2 = high.top();
                        high.pop();
                        high.push(tmp);
                        tmp = tmp2;
                    }
                    if (low.top() > tmp) {
                        tmp2 = low.top();
                        low.pop();
                        low.push(tmp);
                        tmp = tmp2;
                    }
                    cout << tmp << '\n';
                    high.push(tmp);
                } else {
                    if (high.top() < tmp) {
                        low.push(high.top());
                        high.pop();
                        high.push(tmp);
                    } else {
                        low.push(tmp);   
                    }
                    cout << low.top() << '\n';
                }
        }
    }

    return 0;
}
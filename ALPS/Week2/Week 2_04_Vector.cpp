#include <bits/stdc++.h> 

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<ll> v;
    v.push_back(1);
    v.push_back(2);
    v.pop_back();
    cout << v.front() << '\n';
    cout << v.size() << '\n';
    cout << v.empty() << '\n';
    return 0;


}
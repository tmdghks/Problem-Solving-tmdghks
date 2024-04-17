#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    vector<ll> v = {4, 5, 1, 49, 1234, 39};

    // 시작 끝 반복자를 파라미터로 넣습니다.
    sort(v.begin(), v.end());
    for (ll i = 0; i < 6; i++) {
        cout << v[i] << " ";
    }
    cout << '\n';

    sort(v.begin(), v.end(), greater<ll>()); 
    // 3번째 파라미터로 비교함수를 넣어줄 수 있습니다.
    for (ll i = 0; i < 6; i++) {
        cout << v[i] << " ";
    }
}
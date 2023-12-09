// 30402 감마선을 맞은 컴퓨터

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    char s[225] = {'\0', };

    for (int i = 0; i < 225; i++) {
        cin >> s[i];
    }
    
    for (int i = 0; i < 225; i++) {
        if (s[i] == 'w') {
            cout << "chunbae";
            break;
        } else if (s[i] == 'b') {
            cout << "nabi";
            break;
        } else if (s[i] == 'g') {
            cout << "yeongcheol";
            break;
        } else {
            continue;
        }
    }
}
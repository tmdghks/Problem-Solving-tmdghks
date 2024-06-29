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
    string initialStr;
    cin >> initialStr;

    list<char> editor(initialStr.begin(), initialStr.end());
    auto curr = editor.end(); // 커서를 문자열 끝으로 초기화

    ll M;
    cin >> M;
    for (ll i = 0; i < M; ++i) {
        char cmd;
        cin >> cmd;
        switch (cmd) {
            case 'L':
                if (curr != editor.begin()) curr--;
                break;
            case 'D':
                if (curr != editor.end()) curr++;
                break;
            case 'B':
                if (curr != editor.begin()) {
                    curr--;
                    curr = editor.erase(curr);
                }
                break;
            case 'P':
                char inputChar;
                cin >> inputChar;
                editor.insert(curr, inputChar);
                break;
        }
    }

    for (char c : editor) {
        cout << c;
    }

    return 0;
}

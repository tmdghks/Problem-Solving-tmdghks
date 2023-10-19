#include <bits/stdc++.h>

using namespace std;

vector<string> split(char *input, char delimiter) {
    char *p = input;
    char *q = input;
    vector<string> answer;

    while (*q) {
        while (*q != delimiter && *q != '\0') {
            q++;
        }
        if (*q == delimiter) {
            *q = '\0';
            answer.push_back(string(p));
            p = ++q;
        } else {
            break;
        }
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    char s[51] = "";
    cin >> s;
    
    vector<string> a = split(s, '-');
    int cnt = 0;

    vector<string> tmp = split(a.back(), '+');
    for (string t:tmp) {
        cnt += stoi(t);
    }
    a.pop_back();

    while (!a.empty()) {
        vector<string> temp = split(a.back(), '+');
        for (auto t:temp) {
            cnt -= stoi(t);
        }
        a.pop_back();
    }


    cout << cnt << '\n';
}
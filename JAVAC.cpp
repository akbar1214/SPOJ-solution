#include<bits/stdc++.h>

using namespace std;

void to_cpp(string &s) {

    string ans;
    for (auto &x:s) {

        if (isupper(x)) {
            ans += "_";
        }
        ans += (char) tolower(x);
    }
    cout << ans << '\n';
}

void toJava(string &s) {

    bool flag = false;
    string ans;
    for (auto &x:s) {

        if (x == '_' && !flag) {
            flag = true;
            continue;
        }
        if (flag && x == '_') {
            cout << "Error!\n";
            return;
        }
        if (flag) {

            flag = false;
            ans += (char) toupper(x);
        } else {
            ans += (char) x;
        }
    }
    cout << ans << '\n';
}

int main() {

    string s;
    while (cin >> s) {
        bool is_cpp = false, isJava = false;
        for (char &x:s) {

            if (x == '_') {
                is_cpp = true;
            }
            if (isupper(x)) {
                isJava = true;
            }
        }
        if ((is_cpp && isJava) || isupper(s[0]) || s[0] == '_' || s[s.size() - 1] == '_') {
            cout << "Error!";
        } else {

            is_cpp ? toJava(s) : to_cpp(s);
        }
    }
}

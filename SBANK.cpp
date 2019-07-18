#include<bits/stdc++.h>

using namespace std;


class Account{
 public:
    int control_digit,bank_code;
    string acc;
    Account(int control_digit, int bank_code, const string &acc)
        : control_digit(control_digit), bank_code(bank_code), acc(acc) {}

    bool operator<(const Account &rhs) const {

        if(control_digit != rhs.control_digit) return control_digit < rhs.control_digit;

        if(bank_code != rhs.bank_code) return bank_code < rhs.bank_code;

        return acc < rhs.acc;
    }
};

int main() {

    int T;cin >> T;
    while(T--) {

        int n;cin >> n;
        int cd,bc;
        multiset<Account> ms;

        for(int i=0;i < n;i++) {
            cin >> cd >> bc;
            string s,s1;
            for(int j=0;j<4;j++){
                cin >> s1;
                s += s1;
            }
            Account a(cd,bc,s);
            ms.insert(a);
        }
        while(!ms.empty()) {
            Account x = *ms.begin();
            printf("%02d %08d ",x.control_digit,x.bank_code);
            cout << x.acc.substr(0,4) << ' ' << x.acc.substr(4,4) << ' ' << x.acc.substr(8,4) << ' ' << x.acc.substr(12) << ' ' << ms.count(x) << '\n';
            ms.erase(x);
        }
    }
    return 0;
}

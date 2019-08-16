#include <bits/stdc++.h>
using namespace std;
 
int main() {
	
	int T;cin >> T;
	while(T--) {
		
		string s,r;cin >> s;
		r = s;
		reverse(s.begin(),s.end());
		cout << (s == r ? "YES\n" : "NO\n");
	}
	return 0;
} 

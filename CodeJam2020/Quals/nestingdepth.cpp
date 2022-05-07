#include <bits/stdc++.h>
using namespace std;

int t;
string s;
int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> t;
    for(int T=1;T<=t;T++){
		cin >> s;
		int numUnclose = 0;
		cout << "Case #"<<T<<": ";
		for(int i=0;i<s.length();i++){
			int a = (int)(s[i] - '0');
			while(numUnclose < a){
				numUnclose++;
				cout << '(';
			}
			while(numUnclose > a){
				numUnclose--;
				cout << ')';
			}
			cout << s[i];
		}
		while(numUnclose > 0){
			numUnclose--;
			cout << ')';
		}
		cout << '\n';
	}		
}

#include <bits/stdc++.h>
using namespace std;

int n,T;
vector<string> s;
int idxes[50];
string str;
int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> T;
    for(int t=1;t<=T;t++){
		cin >> n;
		for(int i=0;i<n;i++) cin >> s[i];
		
		cout << "Case #"<<t<<":\n";
		
		string ans = s[0];
		memset(idxes,0,n);
		for(int i=1;i<n;i++){  //For each string	
			int idxA=0,idxS=0;
			string newAns = "";
			while(idxA<ans.length() && idxS<s[i].length()){
				if(ans[idxA] == '*'){
					while(ans[idxA+1] != s[i][idxS] && s[i][idxS] != '*') {
						newAns+=s[i][idxS];
						idxS++;
					}
					idxA++;
					continue;
				}
				if(s[i][idxS] == '*'){
					while(ans[idxA] != s[i][idxS+1] && ans[idxA] != '*') {
						newAns+=s[i][idxA];
						idxA++;
					}
					idxS++;
					continue;
				}
				if(ans[idxA] == s[i][idxS]) newAns += ans[idxA];
			}
		}
    }
}

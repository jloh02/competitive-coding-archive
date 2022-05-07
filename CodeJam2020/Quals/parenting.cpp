#include <bits/stdc++.h>
using namespace std;

bool bypass;
int t,n,s,e, cbe,jbe;
char op[1000];
int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> t;
    for(int T=1;T<=t;T++){
		cin >> n;
		bypass = false;
		cbe = jbe = 0;
		cout << "Case #"<<T<<": ";
		vector<tuple<int,int,int>> it;
		for(int i=0;i<n;i++){
			cin >> s >> e;
			it.push_back({s,e,i});
		}
		sort(it.begin(),it.end());
		for(int i=0;i<n;i++){
			//auto [s,e,idx] = it[i];
			s = get<0>(it[i]);
			e = get<1>(it[i]);
			int idx = get<2>(it[i]);
			if(bypass) continue;
			//cout << s << " " << e << '\n';
			if(cbe <= s){
				//cout << "CHOSE C\n";
				op[idx] = 'C';
				cbe = e;
			}
			else if(jbe <= s){
				//cout << "CHOSE J\n";
				op[idx] = 'J';
				jbe = e;
			}
			else {
				bypass = true;
			}
		}
		if(bypass) cout << "IMPOSSIBLE\n";
		else{
			for(int i=0;i<n;i++) cout << op[i];
			cout << '\n';
		}
	}		
}

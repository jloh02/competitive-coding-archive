#include <bits/stdc++.h>
using namespace std;

int t,n,m,c,r,trace;
int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> t;
    for(int T=1;T<=t;T++){
		c=trace=r=0;
		cin >> n;
		//memset(col,0,n);
		int expS=0;
		unordered_set<int> col[101];
		for(int i=1;i<=n;i++)expS += i;
		for(int i=0;i<n;i++){
			unordered_set<int> row;
			for(int j=0;j<n;j++){
				cin >> m;
				if(i==j) trace += m;
				row.insert(m);
				col[j].insert(m);
			}
			if(row.size() != n) r++; 
		}
		for(int i=0;i<n;i++) if(col[i].size() != n) c++;
		printf("Case #%d: %d %d %d\n",T,trace,r,c);
	}		
}

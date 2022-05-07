#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T,r,c;
	cin>>T;
	for(int t=0;t<T;t++){
		cin >> r >> c;
		if((r<4 && c <=4) || (r<=4 && c <4) || r == 1 || c == 1) printf("Case #%d: IMPOSSIBLE\n",t+1);
		else{
			printf("Case #%d: POSSIBLE\n",t+1);
			bool swapped = false;
			if(c>r){
				int temp = c;
				c = r;
				r = temp;
				swapped = true;
			}
			
			bool vis[c][r];
			for(int i=0;i<c;i++)
				for(int j=0;j<r;j++) vis[i][j] = false;
				
			
			int rowIndex = 0;
			for(int j=0;j<r;j++){
				for(int i=0;i<c;i++){	
					while(vis[i][rowIndex] == true) {
						rowIndex++;		
						rowIndex %= r;
					}		
					if(!swapped) {
						printf("%d %d\n",rowIndex+1,i+1);						
					}
					else {
						printf("%d %d\n",i+1,rowIndex+1);
					}
					vis[i][rowIndex] = true;
					rowIndex += 2;
					rowIndex %= r;
				}
			}
		}
	}
}

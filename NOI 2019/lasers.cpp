#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int l,r,x,w;
	cin >> l >> r;
	
	bool globalPass[l];
	for(int i=0;i<l;i++) globalPass[i] = true;
	while(r--){
		vector<int> walls;
		cin >> x;
		//if(x != 1) AllXOne = false;
		bool subPass[l];
		for(int i=0;i<l;i++) subPass[i] = false;
		int sumWallWidth = 0;
		
		walls.push_back(0);
		
		if(x==1){
			cin >> w;
			for(int i=l-w;i<w;i++) globalPass[i] = false;
		}
		else{
			for(int i=0;i<x;i++) {
				cin >> w;
				walls.push_back(w);
				sumWallWidth += w;
			}
			int posL = 0;//, posR = l-sumWallWidth-1;
			for(int i=0;i<=x;i++){
				posL+=walls[i];
				for(int j=posL;j<=l-sumWallWidth-1+posL;j++) {
					subPass[j] = true;
					//cout << j << " Passes" << endl;
				}
			//	cout << "-----" << endl;
			}
			for(int i=0;i<l;i++) {
				if(!subPass[i]) {
					globalPass[i] = false;
				//	cout << i << " Never Passes" << endl;
				}
			}
		}
	}
	int sumBlock = 0;
	for(int i=0;i<l;i++) if(!globalPass[i]) sumBlock++;
	cout << sumBlock;
}


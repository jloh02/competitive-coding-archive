#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T,P,Q,X,Y;
	char dir;
	cin >> T;
	for(int t=0;t<T;t++){
		cin >> P >> Q;
		vector<int> midY(Q+2,0);
		vector<int> midX(Q+2,0);
		vector<pair<int,int>> intervalX, intervalY;
		for(int i=0;i<P;i++){
			cin >> X >> Y >> dir;
			if(dir == 'N') midY[Y+1]++,midY[Q+1]--;//intervalY.push_back(make_pair(Y,Q));
			else if(dir == 'S') midY[0]++,midY[Y]--;//intervalY.push_back(make_pair(1,Y));
			else if(dir == 'E') midX[X+1]++,midX[Q+1]--;//intervalX.push_back(make_pair(X,Q));
			else midX[0]++,midX[X]--;// intervalX.push_back(make_pair(1,X));
		}
		int maxIntY=0, maxIntX=0, xPos=0, yPos=0;
		int countY=0, countX=0;
		for(int i=0;i<=Q;i++){
			countY += midY[i];
			countX += midX[i];
			//printf("X:%d, Y:%d\n",countX,countY);
			if(countY > maxIntY){
				maxIntY = countY;
				yPos = i;
			}
			if(countX > maxIntX){
				maxIntX = countX;
				xPos = i;
			}
		}
		printf("Case #%d: %d %d\n",t+1,xPos,yPos);
	} 
}
/*
 int grid[Q][Q];
		for(int i=0;i<Q;i++)
			for(int j=0;j<Q;j++)
				grid[i][j] = 0;
		for(int i=0;i<P;i++) {
			cin >> X >> Y >> dir;
			if(dir == 'N')
				for(int j=Y;j<Q;j++) grid[X-1][j]++;
			else if(dir == 'S')
				for(int j=0;j<Y-1;j++) grid[X-1][j]++;
			else if(dir == 'W')
				for(int j=0;j<X-1;j++) grid[j][Y-1]++;
			else
				for(int j=X;j<Q;j++) grid[j][Y-1]++;
			
		}
		vector<pair<int,int>> answers;
		int max = 0;
		for(int i=0;i<Q;i++)
			for(int j=0;j<Q;j++){
				cout << i << " " << j << " " << grid[i][j] << endl;
				if(grid[i][j]>max){
					max = grid[i][j];
					answers.clear();
					answers.push_back(make_pair(i,j));
				}
				else if(grid[i][j]==max) answers.push_back(make_pair(i,j));
			}
		
		sort(answers.begin(),answers.end());
		for(int i=0;i<answers.size();i++) printf("%d\n",answers[i]);*/


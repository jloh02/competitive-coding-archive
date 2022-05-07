#include <bits/stdc++.h>
using namespace std;

map<pair<int,int>,vector<pair<pair<int,int>,int>>> a;

int triangle[31][31];

vector<pair<int,int>> search(int target){
	queue<tuple<pair<int,int>, int, vector<pair<int,int>>>> q;  //< <line,k>, totalDist, <storage line k> >
	vector<pair<int,int>> v;
	v.push_back({1,1});
	q.push({{1,1},1,v});
	while(!q.empty()){
		tuple<pair<int,int>, int, vector<pair<int,int>>> curr = q.front();
		pair<int,int> cv = get<0>(curr);
		int cd = get<1>(curr);
		vector<pair<int,int>> cr = get<2>(curr);
		
		//cout  << "TEST " << cv.first << " " << cv.second << " " << cd << '\n';/*<<  "ROUTE:\n";
		//for(int i=0;i<cr.size();i++) cout << cr[i].first << cr[i].second << endl;
		//cout << "---------------------\n";*/
		q.pop();
		
		if(cd == target) return cr;
		if(cd>target) continue;
		//if(vis[cv]) continue;
		//vis[cv] = true;
		
		for(int i=0;i<a[cv].size();i++){
			//if(!vis[a[cv][i]]){
			if(a[cv][i].first.first > target) continue;
			
			vector<pair<int,int>> temp;
			copy(cr.begin(), cr.end(), back_inserter(temp));
			temp.push_back({a[cv][i].first}); 
			//cout << "ADJ: " << a[cv][i].first.first << " " << a[cv][i].first.second << " " << a[cv][i].second << endl;
			q.push({{a[cv][i].first},cd+a[cv][i].second,temp});
				//dis[a[cv][i]] = 1 + dis[cv];
				//q.push(a[cv][i]);
			//}
		}
	}
	return v;
}

int n,T;
int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> T;
    
    int numRow = 30;
    for (int line = 1; line <= numRow; line++){ 
		int C = 1;
		for (int i = 1; i <= line; i++) {
			//cout << C << " ";
			triangle[line][i] = C;
			C = C * (line - i) / i;  
		}
	}
	/*
	for (int line = 1; line <= numRow; line++){ 
		for (int i = 1; i <= line; i++) {
			cout << triangle[line][i] << " ";
		}
		cout << '\n';
	}*/
	
	for(int i=1;i<=numRow;i++){ //Same row neighbours
		for(int j=1;j<=i;j++){
			if(j!=1) a[{i,j}].push_back({{i,j-1},triangle[i][j-1]});
			if(j!=i) a[{i,j}].push_back({{i,j+1},triangle[i][j+1]});
		}
	}
	
	for(int i=1;i<numRow;i++){ //Lower tier child
		for(int j=1;j<=i;j++){
			a[{i,j}].push_back({{i+1,j},triangle[i+1][j]});
			a[{i,j}].push_back({{i+1,j+1},triangle[i+1][j+1]});
			//if(i == 1  && j == 1) {
				//cout << "dist " << triangle[i+1][j] << triangle[i+1][j+1] << triangle[2][0] << triangle[2][1] << triangle[2][2] << endl;
			//}
		}
	}
	
	for(int i=2;i<=numRow;i++){ //Upper tier child
		for(int j=1;j<=i;j++){
			a[{i,j}].push_back({{i-1,j},triangle[i-1][j]});
			if(j != 1) a[{i,j}].push_back({{i-1,j-1},triangle[i-1][j-1]});
		}
	}
		
    for(int t=1;t<=T;t++){
		cout << "Case #"<<t<<":\n";
		cin >> n;
		vector<pair<int,int>> r = search(n);
		for(int i=0;i<r.size();i++) cout << r[i].first << " " << r[i].second << '\n';
    }
}

#include <bits/stdc++.h>
using namespace std;

#define whatis(x) cout << #x << ": " << x << endl;
#define display(x) cout << #x << ": "; for (auto i : x) cout << i << " "; cout << endl;

int T,x,y;
//pair<int,string> dp[32][][]
pair<int,string> solve(int step,int xPos, int yPos, string output){
    int minAns = 1e9;
    string retStr = "IMPOSSIBLE";
    //if(abs(xPos) > abs(x)) return {1e9,"IMPOSSIBLE"};
    //if(abs(yPos) > abs(y)) return {1e9,"IMPOSSIBLE"};
    if(abs(xPos) > 999999) return {1e9,"IMPOSSIBLE"};
    if(abs(yPos) > 999999) return {1e9,"IMPOSSIBLE"};

    if(xPos == x && yPos == y) return {0,output};
    pair<int,string> f1 = solve(step+1,xPos+(1<<step),yPos,output+"E");
    int a1 = f1.first;
    string v1 = f1.second;
    a1++;
    if(a1 < minAns) {minAns=a1; retStr=v1;}

    pair<int,string> f2 = solve(step+1,xPos-(1<<step),yPos,output+"W");
    int a2= f2.first;
    string v2 = f2.second;
    a2++;
    if(a2 < minAns) {minAns=a2; retStr=v2;}

    pair<int,string> f3 = solve(step+1,xPos,yPos+(1<<step),output+"N");
    int a3 = f3.first;
    string v3 = f3.second;
    a3++;
    if(a3 < minAns) {minAns=a3; retStr=v3;}

    pair<int,string> f4 = solve(step+1,xPos,yPos-(1<<step),output+"S");
    int a4 = f4.first;
    string v4 = f4.second;
    a4++;
    if(a4 < minAns) {minAns=a4; retStr=v4;}
    /*
    minAns = min(1+solve(step+1,xPos+(1<<step),yPos,output+"E"),minAns);
    minAns = min(1+solve(step+1,xPos-(1<<step),yPos,output+"W"),minAns);
    minAns = min(1+solve(step+1,xPos,yPos+(1<<step),output+"N"),minAns);
    minAns = min(1+solve(step+1,xPos,yPos-(1<<step),output+"S"),minAns);*/
    return {minAns,retStr};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    
    cin >> T;
    for(int t=1;t<=T;t++){
        cout << "Case #" << t << ": ";
        cin >> x >> y;
        cout << solve(0,0,0,"").second << '\n';
    }
}

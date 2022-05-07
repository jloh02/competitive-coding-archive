#include <bits/stdc++.h>
using namespace std;

#define whatis(x) cout << #x << ": " << x << endl;
#define display(x) cout << #x << ": "; for (auto i : x) cout << i << " "; cout << endl;

int n,d,x,a,b;
vector<tuple<int,int,int>>stops;

bool can(int f){
    int stopNum=0;
    int fuelLeft = f;
    int dist=0;

    while(true){
        //cout << d-dist << " " << fuelLeft << endl;
        if(d-dist <= fuelLeft) return true;
        while((get<2>(stops[stopNum]) < f || get<0>(stops[stopNum]) < dist) && stopNum < n) stopNum++;
        //whatis(stopNum);
        if(stopNum == n) return false;
        if((get<0>(stops[stopNum])-dist) > fuelLeft) return false;
        //cout << "Stopped at " << get<0>(stops[stopNum]) << " " << get<1>(stops[stopNum]) << " " << get<2>(stops[stopNum]) << endl;
        fuelLeft += get<1>(stops[stopNum])-(get<0>(stops[stopNum])-dist);
        dist = get<0>(stops[stopNum]);
        stopNum++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    
    cin >> n >> d;
    for(int i=0;i<n;i++){
        cin >> x >> a >> b;
        stops.push_back({x,a,b});
    }
    sort(stops.begin(),stops.end());
    int ans = 0;
    for(int i=1;i<=d;i++){
        if(can(i)) {ans = i; break;}
    }
    cout << ans;

    /*
    int hi=d,lo=1;
    while(hi > lo){
        int mid = (hi+lo)/2;
        bool keyi = can(mid);
        whatis(mid);
        whatis(keyi);
        if(keyi) hi = mid;
        else lo = mid+1;        
    }
    cout << (hi+lo)/2;
    */
}

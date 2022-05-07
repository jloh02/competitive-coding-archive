#include <bits/stdc++.h>
using namespace std;

#define whatis(x) cout << #x << ": " << x << endl;
#define display(x) cout << #x << ": "; for (auto i : x) cout << i << " "; cout << endl;

int T,a,b,x,y;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    
    cin >> T;
    for(int t=1;t<=T;t++){
        cout << "Case #" << t << ":";
        cin >> a >> b;
        for(int i=-1e9;i<1e9;i+=50){
            for(int j=-1e9;j<1e9;j+=50){
                cout << i << " " << j << endl;
                string s;
                cin >> s;
                if(s == "HIT"){x=i;y=j;goto bina;}
            }
        }
        bina:
            int lo = x, hi = 1e9,mid;
            while(hi > lo){
                mid = (hi+lo)/2;
                cout << mid << " " <<  y << endl;
                string s;
                cin >> s;
                if(s == "HIT"){
                    lo = mid+1;
                }
                else hi = mid;
            }
            

    }
}

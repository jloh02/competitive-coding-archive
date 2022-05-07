#include <bits/stdc++.h>
using namespace std;

#define INF 9e9

#define whatis(x) cout << #x << ": " << x << endl;
#define display(x) cout << #x << ": "; for (auto i : x) cout << i << " "; cout << endl;

struct fenwick{
    vector<long long> fw;
    int N;
    fenwick(int n){
        N = n;
        fw.assign(N+1,0);
    }
    
    fenwick(vector<int> v):fenwick(v.size()){
        for(int i=0;i<N;i++){
            add(i+1,v[i]);
        }
    }
    
    void add(int x, int v) {
        for (; x<=N; x+=x&(-x)) {
            fw[x] += v; 
        }
    }
    
    long long sum(int x) {
        int res = 0;
        for(; x; x-=x&(-x)) {
            res += fw[x];
        }
        return res;	
    }
    
    long long sum(int i,int j){
        return sum(j)-sum(i-1);
    }

    int select(long long k) {                       // O(log^2 n)
        int lo = 1, hi = N;
        for (int i = 0; i < 30; ++i) {              // 2^30 > 10^9; usually ok
            int mid = (lo+hi) / 2;                  // BSTA
            (sum(1, mid) < k) ? lo = mid : hi = mid;// See Section 3.3.1
        }
        return hi;
    }
};


uint64_t factDP[300001];
void genFactMod(int N,int p){
    int n=1;
    uint64_t res=1;
    while(n<=N){
        res = (res*n)%p;
        factDP[n] = res;
        n++;
    }
}

uint64_t factmod(uint64_t n,int p){
    return factDP[n];
}

int n;
uint64_t a[300001], b[300001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 

    for(int i=0;i<300001;i++) factDP[i] = INF;
    genFactMod(300000,1000000007);

    cin >> n;
    bool increasing = true;
    bool decreasing = true;

    for(int i=0;i<n;i++){
        cin >> a[i];
        b[i] = a[i];
        if(i && a[i] < a[i-1]) increasing = false;
        if(i && a[i] > a[i-1]) decreasing = false;
    }
    if(increasing) {
        cout << 1;
        return 0;
    }
    else if(decreasing){
        //cout << fact(n-1,1000000007);
        //cout << "FACT ";
        cout << factmod(n,1000000007);
        return 0;
    }
    else{
        sort(b,b+n);
        map<int,int> elemToPos;
        for(int i=0;i<n;i++){
            elemToPos[b[i]] = i+1;
        }
        //cout << factmod(50,1000000007) << endl;

        uint64_t c=1; //ANSWER
        vector<int> init(n);
        init.assign(n,1);
        fenwick ft(init); //Init all to 1
        for(int i=0;i<n-1;i++){ //ignore last one --> always 1
            int pos = elemToPos[a[i]];
            uint64_t numSkip = ft.sum(pos-1);
            ft.add(pos,-1);
            //whatis(pos);
            // whatis(numSkip);
            if(numSkip == 0) continue;
            //whatis(i);
            //whatis(n-(i+1));
            c += ((numSkip%1000000007)*factmod(n-(i+1),1000000007))%1000000007;
            c %= 1000000007;
            //c += (numSkip*fact(n-(i+1),1000000007))%1000000007;
            
            //whatis(numSkip*factmod(n-(i+1),100000));
            //cout << "------------------------\n";
        }
        cout << c;
    }
}

#include <bits/stdc++.h>
using namespace std;

#define whatis(x) cout << #x << ": " << x << endl;
#define display(x) cout << #x << ": "; for (auto i : x) cout << i << " "; cout << endl;

#define INF 1e9
#define MAX_V 501 // if |V| > 450, you cannot use Floyd Washall's

int a[MAX_V][MAX_V]; //Adjacency matrix; No path -> INF
int main(){

    //Initialization
    int V, E, K; scanf("%d %d %d", &V, &E, &K);
    for (int u = 0; u < V; ++u) {
        for (int v = 0; v < V; ++v)
            a[u][v] = INF;
        a[u][u] = 0;
    }

    //Build Graph
    for (int i = 0; i < E; ++i) {
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        u--;
        v--;
        a[u][v] = w;                                // directed graph
        a[v][u] = w;
    }

    //Floyd Warshall
    for (int k = 0; k < V; ++k)                    // loop order is k->u->v
        for (int u = 0; u < V; ++u)
            for (int v = 0; v < V; ++v)
                a[u][v] = min(a[u][v], a[u][k]+a[k][v]);

    vector<int> specCities(K);
    for(int i=0;i<K;i++) {
        cin >> specCities[i];
        specCities[i]--;
    }

    /*
    //Print
    for (int u = 0; u < V; ++u)
        for (int v = 0; v < V; ++v)
            printf("APSP(%d, %d) = %d\n", u, v, a[u][v]);*/

    int minD = INF;
    sort(specCities.begin(),specCities.end());
    
    for(int e=0;e<K;e++){
        for(int b=e+1;b<K;b++){
            //cout << "AB " << specCities[e]<< " " << specCities[b] << endl;
            int AB = a[specCities[e]][specCities[b]];
            if(AB == INF) continue;
            for(int c=e+1;c<K;c++){
                if(c==b) continue;
                for(int d=c+1;d<K;d++){
                    if(d==b) continue;
                    //cout << "CD " << specCities[c]<< " " << specCities[d] << endl;
                    int CD = a[specCities[c]][specCities[d]];
                    if(CD == INF) continue;
                    minD = min(minD,AB+CD);
                }  
            }
        }
    }
    cout << minD;
    
}

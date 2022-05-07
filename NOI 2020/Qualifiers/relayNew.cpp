#include <bits/stdc++.h>
using namespace std;

#define whatis(x) cout << #x << ": " << x << endl;
#define display(x) cout << #x << ": "; for (auto i : x) cout << i << " "; cout << endl;

#define INF 1e15 //Infinity 
 
const int sz=100001;			//Maximum possible number of vertices
vector<pair<int,int> > a[sz];	//Adjacency list
uint64_t dis[sz]; 				//Stores shortest distance
bool vis[sz]={0}; 				//Determines whether the node has been visited or not
 
void Dijkstra(int source, int n) //Algorithm for SSSP (Source, Num vertices)
{
    for(int i=0;i<n;i++){ //Set initial distances to Infinity
        dis[i]=INF;
        vis[i]=false;
    }
    
    //Comparator for priority queue
    class prioritize{
        public: 
        bool operator ()(pair<int, uint64_t>&p1 ,pair<int, uint64_t>&p2){
            return p1.second > p2.second;
        }
    };
    
    //Priority queue to store vertex,weight pairs
    priority_queue<pair<int,uint64_t> ,vector<pair<int,uint64_t> >, prioritize> pq; 
    
    //Pushing the source with distance from itself as 0
    pq.push(make_pair(source,dis[source]=0));
    while(!pq.empty())
    {
        pair<int, uint64_t> curr=pq.top(); //Current vertex
        pq.pop();
        int cv=curr.first;
        uint64_t cw=curr.second; //'cw' the final dist for vertex
        if(vis[cv]) //If vertex visited, continue
            continue;
        vis[cv]=true; 
        
        //cout << "Adjacent List Size: " << a[cv].size() << endl;
        
        //Iterating through all adjacent vertices
        for(int i=0;i<a[cv].size();i++){ 
            //If not visited & distance to node through parent < actl distance,
            //Update node 
            if(!vis[a[cv][i].first] && a[cv][i].second+cw<dis[a[cv][i].first]) {
                //Set the new distance and add to priority queue
                pq.push(make_pair(a[cv][i].first,(dis[a[cv][i].first]=a[cv][i].second+cw)));
                //cout << "Set " << a[cv][i].first << " as " << a[cv][i].second+cw << endl;
            }
        }
    }
}



int main(){

    //Initialization
    int V, E, K; scanf("%d %d %d", &V, &E, &K);
    //Build Graph
    for (int i = 0; i < E; ++i) {
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        u--;
        v--;
        a[u].push_back({v,w});                                // directed graph
        a[v].push_back({u,w});
    }

    vector<int> specCities(K);
    for(int i=0;i<K;i++) {
        cin >> specCities[i];
        specCities[i]--;
    }
    sort(specCities.begin(),specCities.end());    
    specCities.erase(specCities.begin(),specCities.begin()+2);

    //display(specCities);

    uint64_t minD = INF;
    
    for(int c=0;c<K-2;c++){
        Dijkstra(specCities[c],V);
        for(int d=c+1;d<K-2;d++){
            //cout << "CD " << specCities[c]<< " " << specCities[d] << endl;
            uint64_t CD = dis[specCities[d]];//a[specCities[c]][specCities[d]];
            //cout << c << " " << d << " " << dis[d] << endl;
            if(CD == INF) continue;
            minD = min(minD,CD);
        }  
    }
        
    cout << minD+1;
    
}

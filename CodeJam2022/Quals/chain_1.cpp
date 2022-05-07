#include <bits/stdc++.h>

using namespace std;

int TEST, n;
uint64_t f[100001];
vector<int> adj[100001];
bool activated[100001];
// pair<int, int> maxFrom[100001]; //<leftNode,maxVal>

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> TEST;
  for (int test = 1; test <= TEST; test++)
  {
    cin >> n;
    unordered_set<int> inits;
    for (int i = 1; i <= n; i++)
    {
      cin >> f[i];
      adj[i].clear();
      inits.insert(i);
    }
    for (int i = 1; i <= n; i++)
    {
      int p;
      cin >> p;
      inits.erase(p);
      adj[i].push_back(p);
    }

    vector<int> initVec(inits.begin(), inits.end());
    sort(initVec.begin(), initVec.end());

    uint64_t maxFun = 0;
    activated[0] = true;
    f[0] = 0;
    do
    {
      for (int i = 1; i <= n; i++)
        activated[i] = false;
      uint64_t totFun = 0;
      for (int i = 0; i < initVec.size(); i++)
      {
        int node = initVec[i];
        uint64_t fun = 0;
        while (!activated[node])
        {
          if (f[node] > fun)
            fun = f[node];
          activated[node] = true;
          // cout << "Processing " << node << endl;
          if (adj[node].size() == 0)
            break;
          node = adj[node][0];
        }
        // for (int j = 1; j <= n; j++)
        //   cout << activated[j];
        // cout << endl;
        totFun += fun;
      }
      if (totFun > maxFun)
        maxFun = totFun;

      // for (int i = 0; i < initVec.size(); i++)
      //   cout << initVec[i] << " ";
      // cout << ": " << totFun << endl;
    } while (next_permutation(initVec.begin(), initVec.end()));

    // stack<tuple<int, int, int>> s; //<node, parentNode, max>
    // s.push(make_tuple(0, 0, 0));
    // while (!s.empty())
    // {
    //   tuple<int, int, int> curr = s.top();
    //   cout << "Checking " << get<0>(curr) << " " << get<1>(curr) << " " << get<2>(curr) << endl;
    // }
    cout << "Case #" << test << ": " << maxFun << endl;
  }
}
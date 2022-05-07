#include <bits/stdc++.h>

using namespace std;

int TEST, n, x;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream in("in-pan.txt");
  // cin.rdbuf(in.rdbuf());

  cin >> TEST;
  for (int test = 1; test <= TEST; test++)
  {
    cin >> n;
    vector<int> pancakes;
    for(int i=0;i<n;i++){
      cin >> x;
      pancakes.push_back(x);
    }

    int front=0,back=n-1;
    int lastMin = 0;
    int pay = 0;
    while(front <= back){
      // cout << pancakes[front] << " " << pancakes[back] << " " << lastMin << " " << pay << endl;
      if(pancakes[front] > pancakes[back]){
        if(pancakes[back] >= lastMin){
          pay++;
          lastMin = pancakes[back];
        }
        back--;
      }
      else {
        if(pancakes[front] >= lastMin){
          pay++;
          lastMin = pancakes[front];
        }
        front++;
      }
    }

    cout << "Case #" << test << ": " << pay << endl;
  }
}
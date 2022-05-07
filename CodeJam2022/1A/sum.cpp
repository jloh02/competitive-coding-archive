#include <bits/stdc++.h>

using namespace std;

int TEST, n;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> TEST;
  for (int test = 1; test <= TEST; test++)
  {
    cin >> n;

    //Stage A
    uint64_t fullSum = 0;
    int count = 0;
    for (uint64_t base = 1; base <= 1e8; base *= 10)
    {
      cout << base << " " << 2 * base << " " << 4 * base << " " << 8 * base << " ";
      fullSum += 15 * base;
      count += 4;
    }
    int num = 1e9;
    vector<int> bigs;
    while (count < n)
    {
      cout << num << " ";
      fullSum += num;
      bigs.push_back(num);
      num--;
      count++;
    }
    cout << endl;

    //Stage B
    int x;
    for (int i = 0; i < n; i++)
    {
      cin >> x;
      fullSum += x;
      if (x > 1e8)
        bigs.push_back(x);
    }

    //Stage C
    uint64_t target = fullSum / 2;
    // cout << "TARGET " << target << endl;
    sort(bigs.begin(), bigs.end());
    int bigI = bigs.size() - 1;
    while (target > 1e9)
    {
      target -= bigs[bigI];
      cout << bigs[bigI] << " ";
      bigI--;
    }
    int numZ = 0;
    while (target > 0)
    {
      // cout << "TARGET " << target << endl;
      int mod;
      while ((mod = target % 10) == 0)
      {
        target /= 10;
        numZ++;
      }
      if (mod >= 8)
      {
        cout << "8";
        for (int i = 0; i < numZ; i++)
          cout << "0";
        cout << " ";
        mod -= 8;
        target -= 8;
      }
      if (mod >= 4)
      {
        cout << "4";
        for (int i = 0; i < numZ; i++)
          cout << "0";
        cout << " ";
        mod -= 4;
        target -= 4;
      }
      if (mod >= 2)
      {
        cout << "2";
        for (int i = 0; i < numZ; i++)
          cout << "0";
        cout << " ";
        mod -= 2;
        target -= 2;
      }
      if (mod >= 1)
      {
        cout << "1";
        for (int i = 0; i < numZ; i++)
          cout << "0";
        cout << " ";
        mod -= 1;
        target -= 1;
      }
    }
    cout << endl;
  }
}
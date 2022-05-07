#include <bits/stdc++.h>
using namespace std;

int heights[1000000] = {};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,q,y;
	cin >> n >> q;
	for(int i=0;i<n;i++) cin >> heights[i];
	for(int i=0;i<q;i++){
		cin >> y;
		unsigned long long sum = 0;
		unsigned long long subSum = 1;
		for(int i=0;i<n;i++){
			if(heights[i] <= y){
				sum+=subSum;
				subSum++;
			}
			else subSum = 1;
			//cout << sum << " " <<subSum << endl;
		}
		printf("%llu\n",sum);
	}
}

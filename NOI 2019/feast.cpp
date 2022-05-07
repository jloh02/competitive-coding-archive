#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,k,A;
	cin >> n >> k;
	int allPos = true;
	long long sumA = 0;
	long long sumB = 0;
	long long negativeSum = 0;
	for(int i=1;i<=n;i++){
		cin >> A;
		if(A<0) {
			allPos = false;
			int x = -A;
			negativeSum += x;
		//	cout << negativeSum
		}
		else if(!allPos) sumB += A;
		else sumA += A;
	}
	if(k == 1 && !allPos){
		if(sumA+sumB-negativeSum > sumA && sumA+sumB-negativeSum > sumB) cout << sumA+sumB-negativeSum << endl;
		else if(sumA > sumB) cout << sumA << endl;
		else cout << sumB << endl;
	}
	else cout << sumA+sumB << endl;
}

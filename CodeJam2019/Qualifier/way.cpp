#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin >> T;
	for(int t=0;t<T;t++){
		int n;
		cin >> n;
		n = n*2-2;
		char move;
		printf("Case #%d: ",t+1);
		while(n--){
			cin >> move;
			if(move == 'E') cout << 'S';
			else cout << 'E';
		}
		cout << endl;
	}
}

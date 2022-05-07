#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin >> T;
	for(int t=0;t<T;t++){
		int a,b=0;
		cin >> a;
		int pos4;
		while((pos4 = to_string(a).find('4')) != string::npos){
			string output = "1";
			int pow10 = to_string(a).length()-pos4-1;
			//cout << pow10 << endl;
			for(int i=0;i<pow10;i++) output += "0";
			int outputNum = stoi(output);
			a-=outputNum;
			b+=outputNum;
		}
		printf("Case #%d: %d %d\n",t+1,a,b);
	}
}

#include <bits/stdc++.h>
using namespace std;

int main(){
  int T,F;
  cin >> T >> F;
  for(int t=0;t<T;t++){
	vector<int> indexOfEachColor[5];
	for(int i=0;i<119;i++){
		char response;
		cout << i*5+1 << endl;
		cin >> response;
		int intRes = (int)(response-'A');
		indexOfEachColor[intRes].push_back(i*5);
	}
	int colorWithoutFirst = 0;
	for(int i=0;i<5;i++) if(indexOfEachColor[i].size() != 24) {colorWithoutFirst = i; break;}
	string output = (char)((int)"A"+colorWithoutFirst) + "";
	
	vector<int> indexOfEachColor2[5];
	for(int i=0;i<23;i++){
		int startIndex = indexOfEachColor[colorWithoutFirst][i] + 1;
		char response;
		cout << startIndex+1 << endl;
		cin >> response;
		int intRes = (int)(response-'A');
		indexOfEachColor2[intRes].push_back(startIndex);
	}
	int colorWithout2nd = 0;
	for(int i=0;i<5;i++) if(indexOfEachColor2[i].size() != 6 && indexOfEachColor2[i].size() != 0) {colorWithout2nd = i; break;}
	output += (char)((int)"A"+colorWithout2nd);
	
	vector<int> indexOfEachColor3[5]; //Color 3
	for(int i=0;i<5;i++){  //Change limit
		int startIndex = indexOfEachColor2[colorWithout2nd][i] + 1;  //eachcolor2, colorWithout2nd
		char response;
		cout << startIndex+1 << endl;
		cin >> response;
		int intRes = (int)(response-'A');
		indexOfEachColor3[intRes].push_back(startIndex);   //Color 3
	}
	int colorWithout3 = 0;  //without3
	for(int i=0;i<5;i++) if(indexOfEachColor3[i].size() != 6 && indexOfEachColor3[i].size() != 0) {colorWithout3 = i; break;} //3 values
	output += (char)((int)"A"+colorWithout3);  //Change
	
	vector<int> indexOfEachColor4[5]; //Color 3
	for(int i=0;i<2;i++){  //Change limit
		int startIndex = indexOfEachColor4[colorWithout3][i] + 1;  //eachcolor2, colorWithout2nd
		char response;
		cout << startIndex+1 << endl;
		cin >> response;
		int intRes = (int)(response-'A');
		indexOfEachColor4[intRes].push_back(startIndex);   //Color 3
	}
	int colorWithout4 = 0;  //without3
	for(int i=0;i<5;i++) if(indexOfEachColor4[i].size() != 6 && indexOfEachColor4[i].size() != 0) {colorWithout4 = i; break;} //3 values
	output += (char)((int)"A"+colorWithout4);  //Change
	
	if(output.find('A') == 0) output+='A';
	else if(output.find('B') == 0) output+='B';
	else if(output.find('C') == 0) output+='C';
	else if(output.find('D') == 0) output+='D';
	else output+='E';
	
  }
  
}

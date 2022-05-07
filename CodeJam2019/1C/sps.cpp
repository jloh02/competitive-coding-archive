#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T,a;
	cin >> T;
	for(int t=0;t<T;t++){
		cin >> a;
		string orders[a];
		int maxStrLength = 0;
		for(int i=0;i<a;i++) {
			cin >> orders[i];
			if(orders[i].length() > maxStrLength)  maxStrLength = orders[i].length();
		}
		//cout << maxStrLength<<endl;
	
		//set<char> typesEachPos[maxStrLength];
		/*
		for(int i=0;i<a;i++) {
			int size = orders[i].length();
			for(int j=0;j<maxStrLength;j++){
				typesEachPos[j].insert(orders[i][j%size]);
			}
		}*/
		
		string output = "";		
		vector<bool> beaten (a,false);
		for(int j=0;j<maxStrLength;j++){
			set<char> types;
			vector<int> indexes[3];
			for(int i=0;i<a;i++) {
				if(!beaten[i]) {
					char chAt = orders[i][j%orders[i].length()];
					types.insert(chAt);
					if(chAt == 'R') indexes[0].push_back(i);
					else if(chAt == 'P') indexes[1].push_back(i);
					else indexes[2].push_back(i);
				}
				if(types.size() == 3) break;
			}
			//printf("Size of Set at %d: %d\n",j,types.size());
			if(types.size() == 3){
				output = "IMPOSSIBLE";
				break;
			}
			else if(types.size() == 1){				
				if(types.count('R') == 1) output += 'P';
				else if(types.count('S') == 1) output += 'R';
				else output += 'S';
				
				if(output[output.length()-1] == 'R') for(int m=0;m<indexes[2].size();m++) beaten[indexes[2][m]] = true;
				else if(output[output.length()-1] == 'P') for(int m=0;m<indexes[0].size();m++) beaten[indexes[0][m]] = true;
				else for(int m=0;m<indexes[1].size();m++) beaten[indexes[1][m]] = true;
			}
			else if(types.size() == 2){
				string toAppend = output; //Special Case
				
				if(types.count('R') == 0) output += 'S';
				else if(types.count('S') == 0) output += 'P';
				else output += 'R';
				
				if(output[output.length()-1] == 'R') for(int m=0;m<indexes[2].size();m++) beaten[indexes[2][m]] = true;
				else if(output[output.length()-1] == 'P') for(int m=0;m<indexes[0].size();m++) beaten[indexes[0][m]] = true;
				else for(int m=0;m<indexes[1].size();m++) beaten[indexes[1][m]] = true;
				
				if(j==maxStrLength-1) {
					output += toAppend;
					j++;
					set<char> typesTemp;
					for(int q=0;q<a;q++) {
						if(!beaten[q]) {
							char tempCharAt = orders[q][j%orders[q].length()];
							typesTemp.insert(tempCharAt);
						}
						if(typesTemp.size() == 3) break;
					}
					if(typesTemp.count('R') == 1) output += 'P';
					else if(typesTemp.count('S') == 1) output += 'R';
					else output += 'S';
				}
			}
			else break;
		}
		if(output.length()>500)output = "IMPOSSIBLE";
		string outputStr = "Case #" + to_string(t+1) + ": "+output+"\n";
		printf(outputStr.c_str());
	}
}

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
int lookup[MAX][MAX]; 
int lookup2[MAX][MAX]; 

// Fills lookup array lookup[n][n] for all possible values of 
// query ranges 
void preprocess(int arr[], int n) 
{ 
    // Initialize lookup[][] for the intervals with length 1 
    for (int i = 0; i < n; i++) 
        lookup[i][i] = i; 
  
    // Fill rest of the entries in bottom up manner 
    for (int i=0; i<n; i++) 
    { 
        for (int j = i+1; j<n; j++) 
  
           // To find minimum of [0,4], we compare minimum of 
           // arr[lookup[0][3]] with arr[4]. 
           if (arr[lookup[i][j - 1]] > arr[j]) 
              lookup[i][j] = lookup[i][j - 1]; 
           else
              lookup[i][j] = j; 
    } 
} 
void preprocess2(int arr[], int n) 
{ 
    // Initialize lookup[][] for the intervals with length 1 
    for (int i = 0; i < n; i++) 
        lookup2[i][i] = i; 
  
    // Fill rest of the entries in bottom up manner 
    for (int i=0; i<n; i++) 
    { 
        for (int j = i+1; j<n; j++) 
  
           // To find minimum of [0,4], we compare minimum of 
           // arr[lookup[0][3]] with arr[4]. 
           if (arr[lookup2[i][j - 1]] > arr[j]) 
              lookup2[i][j] = lookup2[i][j - 1]; 
           else
              lookup2[i][j] = j; 
    } 
} 
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T,N,K,C,D;	
	T = 8;//cin >> T;
	if(T<=8){
		for(int t=0;t<T;t++){
			//cin >> N >> K;
			N = 100000,K=1;
			int cInput[N],dInput[N];			
			for(int i=0;i<N;i++)cInput[i] = 100000;//cin >> cInput[i];	
			for(int i=0;i<N;i++)dInput[i] = 100000;//cin >> dInput[i];	
			int output = 0;
			for(int i=0;i<N;i++){
				for(int j=i;j<N;j++){
					int maxD=0,maxC=0;
					for(int a=i;a<=j;a++){
						if(maxC<cInput[a])maxC=cInput[a];
						if(maxD<dInput[a])maxD=dInput[a];
					}
					//cout << "Test" << endl;
					if(abs(maxD-maxC) <= K) output++;
				}
			}
			printf("Case #%d: %d\n",t+1,output);
		} 
	}
	else {
		for(int t=0;t<T;t++){
			//cin >> N >> K;
			N = 1000,K=1;
			int arr[N],arr2[N];
			for(int i=0;i<N;i++)arr [i] = 100000;//cin >> arr[i];	
			for(int i=0;i<N;i++)arr2[i] = 100000;// cin >> arr2[i];	
			preprocess(arr, N);
			preprocess2(arr2, N);
			int output = 0;
			for(int i=0;i<N;i++){
				for(int j=i;j<N;j++){
					//cout << arr[lookup[i][j]] << " " << arr2[lookup2[i][j]] << endl;
					if(abs(arr[lookup[i][j]]-arr2[lookup2[i][j]]) <= K) output++;
				}
			}
			printf("Case #%d: %d\n",t+1,output);
		} 
	}
}


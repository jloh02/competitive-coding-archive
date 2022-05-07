#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{

    if(b == 0) {
            return a;
    }
    else {
        return gcd(b, a % b);
    }
}

int binarySearch(vector<int> arr, int l, int r, int x) 
{ 
    while (l <= r) { 
        int m = l + (r - l) / 2; 
  
        // Check if x is present at mid 
        if (arr[m] == x) 
            return m; 
  
        // If x greater, ignore left half 
        if (arr[m] < x) 
            l = m + 1; 
  
        // If x is smaller, ignore right half 
        else
            r = m - 1; 
    } 
  
    // if we reach here, then element was 
    // not present 
    return -1; 
} 

vector<int> primes;
vector<int> corresponds;

int main(){
	int t,n,l;
	cin >> t;
	while(t--){
		cin >> n >> l;
		int firstVal, secondVal;
		cin >> firstVal >> secondVal;
		int divisor = gcd(firstVal,secondVal);
		//cout << "Divisor: " << divisor << endl;
		corresponds.push_back(firstVal/divisor);
		corresponds.push_back(divisor);
		int nextVal = secondVal/divisor;
		corresponds.push_back(nextVal);
		printf("%d %d %d ",firstVal/divisor,divisor,nextVal);
		int temp;
		cin >> temp;
		for(int i=3;i<l;i++){
			int val;
			cin >> val;
			nextVal = val/nextVal;
			corresponds.push_back(nextVal);			
			printf("%d ",nextVal);
		}
		primes = corresponds;
		sort(primes.begin(),primes.end());
		
		cout << endl;
		for(int i=0;i<l+1;i++){
			cout << primes[i] << " ";
		}
		primes.erase( unique( primes.begin(), primes.end() ), primes.end() );
		cout << endl;
		cout << endl;
		for(int i=0;i<l+1;i++){
			cout << primes[i] << " ";
		}
		cout << endl;
		cout << endl;
		for(int i=0;i<l+1;i++){
			cout << binarySearch(primes,0,primes.size()-1,corresponds[i]) << " ";
		}
		cout << endl;
		cout << endl;
		for(int i=0;i<l+1;i++){
			cout << (char)(binarySearch(primes,0,primes.size()-1,corresponds[i])+'A');
		}
	}
}

//Sum of Subset reduces to 0/1 Knapsack
#include <bits/stdc++.h>
using namespace std;
bool sos(int arr[],int sum,int n){
	bool m[n+1][sum+1] ={0};
	
	for(int i=0;i<=n;i++){
		m[i][0] = true;
	}
	for(int j=1;j<=sum;j++){
		m[0][j] = false;
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){
			if(j>= arr[i-1]){
			
				m[i][j] = m[i-1][j] || m[i-1][j-arr[i-1]];
			}
			else m[i][j] = m[i-1][j];
		}
	}
	
	return m[n][sum];
}

int main() {
   int n,s;
   cin>>n>>s;
   int arr[n];
   
   
   for(int i=0;i<n;i++)
     cin>>arr[i];
     
     
    if(sos(arr,s,n)){
    	cout<<"yes,it is possible to get sum\n";
    }
    else cout<<"No, we dont have any subset which satisfy the give sum\n";
	return 0;
}
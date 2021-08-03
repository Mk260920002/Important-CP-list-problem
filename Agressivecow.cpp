#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t;
	cin>>t;
	while(t--){
		
	int n,c;
	cin>>n>>c;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
		sort(arr,arr+n);
		
		//binary search apply
		int lb=0;
		int ub=1e9;
    int ans=0;
		while(lb<=ub){
		int	mid=(lb+ub)/2;
		int cow=1;
		
		int prev=arr[0];
		for(int i=0;i<n;i++){
			if(arr[i]-prev>=mid){
				prev=arr[i];
				cow++;
			}
			if(cow==c){
			  ans=mid;
			  break;
			}
		}
		if(cow==c){
			lb=mid+1;
		}
		else{
			ub=mid-1;
		}
			
		}
		cout<<ans<<endl;
		
	}
	return 0;
}

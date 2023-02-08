/*
Platform :- Codechef
Contest :- Codechef Cook off February 2023
Approach :- You need to reduce the expression first , 3*(mean - median) --> for (a,b,c) in sorted order
            3 * ((a+b+c)/3 - median) => 3*( (a+b+c) - 3*median)/3 ==> ((a+b+c) - 3*b)   --  median is middle element and 'b' is middle of (a,b,c) as they are in sorted order
            --> Now we need to find best 'c' -> (c = 3*b - (b+a)) ==>  [ c = 2*b - a ]
            So we will find the closest value to this 'c' for all the pairs (a,b) .
            1. Sort the array in increasing order 
            2. Find all the pairs (a,b) bruteforce 
            3. for each pairs binary search on remaining values and find the best values closest to 'c' 
            4. Find the score and store the minimum of all 
Time Complexity :- O(n^2 log n) --> n^2 --  for all pairs (a,b) , log n  for binary search to find 'c'
*/
#include <bits/stdc++.h>
using namespace std;

int search(vector<long long>&A,int start,int end,long long req){
    int mid = (start+end)/2;
    int ans = A.size()-1;
    while(start<=end){
        if(A[mid]>=req){
            ans = min(ans,mid);
            end = mid-1;
            mid = (start+end)/2;
        }
        else{
            start = mid+1;
            mid = (start+end)/2;
        }
    }
    return ans;
} 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    
	    vector<long long> A(n);
	    
	    for(int i=0;i<n;++i){
	        cin>>A[i];
	    }
	    sort(A.begin(),A.end());
	    
	    long long ans = 1e18;
	    long long req,cur,score;
	    
	    for(int i=0;i<(n-2);++i){
	        for(int j=i+1;j<(n-1);++j){
	            req = 2ll*A[j] - A[i];
	           // cout<<i<<" "<<j<<" -- "<<req<<" ";
	            int idx = search(A,j+1,n-1,req);
	            cur = A[idx];
	            score = abs(cur - req);
	            ans = min(ans,score);
	            if(idx>(j+1)){
	                idx--;
	            }
	          //  cout<<idx<<" -- ";
	            cur = A[idx];
	           // cout<<cur<<"\n";
	            score = abs(cur - req);
	            ans = min(ans,score);
	        }
	    }
	    
	    cout<<ans<<"\n";
	}
	return 0;
}

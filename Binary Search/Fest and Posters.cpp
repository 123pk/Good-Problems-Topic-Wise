/*
Platform :- GeeksforGeeks
Link :- https://practice.geeksforgeeks.org/contest/job-a-thon-18-hiring-challenge/problems#
Approach :- Binary Search in range (1 to 10^15) ,
            why till 10^15 , because we can finish all the given problems in worst case in (10^7)*10^7 time = 10^14 , here in worst case you can consider 
            there is just one student and he take 10^7 time per problem and you have to solve 10^7 problems.
            
Time Complexity :- O( n log n)
*/
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


 // } Driver Code Ends
class Solution {
  public:
    long long minimumTime(int N, int NUM, vector<int> &time) {
        // code here
        //binary search
        
        long long start = 1,end = 1e15,mid = (start+end)/2ll;
        long long ans = 1e15;
        while(start<=end){
            
            long long score = 0;
            for(auto&x:time){
                long long val = x;
                val = mid/x;
                score += val;
            }
            
            if(score >= NUM){
                //reduce the time
                ans = min(ans,mid);
                end = mid-1ll;
                mid = (start+end)/2ll;
            }
            else{
                start = mid+1ll;
                mid  = (start+end)/2ll;
            }
        }
        
        return ans;
    }
};


// { Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int NUM;
        scanf("%d",&NUM);
        
        
        vector<int> time(N);
        Array::input(time,N);
        
        Solution obj;
        long long res = obj.minimumTime(N, NUM, time);
        
        cout<<res<<endl;
        
    }
}
  // } Driver Code Ends

/*
Platform :- Leetcode 
Approach :- You need to find the best order which will increase the 'money' required ,
             let 'Value' = ( cashback - cost ) this is the amount we are adding to 'money' we have .
             - So we want to sort our transactions in increaseing order of 'Value'.
             - If we have multiple -ve such values we will prioirtise the one which have smallest 'Cashback' as it will reduce the 'Value'
             We will use a comparator function for this .
             - We can use binary search on findinng the minimum starting 'money'

Time Complexity :- O(n log n)
*/
bool comp(vector<int>&P,vector<int>&Q){
    int val1 = P[1]-P[0];
    int val2 = Q[1] - Q[0];
    if(val1<0 && val2<0)return P[1]<Q[1];
    else if(val1>=0 && val2>=0)return P[0]>Q[0];
    return val1<0; 
}
class Solution {
public:
  
    long long minimumMoney(vector<vector<int>>& transactions) {

        sort(transactions.begin(),transactions.end(),comp);
        
        
         //binary search problem as we have a fixed range
         long long start = 0,end = 1e18,mid = (start+(end-start)/2ll);
         long long ans = 1e18;
         while(start<=end){
             
             long long cur = mid;
             for(auto&x:transactions){
                 long long z = x[0];
                 if(cur<z){
                     cur = -1ll;
                     break;
                 }
                 long long y = x[1];
                cur += (y-z);
                 
             }

             if(cur<0){
                 //increase the value
                 start = mid+1ll;
                 mid = (start+(end-start)/2ll);
             }
             else{
                 ans = min(ans,mid);
                 end = mid-1ll;
                 mid = (start + (end - start)/2ll);
             }

         }
         return ans;
        
    }
};

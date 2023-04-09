/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 340
Video Solution( Hindi ) :- https://youtu.be/1LxCKQ2emQc
Time complexity :- O( n log e) ~ e = 10^9
*/
class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        //binary serach 
        sort(nums.begin(),nums.end());
         
        int n = nums.size();
        
        //let us find smallest difference value with p pairs 
        long long start = 0, end = 1e9,mid = (start+end)/2ll;
        long long ans = 1e9;
        while(start<=end){
             
            
            //we will count how many pairs we can form if only 
            //absolute difference <= mid is allowed 
            int c = 0;
            for(int i=n-2;i>=0;--i){
                int dif = nums[i+1]-nums[i];
                if(dif<=mid){
                    c++;
                    --i;
                }
            }
            //if we can form p pairs 
            if(c>=p){
                //decrease the mid value and check for that
                ans = min(ans,mid);
                
                end = mid-1ll;
                mid = (start+end)/2ll;
            }
            else{
                //else we need to increse the value
                start = mid+1ll;
                mid = (start+end)/2ll;
            }
        }
        int val = ans;
        return val;
    }
};

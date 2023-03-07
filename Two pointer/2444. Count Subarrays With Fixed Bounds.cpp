/*
Platform :- Leetcode
Appraoch :- This is a good problem to check your two pointer skills ,
            Here we want a O(n) or O(n log n) solution ,
            O(n) -- > give us hint at greedy and two pointer
            O(n log n) --> give us hint at Binary search , but how can we use binary serach ? There is no way we can use binary serach here .
            SO We are left with O(n) solution , using two pointer or greedy way .
            
            So if we are at ith index and can we want to find number of 'Fixed Bound subarrays' ending at index 'i' ?
            --> First obervation we can have Fixed bound subarray if we have (mxK and mnK) present <= i 
            --> Similarly we maitain one start array which points to the start of valid array , or we need to have value from[start , i]
                in range [mnK,mxK] . 
            --> Now we can have all from 'x' to this index 'i' such that 'x' in in range [start, bounday_index] , 
            --> what is bounday_index ,  it is the index beyond which we dont have both the [ 'mnK' and 'mxK']
                bounday_index is last occurence of either 'mnK' or 'mxK', beyond this we will loose one of mnK or mxK.
            
            --> So for all index 'i' we check if there is valid range , then we also find 'boundary_index' and no of subarrays ending at 'i'
                is (boundary_index - start)+1
            
 Implementation :- 
            --> We need 5 variables 
            i. small_idx -- this stores the latest index of 'mnK' ( largest_index <= i)
           ii. big_idx -- this stores the latest index of 'mxK' ( largest index <= i)
          iii. cur_mn -- it stores the current minimum value in range from [start, i]
           iv. cur_mx --  it stores the current minimum value in range from [start, i]
            v. start -- it stores the starting index of valid range ( valid means all values should be in range mnK <= x <= mxK ) 
            
            Now for each index , we if start = -1, it means we are looking for a range with valid value 
            if at any index we have nums[i] == mn or nums[i] == mx , we update our 'small_idx' and 'big_idx'
            at any index if we have start != -1 , and neither small_idx and big_idx = -1, this means we have a range where we already have
            'mnK' and 'mxK' values . Now number of valid subarray ending at index 'i' = (boundary_index - start)+1
            here **bounday index = min( small_idx, big_idx)** ,
            we add this to our answer.
            
*/
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int mn, int mx) {
         
        long long ans = 0;
        /*
         --> We need 5 variables 
            i. small_idx -- this stores the latest index of 'mnK' ( largest_index <= i)
           ii. big_idx -- this stores the latest index of 'mxK' ( largest index <= i)
          iii. cur_mn -- it stores the current minimum value in range from [start, i]
           iv. cur_mx --  it stores the current minimum value in range from [start, i]
            v. start -- it stores the starting index of valid range ( valid means all values should be in range mnK <= x <= mxK ) 

        */
        int small_idx = -1,big_idx = -1;
        int cur_mn = INT_MAX , cur_mx = 0;
        int start = -1;

        int n = nums.size();

        for(int i=0;i<n;++i){
            //this means we are looking for a value in range which could be 
            //start index of our valid range
            if(start == -1){

                //if current vlaue is in range [ mn <= nums[i] <= mx ]
                if(mn<=nums[i] && nums[i]<=mx){
                    //we update the current maximum and current minimum
                    cur_mn = nums[i];
                    cur_mx = nums[i];
                    //similarly updating the indexes too if current vlaue is [mn] or [mx]
                    if(nums[i] == mn)small_idx = i;
                    if(nums[i] == mx)big_idx = i;
                    start  = i;
                    
                    //if mx and mn are equal than this value is a valid range so we update ans
                    if(mx == mn)ans++;
                }
                 continue;
            }
            else{
                //here we have a start value and all values in [start , i-1] are in range (mn<=x && x<= mx)
                //thats why start is not -1
                //we are updating current maximum and current minimum value
                cur_mn = min(cur_mn,nums[i]);
                cur_mx = max(cur_mx,nums[i]);
                
                //if this vlaue is out of range it means we close our previous ragne 
                //and again start serachin for valid one and make start = -1
                if(cur_mn<mn || cur_mx > mx){
                    start = -1;
                    small_idx = -1;
                    big_idx = -1;
                }
                else{
                    //if current vaulue is [mn]
                    if(nums[i] == mn){
                       //we will change smallidx
                       small_idx = i;
                       if(nums[i] == mx)big_idx = i;

                       //if we already have [mn] in current range 
                        //then number of valid subarray ending at 'i'
                        // is min(small_idx,big_idx) - start + 1;
                       long long count = 0;
                       if(big_idx != -1){
                           count = min(small_idx,big_idx) - start;
                           count++;
                       }
                        ans += count;
                    }
                    else if(nums[i] == mx){

                        //we will change big_idx 
                        big_idx = i;
                        long long count = 0;

                        //if we already have [mn] in current range 
                        //then number of valid subarray ending at 'i'
                        // is min(small_idx,big_idx) - start + 1;
                        if(small_idx != -1){
                            count = min(small_idx,big_idx) - start;
                            count++;
                         }
                        
                        ans += count;
                    }
                    else{
                        //how many subarray which will end at
                        //index i 
                        //if we already have [mn] in current range 
                        //then number of valid subarray ending at 'i'
                        // is min(small_idx,big_idx) - start + 1;
                        if(small_idx!=-1 && big_idx != -1){
                            long long count = (min(small_idx,big_idx) - start)+1;
                            ans += count;
                        }
                    }
                }
            }
        }


        return ans;
    }
};

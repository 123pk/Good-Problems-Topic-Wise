/*
Platform :- Leetcode
Appraoch :- This is a good problem to check your two pointer skills ,
            Here we want a O(n) or O(n log n) solution ,
            O(n) -- > give us hint at greedy and two pointer
            O(n log n) --> give us hint at Binary search , but how can we use binary serach ? There is no way we can use binary serach here .
            SO We are left with O(n) solution , using two pointer or greedy way .
            
            So we are at ith index and we want to find number of 'Fixed Bound subarrays' ending at index 'i' .
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

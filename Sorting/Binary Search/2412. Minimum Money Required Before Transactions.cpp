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

/*
=========================================================
Problem: Single Element in a Sorted Array
Difficulty: Medium

My Approach:
- Used binary search to find the single element.
- Since the array is sorted, every element except one appears
  exactly twice.
- Analyzed the pairing pattern around the middle element.
- Used the length of the current search range and its parity
  to determine which side could contain the single element.
- Divided the possible cases based on:
      len % 4
- Depending on the pairing of nums[mid] with nums[mid-1] or
  nums[mid+1], adjusted the search boundaries accordingly.
- Continued reducing the search space until the single element
  was found.

Example:

    nums = [1, 1, 2, 2, 3, 4, 4, 5, 5]

    Pairing:

    1 1 | 2 2 | 3 | 4 4 | 5 5
                  ↑
               Single

The single element breaks the normal pairing pattern.

Key Concepts:
- Binary Search
- Sorted Array
- Pairing Pattern
- Parity
- Modulo
- Search-Space Reduction

Core Observation:
Every element appears exactly twice except one element.

Before the single element, pairs follow one pattern,
and after the single element, the pairing pattern shifts.

I used the parity of the current search range and:

    len % 4

to determine how the pair containing nums[mid] affects
the direction of the binary search.

Time Complexity:
O(log n)

The search range is reduced approximately by half
in every iteration.

Space Complexity:
O(1)

Only a constant number of variables are used.

What I Learned:
- Binary search problems can sometimes be solved by deriving
  the structural pattern of the search range rather than
  memorizing a fixed template.
- Parity can provide useful information about how elements
  are paired in a sorted array.
- Modulo reasoning can help determine which half of the
  search space contains the answer.
- The key to binary search is identifying an invariant that
  tells us which half can be safely discarded.

Potential Improvement:
- The current solution uses several separate cases based on
  the parity of len and len % 4.
- The implementation can be simplified by deriving a more
  direct invariant using the parity of mid and its paired
  element.

Problem Solving Status:
🟢 Independently Solved
🟢 Accepted
🟢 O(log n) Time
🟢 O(1) Auxiliary Space

=========================================================
*/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int high=nums.size()-1;
        int low=0;
        int mid;
        if(high==low)
        return nums[0];
        while(high>=low){
            int len=high-low+1;
            mid=(high+low)/2;
            if(nums[mid]!=nums[mid-1]&&nums[mid]!=nums[mid+1])
            break;
            if(len%2==0&&len%4==0){
             if(nums[mid]==nums[mid-1])
             low=mid+1;
             else if(nums[mid]==nums[mid+1])
             low=mid+2;
             if(high==low)
             return nums[high];
            }
            else if(len%2==0&&(len+2)%4==0){
                if(nums[mid]==nums[mid-1])
                high=mid-2;
               if(high==low)
             return nums[high];
            }
            else if(len%2==1&&((len-1)/2)%2==0){
             if(nums[mid]==nums[mid-1])
             high=mid-2;
             else if(nums[mid]==nums[mid+1])
             low=mid+2;
              if(high==low)
             return nums[high];
            }
            else if(len%2==1&&((len-1)/2)%2==1){
                if(nums[mid]==nums[mid-1])
                low=mid+1;
                else if(nums[mid]==nums[mid+1])
                high=mid-1;
                if(high==low)
                return nums[low];

            }     
        }
        return nums[mid];
    }
};
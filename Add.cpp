/*
=========================================================
Problem: Add Two Numbers
Difficulty: Medium

My Approach:
- Used two pointers to traverse the two linked lists.
- Performed digit-by-digit addition while maintaining a
  carry value.
- For each pair of digits:
      sum = digit1 + digit2 + carry
- Stored the resulting digit using:
      digit = sum % 10
- Updated the carry using:
      carry = sum / 10
- Modified the existing nodes to store the calculated digits.
- When one linked list ended before the other, continued
  processing the remaining list using the existing carry.
- If a carry remained after processing the final digits,
  created a new node containing the carry.
- Returned the list containing the resulting number.

Example:

    l1: 2 → 4 → 3
    l2: 5 → 6 → 4

Addition:

    2 + 5 = 7
    4 + 6 = 10 → digit = 0, carry = 1
    3 + 4 + 1 = 8

Result:

    7 → 0 → 8

Key Concepts:
- Linked List Traversal
- Elementary Addition
- Carry Handling
- Pointer Manipulation
- Different Linked List Lengths

Core Observation:
The numbers are stored in reverse order, so the linked lists
can be traversed from the head while performing normal
addition from the least significant digit.

For every position:

    digit = sum % 10
    carry = sum / 10

Time Complexity:
O(max(m, n))

where:
m = length of l1
n = length of l2

Space Complexity:
O(1) auxiliary space

Apart from the final carry node that may need to be created.

What I Learned:
- Linked lists can naturally represent numbers when digits
  are stored in reverse order.
- Carry must be propagated to the next position.
- Different list lengths can be handled by continuing
  traversal of the longer list.
- Reusing existing nodes can reduce additional memory
  requirements.

Potential Improvement:
- Simplify the implementation by handling missing nodes
  uniformly instead of maintaining separate branches for
  the three possible combinations of list availability.
- Consider whether modifying the input lists is desirable
  or whether a separate result list would make the solution
  cleaner.

Problem Solving Status:
🟢 Independently Solved
🟢 O(1) Auxiliary Space

=========================================================
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        int sum=0;
        int digit=0;
        ListNode *temp1=l1;
        ListNode *temp2=l2;
        while(temp1!=nullptr||temp2!=nullptr){
            if(temp1!=nullptr&&temp2!=nullptr){
                sum=carry+temp1->val+temp2->val;
                digit=sum%10;
                 carry=sum/10;
                 temp1->val=digit;
                 temp2->val=digit;
                 if(temp1->next==nullptr&&temp2->next==nullptr){
                    if(carry>0){
                    ListNode*head=new ListNode(carry);
                    temp2->next=head;
                  }
                  return l2;
                 }
                temp1=temp1->next;
                temp2=temp2->next;
            }
            else if(temp1==nullptr&&temp2!=nullptr){
                sum=carry+temp2->val;
                digit=sum%10;
                 carry=sum/10;
                 temp2->val=digit;
                if(temp2->next==nullptr){
                  if(carry>0){
                    ListNode*head=new ListNode(carry);
                    temp2->next=head;
                  }
                  return l2;
                }
                temp2=temp2->next;
            }
            else if(temp1!=nullptr&&temp2==nullptr){
                sum=carry+temp1->val;
                 digit=sum%10;
                 carry=sum/10;
                 temp1->val=digit;
                if(temp1->next==nullptr){
                  if(carry>0){
                    ListNode*head=new ListNode(carry);
                    temp1->next=head;
                  }
                  return l1;
                }
                temp1=temp1->next;
            }
        }
        return l2;
    }
};
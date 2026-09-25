/*
Problem: Intersection of Two Linked Lists
Difficulty: Easy

My Approach:
Used two pointers, one starting at the head of each linked list.
Each pointer moves through its own list normally. When a pointer reaches
the end of its list, it is redirected to the head of the other list.

This makes both pointers travel through the same combined path length:
length(A) + length(B). Therefore, if an intersection exists, both
pointers eventually meet at the intersection node. If there is no
intersection, the pointers eventually reach the end without finding one.

Key Concepts:
- Linked Lists
- Two Pointers
- Pointer Switching
- Intersection Detection
- Equalizing Traversal Distance

Time Complexity: O(m + n)

Space Complexity: O(1)

What I Learned:
When two linked lists have different lengths, switching each pointer to
the other list after reaching the end effectively eliminates the length
difference without explicitly calculating the lengths.

Future Improvement / Optimization Opportunity:
The algorithm is already optimal at O(m + n) time and O(1) auxiliary
space. The termination logic could be simplified by allowing both
pointers to naturally reach nullptr instead of using an additional
counter.

Revision Note:
For linked-list intersection problems, think about making both pointers
travel the same total distance rather than explicitly finding the length
difference.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * temp1=headA;
        ListNode *temp2=headB;
        int i=0;
        while(temp1!=temp2){
            if(temp1->next==nullptr){
            temp1=headB;
             i++;
             if(i==2)
             return nullptr;
            }
            else
            temp1=temp1->next;
            if(temp2->next==nullptr)
            temp2=headA;
            else
            temp2=temp2->next;
        }
        return temp1;
    }
};
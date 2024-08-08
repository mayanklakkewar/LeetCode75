/*

Problem Satement -

Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]
Example 2:


Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]

*/

// Code - 



class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head; // If the list is empty or has only one node, return it as is.
        }

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even; // Keep the start of the even list to later append it to the odd list

        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next; // Link odd node to the next odd node
            odd = odd->next; // Move odd pointer

            even->next = odd->next; // Link even node to the next even node
            even = even->next; // Move even pointer
        }

        odd->next = evenHead; // Attach the even list after the odd list

        return head; // The head of the modified list
    }
};
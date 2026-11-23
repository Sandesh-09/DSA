/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* swapPairs(struct ListNode* head) {
    if(head==NULL || head->next==NULL) return head;

    struct ListNode* second_next= head->next;
    head->next=swapPairs(second_next->next);
    second_next->next=head;
    return second_next;
}
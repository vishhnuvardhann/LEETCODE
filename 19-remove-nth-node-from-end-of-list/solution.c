// 0 ms | 10.3 MB
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode dummy = {0, head};
    struct ListNode *fast = &dummy;
    struct ListNode *slow = &dummy;

    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }

    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    struct ListNode *temp = slow->next;
    slow->next = slow->next->next;
    free(temp);

    return dummy.next;
}
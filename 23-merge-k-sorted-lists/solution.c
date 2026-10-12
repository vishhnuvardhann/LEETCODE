// 4 ms | 14.5 MB

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* a, struct ListNode* b) {
    struct ListNode dummy = {0, NULL};
    struct ListNode *current = &dummy;

    while (a != NULL && b != NULL) {
        if (a->val <= b->val) {
            current->next = a;
            a = a->next;
        } else {
            current->next = b;
            b = b->next;
        }
        current = current->next;
    }

    current->next = (a != NULL) ? a : b;
    return dummy.next;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0) {
        return NULL;
    }

    while (listsSize > 1) {
        int mergedSize = 0;

        for (int i = 0; i < listsSize; i += 2) {
            if (i + 1 < listsSize) {
                lists[mergedSize++] = mergeTwoLists(lists[i], lists[i + 1]);
            } else {
                lists[mergedSize++] = lists[i];
            }
        }

        listsSize = mergedSize;
    }

    return lists[0];
}

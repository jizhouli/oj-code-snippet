/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stddef.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val) {
    if (!head) return NULL;
    
    struct ListNode* newHead = NULL;
    struct ListNode* preKill = head;
    struct ListNode* node = head;
    
    while (node) {
        // get node point to val node and set to preKill
        while(node && (node->val != val)) {
            if (!newHead) newHead = node;
            preKill = node;
            node = node->next;
        }
        
        // skip continuous val
        while (node && (node->val == val)) node=node->next;
        
        if (preKill->next != node)
            preKill->next = node;
    }
    
    return head;
}

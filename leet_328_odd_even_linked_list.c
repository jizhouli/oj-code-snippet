#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* oddEvenList(struct ListNode* head) {
    if (head == NULL
        || head->next == NULL
        || head->next->next == NULL)
        return head;

    struct ListNode* odd = head;
    struct ListNode* even = head->next;

    struct ListNode* p = odd;
    struct ListNode* q = even;
    struct ListNode* r = q->next;
    int cnt = 3;
    while(r != NULL) {
        if (cnt % 2 == 1) {
            p->next = r;
            p = p->next;
        } else {
            q->next = r;
            q = q->next;
        }

        r = r->next;
        cnt++;
    }
    p->next = NULL;
    q->next = NULL;

    p->next = even;
    return odd;
}

int main(int argc, char* argv[]) {
    struct ListNode* list = NULL;
    struct ListNode* p = NULL;
    for (int i=0;i<3;i++) {
        //struct ListNode* node = new struct ListNode();
        struct ListNode* pnode = (struct ListNode*)malloc(sizeof(struct ListNode));
        pnode->val = i+1;
        pnode->next = NULL;

        if (p == NULL)
            p = pnode;
        else {
            p->next = pnode;
            p = p->next;
            //printf("%d: %d 0x%08x 0x%08x\n", i, p->val, p, p->next);
        }

        if (list == NULL)
            list = p;
    }

    printf("singly linked list: ");
    for (p = list;p != NULL; p=p->next) {
        printf("%d ", p->val);
    }
    printf("\n");

    list = oddEvenList(list);

    printf("odd even list: ");
    for (p = list;p != NULL; p=p->next) {
        printf("%d ", p->val);
    }
    printf("\n");

}

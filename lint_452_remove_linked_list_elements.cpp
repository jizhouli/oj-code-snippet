#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /**
     * @param head a ListNode
     * @param val an integer
     * @return a ListNode
     */
    ListNode *removeElements(ListNode *head, int val) {
        ListNode *pNew = NULL;
        ListNode *pre = NULL;
        ListNode *p = head;
        while (p) {
            if (p->val == val) {
                ListNode *tmp = p;
                p = p->next;
                free(tmp);
            } else {
                if (!pNew)
                    pNew = p;
                if (pre)
                    pre->next = p;
                pre = p;

                p = p->next;
                pre->next = NULL; /*斩断*/
            }
        }

        return pNew;
    }
};

int main(int argc, char* argv[]) {
    ListNode *pNextNode = NULL;
    int val = 20160212;
    for (int i=70; i>0; i--) {
        ListNode *p = (ListNode*)malloc(sizeof(ListNode));
        p->val = i%7==0 ? val : i;
        p->next = pNextNode;

        pNextNode = p;
    }
    cout << "old list address: " << pNextNode << endl;

    Solution solution;
    ListNode* pNew = solution.removeElements(pNextNode, val);
    cout << "new list address: " << pNew << endl;

    ListNode* p=pNew;
    while (p != NULL) {
        ListNode* pDel = p;
        p = p->next;
        cout << pDel->val << " -> ";

        free(pDel);
    }

    cout << "NULL" << endl;
    return 0;
}

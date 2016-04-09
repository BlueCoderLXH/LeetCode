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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
        {
            return head;
        }
        
        ListNode* p = head;
        while(p && p->next)
        {
            ListNode* next = p->next;
            
            // 相等, 删除next, 但不移动p
            if(p->val == next->val)
            {
                p->next = next->next;
                
                next->next = NULL;
                delete next;
            }
            // 不相等, 移动p
            else
            {
                p = p->next;
            }
        }
        
        return head;
    }
};

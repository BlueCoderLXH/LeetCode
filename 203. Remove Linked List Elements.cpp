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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL)
        {
            return head;
        }
        
        ListNode* node = head;
        // 删除等于val的节点(非头结点)
        while(node != NULL)
        {
            if(node->next && node->next->val == val)
            {
                ListNode* tmp = node->next;
                
                node->next = tmp->next;
                
                delete tmp;
                tmp = NULL;
            }
            else
            {
                node = node->next;
            }
        }
        
        // 对头节点单独处理
        if(head->val == val)
        {
            ListNode* tmp = head;
            
            head = head->next;
            
            delete tmp;
            tmp = NULL;
        }
        
        return head;
    }
};

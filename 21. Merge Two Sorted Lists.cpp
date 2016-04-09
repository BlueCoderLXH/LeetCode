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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)
        {
            return l2;
        }
        
        if(l2 == NULL)
        {
            return l1;
        }
        
        // 新表的头尾
        ListNode* newHead = NULL;
        if(l1->val < l2->val)
        {
            newHead = l1;
            l1 = l1->next;
        }
        else
        {
            newHead = l2;
            l2 = l2->next;
        }
        
        ListNode* newRear = newHead;
        
        while(l1 != NULL || l2 != NULL)
        {
            // l1插入完毕, 继续插入l2
            if(l1 == NULL)
            {
                newRear->next = l2;
                newRear = l2;
                
                l2 = l2->next;
            }
            // l2插入完毕, 继续插入l1
            else if(l2 == NULL)
            {
                newRear->next = l1;
                newRear = l1;
                
                l1 = l1->next;
            }
            // l1, l2均不为空
            else
            {
                if(l1->val < l2->val)
                {
                    newRear->next = l1;
                    newRear = l1;
                    
                    l1 = l1->next;
                }
                else
                {
                    newRear->next = l2;
                    newRear = l2;
                    
                    l2 = l2->next;
                }
            }
        }
        
        newRear->next = NULL;
        return newHead;
    }
};

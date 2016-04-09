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
    ListNode* reverseList(ListNode* head) {
        // 链表为空(注:此链表为头节点)
        if(head == NULL)
        {
            return head;
        }
        
        stack<ListNode*> nodeStack;
        ListNode* p = head;
        // 节点依次压站
        while(p != NULL)
        {
            nodeStack.push(p);
            p = p->next;
        }
        
        ListNode* rear = NULL;
        // 逆序重新插入链表
        while(!nodeStack.empty())
        {
            ListNode* temp = nodeStack.top();
            
            if(rear == NULL)
            {
                rear = temp;
                temp->next = NULL;
                head = temp;
            }
            else
            {
                rear->next = temp;
                rear = temp;
                rear->next = NULL;
            }
            
            nodeStack.pop();
        }
        
        return head;
    }
};

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL)
        {
            return head;
        }
        
        int len = 0;
        ListNode* tmp = head;
        
        // 先求链表长度
        while(tmp != NULL)
        {
            tmp = tmp->next;
            len++;
        }
        
        int nth = len - n + 1;
        int i = 1;
        tmp = head;
        // 遍历到删除节点的前一个节点为止
        while(tmp != NULL && i < nth - 1)
        {
            tmp = tmp->next;
            i++;
        }
        
        // 删除头结点
        if(i == 1 && nth == 1)
        {
            ListNode* deleteNode = head;
            head = head->next;
            
            delete deleteNode;
            deleteNode = NULL;
        }
        else
        {
            // 删除对应节点
            ListNode* deleteNode = tmp->next;
            tmp->next = deleteNode->next;
            
            delete deleteNode;
            deleteNode = NULL;   
        }
        
        return head;
    }
};

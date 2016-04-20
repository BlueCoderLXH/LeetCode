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
    // 求链表的长度
    int getLen(ListNode* node) {
        int len = 0;
        
        while(node != NULL)
        {
            node = node->next;
            
            len++;
        }
        
        return len;
    }
    
    // 获取中间节点
    ListNode* getMidNode(ListNode* node, int mid) {
        int i = 0;
        
        while(node != NULL && i < mid)
        {
            node = node->next;
            i++;
        }
        
        return node;
    }
    
    // 逆转链表
    ListNode* revereList(ListNode* head) {
        ListNode* pre = head->next;
        ListNode* next = pre->next;
        
        while(next != NULL)
        {
            pre->next = next->next;
            
            // 将后续节点依次插入到链表头和第一个节点之间(最终逆序)
            ListNode *headNext = head->next;
            head->next = next;
            next->next = headNext;
            
            next = pre->next;
        }
        
        return head->next;
    }
    
    /*
        算法思想:
        找到链表的中间节点位置, 以此将链表分割为两个等份子链表, 将中间节点后面的子链表(第二个链表)逆序,
    然后依次判断两个子链表的元素即可
    
        这样就能保证时间复杂度为O(n), 空间复杂度为O(1)
    */
    bool isPalindrome(ListNode* head) {
        // 空链表或单节点链表默认为回文链表
        if(head == NULL || head->next == NULL)
        {
            return true;
        }
        
        // 第一个子链表头
        ListNode* firstListHead = head;
        
        int len = getLen(head);
        
        int secondListStart;
        if(len % 2 == 0)
        {
            secondListStart = len / 2 - 1;
        }
        else
        {
            secondListStart = len / 2;
        }
        
        // 第二个子链表头
        ListNode* secondListHead = revereList(getMidNode(head, secondListStart));
        
        int i = 0;
        // 顺序依次判断两个子链表的元素
        while(i < len / 2)
        {
            if(firstListHead->val != secondListHead->val)
            {
                return false;
            }
            
            firstListHead = firstListHead->next;
            secondListHead = secondListHead->next;
            
            i++;
        }
        
        return true;
    }
};

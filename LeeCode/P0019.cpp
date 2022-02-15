/*
��Ŀ������
    ����һ������ɾ������ĵ�����?n?����㣬���ҷ��������ͷ��㡣
ʾ�� 1��
���룺
    head = [1,2,3,4,5],n=2
�����
    [1,2,3,5]
ʾ�� 2��
���룺
    head = [1], n = 1
�����
    []
ʾ�� 3��
���룺
    head = [1,2], n = 1
�����
    [1]

*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p=head;
        int count=0;
        while (p!=NULL)
        {
            p=p->next;
            count++;
        }
        p=head;
        count=count-n-1;
        if (count==-1) return head->next;
        while (count>0)
        {
            count--;
            p=p->next;
        }
        p->next=p->next->next;
        return head;
    }
};
/*
��Ŀ������
    ����һ��ͷ���Ϊ head?�ķǿյ���������������м��㡣����������м��㣬�򷵻صڶ����м��㡣
ʾ�� 1��
���룺[1,2,3,4,5]
�����
    ���б��еĽ�� 3 (���л���ʽ��[3,4,5])
    ���صĽ��ֵΪ 3 �� (����ϵͳ�Ըý�����л������� [3,4,5])��
    ע�⣬���Ƿ�����һ�� ListNode ���͵Ķ��� ans��������
    ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, �Լ� ans.next.next.next = NULL.
ʾ��?2��
���룺[1,2,3,4,5,6]
�����
    ���б��еĽ�� 4 (���л���ʽ��[4,5,6])
    ���ڸ��б��������м��㣬ֵ�ֱ�Ϊ 3 �� 4�����Ƿ��صڶ�����㡣

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
    ListNode* middleNode(ListNode* head) {
        int count=0;
        ListNode *p=head;
        while (p!=NULL) 
        {
            count++;
            p=p->next;
        }
        p=head;
        count/=2;
        while (count>0) 
        {
            p=p->next;
            count--;
        }
        return p;
    }
};
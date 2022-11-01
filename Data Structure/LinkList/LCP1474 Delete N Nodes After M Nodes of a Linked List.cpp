/*
����������P1474
��������?head?����������?m?��?n. �����������������·�ʽɾ���ڵ�:
��ʼʱ��ͷ�ڵ���Ϊ��ǰ�ڵ�.
�����Ե�ǰ�ڵ㿪ʼ��ǰ?m?���ڵ�.
ɾ����������?n?���ڵ�.
�ظ����� 2 �� 3,?ֱ�����������β.
��ɾ����ָ�����֮��,?�����޸Ĺ���������ͷ�ڵ�.
ʾ�� 1:
����: head = [1,2,3,4,5,6,7,8,9,10,11,12,13], m = 2, n = 3
���: [1,2,6,7,11,12]
����: ����ǰ(m = 2)�����,  Ҳ�����Ժ�ɫ�ڵ��ʾ�Ĵ�����ͷ��㿪ʼ�Ľ��(1 ->2).
ɾ����������(n = 3)�����(3 -> 4 -> 5), ��ͼ���Ժ�ɫ����ʾ.
������ͬ�Ĳ���, ֱ�������ĩβ.
����ɾ�����֮��������ͷ���.
ʾ�� 2:
����: head = [1,2,3,4,5,6,7,8,9,10,11], m = 1, n = 3
���: [1,5,9]
����: ����ɾ�����֮��������ͷ���.
ʾ�� 3:
����: head = [1,2,3,4,5,6,7,8,9,10,11], m = 3, n = 1
���: [1,2,3,5,6,7,9,10,11]
ʾ��?4:
����: head = [9,3,7,7,9,10,8,2], m = 1, n = 2
���: [9,7,8]
��ʾ:
�����нڵ���Ŀ�ڷ�Χ [1, 104] ��
1 <= Node.val <= 106
1 <= m, n <= 1000
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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode* cur=head;
        while (cur->next!=NULL)
        {
            for (int i=1;i<m;i++) if (cur->next) cur=cur->next;
            if (!cur->next) return head;
            for (int i=0;i<n;i++)
            {
                if (cur->next->next) cur->next=cur->next->next;
                else
                {
                    cur->next=NULL;
                    return head;
                }
            }
            if (cur->next) cur=cur->next;
        }
        return head;
    }
};
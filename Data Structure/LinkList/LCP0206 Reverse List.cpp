/*
������������ת����
���㵥�����ͷ�ڵ� head �����㷴ת���������ط�ת�������
ʾ�� 1��
���룺head = [1,2,3,4,5]
�����[5,4,3,2,1]
ʾ�� 2��
���룺head = [1,2]
�����[2,1]
ʾ�� 3��
���룺head = []
�����[]
��ʾ��
�����нڵ����Ŀ��Χ�� [0, 5000]
-5000 <= Node.val <= 5000
���ף��������ѡ�õ�����ݹ鷽ʽ��ɷ�ת�����ܷ������ַ����������⣿
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
    ListNode* reverseList(ListNode* head) {
        ListNode* p;
        for(p=NULL;head;swap(head,p)) swap(p,head->next);
        return p;
    }
};
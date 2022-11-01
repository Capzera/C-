/*
����������P1290
����һ������������ý��?head��������ÿ������ֵ���� 0 ���� 1����֪��������һ���������ֵĶ����Ʊ�ʾ��ʽ��
���㷵�ظ���������ʾ���ֵ� ʮ����ֵ ��
ʾ�� 1��
���룺head = [1,0,1]
�����5
���ͣ��������� (101) ת��Ϊʮ������ (5)
ʾ�� 2��
���룺head = [0]
�����0
ʾ�� 3��
���룺head = [1]
�����1
ʾ�� 4��
���룺head = [1,0,0,1,0,0,1,1,1,0,0,0,0,0,0]
�����18880
ʾ�� 5��
���룺head = [0,0]
�����0
��ʾ��
����Ϊ�ա�
����Ľ������������?30��
ÿ������ֵ����?0 ���� 1��
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
    int power=0;
    int getDecimalValue(ListNode* head) {
        if(!head) return 0;
        int ans=getDecimalValue(head->next);
        if(!power) power=1;
        else power*=2;
        if (!head->val) return ans;
        return ans+power;
    }
};
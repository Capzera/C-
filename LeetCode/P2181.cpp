/*
����������P2181
����һ�������ͷ�ڵ� head ������������� 0 �ָ�����һ��������������� ���� �� ĩβ �Ľڵ㶼���� Node.val == 0 ��
����ÿ�������ڵ� 0 �����㽫����֮������нڵ�ϲ���һ���ڵ㣬��ֵ�������Ѻϲ��ڵ��ֵ֮�͡�
Ȼ������ 0 �Ƴ����޸ĺ������Ӧ�ú����κ� 0 ��
?�����޸ĺ������ͷ�ڵ� head ��
ʾ�� 1��
���룺head = [0,3,1,0,4,5,2,0]
�����[4,11]
���ͣ�
��ͼ��ʾ����������޸ĺ�����������
- ���Ϊ��ɫ�Ľڵ�֮�ͣ�3 + 1 = 4
- ���Ϊ��ɫ�Ľڵ�֮�ͣ�4 + 5 + 2 = 11
ʾ�� 2��
���룺head = [0,1,0,3,0,2,2,0]
�����[1,3,4]
���ͣ�
��ͼ��ʾ����������޸ĺ�����������
- ���Ϊ��ɫ�Ľڵ�֮�ͣ�1 = 1
- ���Ϊ��ɫ�Ľڵ�֮�ͣ�3 = 3
- ���Ϊ��ɫ�Ľڵ�֮�ͣ�2 + 2 = 4
��ʾ��
�б��еĽڵ���Ŀ�ڷ�Χ [3, 2 * 105] ��
0 <= Node.val <= 1000
�� ������������?Node.val == 0 �Ľڵ�
����� ���� �� ĩβ �ڵ㶼���� Node.val == 0
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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ans=new ListNode();
        ListNode* p=ans;
        while(head)
        {
            head=head->next;
            if (!head->next) break;
            if (!head->val)
            {
                ans->next=new ListNode();
                ans=ans->next;
            }
            else ans->val+=head->val;
        }
        return p;
    }
};
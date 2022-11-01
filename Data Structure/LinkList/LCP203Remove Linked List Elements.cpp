/*
����������
����һ�������ͷ�ڵ� head ��һ������ val ������ɾ���������������� Node.val == val �Ľڵ㣬������ �µ�ͷ�ڵ� ��
ʾ�� 1��
���룺head = [1,2,6,3,4,5,6], val = 6
�����[1,2,3,4,5]
ʾ�� 2��
���룺head = [], val = 1
�����[]
ʾ�� 3��
���룺head = [7,7,7,7], val = 7
�����[]
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
    ListNode* removeElements(ListNode* head, int val) {
        while (head!=NULL&&head->val==val) head=head->next;//����ͷ���ΪĿ���������
        ListNode* p=head;
        ListNode* r;
        while (p!=NULL)
        {
            if (p->val!=val) r=p;//��¼��һ���Ϸ���ַ
            else r->next=p->next;//�޸���һ���Ϸ���ַ��next
            p=p->next;//ָ��ǰ��
        }
        return head;
    }
};
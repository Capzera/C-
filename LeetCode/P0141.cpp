/*
����������
����һ�������ͷ�ڵ� head ���ж��������Ƿ��л���
�����������ĳ���ڵ㣬����ͨ���������� next ָ���ٴε���������д��ڻ��� 
Ϊ�˱�ʾ���������еĻ�������ϵͳ�ڲ�ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ����
ע�⣺pos ����Ϊ�������д���?��������Ϊ�˱�ʶ�����ʵ�������
��������д��ڻ�?���򷵻� true �� ���򣬷��� false ��
ʾ�� 1��
���룺head = [3,2,0,-4], pos = 1
�����true
���ͣ���������һ��������β�����ӵ��ڶ����ڵ㡣
ʾ��?2��
���룺head = [1,2], pos = 0
�����true
���ͣ���������һ��������β�����ӵ���һ���ڵ㡣
ʾ�� 3��
���룺head = [1], pos = -1
�����false
���ͣ�������û�л���
*/
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
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> us;
        while (head!=nullptr)
        {
            if (us.count(head)) return true;
            us.insert(head);
            head=head->next;
        }
        return false;
    }
};

/*
����������P0160
���������������ͷ�ڵ�?headA �� headB �������ҳ������������������ཻ����ʼ�ڵ㡣����������������ཻ�ڵ㣬���� null ��
ͼʾ���������ڽڵ� c1 ��ʼ�ཻ��
��Ŀ���� ��֤ ������ʽ�ṹ�в����ڻ���
ע�⣬�������ؽ����������� ������ԭʼ�ṹ ��
�Զ������⣺
����ϵͳ ���������£�����Ƶĳ��� ������ �����룩��
intersectVal - �ཻ����ʼ�ڵ��ֵ������������ཻ�ڵ㣬��һֵΪ 0
listA - ��һ������
listB - �ڶ�������
skipA - �� listA �У���ͷ�ڵ㿪ʼ����������ڵ�Ľڵ���
skipB - �� listB �У���ͷ�ڵ㿪ʼ����������ڵ�Ľڵ���
����ϵͳ��������Щ���봴����ʽ���ݽṹ��
��������ͷ�ڵ� headA �� headB ���ݸ���ĳ�����������ܹ���ȷ�����ཻ�ڵ㣬��ô��Ľ���������� ������ȷ�� ��
ʾ�� 1��
���룺intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
�����Intersected at '8'
���ͣ��ཻ�ڵ��ֵΪ 8 ��ע�⣬������������ཻ����Ϊ 0����
�Ӹ��Եı�ͷ��ʼ�������� A Ϊ [4,1,8,4,5]������ B Ϊ [5,6,1,8,4,5]��
�� A �У��ཻ�ڵ�ǰ�� 2 ���ڵ㣻�� B �У��ཻ�ڵ�ǰ�� 3 ���ڵ㡣
ʾ��?2��
���룺intersectVal?= 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
�����Intersected at '2'
���ͣ��ཻ�ڵ��ֵΪ 2 ��ע�⣬������������ཻ����Ϊ 0����
�Ӹ��Եı�ͷ��ʼ�������� A Ϊ [1,9,1,2,4]������ B Ϊ [3,2,4]��
�� A �У��ཻ�ڵ�ǰ�� 3 ���ڵ㣻�� B �У��ཻ�ڵ�ǰ�� 1 ���ڵ㡣
ʾ��?3��
���룺intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
�����null
���ͣ��Ӹ��Եı�ͷ��ʼ�������� A Ϊ [2,6,4]������ B Ϊ [1,5]��
���������������ཻ������ intersectVal ����Ϊ 0���� skipA �� skipB ����������ֵ��
�����������ཻ����˷��� null ��
��ʾ��
listA �нڵ���ĿΪ m
listB �нڵ���ĿΪ n
1 <= m, n <= 3 * 104
1 <= Node.val <= 105
0 <= skipA <= m
0 <= skipB <= n
��� listA �� listB û�н��㣬intersectVal Ϊ 0
��� listA �� listB �н��㣬intersectVal == listA[skipA] == listB[skipB]
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> um;
        ListNode* p=headA;
        while (p)
        {
            um.insert(p);
            p=p->next;
        }
        p=headB;
        while (p)
        {
            if (um.find(p)==um.end()) p=p->next;
            else break;
        }
        return p;
    }
};
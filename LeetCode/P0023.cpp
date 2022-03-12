/*
����������P0023
����һ���������飬ÿ�������Ѿ����������С�
���㽫��������ϲ���һ�����������У����غϲ��������
ʾ�� 1��
���룺lists = [[1,4,5],[1,3,4],[2,6]]
�����[1,1,2,3,4,4,5,6]
���ͣ������������£�
[
  1->4->5,
  1->3->4,
  2->6
]
�����Ǻϲ���һ�����������еõ���
1->1->2->3->4->4->5->6
ʾ�� 2��
���룺lists = []
�����[]
ʾ�� 3��
���룺lists = [[]]
�����[]
��ʾ��
k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] �� ���� ����
lists[i].length ���ܺͲ����� 10^4
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size(),tot=0;
        ListNode* ans=new ListNode(-1);
        ListNode* p=ans;
        vector<ListNode*> pointer(n);
        for(int i=0;i<n;i++) 
        {
            pointer[i]=lists[i];
            ListNode* q=lists[i];
            while (q!=NULL)
            {
                tot++;
                q=q->next;
            }
        }
        for(int i=0;i<tot;i++)
        {
            int min=INT_MAX,minloc=-1;
            for(int j=0;j<n;j++)
            {
                if (!lists[j]||lists[j]->val>=min) continue;
                if (lists[j]->val<min)
                {
                    min=lists[j]->val;
                    minloc=j;
                }
            }
            ListNode* q=new ListNode(min);
            ans->next=q;
            ans=ans->next;
            lists[minloc]=lists[minloc]->next;
        }
        return p->next;
    }
};
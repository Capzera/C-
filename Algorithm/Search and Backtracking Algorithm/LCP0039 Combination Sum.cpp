/*
����������P0039
����һ�� ���ظ�Ԫ�� ����������?candidates ��һ��Ŀ������?target?��
�ҳ�?candidates?�п���ʹ���ֺ�ΪĿ����?target �� ����?��ͬ��� �������б���ʽ���ء�����԰� ����˳�� ������Щ��ϡ�
candidates �е� ͬһ�� ���ֿ��� �������ظ���ѡȡ ���������һ�����ֵı�ѡ������ͬ������������ǲ�ͬ�ġ�?
���ڸ��������룬��֤��Ϊ?target �Ĳ�ͬ��������� 150 ����
ʾ��?1��
���룺candidates = [2,3,6,7], target = 7
�����[[2,2,3],[7]]
���ͣ�
2 �� 3 �����γ�һ���ѡ��2 + 2 + 3 = 7 ��ע�� 2 ����ʹ�ö�Ρ�
7 Ҳ��һ����ѡ�� 7 = 7 ��
������������ϡ�
ʾ��?2��
����: candidates = [2,3,5], target = 8
���: [[2,2,2,2],[2,3,3],[3,5]]
ʾ�� 3��
����: candidates = [2], target = 1
���: []
��ʾ��
1 <= candidates.length <= 30
1 <= candidates[i] <= 200
candidate �е�ÿ��Ԫ�ض� ������ͬ
1 <= target <= 500
*/
class Solution {
public:
    vector<vector<int>> ans;//�����
    vector<int> tmp;//��ʱ����ÿһ�����н�
    int n;
    void dfs(vector<int>candidates,vector<int> tmp,int target,int index)
    {
        if (!target)//���
        {
            ans.push_back(tmp);//�����
            return;
        }
        for(int i=index;i<n;i++)
        {
            if (target-candidates[i]>=0)//�����ǰ��ֵ��ʹtarget��Ϊ����
            {
                tmp.push_back(candidates[i]);//�����
                dfs(candidates,tmp,target-candidates[i],i);//��һ��dfs
                tmp.pop_back();//����
            }
            else break;//��Ϊcandidates���������Ż���֦
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this->n=candidates.size();
        sort(candidates.begin(),candidates.end());
        dfs(candidates,tmp,target,0);
        return ans;
    }
};
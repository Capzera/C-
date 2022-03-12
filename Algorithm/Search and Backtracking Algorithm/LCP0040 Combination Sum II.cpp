/*
����������P0040
����һ����ѡ�˱�ŵļ���?candidates?��һ��Ŀ����?target?���ҳ�?candidates?�����п���ʹ���ֺ�Ϊ?target?����ϡ�
candidates?�е�ÿ��������ÿ�������ֻ��ʹ��?һ��?��
ע�⣺�⼯���ܰ����ظ�����ϡ�?
ʾ��?1:
����: candidates =?[10,1,2,7,6,1,5], target =?8,
���:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
ʾ��?2:
����: candidates =?[2,5,2,1,2], target =?5,
���:
[
[1,2,2],
[5]
]
��ʾ:
1 <=?candidates.length <= 100
1 <=?candidates[i] <= 50
1 <= target <= 30
*/
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> tmp;
    int n;
    void dfs(vector<int> candidates,vector<int> tmp,int target,int index)
    {
        if (!target)
        {
            ans.push_back(tmp);
            return;
        }
        for(int i=index;i<n;i++)
        {
            if (i>index&&candidates[i]==candidates[i-1]) continue;
            if (target-candidates[i]>=0)
            {
                tmp.push_back(candidates[i]);
                dfs(candidates,tmp,target-candidates[i],i+1);
                tmp.pop_back();
            }
            else break;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        this->n=candidates.size();
        sort(candidates.begin(),candidates.end());
        dfs(candidates,tmp,target,0);
        return ans;
    }
};
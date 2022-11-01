/*
����������P0056
������ intervals ��ʾ���ɸ�����ļ��ϣ����е�������Ϊ intervals[i] = [starti, endi] ��
����ϲ������ص������䣬������?һ�����ص����������飬��������ǡ�ø��������е���������?��
ʾ�� 1��
���룺intervals = [[1,3],[2,6],[8,10],[15,18]]
�����[[1,6],[8,10],[15,18]]
���ͣ����� [1,3] �� [2,6] �ص�, �����Ǻϲ�Ϊ [1,6].
ʾ��?2��
���룺intervals = [[1,4],[4,5]]
�����[[1,5]]
���ͣ����� [1,4] �� [4,5] �ɱ���Ϊ�ص����䡣
��ʾ��
1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        int n=intervals.size(),i,st=intervals[0][0],ed=intervals[0][1];
        for(i=1;i<n;i++)
        {
            if (intervals[i][0]<=ed&&intervals[i][1]>ed) ed=intervals[i][1];
            else if (intervals[i][0]>ed)
            {
                ans.push_back({st,ed});
                st=intervals[i][0];
                ed=intervals[i][1];
            }
        }
        if(!ans.size()||st>ans[ans.size()-1][1]) ans.push_back({st,ed});
        else ans[ans.size()-1][1]=ed;
        return ans;
    }
};
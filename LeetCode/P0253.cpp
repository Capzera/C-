/*
����������P0253
����һ������ʱ�䰲�ŵ����� intervals ��
ÿ������ʱ�䶼�������ʼ�ͽ�����ʱ�� intervals[i] = [starti, endi] ������ ��������ҵ���С���� ��
ʾ�� 1��
���룺intervals = [[0,30],[5,10],[15,20]]
�����2
ʾ�� 2��
���룺intervals = [[7,10],[2,4]]
�����1
��ʾ��
1 <=?intervals.length <= 104
0 <= starti < endi <= 106
*/
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
		int n=intervals.size(),sptr=0,eptr=0;
        vector<int> start,end;
        for (auto& i:intervals) start.push_back(i[0]),end.push_back(i[1]);
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        while(sptr<n){
			if (start[sptr++]>=end[eptr]) eptr++;
		}
        return sptr-eptr;
    }
};
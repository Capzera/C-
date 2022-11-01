/*
����������P0954
����һ������Ϊż������������ arr��ֻ�ж� arr ����������������
 ������ÿ�� 0 <=?i < len(arr) / 2������ arr[2 * i + 1] = 2 * arr[2 * i]��?ʱ������ true�����򣬷��� false��
?
ʾ�� 1��
���룺arr = [3,1,3,6]
�����false
ʾ�� 2��
���룺arr = [2,1,2,6]
�����false
ʾ�� 3��
���룺arr = [4,-2,2,-4]
�����true
���ͣ������� [-2,-4] �� [2,4] ��������� [-2,-4,2,4] ���� [2,4,-2,-4]
?
��ʾ��
0 <= arr.length <= 3 * 104
arr.length ��ż��
-105 <= arr[i] <= 105
*/
class Solution {
public:
    static bool cmp(int a,int b){
        return abs(a)<abs(b);
    }
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int,int> um;
        set<int> s;
        for (int arrs:arr) um[arrs]++;
        if (um.count(0)&&um[0]%2) return false;
        s.insert(arr.begin(),arr.end());
        arr.assign(s.begin(),s.end());
        sort(arr.begin(),arr.end(),cmp);
        for (int i:arr) {
            if (um[i*2]<um[i]) return false;
            else um[i*2]-=um[i];
        }
        return true;
    }
};
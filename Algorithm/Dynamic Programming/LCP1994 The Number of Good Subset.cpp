/*
����������P1994
����һ����������?nums?�����?nums?��һ���Ӽ��У�����Ԫ�صĳ˻����Ա�ʾΪһ������ ������ͬ������ �ĳ˻�����ô���ǳ���Ϊ?���Ӽ�?��
�ȷ�˵�����?nums = [1, 2, 3, 4]?��
[2, 3]?��[1, 2, 3]?��?[1, 3]?�� ��?�Ӽ����˻��ֱ�Ϊ?6 = 2*3?��6 = 2*3?��?3 = 3?��
[1, 4] ��?[4]?���� ��?�Ӽ�����Ϊ�˻��ֱ�Ϊ?4 = 2*2 ��?4 = 2*2?��
���㷵�� nums?�в�ͬ��?��?�Ӽ�����Ŀ��?109 + 7?ȡ��?�Ľ����
nums?�е� �Ӽ�?��ͨ��ɾ�� nums?��һЩ������һ������ɾ����Ҳ����ȫ����ɾ����Ԫ�غ�ʣ��Ԫ����ɵ����顣
��������Ӽ�ɾ�����±겻ͬ����ô���Ǳ���Ϊ��ͬ���Ӽ���
ʾ�� 1��
���룺nums = [1,2,3,4]
�����6
���ͣ����Ӽ�Ϊ��
- [1,2]���˻�Ϊ 2 �����Ա�ʾΪ���� 2 �ĳ˻���
- [1,2,3]���˻�Ϊ 6 �����Ա�ʾΪ������ͬ������ 2 �� 3 �ĳ˻���
- [1,3]���˻�Ϊ 3 �����Ա�ʾΪ���� 3 �ĳ˻���
- [2]���˻�Ϊ 2 �����Ա�ʾΪ���� 2 �ĳ˻���
- [2,3]���˻�Ϊ 6 �����Ա�ʾΪ������ͬ������ 2 �� 3 �ĳ˻���
- [3]���˻�Ϊ 3 �����Ա�ʾΪ���� 3 �ĳ˻���
ʾ�� 2��
���룺nums = [4,2,3,15]
�����5
���ͣ����Ӽ�Ϊ��
- [2]���˻�Ϊ 2 �����Ա�ʾΪ���� 2 �ĳ˻���
- [2,3]���˻�Ϊ 6 �����Ա�ʾΪ������ͬ���� 2 �� 3 �ĳ˻���
- [2,15]���˻�Ϊ 30 �����Ա�ʾΪ������ͬ���� 2��3 �� 5 �ĳ˻���
- [3]���˻�Ϊ 3 �����Ա�ʾΪ���� 3 �ĳ˻���
- [15]���˻�Ϊ 15 �����Ա�ʾΪ������ͬ���� 3 �� 5 �ĳ˻���
��ʾ��
1 <= nums.length <= 105
1 <= nums[i] <= 30
*/
const long mod = 1e9+7;
class Solution {
public:
    long pow(long a, long e) {
        if(e == 0) return 1;
        if(e == 1) return a;
        long tmp = pow(a,e/2);
        return (e&1) ? ((tmp * tmp)%mod * a) % mod: (tmp * tmp) % mod;
    }
    int numberOfGoodSubsets(vector<int>& nums) {
        int cnt[31];
        memset(cnt, 0, sizeof(cnt));
        for(int e:nums)
            cnt[e]++;
        map<long,long> m;
        m[1] = pow(2, cnt[1]);
        for(int e:{2,3,5,6,7,10,11,13,14,15,17,19,21,22,23,26,29,30}){
            for(auto &p:m) {
                if(gcd(p.first, e) == 1) {
                    m[p.first * e] = (m[p.first * e] + cnt[e]*p.second)  % mod;
                }
            }
        }
        int ans = -m[1];
        for(auto &p:m) {
            ans = (ans + p.second) % mod;
        }
        return ans;
    }
};
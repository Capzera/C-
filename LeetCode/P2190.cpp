/*
����������P2190 ���۵�73��˫����
����һ���±�� 0?��ʼ����������?nums?��ͬʱ����һ������?key?������?nums?���ֹ���
ͳ��?�� nums?�����н����� key?������ֵĲ�ͬ����?target?�ĳ��ִ���������֮��target?�ĳ��ִ���Ϊ�������������� i?����Ŀ��
0 <= i <= n - 2
nums[i] == key?��
nums[i + 1] == target?��
���㷵�س��� ���?������?target?���������ݱ�֤���ִ������� target?��Ψһ�ġ�
ʾ�� 1��
���룺nums = [1,100,200,1,100], key = 1
�����100
���ͣ����� target = 100 �����±� 1 �� 4 �����ֹ� 2 �Σ��Ҷ������� key ��
û������������ key ��������ų��֣��������Ƿ��� 100 ��
ʾ�� 2��
���룺nums = [2,2,2,2,3], key = 2
�����2
���ͣ����� target = 2 �����±� 1 ��2 �� 3 �����ֹ� 3 �Σ��Ҷ������� key ��
���� target = 3 �����±� 4 �����ֹ� 1 �Σ��ҽ����� key ��
target = 2 �ǽ����� key ֮����ִ����������֣��������Ƿ��� 2 ��
��ʾ��
2 <= nums.length <= 1000
1 <= nums[i] <= 1000
�������ݱ�֤����Ψһ�ġ�
*/
class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        int n=nums.size(),maxcot=-1,ans;
        for (int i=0;i<n-1;i++)
        {
            if (nums[i]!=key) continue;//������������������
            int target=nums[i+1],count=1;
            for(int j=i+2;j<n;j++) if (nums[j]==target&&nums[j-1]==key) count++;
            if (count>maxcot){
                maxcot=count;
                ans=target;
            }
        }
        return ans;
    }
};
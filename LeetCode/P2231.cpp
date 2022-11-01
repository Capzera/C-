/*
����������P2231 ���۵�288������
����һ�������� num ������Խ��� num �� ��ż�� ��ͬ��������λ���֣�����������������ż������
���ؽ��� ���� ��֮�� num �� ��� ����ֵ��
ʾ�� 1��
���룺num = 1234
�����3412
���ͣ��������� 3 ������ 1 ������õ� 3214 ��
�������� 2 ������ 4 ������õ� 3412 ��
ע�⣬���ܴ��������������У����ǿ���֤�� 3412 ��������ֵ��
ע�⣬���ܽ������� 4 ������ 1 ����Ϊ������ż�Բ�ͬ��
ʾ�� 2��
���룺num = 65875
�����87655
���ͣ��������� 8 ������ 6 ������õ� 85675 ��
�������� 5 ������ 7 ������õ� 87655 ��
ע�⣬���ܴ��������������У����ǿ���֤�� 87655 ��������ֵ��
��ʾ��
1 <= num <= 109
*/
class Solution {
    static bool cmp(int a,int b){
        return a>b;
    }
public:
    int largestInteger(int num) {
        int ans=0;
        vector<int> nums;
        while (num) {
            int n=num%10;
            nums.push_back(n);
            num/=10;
        }
        reverse(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> indexo,indexe;
        vector<int> odd,even;
        for (int i=0;i<n;i++) {
            if (nums[i]%2) {
                indexo.push_back(i);
                odd.push_back(nums[i]);
            }
            else{
                indexe.push_back(i);
                even.push_back(nums[i]);
            }
        }
        int x=0,y=0,i=0;
        sort(odd.begin(),odd.end(),cmp);
        sort(even.begin(),even.end(),cmp);
        while (i<n){
            if (x<odd.size()&&indexo[x]==i){
                ans=ans*10+odd[x++];
            }
            else if (y<even.size()&&indexe[y]==i) {
                ans=ans*10+even[y++];
            }
            i++;
        }
        return ans;
    }
};
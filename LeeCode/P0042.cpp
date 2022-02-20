/*
����������P0042
����?n ���Ǹ�������ʾÿ�����Ϊ 1 �����ӵĸ߶�ͼ�����㰴�����е����ӣ�����֮���ܽӶ�����ˮ��
ʾ�� 1��
���룺height = [0,1,0,2,1,0,1,3,2,1,2,1]
�����6
���ͣ������������� [0,1,0,2,1,0,1,3,2,1,2,1] ��ʾ�ĸ߶�ͼ������������£����Խ� 6 ����λ����ˮ����ɫ���ֱ�ʾ��ˮ���� 
ʾ�� 2��
���룺height = [4,2,0,3,2,5]
�����9
��ʾ��
n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(),i=0,ans=0;
        int left=0,right=n-1,maxleft=height[0],maxright=height[n-1];
        while (left<right)
        {
            maxleft=max(maxleft,height[left]);
            maxright=max(maxright,height[right]);
            if (height[left]<height[right]) 
            {
                ans+=maxleft-height[left];
                left++;
            }
            else
            {
                ans+=maxright-height[right];
                right--;
            }
        }
        return ans;
    }
};
/*
����������
��������ϡ���������������ǵĵ��������������
ʵ����?SparseVector��
SparseVector(nums)?������?nums?��ʼ������
dotProduct(vec)?�����������?vec?�ĵ����
ϡ������ ��ָ�����������Ϊ 0 ������������Ҫ ��Ч �ش洢�������������������ϡ�������ĵ����
���ף�������ֻ��һ��������ϡ������ʱ�������ν�������⣿
ʾ�� 1��
���룺nums1 = [1,0,0,2,3], nums2 = [0,3,0,4,0]
�����8
���ͣ�v1 = SparseVector(nums1) , v2 = SparseVector(nums2)
v1.dotProduct(v2) = 1*0 + 0*3 + 0*0 + 2*4 + 3*0 = 8
ʾ�� 2��
���룺nums1 = [0,1,0,0,0], nums2 = [0,0,0,0,2]
�����0
���ͣ�v1 = SparseVector(nums1) , v2 = SparseVector(nums2)
v1.dotProduct(v2) = 0*0 + 1*0 + 0*0 + 0*0 + 0*2 = 0
ʾ�� 3��
���룺nums1 = [0,1,0,0,2,0,0], nums2 = [1,0,0,0,3,0,4]
�����6
*/
class SparseVector {
public:
    
    SparseVector(vector<int> &nums) {
       this->nums=nums;
    }
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int n=nums.size(),i,ans=0;
        for(i=0;i<n;i++) ans+=nums[i]*vec.nums[i];
        return ans;
    }
private:
    vector<int> nums;
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
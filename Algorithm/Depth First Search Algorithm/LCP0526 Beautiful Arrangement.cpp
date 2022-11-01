/*
����������P0526
�����д� 1 �� n �� n ������������Щ��������һ������ perm���±�� 1 ��ʼ����
ֻҪ������������ ֮һ �����������һ�� ���������� ��
perm[i] �ܹ��� i ����
i �ܹ��� perm[i] ����
����һ������ n �����ؿ��Թ���� �������� �� ���� ��
ʾ�� 1��
���룺n = 2
�����2
���ͣ�
�� 1 �������������� [1,2]��
    - perm[1] = 1 �ܱ� i = 1 ����
    - perm[2] = 2 �ܱ� i = 2 ����
�� 2 �������������� [2,1]:
    - perm[1] = 2 �ܱ� i = 1 ����
    - i = 2 �ܱ� perm[2] = 1 ����
ʾ�� 2��
���룺n = 1
�����1
��ʾ��
1 <= n <= 15
*/
class Solution {
public:
    int n;
    int ans=0;
    vector<vector<int>> nums;
    vector<int> loc;
    void dfs(int cur){
        if (cur==n) {
            ans++;
            return;
        }
        for (auto i:nums[cur]){
            if (loc[i-1]==1) continue;
            loc[i-1]=1;
            dfs(cur+1);
            loc[i-1]=0;
        }
    }
    int countArrangement(int n) {
        this->n=n;
        nums=vector<vector<int>> (n);
        loc=vector<int> (n);
        for (int i=0;i<n;i++) {
            for (int j=1;j<=n;j++) {
                if (j%(i+1)==0||(i+1)%j==0) nums[i].push_back(j);
            }
        }
        dfs(0);
        return ans;
    }
};
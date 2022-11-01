/*
����������P5253 ����������286��
����һ����������?queries?��һ�� ��?����?intLength?�����㷵��һ������?answer?��
����?answer[i] �ǳ���Ϊ?intLength?��?�������� �е�?queries[i]?С�����֣���������������Ļ���������Ϊ -1?��
������ ָ���Ǵ�ǰ����ʹӺ���ǰ��һģһ�������֡�������������ǰ�� 0 ��
ʾ�� 1��
���룺queries = [1,2,3,4,5,90], intLength = 3
�����[101,111,121,131,141,999]
���ͣ�
����Ϊ 3 ����С�����������ǣ�
101, 111, 121, 131, 141, 151, 161, 171, 181, 191, 201, ...
�� 90 ������Ϊ 3 �Ļ������� 999 ��
ʾ�� 2��
���룺queries = [2,4,6], intLength = 4
�����[1111,1331,1551]
���ͣ�
����Ϊ 4 ��ǰ 6 ���������ǣ�
1001, 1111, 1221, 1331, 1441 �� 1551 ��
��ʾ��
1 <= queries.length <= 5 * 104
1 <= queries[i] <= 109
1 <= intLength?<= 15
*/
class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        vector<long long> ans;
        int exp=intLength/2-1;//exp�����������ǰ�벿�ֵ�10�Ĵη���
		if (intLength%2) exp++;//������������Ҫö���м����һλ
		int MAX=9*pow(10,exp);
        for (int i=0;i<queries.size();i++) {
            int j=queries[i]-1+pow(10,exp);//exp��queries[i]-1Ϊ��j������ǰ�벿��
            if (queries[i]>MAX) {//�������������ж�
                ans.push_back(-1);
                continue;
             }
			string s1=to_string(j),s2;
			s2=s1.substr(0,exp-intLength%2+1);//���Ϊ������s2����s1��ǰexp-1λ������s2=s1
			reverse(s2.begin(),s2.end());//���ĶԳ�
			ans.push_back(stoll(s1+s2));//�����
        }
        return ans; 
    }
};
/*
����������P0728
�Գ���?��ָ���Ա���������ÿһλ������������
���磬128 ��һ�� �Գ��� ����Ϊ?128 % 1 == 0��128 % 2 == 0��128 % 8 == 0��
�Գ��� ��������� 0 ��
������������?left?��?right ������һ���б��б��Ԫ���Ƿ�Χ?[left, right]?�����е� �Գ��� ��
ʾ�� 1��
���룺left = 1, right = 22
�����[1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
ʾ�� 2:
���룺left = 47, right = 85
�����[48,55,66,77]
��ʾ��
1 <= left <= right <= 104
*/
class Solution {
public:
    bool check(int n){
        int div=n;
		while (n) {
			int tmp=n%10;
            n/=10;
            if (!tmp||div%tmp) return false;
		}
        return true;
	}
    vector<int> selfDividingNumbers(int left, int right) {
		vector<int> ans;
        for (int i=left;i<=right;i++) {
			if (check(i)) ans.push_back(i);
		}
        return ans;
    }
};
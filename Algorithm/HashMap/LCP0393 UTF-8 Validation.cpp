/*
����������P0393
����һ����ʾ���ݵ���������?data?���������Ƿ�Ϊ��Ч�� UTF-8 ���롣
UTF-8 �е�һ���ַ����ܵĳ���Ϊ 1 �� 4 �ֽڣ���ѭ���µĹ���
���� 1 �ֽ�?���ַ����ֽڵĵ�һλ��Ϊ 0 ������ 7 λΪ������ŵ� unicode �롣
���� n �ֽ�?���ַ� (n > 1)����һ���ֽڵ�ǰ n λ����Ϊ1���� n+1 λ��Ϊ 0 �������ֽڵ�ǰ��λһ����Ϊ 10 ��ʣ�µ�û���ἰ�Ķ�����λ��ȫ��Ϊ������ŵ� unicode �롣
���� UTF-8 ����Ĺ�����ʽ��
   Char. number range  |        UTF-8 octet sequence
      (hexadecimal)    |              (binary)
   --------------------+---------------------------------------------
   0000 0000-0000 007F | 0xxxxxxx
   0000 0080-0000 07FF | 110xxxxx 10xxxxxx
   0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
   0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
ע�⣺�������������顣ֻ��ÿ�������� ��� 8 ����Чλ �����洢���ݡ�����ζ��ÿ������ֻ��ʾ 1 �ֽڵ����ݡ�
ʾ�� 1��
���룺data = [197,130,1]
�����true
���ͣ����ݱ�ʾ�ֽ�����:11000101 10000010 00000001��
������Ч�� utf-8 ���룬Ϊһ�� 2 �ֽ��ַ�������һ�� 1 �ֽ��ַ���
ʾ�� 2��
���룺data = [235,140,4]
�����false
���ͣ����ݱ�ʾ 8 λ������: 11101011 10001100 00000100.
ǰ 3 λ���� 1 ���� 4 λΪ 0 ��ʾ����һ�� 3 �ֽ��ַ���
��һ���ֽ��ǿ�ͷΪ 10 �������ֽڣ�������ȷ�ġ�
���ڶ��������ֽڲ��� 10 ��ͷ�������ǲ����Ϲ���ġ�
��ʾ:
1 <= data.length <= 2 * 104
0 <= data[i] <= 255
*/
class Solution {
public:
    static const int MASK1 = 1 << 7;
    static const int MASK2 = (1 << 7) + (1 << 6);

    bool isValid(int num) {
        return (num & MASK2) == MASK1;
    }

    int getBytes(int num) {
        if ((num & MASK1) == 0) {
            return 1;
        }
        int n = 0;
        int mask = MASK1;
        while ((num & mask) != 0) {
            n++;
            if (n > 4) {
                return -1;
            }
            mask >>= 1;
        }
        return n >= 2 ? n : -1;
    }

    bool validUtf8(vector<int>& data) {
        int m = data.size();
        int index = 0;
        while (index < m) {
            int num = data[index];
            int n = getBytes(num);
            if (n < 0 || index + n > m) {
                return false;
            }
            for (int i = 1; i < n; i++) {
                if (!isValid(data[index + i])) {
                    return false;
                }
            }
            index += n;
        }
        return true;
    }
};
/*
����������P0806
����Ҫ�Ѹ������ַ��� S?������д��ÿһ���ϣ�ÿһ�е�������Ϊ100����λ��
���������дĳ����ĸ��ʱ���ʹ���г�����100 ����λ����ô����Ӧ�ð������ĸд����һ�С�
���Ǹ�����һ������?widths?���������?widths[0] ���� 'a' ��Ҫ�ĵ�λ��?
widths[1] ���� 'b' ��Ҫ�ĵ�λ��...��?widths[25] ���� 'z' ��Ҫ�ĵ�λ��
���ڻش��������⣺���ٶ������ܷ���S���Լ����һ��ʹ�õĿ����Ƕ��ٸ���λ������Ĵ���Ϊ����Ϊ2�������б����ء�
ʾ�� 1:
����: 
widths = [10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10]
S = "abcdefghijklmnopqrstuvwxyz"
���: [3, 60]
����: 
���е��ַ�ӵ����ͬ��ռ�õ�λ10��������д���е�26����ĸ��
������Ҫ2�����к�ռ��60����λ��һ�С�
ʾ�� 2:
����: 
widths = [4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10]
S = "bbbcccdddaaa"
���: [2, 4]
����: 
��ȥ��ĸ'a'���е��ַ�������ͬ�ĵ�λ10�������ַ��� "bbbcccdddaa" ���Ḳ�� 9 * 10 + 2 * 4 = 98 ����λ.
���һ����ĸ 'a' ���ᱻд���ڶ��У���Ϊ��һ��ֻʣ��2����λ�ˡ�
���ԣ��������2�У��ڶ�����4����λ���ȡ�
ע:
�ַ���?S �ĳ�����?[1, 1000] �ķ�Χ��
S ֻ����Сд��ĸ��
widths �ǳ���Ϊ?26�����顣
widths[i]?ֵ�ķ�Χ��?[2, 10]��
*/
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int width=1,col=0;
        unordered_map<char,int> um;
        for (int i=0;i<26;i++) um[i+97]=widths[i];
        for (auto i:s) {
            col+=um[i];
            if (col>100) {
                col=um[i];
                width++;
            }
        }
        return {width,col};
    }
};
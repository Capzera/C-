/*
����������P2232 ���۵�288������
����һ���±�� 0 ��ʼ���ַ��� expression ����ʽΪ "<num1>+<num2>" ������ <num1> �� <num2> ��ʾ��������
������ expression �����һ�����ţ�ʹ�������֮�� expression ��Ȼ��һ����Ч����ѧ���ʽ��
���Ҽ������Եõ� ��С ����ֵ�������� ���� ����� '+' ����࣬�������ű�������� '+' ���Ҳࡣ
�������һ�����ź��γɵı��ʽ?expression �������� expression ����õ� ��С ����ֵ��
������ڶ���𰸶��ܲ�����ͬ�������������һ���𰸡�
���ɵ��������㣺expression ��ԭʼֵ���������Ҫ�����һ������֮�� expression ��ֵ�������� 32-bit ������������Χ��
ʾ�� 1��
���룺expression = "247+38"
�����"2(47+38)
���ͣ����ʽ����õ� 2 * (47 + 38) = 2 * 85 = 170 ��
ע�� "2(4)7+38" ������Ч�Ľ������Ϊ�����ű�������� '+' ���Ҳࡣ
����֤�� 170 ����С����ֵ��
ʾ�� 2��
���룺expression = "12+34"
�����"1(2+3)4"
���ͣ����ʽ����õ� 1 * (2 + 3) * 4 = 1 * 5 * 4 = 20 ��
ʾ�� 3��
���룺expression = "999+999"
�����"(999+999)"
���ͣ����ʽ����õ� 999 + 999 = 1998 ��
��ʾ��
3 <= expression.length <= 10
expression �������� '1' �� '9' �� '+' ���
expression �����ֿ�ʼ�ͽ���
expression ǡ�ý�����һ�� '+'.
expression ��ԭʼֵ���������Ҫ�����һ������֮�� expression ��ֵ�������� 32-bit ������������Χ
*/
class Solution {
public:
    string minimizeResult(string expression) {
        int n=expression.size(),i=0,minsum=INT_MAX,ansl=-1,ansr=-1;
        while (i<n&&expression[i]!='+') i++;
        string s=expression.substr(0,i),t=expression.substr(i+1,n-i-1),ans="";
        int len1=s.size(),len2=t.size();
        for (int i=0;i<len1;i++) {
            for (int j=0;j<len2;j++) {
                int plus1,plus2,mul1,mul2;
                plus1=stoi(s.substr(i,len1-i));
                plus2=stoi(t.substr(0,j+1));
                if (i==0) mul1=1;
                else mul1=stoi(s.substr(0,i));
                if (j==len2-1) mul2=1;
                else mul2=stoi(t.substr(j+1,len2-j-1));
                int sum=mul1*(plus1+plus2)*mul2;
                if (sum<minsum) {
                    minsum=sum;
                    ansl=i;
                    ansr=j;
                }
            }
        }
        ans=s.substr(0,ansl)+"("+s.substr(ansl,len1-ansl)+"+"+t.substr(0,ansr+1)+")"+t.substr(ansr+1,len2-ansr-1);
        return ans;
    }
};
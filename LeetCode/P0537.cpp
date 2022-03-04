/*
����������P0537
���� �������ַ�����ʾ����ѭ "ʵ��+�鲿i" ����ʽ������������������
ʵ�� ��һ��������ȡֵ��Χ�� [-100, 100]
�鲿 Ҳ��һ��������ȡֵ��Χ�� [-100, 100]
i2 == -1
���������ַ�����ʾ�ĸ��� num1 �� num2 ��������ѭ������ʾ��ʽ�����ر�ʾ���ǳ˻����ַ�����
ʾ�� 1��
���룺num1 = "1+1i", num2 = "1+1i"
�����"0+2i"
���ͣ�(1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i ������Ҫ����ת��Ϊ 0+2i ����ʽ��
ʾ�� 2��
���룺num1 = "1+-1i", num2 = "1+-1i"
�����"0+-2i"
���ͣ�(1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i ������Ҫ����ת��Ϊ 0+-2i ����ʽ�� 
*/
class Solution {
public:
    void trans(string s,int &real,int &vir)
    {
        int i,minus=0,minus2=0;
        if (s[0]=='-')
        {
            minus2=1;
            i=1;
        }
        else i=0;
        while (s[i]!=43) real=real*10+s[i++]-48;
        if (minus2) real-=2*real;
        if (s[i+1]==45) 
        {
            minus=1;
            i+=2;
        }
        else i+=1;
        while (s[i]!='i') vir=vir*10+s[i++]-48;
        if (minus) vir-=2*vir;
    }
    string complexNumberMultiply(string num1, string num2) {
        int real1=0,real2=0,vir1=0,vir2=0;
        string ans="";
        trans(num1,real1,vir1);
        trans(num2,real2,vir2);
        ans+=to_string(real1*real2-vir1*vir2);
        ans+='+';
        ans+=to_string(real1*vir2+real2*vir1);
        ans+='i';
        return ans;
    }
};
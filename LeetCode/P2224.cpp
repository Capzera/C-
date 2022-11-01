/*
����������P2224 ���۵�287������
���������ַ��� current �� correct ����ʾ���� 24 Сʱ��ʱ�� ��
24 Сʱ��ʱ�� �� "HH:MM" ���и�ʽ�������� HH �� 00 �� 23 ֮�䣬�� MM �� 00 �� 59 ֮�䡣
����� 24 Сʱ��ʱ��Ϊ 00:00 ��������� 23:59 ��
��һ�������У�����Խ� current ���ʱ������ 1��5��15 �� 60 ���ӡ������ִ����һ���� ���� ������
���ؽ�?current ת��Ϊ correct ��Ҫ�� ���ٲ����� ��
ʾ�� 1��
���룺current = "02:30", correct = "04:35"
�����3
���ͣ�
���԰����� 3 �������� current ת��Ϊ correct ��
- Ϊ current �� 60 ���ӣ�current ��Ϊ "03:30" ��
- Ϊ current �� 60 ���ӣ�current ��Ϊ "04:30" �� 
- Ϊ current �� 5 ���ӣ�current ��Ϊ "04:35" ��
����֤�����޷������� 3 �������� current ת��Ϊ correct ��
ʾ�� 2��
���룺current = "11:00", correct = "11:01"
�����1
���ͣ�ֻ��ҪΪ current ��һ���ӣ�������С�������� 1 ��
��ʾ��
current �� correct ������ "HH:MM" ��ʽ
current <= correct
*/
class Solution {
public:
    int convertTime(string current, string correct) {
        if (current==correct) return 0;
        int ans=0,target=0;
        int h1,h2,m1,m2;
        h1=stoi(current.substr(0,2));
        m1=stoi(current.substr(3,2));
        h2=stoi(correct.substr(0,2));
        m2=stoi(correct.substr(3,2));
        if (m2>=m1) target=(h2-h1)*60+(m2-m1);
        else target=(h2-h1-1)*60+m2+60-m1;
        cout<<target<<endl;
        while (target) {
            if (target>=60) target-=60;
            else if (target>=15) target-=15;
            else if (target>=5) target-=5;
            else target-=1;
            ans++;
        }
        return ans;
    }
};
/*
����������
����ʵ������ API append��addAll?��?multAll?��ʵ���������С�
��ʵ��?Fancy?�� ��
Fancy()?��ʼ��һ�������ж���
void append(val) ������?val?���������ĩβ��
void addAll(inc)?�����������е�������ֵ������?inc?��
void multAll(m)?�������е�����������ֵ����������?m?��
int getIndex(idx) �õ��±�Ϊ?idx?������ֵ���±�� 0 ��ʼ�������������?109 + 7?ȡ�ࡣ����±���ڵ������еĳ��ȣ��뷵��?-1?��
ʾ����
���룺
["Fancy", "append", "addAll", "append", "multAll", "getIndex", "addAll", "append", "multAll", "getIndex", "getIndex", "getIndex"]
[[], [2], [3], [7], [2], [0], [3], [10], [2], [0], [1], [2]]
�����
[null, null, null, null, null, 10, null, null, null, 26, 34, 20]
���ͣ�
Fancy fancy = new Fancy();
fancy.append(2);   // �������У�[2]
fancy.addAll(3);   // �������У�[2+3] -> [5]
fancy.append(7);   // �������У�[5, 7]
fancy.multAll(2);  // �������У�[5*2, 7*2] -> [10, 14]
fancy.getIndex(0); // ���� 10
fancy.addAll(3);   // �������У�[10+3, 14+3] -> [13, 17]
fancy.append(10);  // �������У�[13, 17, 10]
fancy.multAll(2);  // �������У�[13*2, 17*2, 10*2] -> [26, 34, 20]
fancy.getIndex(0); // ���� 26
fancy.getIndex(1); // ���� 34
fancy.getIndex(2); // ���� 20
*/
int mod =1000000007;
long long val[100005];
int cnt = 0;
class Fancy {
public:
    Fancy() 
    {
        cnt= 0;
    }
    void append(int v)
    {
        v=(v-add+mod)*qpow(mult,mod-2)%mod;
        val[cnt++]=v;
    }
    void addAll(int inc) 
    {
        add=(add+inc)%mod;
    }
    void multAll(int m) 
    {
        mult=(mult*m)%mod;
        add=(add*m)%mod;
    }
    int getIndex(int idx)
    {
        return idx >= cnt? -1:(val[idx]*mult+add)%mod;
    }
    inline int qpow(long long a, int b)
    {
        int ans = 1;
        a=(a%mod+mod)%mod;
        for (;b;b>>=1)
        {
            if (b&1) ans=(a*ans)%mod;
            a=(a*a)%mod;
        }
        return ans;
    }
    long long  mult=1,add=0;
};
/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
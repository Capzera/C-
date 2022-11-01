/*
����������P0433
�������п��Ա�ʾΪһ���� 8 ���ַ���ɵ��ַ���������ÿ���ַ����� 'A'��'C'��'G' �� 'T' ֮һ��

����������Ҫ����ӻ�������?start ��Ϊ end �������Ļ���仯��һ�λ���仯����ζ��������������е�һ���ַ������˱仯��

���磬"AACCGGTT" --> "AACCGGTA" ����һ�λ���仯��
����һ������� bank ��¼��������Ч�Ļ���仯��ֻ�л�����еĻ��������Ч�Ļ������С�
���������������� start �� end ���Լ�һ������� bank ��
�����ҳ��������ܹ�ʹ?start �仯Ϊ end ��������ٱ仯����������޷���ɴ˻���仯������ -1 ��
ע�⣺��ʼ��������?start Ĭ������Ч�ģ�����������һ��������ڻ�����С�
ʾ�� 1��
���룺start = "AACCGGTT", end = "AACCGGTA", bank = ["AACCGGTA"]
�����1
ʾ�� 2��
���룺start = "AACCGGTT", end = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
�����2
ʾ�� 3��
���룺start = "AAAAACCC", end = "AACCCCCC", bank = ["AAAACCCC","AAACCCCC","AACCCCCC"]
�����3
��ʾ��
start.length == 8
end.length == 8
0 <= bank.length <= 10
bank[i].length == 8
start��end �� bank[i] �����ַ� ['A', 'C', 'G', 'T'] ���
*/
class Solution {
public:
    string e;
    queue<string> q;
    set<string> banks;
    bool compare(string s1,string s2){
        int dif=0;
        for (int i=0;i<8;i++) {
            if (s1[i]!=s2[i]) dif++;
            if (dif>1) return false;
        }
        return dif==1;
    }
    int bfs(int depth) {
        int size=q.size();//���浱ǰBFS���г���
        bool c=true;//��¼�Ƿ���Խ�����һ������
        while (size--) {
            string tmp=q.front();q.pop();//ȡ����ͷԪ��
            if (tmp==e) return depth;//����ҵ�end�ͷ��ز�
            for (auto s:banks) {
                if (compare(tmp,s)) {//�����ǰԪ��Ϊ��ͷԪ�ص���һ������
                    q.push(s);//�����β
                    banks.erase(s);//�Ƴ���Ԫ��
                    c=false;//��¼�������޸�
                }
            }
        }
        if (c) return -1;//���δ�������޸ģ�˵�������Խ�����һ���������޷��ҵ�Ŀ��
        return bfs(depth+1);//BFS��һ��
    }
    int minMutation(string start, string end, vector<string>& bank) {
        if (start==end) return 0;//��������յ���ͬʱ
        for (auto s:bank) banks.insert(s);//��bankԪ�ؼ��뼯��banks
        e=end;//���������յ�
        q.push(start);//��¼���
        return bfs(0);
    }
};
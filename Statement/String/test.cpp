




void getnext(string t) {
    
}

function KMP(string s,string t) {
    //Ԥ��Next����
    int i=0,j=0//i������s��ָ�룬j���Ӵ�t��ָ��
    while (i<s.size()&&j<t.size()) {
        if (s[i]==t[j]) {//�жϵ�ǰ����ָ��ָ����ַ��Ƿ����
            i++;
            j++;
        }
        else j=next[j];
        if (j>=t.size()) �ɹ�
        else ʧ��
    }
}
/*next[j]=(-1,����);
next[j]==-1 j==0
next[j]==0  ��ǰ��׺ƥ�� 
next[j]==������� ��ǰ��׺ƥ��
/\
��ǰ������ָ��ָ����ַ����ʱ
��ǰ������ָ��ָ����ַ�����ʱ
*/
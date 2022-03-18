/*
����������P2043
���������Ϊһ�����ܻ�ӭ���������һ��������Զ���ִ�����д���Ľ��ף�ת�ˣ�����ȡ������й��� n ���˻�����Ŵ� 1 �� n ��
ÿ���˺ŵĳ�ʼ���洢��һ���±�� 0 ��ʼ���������� balance?�У����е� (i + 1) ���˻��ĳ�ʼ����� balance[i] ��
����ִ������ ��Ч�� ���ס������������ȫ������������ ��Ч ��
ָ�����˻������� 1 �� n ֮�䣬��
ȡ�����ת����Ҫ��Ǯ������ С�ڻ��ߵ��� �˻���
ʵ�� Bank �ࣺ
Bank(long[] balance) ʹ���±�� 0 ��ʼ���������� balance ��ʼ���ö���
boolean transfer(int account1, int account2, long money) 
�ӱ��Ϊ?account1 ���˻�����Ϊ account2 ���˻�ת�� money ��Ԫ��������׳ɹ������� true �����򣬷��� false ��
boolean deposit(int account, long money) 
����Ϊ?account ���˻���� money ��Ԫ��������׳ɹ������� true �����򣬷��� false ��
boolean withdraw(int account, long money) 
�ӱ��Ϊ account ���˻�ȡ�� money ��Ԫ��������׳ɹ������� true �����򣬷��� false ��
ʾ����
���룺
["Bank", "withdraw", "transfer", "deposit", "transfer", "withdraw"]
[[[10, 100, 20, 50, 30]], [3, 10], [5, 1, 20], [5, 20], [3, 4, 15], [10, 50]]
�����
[null, true, true, true, false, false]
���ͣ�
Bank bank = new Bank([10, 100, 20, 50, 30]);
bank.withdraw(3, 10);    // ���� true ���˻� 3 ������� $20 �����Կ���ȡ�� $10 ��
                         // �˻� 3 ���Ϊ $20 - $10 = $10 ��
bank.transfer(5, 1, 20); // ���� true ���˻� 5 ������� $30 �����Կ���ת�� $20 ��
                         // �˻� 5 �����Ϊ $30 - $20 = $10 ���˻� 1 �����Ϊ $10 + $20 = $30 ��
bank.deposit(5, 20);     // ���� true ���������˻� 5 ��� $20 ��
                         // �˻� 5 �����Ϊ $10 + $20 = $30 ��
bank.transfer(3, 4, 15); // ���� false ���˻� 3 �ĵ�ǰ����� $10 ��
                         // �����޷�ת�� $15 ��
bank.withdraw(10, 50);   // ���� false ��������Ч����Ϊ�˻� 10 �������ڡ�
��ʾ��
n == balance.length
1 <= n, account, account1, account2 <= 105
0 <= balance[i], money <= 1012
transfer, deposit, withdraw ����������ÿ�� ������ 104 ��
*/
class Bank {
public:
    Bank(vector<long long>& balance) {
        this->balance.assign(balance.begin(),balance.end());
        this->n=balance.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (account1<=n&&account2<=n&&balance[account1-1]>=money){
           balance[account1-1]-=money;
           balance[account2-1]+=money;
           return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if (account<=n){
            balance[account-1]+=money;
            return true;
        }
        return false;
    }

    bool withdraw(int account, long long money) {
        if (account<=n&&balance[account-1]>=money){
            balance[account-1]-=money;
            return true;
        }
        return false;
    }
private:
    vector<long long> balance;
    int n;
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
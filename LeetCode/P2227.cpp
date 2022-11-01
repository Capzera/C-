/*
����������P2227 ���۵�287������
����һ���ַ����� keys �������� ������ͬ ���ַ���ɡ�����һ���ַ������� values ���ں����ɳ���Ϊ 2 ���ַ�����
�����һ���ַ������� dictionary ���������ܺ����������ԭ�ַ�����
������Ʋ�ʵ��һ��֧�ּ��ܼ������±�� 0 ��ʼ�ַ��������ݽṹ��
�ַ��� ���� ������������У�
���ַ����е�ÿ���ַ� c ���ȴ� keys ���ҳ����� keys[i] == c ���±� i ��
���ַ����У���?values[i] �滻�ַ� c ��
�ַ��� ���� ������������У�
���ַ���ÿ���� 2 ���ַ�����Ϊһ�����ַ���������ÿ�����ַ��� s ��
�ҳ����� values[i] == s ��һ���±� i ��������ڶ����Ч�� i ������ѡ�� ���� һ����
����ζ��һ���ַ������ܿ��ܵõ���������ַ�����
���ַ����У��� keys[i] �滻 s ��
ʵ�� Encrypter �ࣺ
Encrypter(char[] keys, String[] values, String[] dictionary) �� keys��values �� dictionary ��ʼ�� Encrypter �ࡣ
String encrypt(String word1) ���������ܹ�����ɶ� word1 �ļ��ܣ������ؼ��ܺ���ַ�����
int decrypt(String word2) ͳ�Ʋ����ؿ����� word2 ���ܵõ��ҳ����� dictionary �е��ַ�����Ŀ��
ʾ����
���룺
["Encrypter", "encrypt", "decrypt"]
[[['a', 'b', 'c', 'd'], ["ei", "zf", "ei", "am"], 
["abcd", "acbd", "adbc", "badc", "dacb", "cadb", "cbda", "abad"]], ["abcd"], ["eizfeiam"]]
�����
[null, "eizfeiam", 2]
���ͣ�
Encrypter encrypter = new Encrypter([['a', 'b', 'c', 'd'], ["ei", "zf", "ei", "am"], 
["abcd", "acbd", "adbc", "badc", "dacb", "cadb", "cbda", "abad"]);
encrypter.encrypt("abcd"); // ���� "eizfeiam"�� 
?                          // 'a' ӳ��Ϊ "ei"��'b' ӳ��Ϊ "zf"��'c' ӳ��Ϊ "ei"��'d' ӳ��Ϊ "am"��
encrypter.decrypt("eizfeiam"); // return 2. 
                              // "ei" ����ӳ��Ϊ 'a' �� 'c'��"zf" ӳ��Ϊ 'b'��"am" ӳ��Ϊ 'd'�� 
                              // ��ˣ����ܺ���Եõ����ַ����� "abad"��"cbad"��"abcd" �� "cbcd"�� 
                              // ���� 2 ���ַ�����"abad" �� "abcd"���� dictionary �г��֣����Դ��� 2 ��
��ʾ��
1 <= keys.length == values.length <= 26
values[i].length == 2
1 <= dictionary.length <= 100
1 <= dictionary[i].length <= 100
���� keys[i] �� dictionary[i] ������ͬ
1 <= word1.length <= 2000
1 <= word2.length <= 200
���� word1[i] �������� keys ��
word2.length ��ż��
keys��values[i]��dictionary[i]��word1 �� word2 ֻ��СдӢ����ĸ
������� encrypt �� decrypt �ܼ� 200 ��
*/
class Encrypter {
public:
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        dict.clear();
        dict.insert(dictionary.begin(),dictionary.end());
        this->lock.clear();
        for (int i=0;i<keys.size();i++) lock[keys[i]]=values[i];
    }
    
    string encrypt(string word1) {
        string ans="";
        for (auto& s:word1) {
            if (lock.find(s)==lock.end()) continue;
            ans+=lock[s];
        }
        return ans;
    }
    
    int decrypt(string word2) {
        int ans=0;
        for (auto& x:dict) if (encrypt(x)==word2&&x.size()*2==word2.size()) ans++;
        return ans;
    }
private:
    unordered_map<char,string> lock;
    set<string> dict;
    int n;
    string target;
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */
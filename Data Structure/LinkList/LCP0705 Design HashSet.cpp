/*
����������P0705
��ʹ���κ��ڽ��Ĺ�ϣ������һ����ϣ���ϣ�HashSet����
ʵ�� MyHashSet �ࣺ
void add(key) ���ϣ�����в���ֵ key ��
bool contains(key) ���ع�ϣ�������Ƿ�������ֵ key ��
void remove(key) ������ֵ key �ӹ�ϣ������ɾ���������ϣ������û�����ֵ��ʲôҲ������
ʾ����
���룺
["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
[[], [1], [2], [1], [3], [2], [2], [2], [2]]
�����
[null, null, null, true, false, null, true, null, false]
���ͣ�
MyHashSet myHashSet = new MyHashSet();
myHashSet.add(1);      // set = [1]
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(1); // ���� True
myHashSet.contains(3); // ���� False ����δ�ҵ���
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(2); // ���� True
myHashSet.remove(2);   // set = [1]
myHashSet.contains(2); // ���� False �������Ƴ���
��ʾ��
0 <= key <= 106
������ 104 �� add��remove �� contains
*/
class MyHashSet {
public:
    MyHashSet() {
        data.resize(1000001);
    }
    
    void add(int key) {
        data[key]++;
    }
    
    void remove(int key) {
        data[key]=0;
    }
    
    bool contains(int key) {
        return data[key]>0;
    }
private:
    vector<int>data;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
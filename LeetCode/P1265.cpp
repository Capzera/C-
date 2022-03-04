/*
����������
����һ�����ɱ������ʹ�����нӿ������ӡÿ���ڵ��ֵ��
ImmutableListNode: �������ɱ�����Ľӿڣ������ͷ�ڵ��Ѹ�����
����Ҫʹ�����º��������ʴ�������?����?ֱ�ӷ���?ImmutableListNode����
ImmutableListNode.printValue()����ӡ��ǰ�ڵ��ֵ��
ImmutableListNode.getNext()��������һ���ڵ㡣
����ֻ�����ڲ���ʼ��������������ͨ���޸����������⡣Ҳ����˵����ֻ��ͨ������ API ����������
ʾ�� 1��
���룺head = [1,2,3,4]
�����[4,3,2,1]
ʾ�� 2��
���룺head = [0,-4,-1,3,-5]
�����[-5,3,-1,-4,0]
ʾ�� 3��
���룺head = [-2,0,6,4,4,-6]
�����[-6,4,4,6,0,-2]
*/
/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * class ImmutableListNode {
 * public:
 *    void printValue(); // print the value of the node.
 *    ImmutableListNode* getNext(); // return the next node.
 * };
 */

class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        auto* next=head->getNext();
        if(next) printLinkedListInReverse(next);
        head->printValue();
        return;
    }
};
/*
����������P0232
�����ʹ������ջʵ�������ȳ����С�����Ӧ��֧��һ�����֧�ֵ����в�����push��pop��peek��empty����
ʵ�� MyQueue �ࣺ
void push(int x) ��Ԫ�� x �Ƶ����е�ĩβ
int pop() �Ӷ��еĿ�ͷ�Ƴ�������Ԫ��
int peek() ���ض��п�ͷ��Ԫ��
boolean empty() �������Ϊ�գ����� true �����򣬷��� false
˵����
�� ֻ�� ʹ�ñ�׼��ջ���� ���� Ҳ����ֻ��?push to top,?peek/pop from top,?size, ��?is empty?�����ǺϷ��ġ�
����ʹ�õ�����Ҳ��֧��ջ�������ʹ�� list ���� deque��˫�˶��У���ģ��һ��ջ��ֻҪ�Ǳ�׼��ջ�������ɡ�
ʾ�� 1��
���룺
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
�����
[null, null, null, 1, 1, false]
���ͣ�
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
��ʾ��
1 <= x <= 9
������ 100 �� push��pop��peek �� empty
�������в���������Ч�� �����磬һ���յĶ��в������ pop ���� peek ������
*/
class MyQueue {
public:
    MyQueue() {
    }
    void push(int x) {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s2.push(x);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    int pop() {
        int ans=s1.top();
        s1.pop();
        return ans;
    }
    int peek() {
        return s1.top();
    }
    bool empty() {
        return s1.size()==0? true:false; 
    }
private:
    stack<int> s1,s2;

};
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
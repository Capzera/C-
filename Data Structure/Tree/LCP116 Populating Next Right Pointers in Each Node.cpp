/*
�������������ÿ��������һ���Ҳ���ָ��
����һ��?����������?��������Ҷ�ӽڵ㶼��ͬһ�㣬ÿ�����ڵ㶼�������ӽڵ㡣�������������£�
struct Node {
    int val;
    Node *left;
    Node *right;
    Node *next;
}
�������ÿ�� next ָ�룬�����ָ��ָ������һ���Ҳ�ڵ㡣����Ҳ�����һ���Ҳ�ڵ㣬�� next ָ������Ϊ NULL��

��ʼ״̬�£�����?next ָ�붼������Ϊ NULL��
ʾ�� 1��
���룺root = [1,2,3,4,5,6,7]
�����[1,#,2,3,#,4,5,6,7,#]
���ͣ�������������ͼ A ��ʾ����ĺ���Ӧ���������ÿ�� next ָ�룬��ָ������һ���Ҳ�ڵ㣬��ͼ B ��ʾ��
���л������������������У�ͬһ��ڵ��� next ָ�����ӣ�'#' ��־��ÿһ��Ľ�����
ʾ�� 2:
���룺root = []
�����[]
��ʾ��
���нڵ��������?[0, 212?- 1]?��Χ��
-1000 <= node.val <= 1000
���ף�
��ֻ��ʹ�ó���������ռ䡣
ʹ�õݹ����Ҳ����Ҫ�󣬱����еݹ����ռ�õ�ջ�ռ䲻��������Ŀռ临�Ӷȡ�
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if (root==NULL) return root;
        queue<Node*> Q;
        Q.push(root);
        while (!Q.empty())
        {
            int size=Q.size();//����ò�Ԫ��
            for(int i=0;i<size;i++)
            {
                Node* node=Q.front();//ȡ����ͷԪ��
                Q.pop();//��ɾ��
                if (i!=size-1) node->next=Q.front();//������ǲ�ĩ������
                if (node->left!=NULL) Q.push(node->left);//�������
                if (node->right!=NULL) Q.push(node->right);//�Һ������
            }
        }
        return root;
    }
};
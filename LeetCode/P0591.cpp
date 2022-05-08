/*
����������P0591
����һ����ʾ����Ƭ�ε��ַ���������Ҫʵ��һ����֤����������δ��룬���������Ƿ�Ϸ����Ϸ��Ĵ���Ƭ����Ҫ�������µ����й���
������뱻�Ϸ��ıպϱ�ǩ��Χ�����򣬴�������Ч�ġ�
�պϱ�ǩ����һ���Ϸ���Ҫ�ϸ���ϸ�ʽ��<TAG_NAME>TAG_CONTENT</TAG_NAME>��
���У�<TAG_NAME>����ʼ��ǩ��</TAG_NAME>�ǽ�����ǩ����ʼ�ͽ�����ǩ�е� TAG_NAME Ӧ����ͬ��
���ҽ���?TAG_NAME �� TAG_CONTENT ���ǺϷ��ģ��պϱ�ǩ���ǺϷ��ġ�
�Ϸ���?TAG_NAME?�����д�д��ĸ�������ڷ�Χ [1,9] ֮�䡣���򣬸�?TAG_NAME?�ǲ��Ϸ��ġ�
�Ϸ���?TAG_CONTENT?���԰��������Ϸ��ıպϱ�ǩ��cdata?����ο�����7���������ַ���ע��ο�����1�����˲�ƥ���<��
��ƥ�����ʼ�ͽ�����ǩ����ƥ��Ļ���в��Ϸ� TAG_NAME �ıպϱ�ǩ������TAG_CONTENT?�ǲ��Ϸ��ġ�
һ����ʼ��ǩ�����û�о�����ͬ?TAG_NAME �Ľ�����ǩ��֮ƥ�䣬�ǲ��Ϸ��ġ���֮��Ȼ����������Ҳ��Ҫ���Ǳ�ǩǶ�׵����⡣
һ��<��������Ҳ���һ��������>��֮ƥ�䣬�ǲ��Ϸ��ġ����ҵ����ҵ�һ��<��</ʱ������ֱ����һ��>��ǰ���ַ���
��Ӧ��������Ϊ?TAG_NAME����һ���Ϸ�����
cdata �����¸�ʽ��<![CDATA[CDATA_CONTENT]]>��CDATA_CONTENT?�ķ�Χ�������?<![CDATA[?�ͺ����ĵ�һ��?]]>֮����ַ���
CDATA_CONTENT?���԰��������ַ���cdata �Ĺ�������ֹ��֤������CDATA_CONTENT��
���Լ�ʹ������һЩ�ַ����Ա�����Ϊ��ǩ�����ۺϷ����ǲ��Ϸ�����ҲӦ�ý�������Ϊ�����ַ���
�Ϸ����������:
����: "<DIV>This is the first line <![CDATA[<div>]]></DIV>"
���: True
����: 
���뱻�������˱պϵı�ǩ�ڣ� <DIV> �� </DIV> ��
TAG_NAME �ǺϷ��ģ�TAG_CONTENT ������һЩ�ַ��� cdata �� 
��ʹ CDATA_CONTENT ���в�ƥ�����ʼ��ǩ�Ͳ��Ϸ��� TAG_NAME����Ӧ�ñ���Ϊ��ͨ���ı��������Ǳ�ǩ��
���� TAG_CONTENT �ǺϷ��ģ���˴����ǺϷ��ġ����շ���True��
����: "<DIV>>>  ![cdata[]] <![CDATA[<div>]>]]>]]>>]</DIV>"
���: True
����:
�������Ƚ�����ָ�Ϊ�� start_tag|tag_content|end_tag ��
start_tag -> "<DIV>"
end_tag -> "</DIV>"
tag_content Ҳ�ɱ��ָ�Ϊ�� text1|cdata|text2 ��
text1 -> ">>  ![cdata[]] "
cdata -> "<![CDATA[<div>]>]]>" ������ CDATA_CONTENT Ϊ "<div>]>"
text2 -> "]]>>]"
start_tag ���� "<DIV>>>" ��ԭ����չ��� 6 ��
cdata ���� "<![CDATA[<div>]>]]>]]>" ��ԭ����չ��� 7 ��
���Ϸ����������:
����: "<A>  <B> </A>   </B>"
���: False
����: ���Ϸ������ "<A>" �Ǳպϵģ���ô "<B>" һ���ǲ�ƥ��ģ���֮��Ȼ��
����: "<DIV>  div tag is not closed  <DIV>"
���: False
����: "<DIV>  unmatched <  </DIV>"
���: False
����: "<DIV> closed tags with invalid tag name  <b>123</b> </DIV>"
���: False
����: "<DIV> unmatched tags with invalid tag name  </1234567890> and <CDATA[[]]>  </DIV>"
���: False
����: "<DIV>  unmatched start tag <B>  and unmatched end tag </C>  </DIV>"
���: False
ע��:
Ϊ�������������Լ�������Ĵ��루�����ᵽ�������ַ���ֻ��������, ��ĸ, '<','>','/','!','[',']'��' '��
*/
class Solution {
public:
    bool isValid(string code) {
        int n = code.size();
        stack<string> tags;

        int i = 0;
        while (i < n) {
            if (code[i] == '<') {
                if (i == n - 1) {
                    return false;
                }
                if (code[i + 1] == '/') {
                    int j = code.find('>', i);
                    if (j == string::npos) {
                        return false;
                    }
                    string tagname = code.substr(i + 2, j - (i + 2));
                    if (tags.empty() || tags.top() != tagname) {
                        return false;
                    }
                    tags.pop();
                    i = j + 1;
                    if (tags.empty() && i != n) {
                        return false;
                    }
                }
                else if (code[i + 1] == '!') {
                    if (tags.empty()) {
                        return false;
                    }
                    string cdata = code.substr(i + 2, 7);
                    if (cdata != "[CDATA[") {
                        return false;
                    }
                    int j = code.find("]]>", i);
                    if (j == string::npos) {
                        return false;
                    }
                    i = j + 3;
                }
                else {
                    int j = code.find('>', i);
                    if (j == string::npos) {
                        return false;
                    }
                    string tagname = code.substr(i + 1, j - (i + 1));
                    if (tagname.size() < 1 || tagname.size() > 9) {
                        return false;
                    }
                    if (!all_of(tagname.begin(), tagname.end(), [](unsigned char c) { return isupper(c); })) {
                        return false;
                    }
                    tags.push(move(tagname));
                    i = j + 1;
                }
            }
            else {
                if (tags.empty()) {
                    return false;
                }
                ++i;
            }
        }

        return tags.empty();
    }
};
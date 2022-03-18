/*
����������P0599
���� Andy �� Doris �������ʱѡ��һ�Ҳ������������Ƕ���һ����ʾ��ϲ���������б�ÿ���������������ַ�����ʾ��
����Ҫ�������������ٵ��������ҳ����ǹ�ͬϲ���Ĳ����� ����𰸲�ֹһ������������д𰸲��Ҳ�����˳�� ����Լ�������Ǵ��ڡ�
ʾ�� 1:
����: list1 = ["Shogun", "Tapioca Express", "Burger King", "KFC"]��
list2 = ["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
���: ["Shogun"]
����: ����Ψһ��ͬϲ���Ĳ����ǡ�Shogun����
ʾ�� 2:
����:list1 = ["Shogun", "Tapioca Express", "Burger King", "KFC"]��list2 = ["KFC", "Shogun", "Burger King"]
���: ["Shogun"]
����: ���ǹ�ͬϲ���Ҿ�����С�����͵Ĳ����ǡ�Shogun����������С��������1(0+1)��
��ʾ:
1 <= list1.length, list2.length <= 1000
1 <= list1[i].length, list2[i].length <= 30?
list1[i] �� list2[i] �ɿո�?' '?��Ӣ����ĸ��ɡ�
list1 �������ַ������� Ψһ �ġ�
list2 �е������ַ������� Ψһ �ġ�
*/
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> ans;
        unordered_map<string,int> um;
        int maxsum=INT_MAX;
        for(int i=0;i<list1.size();i++) um[list1[i]]=i;
        for(int i=0;i<list2.size();i++){
            if (i>maxsum) break;
            if (!um.count(list2[i])) continue;
            if (i+um[list2[i]]==maxsum) ans.push_back(list2[i]);
            else if (i+um[list2[i]]<maxsum){
                ans.resize(1);
                ans[0]=list2[i];
                maxsum=i+um[list2[i]];
            }
        }
        return ans;
    }
};
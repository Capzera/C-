/*
����������P0475
�����Ѿ����١�?������������һ���й̶����Ȱ뾶�Ĺ�ů�������з��ݹ�ů��
�ڼ������ļ��Ȱ뾶��Χ�ڵ�ÿ�����ݶ����Ի�ù�ů��
���ڣ�����λ��һ��ˮƽ���ϵķ���?houses �͹�ů��?heaters ��λ�ã������ҳ������ؿ��Ը������з��ݵ���С���Ȱ뾶��
˵�������й�ů������ѭ��İ뾶��׼�����ȵİ뾶Ҳһ����
ʾ�� 1:
����: houses = [1,2,3], heaters = [2]
���: 1
����: ����λ��2����һ����ů����������ǽ����Ȱ뾶��Ϊ1����ô���з��ݾͶ��ܵõ���ů��
ʾ�� 2:
����: houses = [1,2,3,4], heaters = [1,4]
���: 1
����: ��λ��1, 4����������ů����������Ҫ�����Ȱ뾶��Ϊ1���������з��ݾͶ��ܵõ���ů��
ʾ�� 3��
���룺houses = [1,5], heaters = [2]
�����3
��ʾ��
1 <= houses.length, heaters.length <= 3 * 104
1 <= houses[i], heaters[i] <= 109
*/
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(),heaters.end());
        set<int>tmp(houses.begin(),houses.end());
        houses.assign(tmp.begin(),tmp.end());//��housesȥ�ؼ��ٹ�����
        int n=houses.size(),h=heaters.size();
        int l=heaters[0]-houses[0],r=max(houses[n-1],heaters[h-1]),ans=INT_MAX;
        while (l<r)
        {
            int mid=l+(r-l)/2,j=0;//ȡ��ֵ��jָ���¼��ǰʹ�õļ�����
            for(int i=0;i<n;i++)
            {
                while(j<h)
                {
                    if (abs(heaters[j]-houses[i])>mid) j++;//��ǰ�������޷�����
                    else break;
                }
            }
            if (j<h) //midΪ�ɽ⣬mid-r���ɽ�
            {
                ans=min(ans,mid);
                r=mid;//�������
            }
            else l=mid+1;//���Ҷ���
        }
        return ans;
    }
};
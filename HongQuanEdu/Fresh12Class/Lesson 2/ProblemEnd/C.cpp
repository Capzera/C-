/*
    *���ŵ�2��
    *100��ƻ���ָ�9��ͬѧ��ƽ������󣬻�ʣ�¼���ƻ��
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    
    int sumApple = 100;
    int studentCount = 9;
    int eachApple = 0;
    int resApple = 0;

    eachApple = sumApple / studentCount;
    resApple = sumApple - studentCount * eachApple;
    
    cout << "Rest " << fixed << setprecision(2) << resApple << " Apple(s)" << endl;
    system("pause");
    return 0;
}
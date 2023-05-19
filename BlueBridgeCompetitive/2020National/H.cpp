#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, x, y;
    cin >> n;
    vector<vector<int>> nums(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> nums[i][1];
        nums[i][0] = x + y;
    }
    sort(nums.begin(), nums.end(), [&](vector<int>& a, vector<int>& b) { return a[0] + a[1] < b[0] + b[1]; });
    long long ans = 0, time = 0;
    for (auto& num : nums) {
        ans += time += num[0];
        time += num[1];
    }
    cout << ans << endl;
    system("pause");
    return 0;
}
/*
题目描述
有 n 位同学同时找老师答疑。每位同学都预先估计了自己答疑的时间。
老师可以安排答疑的顺序，同学们要依次进入老师办公室答疑。 一位同学答疑的过程如下：
首先进入办公室，编号为 i 的同学需要 si毫秒的时间。然后同学问问题老师解答，编号为 i 的同学需要 ai毫秒的时间。
答疑完成后，同学很高兴，会在课程群里面发一条消息，需要的时间可以忽略。
最后同学收拾东西离开办公室，需要 ei 毫秒的时间。一般需要 10 秒、20 秒或 30 秒,
即 ei 取值为 10000，20000 或 30000。
一位同学离开办公室后，紧接着下一位同学就可以进入办公室了。
答疑从 0 时刻开始。老师想合理的安排答疑的顺序，使得同学们在课程群里面发消息的时刻之和最小。
输入描述
输入第一行包含一个整数 n，表示同学的数量。
接下来 n 行，描述每位同学的时间。其中第 i 行包含三个整数 si, ai, ei，意义如上所述。
其中有 ，1 ≤ n ≤ 1000，1 ≤ si ≤ 60000，1 ≤ ai ≤ 10^6， 
ei ∈ {10000, 20000, 30000}
即 ei一定是 10000、20000、30000 之一。
输出描述
输出一个整数，表示同学们在课程群里面发消息的时刻之和最小是多少。
输入输出样例
示例
输入
3
10000 10000 10000
20000 50000 20000
30000 20000 30000
20 10
70 20
50 30
输出
280000
20 + 80 + 180 + 20
*/
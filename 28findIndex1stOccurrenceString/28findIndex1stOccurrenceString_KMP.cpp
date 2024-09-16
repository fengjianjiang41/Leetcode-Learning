#include "../common.h"

class Solution
{
public:
    int strStr(string s, string p)
    {
        int n = s.size(), m = p.size();
        if (m == 0)
            return 0;
        // 设置哨兵
        s.insert(s.begin(), ' ');
        p.insert(p.begin(), ' ');
        vector<int> next(m + 1);
        // 预处理next数组
        for (int i = 2, j = 0; i <= m; i++)
        {
            while (j > 0 && p[i] != p[j + 1])
                j = next[j];
            if (p[i] == p[j + 1])
                j++;
            next[i] = j;
        }
        // 匹配过程
        for (int i = 1, j = 0; i <= n; i++)
        {
            while (j > 0 && s[i] != p[j + 1])
                j = next[j];
            if (s[i] == p[j + 1])
                j++;
            if (j == m)
                return i - m;
        }
        return -1;
    }
};

int main()
{
    Solution s;
    string s1, s2;
    cin >> s1 >> s2;
    cout << s.strStr(s1, s2);
    return 0;
}
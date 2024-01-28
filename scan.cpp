#include <bits/stdc++.h>
using namespace std;

const int N = 101;
int arr[N][N];
int ans[N][N];  //这里单独开一个记录答案的数组

int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    //因为后续有下标通过max()和min()来维护其合法性，所以我们从 1 开始输入
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> arr[i][j];

    //扫雷
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (arr[i][j] == 1)
            {
                ans[i][j] = 9;
                continue;
            }
            for (int a = max(1, i - 1); a <= min(n, i + 1); ++a)
            {
                for (int b = max(1, j - 1); b <= min(m, j + 1); ++b)
                {
                    if (arr[a][b])
                        ans[i][j]++;
                }
            }
        }
    }

    //在 " \n"[d == m] 中,若d=m,输出'\n', 否则输出' '
    //[]-->正则表达式
    for (int c = 1; c <= n; ++c)
        for (int d = 1; d <= m; ++d)
            cout << ans[c][d] << " \n"[d == m];
    
    return 0;
}

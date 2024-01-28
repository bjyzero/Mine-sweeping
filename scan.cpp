#include <bits/stdc++.h>
using namespace std;

const int N = 101;
int arr[N][N];
int ans[N][N];

int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> arr[i][j];
        }
    }

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

    for (int c = 1; c <= n; ++c)
    {
        for (int d = 1; d <= m; ++d)
        {
            cout << ans[c][d] << " \n"[d == m];
        }
    }

    return 0;
}
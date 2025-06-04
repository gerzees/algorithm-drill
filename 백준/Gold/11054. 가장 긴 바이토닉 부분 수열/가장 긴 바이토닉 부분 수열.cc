#include <bits/stdc++.h>

using namespace std;


int N;
int A[1'001];
int cnt_left[1'001];
int cnt_right[1'001];
int result;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 입력
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    // 처리
    for (int i = 0; i < N; ++i)
    {
        int mxm = -1;
        for (int left = 0; left < i; ++left)
        {
            if (A[left] >= A[i])
            {
                continue;
            }
            mxm = max(cnt_left[left], mxm);
        }
        if (mxm >= 0)
        {
            cnt_left[i] = mxm + 1;
        }
    }

    for (int i = N - 1; i >= 0; --i)
    {
        int mxm = -1;
        for (int right = N - 1; i < right; --right)
        {
            if (A[right] >= A[i])
            {
                continue;
            }
            mxm = max(cnt_right[right], mxm);
        }
        if (mxm >= 0)
        {
            cnt_right[i] = mxm + 1;
        }
    }

    for (int i = 0; i < N; ++i)
    {
        result = max(result, cnt_left[i] + cnt_right[i] + 1);
    }
    // 출력
    cout << result;
}

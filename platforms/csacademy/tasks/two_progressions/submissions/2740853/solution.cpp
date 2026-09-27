#include <bits/stdc++.h>

using namespace std;

int t, a[100005], n, ansr, ansl;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        ansr = 1e8, ansl = 1e8;
        for (int i = 1; i <= n; i++) cin >> a[i];
        int r = a[n] - a[n - 1];
        int pt = n - 1;
        while (a[pt] - a[pt - 1] == r) pt--;
        if (r == 0) pt = n;
        r = a[2] - a[1];
        int r2 = 0, pre = a[2], pre2 = -1, l = 2;
        for (int i = 3; i <= n; i++)
        {
            if (i >= pt && (pre2 == -1 || (pre2 + a[n] - a[n - 1] == a[i] && (r2 == a[n] - a[n - 1] || r2 == 0)))) break;
            if (a[i] - pre == r)
            {
                pre = a[i];
                l++;
            }
            else
            {
                if (pre2 == -1) pre2 = a[i];
                else if (r2 == 0)
                {
                    r2 = a[i] - pre2;
                    pre2 = a[i];
                }
                else
                {
                    if (a[i] - pre2 == r2) pre2 = a[i];
                    else
                    {
                        r = 0;
                        break;
                    }
                }
            }
        }
        if (r != 0) ansr = r, ansl = l;
        r = a[3] - a[1], pre = a[3];
        r2 = 0, pre2 = a[2], l = 2;
        for (int i = 4; i <= n; i++)
        {
            if (i >= pt && (pre2 + r2 == a[i] && r2 == a[n] - a[n - 1])) break;
            if (a[i] - pre == r)
            {
                pre = a[i];
                l++;
            }
            else
            {
                if (r2 == 0)
                {
                    r2 = a[i] - pre2;
                    pre2 = a[i];
                }
                else
                {
                    if (a[i] - pre2 == r2) pre2 = a[i];
                    else
                    {
                        r = 0;
                        break;
                    }
                }
            }
        }
        if (r != 0)
        {
            if (ansr > r || (ansr == r && ansl > l))
            {
                ansr = r;
                ansl = l;
            }
        }
        r = 0, pre = a[1];
        r2 = a[3] - a[2], pre2 = a[3], l = 2;
        for (int i = 4; i <= n; i++)
        {
            if (i >= pt && ((r == 0 && a[i] - pre == a[n] - a[n - 1]) || (pre + r == a[i] && r == a[n] - a[n - 1])))
            {
                r = a[i] - pre;
                break;
            }
            if (a[i] - pre2 != r2)
            {
                if (r == 0)
                {
                    r = a[i] - pre;
                    pre = a[i];
                }
                else
                {
                    if (a[i] - pre == r) pre = a[i];
                    else
                    {
                        r = 0;
                        break;
                    }
                }
            }
            else
            {
                pre2 = a[i];
                l++;
            }
        }
        l = n - l;
        if (r != 0)
        {
            if (ansr > r || (ansr == r && ansl > l))
            {
                ansr = r;
                ansl = l;
            }
        }
        if (ansr < 1e8 - 10) cout << a[1] << " " << ansr << " " << ansl << endl;
        else cout << -1 << endl;
    }
    return 0;
}
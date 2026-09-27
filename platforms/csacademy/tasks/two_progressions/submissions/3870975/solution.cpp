#include <stdio.h>
#include <string.h>
const int N = 100005;

int n;
int v[N];
bool marked[N];

inline void scan_d(int &ret)
{
    char c;
    if (c = getchar(), c == EOF)
        return;
    while (c < '0' || c > '9')
        c = getchar();
    ret = c - '0';
    while (c = getchar(), c >= '0' && c <= '9')
        ret = ret * 10 + (c - '0');
}
inline void out(int x)
{
    if (x > 9)
        out(x / 10);
    putchar(x % 10 + '0');
}
struct po
{
    int fi, ratio, len;
    po(int fi = 1e9, int ratio = 0, int len = -1) : fi(fi), ratio(ratio), len(len) {}
    void init()
    {
        fi = 1e9;
        len = -1;
    }
    bool operator<(const po &b) const
    {
        if (fi == b.fi)
        {
            if (ratio == b.ratio)
            {
                return len < b.len;
            }
            return ratio < b.ratio;
        }
        return fi < b.fi;
    }
} ans;
void read()
{
    scan_d(n);
    for (int i = 0; i < n; ++i)
        scan_d(v[i]);
}

bool is_progression(int *v, int v_size)
{
    if (v_size < 2)
        return false;
    int ratio = v[1] - v[0];
    if (ratio == 0)
    {
        return false;
    }

    for (int i = 0; i + 1 < v_size; ++i)
        if (v[i] + ratio != v[i + 1])
            return false;
    return true;
}

int second_progression[N];
void check_progression(int first_idx, int ratio, int last_idx)
{
    if (ratio == 0)
    {
        return;
    }
    memset(marked, false, sizeof(marked));
    int value = v[first_idx];
    int progression_size = 0;
    for (int i = 0; i <= last_idx; i += 1)
    {
        if (v[i] == value)
        {
            marked[i] = true;
            value += ratio;
            ++progression_size;
        }
    }
    if (!marked[last_idx])
        return;

    int lsc = 0;
    for (int i = 0; i < n; ++i)
        if (!marked[i])
            second_progression[lsc++] = v[i];
    if (!is_progression(second_progression, lsc))
        return;

    po tp;
    if (first_idx == 0)
    {
        tp = po(v[first_idx], ratio, progression_size);
    }
    else
    {
        tp = po(second_progression[0], second_progression[1] - second_progression[0], lsc);
    }
    if (tp < ans)
        ans = tp;
}

void special_case()
{
    int ratio = v[n - 1] - v[n - 2];
    int i;

    for (i = n - 2; i >= 2; --i)
        if (v[i] != v[n - 1] - ratio * (n - 1 - i))
        {
            check_progression(0, v[1] - v[0], i);
            return;
        }
}

void solve()
{
    if (n == 4)
    {
        if (v[0] != v[1] && v[2] != v[3])
        {
            out(v[0]);
            putchar(' ');
            out(v[1] - v[0]);
            putchar(' ');
            out(2);
            putchar('\n');
            return;
        }

        if (v[0] != v[2] && v[1] != v[3])
        {
            out(v[0]);
            putchar(' ');
            out(v[2] - v[0]);
            putchar(' ');
            out(2);
            putchar('\n');
            return;
        }
        if (v[0] != v[3] && v[1] != v[2])
        {
            out(v[0]);
            putchar(' ');
            out(v[3] - v[0]);
            putchar(' ');
            out(2);
            putchar('\n');
            return;
        }

        puts("-1\n");
        return;
    }

    special_case();
    if (ans.len > 1)
    {
        goto E;
    }
    for (int first_idx = 0; first_idx <= 2; first_idx++)
    {
        check_progression(first_idx, v[n - 1] - v[n - 2], n - 1);
        for (int second_idx = first_idx + 1; second_idx <= 2; ++second_idx)
        {
            for (int last_idx = n - 2; last_idx < n; ++last_idx)
            {
                check_progression(first_idx, v[second_idx] - v[first_idx], last_idx);
            }
        }
    }

    if (ans.len < 2)
    {
        puts("-1");
    }
    else
    {
    E:
        out(ans.fi);
        putchar(' ');
        out(ans.ratio);
        putchar(' ');
        out(ans.len);
        putchar('\n');
    }
}

int main()
{
    int T;
    scan_d(T);
    while (T--)
    {
        ans.init();
        read();
        solve();
    }
    return 0;
}

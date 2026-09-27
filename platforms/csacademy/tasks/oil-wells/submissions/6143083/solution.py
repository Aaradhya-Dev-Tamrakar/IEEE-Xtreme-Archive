import sys


def feasible_ge(arr, K, x):
    # Check if there exists an odd-length subarray of length >= K
    # whose median >= x. Streaming prefix sums over +1 (>=x) / -1 (<x)
    n = len(arr)
    INF = 10 ** 18
    min0 = INF
    min1 = INF
    s_cur = 0
    # ring buffer to get s[t] at t = r-K
    buf = [0] * (K + 1)
    buf[0] = 0  # s[0]
    for r in range(1, n + 1):
        v = arr[r - 1]
        s_cur += (1 if v >= x else -1)
        buf[r % (K + 1)] = s_cur
        t = r - K
        if t >= 0:
            s_t = buf[t % (K + 1)]
            if (t & 1) == 0:
                if s_t < min0:
                    min0 = s_t
            else:
                if s_t < min1:
                    min1 = s_t
        cand = min1 if (r & 1) == 0 else min0
        if cand <= s_cur - 1:
            return True
    return False


def feasible_le(arr, K, x):
    # Check existence of odd-length subarray length >= K with median <= x
    n = len(arr)
    INF = 10 ** 18
    min0 = INF
    min1 = INF
    s_cur = 0
    buf = [0] * (K + 1)
    buf[0] = 0
    for r in range(1, n + 1):
        v = arr[r - 1]
        s_cur += (1 if v <= x else -1)
        buf[r % (K + 1)] = s_cur
        t = r - K
        if t >= 0:
            s_t = buf[t % (K + 1)]
            if (t & 1) == 0:
                if s_t < min0:
                    min0 = s_t
            else:
                if s_t < min1:
                    min1 = s_t
        cand = min1 if (r & 1) == 0 else min0
        if cand <= s_cur - 1:
            return True
    return False


def feasible_eq(arr, K, x, ctx=None):
    # Check existence of odd-length subarray length >= K with median == x
    # Streaming mapping: >x -> +1, <x -> -1, ==x -> 0; and eq count
    n = len(arr)
    off = n
    size = 2 * n + 3
    BIG = n + 1

    if ctx is None:
        best0 = [0] * size
        best1 = [0] * size
        stamp0 = [0] * size
        stamp1 = [0] * size
        ver = 1
        ctx = {
            'best0': best0,
            'best1': best1,
            'stamp0': stamp0,
            'stamp1': stamp1,
            'ver': ver,
            'BIG': BIG,
            'size': size,
        }
    else:
        best0 = ctx['best0']
        best1 = ctx['best1']
        stamp0 = ctx['stamp0']
        stamp1 = ctx['stamp1']
        ver = ctx['ver'] + 1
        ctx['ver'] = ver
        BIG = ctx['BIG']

    s_cur = 0
    eq_cur = 0
    # ring buffer to get (s, eq) at t = r-K
    buf_s = [0] * (K + 1)
    buf_eq = [0] * (K + 1)
    buf_s[0] = 0
    buf_eq[0] = 0

    for r in range(1, n + 1):
        v = arr[r - 1]
        if v > x:
            s_cur += 1
        elif v < x:
            s_cur -= 1
        else:
            eq_cur += 1
        idx = r % (K + 1)
        buf_s[idx] = s_cur
        buf_eq[idx] = eq_cur

        t = r - K
        if t >= 0:
            slot = t % (K + 1)
            s_t = buf_s[slot]
            et = buf_eq[slot]
            bidx = s_t + off
            if (t & 1) == 0:
                if stamp0[bidx] != ver:
                    best0[bidx] = BIG
                    stamp0[bidx] = ver
                if et < best0[bidx]:
                    best0[bidx] = et
            else:
                if stamp1[bidx] != ver:
                    best1[bidx] = BIG
                    stamp1[bidx] = ver
                if et < best1[bidx]:
                    best1[bidx] = et
        # Require odd length: parity(t) != parity(r), and s[r] - s[t] == 0
        idxr = s_cur + off
        if (r & 1) == 0:
            val = best1[idxr] if stamp1[idxr] == ver else BIG
            if val <= eq_cur - 1:
                return True
        else:
            val = best0[idxr] if stamp0[idxr] == ver else BIG
            if val <= eq_cur - 1:
                return True
    return False


def solve(data):
    it = iter(map(int, data.split()))
    try:
        N = next(it)
        K = next(it)
    except StopIteration:
        return ""
    arr = [next(it) for _ in range(N)]

    if K > N:
        # No valid subarray
        return "0\n"

    vals = sorted(set(arr))
    if not vals:
        return "0\n"

    # Find maximum achievable median (largest v such that feasible_ge is True)
    lo, hi = 0, len(vals) - 1
    max_idx = -1
    while lo <= hi:
        mid = (lo + hi) // 2
        if feasible_ge(arr, K, vals[mid]):
            max_idx = mid
            lo = mid + 1
        else:
            hi = mid - 1

    if max_idx == -1:
        # No odd-length subarray of required length exists or logic fails
        return "0\n"

    # Find minimum achievable median (smallest v such that feasible_le is True)
    lo, hi = 0, len(vals) - 1
    min_idx = -1
    while lo <= hi:
        mid = (lo + hi) // 2
        if feasible_le(arr, K, vals[mid]):
            min_idx = mid
            hi = mid - 1
        else:
            lo = mid + 1

    if min_idx == -1:
        return "0\n"

    # Medians should form a contiguous range between min and max indices
    if min_idx > max_idx:
        return "0\n"

    # Filter the contiguous range using exact median predicate（使用懒重置加速）
    eq_ctx = None
    candidates = vals[min_idx:max_idx + 1]
    res_vals = []
    for v in candidates:
        eq_ctx = eq_ctx or {'best0': [0] * (2 * N + 3),
                            'best1': [0] * (2 * N + 3),
                            'stamp0': [0] * (2 * N + 3),
                            'stamp1': [0] * (2 * N + 3),
                            'ver': 0,
                            'BIG': N + 1,
                            'size': 2 * N + 3}
        if feasible_eq(arr, K, v, eq_ctx):
            res_vals.append(v)
    out = [str(len(res_vals)), " ".join(map(str, res_vals))]
    return "\n".join(out) + "\n"


def main():
    data = sys.stdin.read().replace('\ufeff', '')
    sys.stdout.write(solve(data))


if __name__ == "__main__":
    main()
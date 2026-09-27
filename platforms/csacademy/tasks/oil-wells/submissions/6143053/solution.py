import sys


def feasible_ge(arr, K, x):
   
    n = len(arr)
    s = [0] * (n + 1)
    for i in range(1, n + 1):
        s[i] = s[i - 1] + (1 if arr[i - 1] >= x else -1)

    INF = 10 ** 18
    
    min_pref = [INF, INF]

    for r in range(1, n + 1):
        t = r - K
        if t >= 0:
            p = t & 1
            if s[t] < min_pref[p]:
                min_pref[p] = s[t]
        # need t parity != r parity (odd length), and s[r] - s[t] >= 1
        cand = min_pref[(r & 1) ^ 1]
        if cand <= s[r] - 1:
            return True
    return False


def feasible_le(arr, K, x):
    # Check existence of odd-length subarray length >= K with median <= x
    n = len(arr)
    s = [0] * (n + 1)
    for i in range(1, n + 1):
        s[i] = s[i - 1] + (1 if arr[i - 1] <= x else -1)

    INF = 10 ** 18
    min_pref = [INF, INF]

    for r in range(1, n + 1):
        t = r - K
        if t >= 0:
            p = t & 1
            if s[t] < min_pref[p]:
                min_pref[p] = s[t]
        cand = min_pref[(r & 1) ^ 1]
        if cand <= s[r] - 1:
            return True
    return False


def feasible_eq(arr, K, x):
    # Check existence of odd-length subarray length >= K with median == x
    # Using mapping: >x -> +1, <x -> -1, ==x -> 0
    n = len(arr)
    s = [0] * (n + 1)
    eq = [0] * (n + 1)
    for i in range(1, n + 1):
        v = arr[i - 1]
        s[i] = s[i - 1] + (1 if v > x else -1 if v < x else 0)
        eq[i] = eq[i - 1] + (1 if v == x else 0)

    # For each parity, store minimal eq-count for each possible prefix sum value
    off = n
    size = 2 * n + 3
    BIG = n + 1
    best0 = [BIG] * size
    best1 = [BIG] * size

    for r in range(1, n + 1):
        t = r - K
        if t >= 0:
            idx = s[t] + off
            et = eq[t]
            if (t & 1) == 0:
                if et < best0[idx]:
                    best0[idx] = et
            else:
                if et < best1[idx]:
                    best1[idx] = et
        # Require odd length: parity(t) != parity(r), and s[r] - s[t] == 0
        idxr = s[r] + off
        if (r & 1) == 0:
            if best1[idxr] <= eq[r] - 1:
                return True
        else:
            if best0[idxr] <= eq[r] - 1:
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

    # Filter the contiguous range using exact median predicate
    candidates = vals[min_idx:max_idx + 1]
    res_vals = []
    for v in candidates:
        if feasible_eq(arr, K, v):
            res_vals.append(v)
    out = [str(len(res_vals)), " ".join(map(str, res_vals))]
    return "\n".join(out) + "\n"


def main():
    data = sys.stdin.read().replace('\ufeff', '')
    sys.stdout.write(solve(data))


if __name__ == "__main__":
    main()
import sys

def main():
    data = sys.stdin.read().split()
    if not data:
        return
    n = int(data[0])
    K = int(data[1])
    A = list(map(int, data[2:2+n]))
    
    if K == 1:
        medians = sorted(set(A))
        print(len(medians))
        print(" ".join(map(str, medians)))
        return
        
    if n <= 1000:
        medians_set = set()
        for start in range(n):
            sorted_list = []
            for end in range(start, n):
                lo, hi = 0, len(sorted_list)
                while lo < hi:
                    mid = (lo + hi) // 2
                    if sorted_list[mid] < A[end]:
                        lo = mid + 1
                    else:
                        hi = mid
                sorted_list.insert(lo, A[end])
                L = end - start + 1
                if L >= K and L % 2 == 1:
                    median_val = sorted_list[L//2]
                    medians_set.add(median_val)
        medians = sorted(medians_set)
        print(len(medians))
        print(" ".join(map(str, medians)))
        return

    min_val = min(A)
    max_val = max(A)
    medians_set = set()
    local_A = A  # Local variable for faster access

    for i in range(n):
        x = local_A[i]
        if x == min_val or x == max_val:
            continue
            
        left_min = {}
        left_min[0] = -1
        s_val = 0
        for j in range(0, i):
            a_j = local_A[j]
            if a_j > x:
                s_val += 1
            elif a_j < x:
                s_val -= 1
            if s_val not in left_min:
                left_min[s_val] = j
            else:
                if j < left_min[s_val]:
                    left_min[s_val] = j
        
        found = False
        for j in range(i, n):
            a_j = local_A[j]
            if a_j > x:
                s_val += 1
            elif a_j < x:
                s_val -= 1
            if s_val in left_min:
                if j - left_min[s_val] >= K:
                    medians_set.add(x)
                    found = True
                    break
                    
    medians = sorted(medians_set)
    print(len(medians))
    print(" ".join(map(str, medians)))

if __name__ == '__main__':
    main()
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
            # Maintain a sorted list for the current subarray using insertion sort
            current_sorted = []
            for end in range(start, n):
                # Insert A[end] into current_sorted in sorted order
                lo, hi = 0, len(current_sorted)
                while lo < hi:
                    mid = (lo + hi) // 2
                    if current_sorted[mid] < A[end]:
                        lo = mid + 1
                    else:
                        hi = mid
                current_sorted.insert(lo, A[end])
                L = end - start + 1
                if L >= K and L % 2 == 1:
                    median_val = current_sorted[L//2]
                    medians_set.add(median_val)
        medians = sorted(medians_set)
        print(len(medians))
        print(" ".join(map(str, medians)))
        return

    min_val = min(A)
    max_val = max(A)
    medians_set = set()
    
    for pos in range(n):
        x = A[pos]
        if x == min_val or x == max_val:
            continue
            
        # Compute prefixB array without storing B array explicitly
        prefixB = [0] * n
        if A[0] > x:
            prefixB[0] = 1
        elif A[0] < x:
            prefixB[0] = -1
        else:
            prefixB[0] = 0
            
        for i in range(1, n):
            if A[i] > x:
                b_val = 1
            elif A[i] < x:
                b_val = -1
            else:
                b_val = 0
            prefixB[i] = prefixB[i-1] + b_val

        left_dict = {}
        if pos == 0:
            left_sum_val = 0
            left_dict[0] = 0
        else:
            for l in range(0, pos+1):
                if l == 0:
                    left_sum_val = prefixB[pos-1]
                else:
                    left_sum_val = prefixB[pos-1] - prefixB[l-1]
                if left_sum_val not in left_dict or l < left_dict[left_sum_val]:
                    left_dict[left_sum_val] = l

        found = False
        start_r = max(pos, K-1)
        for r in range(start_r, n):
            if pos == n-1:
                right_sum_val = 0
            else:
                if r < pos+1:
                    right_sum_val = 0
                else:
                    right_sum_val = prefixB[r] - prefixB[pos]
            s = -right_sum_val
            if s in left_dict:
                l_val = left_dict[s]
                if l_val <= r - K + 1:
                    found = True
                    break
                    
        if found:
            medians_set.add(x)
            
    medians = sorted(medians_set)
    print(len(medians))
    print(" ".join(map(str, medians)))

if __name__ == '__main__':
    main()
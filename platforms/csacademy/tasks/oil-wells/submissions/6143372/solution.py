import sys

def main():
    data = sys.stdin.read().split()
    if not data:
        return
    n = int(data[0])
    K = int(data[1])
    A = list(map(int, data[2:2+n]))
    
    medians_set = set()
    
    # 直接方法用于小 N
    if n <= 1000:
        for start in range(n):
            current_subarray = []
            for end in range(start, n):
                current_subarray.append(A[end])
                L = end - start + 1
                if L >= K and L % 2 == 1:
                    sorted_sub = sorted(current_subarray)
                    median_val = sorted_sub[L // 2]
                    medians_set.add(median_val)
    else:
        # 值基于的方法
        for idx in range(n):
            x = A[idx]
            pos = idx
            left_balance_dict = {}
            balance = 0
            # 计算左平衡 for l from pos down to 0
            for l in range(pos, -1, -1):
                if l < pos:
                    if A[l] > x:
                        balance += 1
                    elif A[l] < x:
                        balance -= 1
                if balance not in left_balance_dict:
                    left_balance_dict[balance] = l
                else:
                    if l < left_balance_dict[balance]:
                        left_balance_dict[balance] = l
            
            right_balance_val = 0
            found = False
            for r in range(pos, n):
                if r > pos:
                    if A[r] > x:
                        right_balance_val += 1
                    elif A[r] < x:
                        right_balance_val -= 1
                required_balance = -right_balance_val
                if required_balance in left_balance_dict:
                    l_val = left_balance_dict[required_balance]
                    if l_val <= r - K + 1:
                        medians_set.add(x)
                        found = True
                        break
            # 可选: 如果未找到，检查其他 cases如 K=1
            if not found and K == 1:
                # 单个元素子序列
                medians_set.add(x)
    
    medians_list = sorted(medians_set)
    print(len(medians_list))
    if medians_list:
        print(" ".join(map(str, medians_list)))
    else:
        print()

if __name__ == '__main__':
    main()
import sys
from collections import defaultdict


def main():
    # 读取输入并处理BOM字符
    input_data = sys.stdin.read().strip()
    if input_data.startswith('\ufeff'):
        input_data = input_data[1:]
    
    lines = input_data.strip().split('\n')
    if not lines:
        return
    
    # 第一行包含 n 和 K
    first_line = lines[0].split()
    n = int(first_line[0])
    K = int(first_line[1])
    
    # 第二行包含所有的数组元素
    if len(lines) > 1:
        second_line = lines[1].strip()
        A = list(map(int, second_line.split()))
    else:
        A = []
    
    # 处理实际可用的数据
    if len(A) == 0:
        print("0")
        print()
        return
    
    actual_n = len(A)
    print(f"Debug: Using {actual_n} elements instead of {n}", file=sys.stderr)

    medians_set = set()

    # 对于较小的N，使用直接方法
    if actual_n <= 2000:
        for start in range(actual_n):
            current_subarray = []
            for end in range(start, actual_n):
                current_subarray.append(A[end])
                L = end - start + 1
                if L >= K and L % 2 == 1:
                    sorted_sub = sorted(current_subarray)
                    median_val = sorted_sub[L // 2]
                    medians_set.add(median_val)
    else:
        # 优化的算法
        for idx in range(actual_n):
            x = A[idx]
            
            # 优化1: 使用数组而不是字典来存储平衡值
            # 平衡值的范围是 [-actual_n, actual_n]，我们将其映射到 [0, 2*actual_n]
            offset = actual_n
            left_positions = [-1] * (2 * actual_n + 1)
            
            # 计算左侧平衡
            balance = 0
            
            # 从当前位置向左扫描
            for l in range(idx, -1, -1):
                if l < idx:
                    if A[l] > x:
                        balance += 1
                    elif A[l] < x:
                        balance -= 1
                
                # 优化2: 只记录第一次出现的位置（最左位置）
                balance_idx = balance + offset
                if left_positions[balance_idx] == -1:
                    left_positions[balance_idx] = l
            
            # 从当前位置向右扫描
            right_balance_val = 0
            found = False
            
            for r in range(idx, actual_n):
                if r > idx:
                    if A[r] > x:
                        right_balance_val += 1
                    elif A[r] < x:
                        right_balance_val -= 1
                
                # 寻找匹配的左侧平衡
                required_balance = -right_balance_val
                required_idx = required_balance + offset
                
                # 优化3: 边界检查和快速查找
                if 0 <= required_idx < len(left_positions):
                    l_val = left_positions[required_idx]
                    if l_val != -1:
                        length = r - l_val + 1
                        
                        # 检查长度条件
                        if length >= K and length % 2 == 1:
                            medians_set.add(x)
                            found = True
                            break  # 优化4: 找到后立即退出
            
            # 特殊情况：K=1时，每个元素都可以是中位数
            if not found and K == 1:
                medians_set.add(x)

    # 输出结果
    medians_list = sorted(medians_set)
    print(len(medians_list))
    if medians_list:
        print(" ".join(map(str, medians_list)))
    else:
        print()


if __name__ == '__main__':
    main()
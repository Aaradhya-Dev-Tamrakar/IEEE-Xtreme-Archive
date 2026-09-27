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
        # 处理可能的长行，确保正确解析所有数字
        second_line = lines[1].strip()
        A = list(map(int, second_line.split()))
    else:
        A = []
    
    # 处理实际可用的数据
    if len(A) == 0:
        print("0")
        print()
        return
    
    # 使用实际的数组长度
    actual_n = len(A)
    print(f"Debug: Using {actual_n} elements instead of {n}", file=sys.stderr)

    medians_set = set()

    # 对于较小的N，使用直接方法
    if actual_n <= 2000:  # 增加阈值以获得更好的性能
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
        # 对于大的N，使用优化的方法
        # 基于原始算法但进行优化
        for idx in range(actual_n):
            x = A[idx]
            
            # 计算左侧平衡
            left_balance_dict = {}
            balance = 0
            
            # 从当前位置向左扫描
            for l in range(idx, -1, -1):
                if l < idx:
                    if A[l] > x:
                        balance += 1
                    elif A[l] < x:
                        balance -= 1
                
                # 记录这个平衡值对应的最左位置
                if balance not in left_balance_dict:
                    left_balance_dict[balance] = l
                else:
                    left_balance_dict[balance] = min(left_balance_dict[balance], l)
            
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
                
                if required_balance in left_balance_dict:
                    l_val = left_balance_dict[required_balance]
                    length = r - l_val + 1
                    
                    # 检查长度条件
                    if length >= K and length % 2 == 1:
                        medians_set.add(x)
                        found = True
                        break
            
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
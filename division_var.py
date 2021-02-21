class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        
        if dividend == 0:
            return 0
        if abs(dividend) < abs(divisor):
            return 0
        
        positive = True
        if (divisor > 0 and dividend < 0) or \
            (divisor < 0 and dividend > 0):
            positive = False
            
        curr_sum = abs(divisor)
        count = 1
        result_stack = []
        result_map = {}
        last_count = 1
        while curr_sum < abs(dividend):
            
            result_stack.append(count)
            result_map[count] = curr_sum
            
            curr_sum += curr_sum
            last_count = count
            count += count
        
        if curr_sum == abs(dividend):
            if positive and count > 2147483647:
                return 2147483647
            if not positive and count > 2147483648:
                return -2147483648
            
            return count if positive else -count
            
        curr_sum -= result_map[result_stack[-1]]
        count = last_count
        for i in range(len(result_stack) - 2, -1, -1):
            curr_num = result_stack[i]
            while curr_sum < abs(dividend):
                curr_sum += result_map[curr_num]
                count += curr_num
                
            if curr_sum == abs(dividend):
                break
            else:
                curr_sum -= result_map[curr_num]
                count -= curr_num

        
        if positive and count > 2147483647:
            return 2147483647
        if not positive and count > 2147483648:
            return -2147483648
                
            
        return count if positive else -count
 

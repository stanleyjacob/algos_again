
def levDis(str1, str2):
    m = len(str1)
    n = len(str2)
    if n < m:
      m, n = n, m
      str1, str2 = str2, str1
     
    dp_table = [i for i in range(n + 1)]
    for i in range(1, m + 1):
        prev_table = dp_table.copy()
        dp_table[0] = i
        for j in range(1, n + 1):
            if str1[i - 1] != str2[j - 1]:
                dp_table[j] = 1 + min(previous_table[j],
                    previous_table[j - 1],
                    dp_table[j - 1])
            else: 
                dp_table[j] = previous_table[j - 1]
    
    return dp_table[n]

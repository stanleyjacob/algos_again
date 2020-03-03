class Solution:
    def minAreaRect(self, points: List[List[int]]) -> int:
        
        x_to_y_dict = collections.defaultdict(list)
        y_to_x_dict = collections.defaultdict(list)
        
        for point in points:
            x_to_y_dict[point[0]].append(point[1])
            y_to_x_dict[point[1]].append(point[0])
    
        minArea = float('inf')
        for x1, y1_list in x_to_y_dict.items():
            for y1 in y1_list:
                x_values = y_to_x_dict[y1]
                
                for x2 in x_values:
                    
                    if x1 == x2:
                        continue
                    
                    y2_list = x_to_y_dict[x2]
                    y2_list.sort(key = lambda y2: abs(y2 - y1))
                    
                    y2_list = y2_list[1:] # ignore smallest elem
                    
                    for y2 in y2_list:
                        if y2 not in x_to_y_dict[x1]:
                            continue
                        else:
                            minArea = min(minArea, abs(y2 - y1) * abs(x2 - x1))
                            break
        
        if minArea == float('inf'):
            return 0
        
        return minArea

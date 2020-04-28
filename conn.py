class Solution:
    
    def criticalConnections(self, n: int, connections: List[List[int]]) -> List[List[int]]:
        
        my_map = {} 
        class GraphNode: 
            def __init__(self, node_val): 
                self.node_val = node_val 
                self.children = [] 
            
        for conn in connections: 
            node1 = conn[0] 
            node2 = conn[1] 
            if node1 not in my_map: 
                my_map[node1] = GraphNode(node1) 
            if node2 not in my_map: 
                my_map[node2] = GraphNode(node2) 
        
        for conn in connections: 
            node1 = conn[0] 
            node2 = conn[1] 
            my_map[node1].children.append(node2) 
            my_map[node2].children.append(node1) 
        
        res = [] 
        for k, v in my_map.items(): 
            if len(v.children) == 1: 
                res.append([k, v.children[0]]) 
                
        return res 
        

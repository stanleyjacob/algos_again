import collections

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        
        # key is str to bool
        cache = collections.defaultdict(bool) 
        return self.wordBreakHelper(s, wordDict, cache)
    
    def wordBreakHelper(self, s, wordDict, cache):
        
        if len(s) == 0:
            return True
        
        if s in cache:
            return cache[s]
        
        boolVal = False
        for curr_word in wordDict:
            if s[0:len(curr_word)] == curr_word:
                boolVal = boolVal or self.wordBreakHelper(s[len(curr_word):], wordDict, cache)
        
        cache[s] = boolVal
        return boolVal 

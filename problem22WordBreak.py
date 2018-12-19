class Solution(object):
    
    def canBreak(self, s, wordDict):
        if s in self.canBreak_:
            return self.canBreak_[s]
        
        for word in wordDict:
            if word == s:
                self.canBreak_[s] = True
                return True
            if s.startswith(word):
                success = self.canBreak(s[(len(word)):], wordDict)
                self.canBreak_[s] = True
                if success:
                    return True
        
        self.canBreak_[s] = False       
        return self.canBreak_[s]
    
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        
        self.canBreak_ =  {}
        
        for word in wordDict:
            self.canBreak_[word] = True
                        
        return self.canBreak(s, wordDict)
        

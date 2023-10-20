
class Solution:
    def reverseWords(self, s: str) -> str:
        
        words = s.split()
        words = [word[::-1] for word in words]
        words = ' '.join([word for word in words])
        
        return words
      

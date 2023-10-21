def longestValidParentheses(s):
        count=0
        left=0
        right=0
        for i in range(len(s)):
            c=s[i]
            if c=='(':
                left+=1
            if c==')':
                right+=1
            if left==right:
                count=max(count,left+right)
            if right > left:
                left=right=0
        left=right=0
        for i in range(len(s)-1,-1,-1):
            c=s[i]
            if c=='(':
                left+=1
            if c==')':
                right+=1
            if left==right:
                count=max(count,left+right)
            if right < left:
                left=right=0
        return count



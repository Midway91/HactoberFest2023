def longestCommonPrefix(strs):
        i=0
        result=strs[0]
        length=len(result)
        for i in range(0,len(strs)):
          while strs[i].find(result)!=0:
            result=result[:length-1]
            length=length-1
        return result



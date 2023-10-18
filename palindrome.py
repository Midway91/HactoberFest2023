def Pali(s) :
    s=list(s) 
    if(len(s)==1 or len(s)==0):
        return True
    else:
        if(s[0]==s[-1]):
            return (Pali(s[1:-1]))
        else:
            return False
print(Pali(input())) 

#eye
#True

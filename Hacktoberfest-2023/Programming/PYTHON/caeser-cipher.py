import string
l=list(string.ascii_lowercase)
while(True):
   eORd=input("Type 'encode' if you want to encode the message or Type 'decode' if you want to decode the message or Type 'quit' to exit : ")
   if(eORd=='encode'):
      message=input(f"Enter message that you want to '{eORd}' : ")
   elif(eORd=='decode'):
      message=input(f"Enter message that you want to '{eORd}' : ")
   if(eORd=='encode'):
     encode=list(message)
     shift=int(input("Enter the shift : "))
     for i in range(len(message)):
       if(message[i]==" "):
         encode[i]=" "
         continue
       if(message[i] in l):
        k=l.index(encode[i])
        k=k+shift
        if(k>=25):
          k=k%25
        encode[i]=l[k]
     message=''.join(encode)
     print(f"Encoded message : {message}")
   elif(eORd=='decode'):
     encode=list(message)
     shift=int(input("Enter the shift : "))
     for i in range(len(message)):
       if(message[i] in l):
        k=l.index(encode[i])
        k=k-shift
        if(k>=25):
          k=k%25
        encode[i]=l[k]
     message=''.join(encode)
     print(f"Decoded message : {message}")
   else:
     break
    
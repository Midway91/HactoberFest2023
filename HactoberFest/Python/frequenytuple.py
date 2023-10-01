temp = input("Enter comma-separated numbers: ")
tup = tuple(int(x) for x in temp.split(','))
print("The Tuple:", tup)

freq={}

for i in tup:
    if i in freq:
        freq[i]+=1
    else:
        freq[i]=1

print("Frequency of Elements:")
for i, freq in freq.items():
    print(f"{i}: {freq}")
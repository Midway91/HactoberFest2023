# accept two numbers (x, n) from stdin and print "x raised to the power of n"
# solve using recursion


def power(x, n):
    if n == 0:
        return 1
    smallOutput = power(x, n - 1)
    output = x * smallOutput
    return output


print("Enter 2 space seperated integers")
input_str = input().split()
x = int(input_str[0])
n = int(input_str[1])
print(power(x, n))

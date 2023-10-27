def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def eulers_totient_function(n):
    if n <= 0:
        return 0

    coprime_count = 0
    for i in range(1, n):
        if gcd(n, i) == 1:
            coprime_count += 1

    return coprime_count

# Example usage:
n = 8
result = eulers_totient_function(n)
print(f"The Euler's Totient function for {n} is {result}.")

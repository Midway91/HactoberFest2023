def generate_primes(limit):
    primes = []
    for num in range(2, limit + 1):
        is_prime = True
        for divisor in range(2, int(num ** 0.5) + 1):
            if num % divisor == 0:
                is_prime = False
                break
        if is_prime:
            primes.append(num)
    return primes

if __name__ == "__main__":
    try:
        limit = int(input("Generate prime numbers up to: "))
        prime_numbers = generate_primes(limit)
        print("Prime numbers up to", limit, "are:", prime_numbers)
    except ValueError:
        print("Please enter a valid number as the limit.")

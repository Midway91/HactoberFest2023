def fibonacci_series(n):
    fib_series = [0, 1]

    while len(fib_series) < n:
        next_term = fib_series[-1] + fib_series[-2]
        fib_series.append(next_term)

    return fib_series

def main():
    # Get the number of terms from the user
    n = int(input("Enter the number of terms in the Fibonacci series: "))

    # Generate and display the Fibonacci series
    fib_series = fibonacci_series(n)
    print(f"Fibonacci Series with {n} terms: {fib_series}")

if __name__ == "__main__":
    main()

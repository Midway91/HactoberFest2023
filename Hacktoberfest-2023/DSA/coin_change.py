'''
@Author: hariom09090
'''

#  Q. Find the minimum number of coins needed from a given set of denominations to reach a specified target amount.
def coinChange(coins, amount):
    dp = [float('inf')] * (amount + 1)
    dp[0] = 0
    
    for coin in coins:
        for i in range(coin, amount + 1):
            dp[i] = min(dp[i], dp[i - coin] + 1)
    
    return dp[amount] if dp[amount] != float('inf') else -1

if __name__ == "__main__":
    try:
        coins_str = input("Enter coin denominations separated by spaces: ")
        coins = list(map(int, coins_str.split()))
        
        amount = int(input("Enter the target amount: "))

        result = coinChange(coins, amount)

        if result != -1:
            print(f"Minimum number of coins needed to make {amount} is: {result}")
        else:
            print("It's impossible to make change for this amount with the given denominations.")
    
    except ValueError:
        print("Invalid input. Please enter valid coin denominations and a target amount.")

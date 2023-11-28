class Solution(object):
    def maxCoins(self, piles):
        """
        :type piles: List[int]
        :rtype: int
        """
        piles.sort(reverse=True)  # Sort the piles in descending order
        n = len(piles)
        your_coins = 0

        for i in range(1, n // 3 * 2, 2):
            your_coins += piles[i]

        return your_coins

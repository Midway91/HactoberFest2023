# Title: 735. Asteroid Collision
# Difficulty: Medium
# Problem: https://leetcode.com/problems/asteroid-collision/description/?envType=study-plan-v2&envId=leetcode-75

## ----- Solution using stack ----- ##


class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        stack = []

        for asteroid in asteroids:
            while stack and asteroid < 0 and stack[-1] > 0:
                if abs(asteroid) == stack[-1]:
                    stack.pop()
                elif abs(asteroid) > stack[-1]:
                    stack.pop()
                    continue
                break
            else:
                stack.append(asteroid)
        return stack


## ----- Solution without using stack ------ ##


class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        # while there are two or more elements in stack and last 2 elements
        end = len(asteroids) - 1
        while end >= 0:
            if asteroids[end] > 0:
                if end < len(asteroids) - 1:
                    if asteroids[end + 1] < 0:
                        if abs(asteroids[end + 1]) < abs(asteroids[end]):
                            asteroids.pop(end + 1)
                            end += 1
                        elif abs(asteroids[end + 1]) == abs(asteroids[end]):
                            asteroids.pop(end + 1)
                            asteroids.pop(end)
                        else:
                            asteroids.pop(end)
            else:
                if end > 0:
                    if asteroids[end - 1] > 0:
                        if abs(asteroids[end - 1]) < abs(asteroids[end]):
                            asteroids.pop(end - 1)
                        elif abs(asteroids[end - 1]) == abs(asteroids[end]):
                            asteroids.pop(end)
                            asteroids.pop(end - 1)
                            end -= 1
                        else:
                            asteroids.pop(end)
            end -= 1

        return asteroids

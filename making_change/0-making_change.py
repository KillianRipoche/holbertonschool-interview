#!/usr/bin/python3
"""
Module for making change
"""


def makeChange(coins, total):
    """
    Determine the fewest number of coins needed to meet a given total.

    Args:
        coins: list of coin values available
        total: target amount

    Return:
        fewest number of coins needed, or -1 if impossible
    """
    if total <= 0:
        return 0

    dp = [float('inf')] * (total + 1)
    dp[0] = 0

    for i in range(1, total + 1):
        for coin in coins:
            if coin <= i and dp[i - coin] + 1 < dp[i]:
                dp[i] = dp[i - coin] + 1

    if dp[total] == float('inf'):
        return -1
    return dp[total]

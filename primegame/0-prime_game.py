#!/usr/bin/python3
"""Prime Game"""


def isWinner(x, nums):
    """
    Determine who wins the most rounds of the prime game.
    Maria always goes first; both play optimally.

    Args:
        x: number of rounds
        nums: list of n values, one per round

    Return: name of the player with most wins, or None if tied
    """
    if not nums or x == 0:
        return None

    max_n = max(nums)

    sieve = [True] * (max_n + 1) if max_n >= 0 else []
    if max_n >= 0:
        sieve[0] = False
    if max_n >= 1:
        sieve[1] = False

    i = 2
    while i * i <= max_n:
        if sieve[i]:
            j = i * i
            while j <= max_n:
                sieve[j] = False
                j += i
        i += 1

    prime_count = [0] * (max_n + 1)
    for i in range(1, max_n + 1):
        prime_count[i] = prime_count[i - 1] + (1 if sieve[i] else 0)

    maria_wins = 0
    ben_wins = 0

    for n in nums[:x]:
        if prime_count[n] % 2 == 1:
            maria_wins += 1
        else:
            ben_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    if ben_wins > maria_wins:
        return "Ben"
    return None

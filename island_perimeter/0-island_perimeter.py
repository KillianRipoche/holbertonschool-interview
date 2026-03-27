#!/usr/bin/python3
"""Module for island_perimeter function."""


def island_perimeter(grid):
    """Return the perimeter of the island described in grid.

    Args:
        grid: list of list of integers (0=water, 1=land)

    Returns:
        Integer perimeter of the island.
    """
    perimeter = 0
    rows = len(grid)
    cols = len(grid[0]) if rows else 0

    for r in range(rows):
        for c in range(cols):
            if grid[r][c] == 1:
                perimeter += 4
                if r > 0 and grid[r - 1][c] == 1:
                    perimeter -= 2
                if c > 0 and grid[r][c - 1] == 1:
                    perimeter -= 2

    return perimeter

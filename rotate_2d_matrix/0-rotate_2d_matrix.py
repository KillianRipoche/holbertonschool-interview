#!/usr/bin/python3
"""
Module for rotating a 2D matrix 90 degrees clockwise
"""


def rotate_2d_matrix(matrix):
    """
    Rotates an n x n 2D matrix 90 degrees clockwise in-place.

    The rotation is done in two steps:
    1. Transpose the matrix (swap rows and columns)
    2. Reverse each row

    Args:
        matrix: 2D list representing the matrix to rotate
    """
    n = len(matrix)

    # Step 1: Transpose the matrix (swap rows and columns)
    for i in range(n):
        for j in range(i, n):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

    # Step 2: Reverse each row
    for i in range(n):
        matrix[i].reverse()

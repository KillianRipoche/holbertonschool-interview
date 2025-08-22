#!/usr/bin/python3
"""
Lockboxes :

Write a method that determines if all the boxes can be opened
"""


def canUnlockAll(boxes):
    """
    Return True if all boxes can be opened, else False
    """
    if not isinstance(boxes, list) or len(boxes) == 0:
        return False
    if not isinstance(boxes[0], list):
        return False

    n = len(boxes)
    opened = set([0])
    stack = list(boxes[0])

    while stack:
        key = stack.pop()
        if isinstance(key, int) and 0 <= key < n and key not in opened:
            opened.add(key)
            if isinstance(boxes[key], list):
                stack.extend(boxes[key])

    return len(opened) == n

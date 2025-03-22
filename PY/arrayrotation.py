# Clockwise Rotation of a 2D List
def rotateClockwise(list2D):
    return [list(x) for x in list(zip(*list2D[::-1]))]

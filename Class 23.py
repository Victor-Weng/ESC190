# storing image in Python

## first row:

im = [[10, 20, 20], [50, 20, 15]]
[[12, 51, 12], [12, 74, 23]],
[[12, 64, 90], [15, 75, 90]]

# a 3 by 2 image
# pixel (2,0) = [12, 64, 90]
# to access (2, 0),: im[2][0]
#im[2][0][1] = 64

'''
store tables in C:
use indices to simulate an n-dim table

store im as 1-D array, reading everything top to bottom left to right
'''

im_flat = [10, 20, 20, 50, 20, 15, 12 ,52, 12, ...]

# want to access (2,0)
# skip 2 rows then skip 0 columns
im_flat[2*(3*2) + 0*3 + 0]

# to access the G channel:
im_flat[2*(3*2) + 0*3 + 1]

# to access the B channel:
im_flat[2*(3*2) + 0*3 + 2]

# channel k of pixel(i, j):
# with width w, number of channels c
# im_flat[i*(w*c) + j*c + k]

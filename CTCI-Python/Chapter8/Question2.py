'''
Robot in a Grid: Imagine a robot sitting on the upper left corner of grid with r rows and c columns.
The robot can only move in two directions, right and down, but certain cells are "off limits" such that
the robot cannot step on them. Design an algorithm to find a path for the robot from the top left to
the bottom right. 
'''


def getPath(matrix):
	if matrix is None:
		return False
	r = len(matrix)
	if not r:
		return False
	c = len(matrix[0])
	if not c:
		return False

	if not matrix[r-1][c-1]:
		return False
	path = []
	if findPath(matrix, 0, 0, r, c, path, set()):
		return path
	return None

def findPath(matrix, r, c, rLen, cLen, path, badPoints):
	point = (r,c)
	if point in badPoints or r == rLen or c == cLen or not matrix[r][c]:
		badPoints.add(point)
		return False
	

	
	if ((r == rLen-1) and (c == cLen-1)) or \
	findPath(matrix, r+1, c, rLen, cLen, path, badPoints) or \
	findPath(matrix, r, c+1, rLen, cLen, path, badPoints):
		path.insert(0,point)
		return True
	else:
		badPoints.add(point)
		return False
matrix = []
for i in xrange(3):
	matrix.append([])
	for j in xrange(8):
			matrix[i].append(True) 

matrix[1][0] = False
matrix[0][2] = False
matrix[2][1] = False
matrix[2][2] = False
matrix[2][3] = False

print matrix
print getPath(matrix)



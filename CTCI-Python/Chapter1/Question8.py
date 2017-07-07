'''
Zero Matrix: Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
column are set to O. 
'''

def zeroMatrix(matrix, m,n):
	cols = set()
	rows = set()

	for(i,r) in enumerate(matrix):
		for(j,c) in enumerate(r):
			if c == 0:
				rows.add(i)
				cols.add(j)
	for(i,r) in enumerate(matrix):
		for(j,c) in enumerate(r):
			if i in rows or j in cols:
				matrix[i][j] = 0

a = []
for i in xrange(3):
	a.append([])
	for j in xrange(8):
		a[i].append(i+j) 

print a
zeroMatrix(a, 3,8)
print a
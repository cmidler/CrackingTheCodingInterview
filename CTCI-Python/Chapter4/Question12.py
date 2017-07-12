'''
Paths with Sum: You are given a binary tree in which each node contains an integer value (which
might be positive or negative). Design an algorithm to count the number of paths that sum to a
given value. The path does not need to start or end at the root or a leaf, but it must go downwards
(traveling only from parent nodes to child nodes). 
'''

class Node():
	def __init__(self, data=None):
		self.data = data
		self.left = None
		self.right = None

def pathsWithSum(root, total):
	if root is None:
		return 0
	
	return pathsFromNode(root, total, 0, {})

def pathsFromNode(node, total, currentSum, sums):
	if node is None:
		return 0

	currentSum+=node.data
	val = currentSum-total

	totalPaths = 0
	if val in sums:
		totalPaths = sums[val]


	if currentSum == total:
		totalPaths+=1


	if currentSum in sums:
		sums[currentSum] +=1
	else:
		sums[currentSum] = 1

	totalPaths+= pathsFromNode(node.left, total, currentSum, sums) + pathsFromNode(node.right, total, currentSum, sums)
	sums[currentSum]-=1

	return totalPaths

n1 = Node(10)
n2 = Node(5)
n3 = Node(1)
n4 = Node(2)
n5 = Node(-1)
n6 = Node(-1)
n7 = Node(7)
n8 = Node(1)
n9 = Node(2)

n1.left = n2
n2.left = n3
n3.left = n4
n4.left = n5
n5.left = n6
n6.left = n7
n7.left = n8
n8.left = n9

print pathsWithSum(n1, 8)



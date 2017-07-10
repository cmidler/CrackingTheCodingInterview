'''
Minimal Tree: Given a sorted (increasing order) array with unique integer elements, write an
algorithm to create a binary search tree with minimal height. 
'''

class Node():
	def __init__(self, data):
		self.data = data
		self.left = None
		self.right = None


def createMinimalTree(sorted_array):
	if not sorted_array:
		return None
	mid = len(sorted_array)/2
	node = Node(sorted_array[mid])
	if len(sorted_array) != 1:
		node.left = createMinimalTree(sorted_array[:mid])
		node.right = createMinimalTree(sorted_array[mid+1:])
	return node

def printTree(root):
	if root!= None:
		print root.data
		printTree(root.left)
		printTree(root.right)


sorted_array = [1,2,3,4,5,6,7,8,9]

printTree(createMinimalTree(sorted_array))
'''
First Common Ancestor: Design an algorithm and write code to find the first common ancestor
of two nodes in a binary tree. Avoid storing additional nodes in a data structure. NOTE: This is not
necessarily a binary search tree. 
'''

class Node():
	def __init__(self, data=None):
		self.data = data
		self.left = None
		self.right = None
		self.isAncestor = False

def ancestor(root, n1, n2):
	node = firstCommonAncestor(root, n1, n2)
	if node is not None and node.isAncestor:
		return node
	return None

def firstCommonAncestor(root, n1, n2):
	if root is None:
		return None

	if root is n1 and root is n2:
		root.isAncestor = True
		return root

	left = firstCommonAncestor(root.left, n1, n2)
	if left is not None and left.isAncestor:
		return left


	right = firstCommonAncestor(root.right, n1, n2)
	if right is not None and right.isAncestor:
		return right
	
	
	if left is not None and right is not None:
		root.isAncestor = True
		return root
	elif root is n1 or root is n2:
		if left is not None or right is not None:
			root.isAncestor = True
		return root
	elif left is not None:
		return left
	else:
		return right

def resetAncestor(root):
	if root is None:
		return
	resetAncestor(root.left)
	resetAncestor(root.right)
	root.isAncestor = False

n1 = Node('A')
n2 = Node('B')
n3 = Node('C')
n4 = Node('D')
n5 = Node('E')
n6 = Node('F')
n7 = Node('G')
n8 = Node('H')
n1.left = n2

n2.left = n3
n2.right = n5

n3.left = n4
n4.left = n6
n4.right = n7

print ancestor(n1, n4, n5).data
resetAncestor(n1)
print ancestor(n1, n6, n7).data
resetAncestor(n1)
print ancestor(n1, n4, n2).data
resetAncestor(n1)
print ancestor(n1, n6, n1).data
resetAncestor(n1)
print ancestor(n1, n4, n8)
resetAncestor(n1)




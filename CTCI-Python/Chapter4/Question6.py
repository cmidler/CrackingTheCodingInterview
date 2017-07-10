'''
Successor: Write an algorithm to find the "next" node (i.e., in-order successor) of a given node in a
binary search tree. You may assume that each node has a link to its parent. 
'''

class Node():
	def __init__(self, data=None):
		self.data = data
		self.left = None
		self.right = None
		self.parent = None

def findSuccessor(node):
	return findNext(node)

def findNext(node):
	if node is None:
		return None
	if node.right is not None:
		return traverse(node.right)
	else:
		return traverseParent(node.parent, node.data)

def traverseParent(node, data):
	if node is None:
		return None
	if node.data >= data:
		return node

	return traverseParent(node.parent, data)

def traverse(node):
	if node.left is not None:
		return traverse(node.left)
	else:
		return node

n1 = Node('8')
n2 = Node('2')
n3 = Node('1')
n4 = Node('6')
n5 = Node('4')
n6 = Node('3')
n7 = Node('5')
n8 = Node('7')
n9 = Node('9')

n1.left = n2
n1.right = n9
n9.parent = n1
n2.parent = n1
n2.left = n3
n3.parent = n2
n2.right = n4
n4.parent = n2
n4.left = n5
n5.parent = n4
n4.right = n8
n8.parent = n4
n5.left = n6
n6.parent = n5
n5.right = n7
n7.parent = n5

print findSuccessor(n2).data
print findSuccessor(n8).data
print findSuccessor(n9)
print findSuccessor(n7).data
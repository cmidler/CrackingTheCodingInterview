'''
Check Balanced: Implement a function to check if a binary tree is balanced. For the purposes of
this question, a balanced tree is defined to be a tree such that the heights of the two subtrees of any
node never differ by more than one. 
'''

class Node():
	def __init__(self, data=None):
		self.data = data
		self.left = None
		self.right = None

def getHeight(node, flag):
	if not flag:
		return -1
	left = node.left
	right = node.right
	if not left and not right:
		return 1
	leftH = 0
	rightH = 0
	if left:
		leftH = getHeight(left, flag)
		if leftH == -1:
			return -1
	if right:
		rightH = getHeight(right, flag)
		if rightH == -1:
			return -1
	print "Left and right height of node: " + node.data + " "+str(leftH) + str(rightH)
	if abs(rightH-leftH) > 1:
		flag = 0
		return -1
	return max(leftH, rightH)+1


def isBalanced(root):
	if root is None:
		return True
	flag = True
	h = getHeight(root, flag)
	if h == -1 or not flag:
		return False
	return True

def printTree(root):
	if root!= None:
		print root.data
		printTree(root.left)
		printTree(root.right)

n1 = Node('A')
n2 = Node('B')
n3 = Node('C')
n4 = Node('D')
n5 = Node('E')
n6 = Node('F')
n7 = Node('G')

n1.left = n2
n1.right = n3

n2.left = n4

n4.left = n5
n4.right = n6

n5.left = n7
printTree(n1)
print isBalanced(n1)

n2.right = n5
n5.left = None
n4.left = None
n3.left = n7
printTree(n1)
print isBalanced(n1)

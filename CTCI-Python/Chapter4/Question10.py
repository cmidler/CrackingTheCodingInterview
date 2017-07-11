'''
Check Subtree: Tl and T2 are two very large binary trees, with Tl much bigger than T2. Create an
algorithm to determine if T2 is a subtree of Tl.
A tree T2 is a subtree of T1 if there exists a node n in T1 such that the subtree of n is identical to T2.
That is, if you cut off the tree at node n, the two trees would be identical. 
'''

class Node():
	def __init__(self, data=None):
		self.data = data
		self.left = None
		self.right = None

def isSubtree(t1, t2):
	if t1 is None:
		return False

	if t1.data == t2.data and isMatch(t1,t2):
		return True

	if isSubtree(t1.left,t2) or isSubtree(t1.right,t2):
		return True
	return False

def isMatch(t1,t2):
	if t1 is None or t2 is None or t1.data!=t2.data:
		return False
	if t2.left is None and t2.right is None:
		return True
	left = True
	right = True
	if t2.left is not None:
		left = isMatch(t1.left, t2.left)
	if t2.right is not None:
		right = isMatch(t1.right, t2.right)
		
	
	return left and right


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

print isSubtree(n1, n4)
print isSubtree(n1, n7)
print isSubtree(n1, n1)
print isSubtree(n1, n2)

n8 = Node('B')
n9 = Node('D')
n8.right = n9

print isSubtree(n1, n8)


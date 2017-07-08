'''
Delete Middle Node: Implement an algorithm to delete a node in the middle (i.e., any node but
the first and last node, not necessarily the exact middle) of a singly linked list, given only access to
that node.
EXAMPLE
Input: the node c from the linked list a - >b- >c - >d - >e- >f
Result: nothing is returned, but the new linked list looks like a - >b- >d - >e- >f 
'''

class Node(object):
	def __init__(self, data, next_node=None):
		self.next = next_node
		self.data = data

def deleteMid(node):
	
	if node is None or node.next is None:
		return
	next_node = node.next
	node.data = next_node.data
	node.next = next_node.next
	next_node.next = None
	next_node = None

def print_list(head):
	cur = head
	while(cur!=None):
		print cur.data
		cur = cur.next
	print '\n\n'



tail = Node(6,None)
n5 = Node(5,tail)
n4 = Node(4, n5)
n3 = Node(3, n4)
n2 = Node(2, n3)
n1 = Node(1, n2)
head = Node(0, n1)

print_list(head)
deleteMid(n2)
print_list(head)
'''
Intersection: Given two (singly) linked lists, determine if the two lists intersect. Return the intersecting
node. Note that the intersection is defined based on reference, not value. That is, if the kth
node of the first linked list is the exact same node (by reference) as the jth node of the second
linked list, then they are intersecting. 
'''

class Node(object):
	def __init__(self, data=None, next_node = None):
		self.data = data
		self.next = next_node


def isSameNode(node1, node2):
	id_set = set()
	while node1 != None:
		id_set.add(id(node1))
		node1 = node1.next
	while node2 != None:
		if id(node2) in id_set:
			return node2
		node2 = node2.next
	return None

def print_list(head):
	cur = head
	while(cur!=None):
		print cur.data
		cur = cur.next
	print '\n\n'


n4 = Node('f', None)
n3 = Node('d', n4)
n2 = Node('c', n3)
n1 = Node('b', n2)
n0 = Node('a', n1)
n5 = Node('f', n2)

print_list(n0)
print_list(n5)

retNode = isSameNode(n0,n5)
if retNode is None:
	print "None"
else:
	print retNode.data
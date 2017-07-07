'''
Remove Dups: Write code to remove duplicates from an unsorted linked list.
FOLLOW UP
How would you solve this problem if a temporary buffer is not allowed? 
'''

class Node(object):
	def __init__(self, data=None, next_node=None):
		self.data = data
		self.next_node = next_node

	def get_data(self):
		return self.data

	def get_next(self):
		return self.next_node

	def set_next(self, next_node):
		self.next_node = next_node



def removeDups(head):
	vals = {}
	vals[head.get_data()] = 1
	prev = head
	cur = head.get_next()
	while(cur!=None):
		if cur.get_data() in vals:
			prev.set_next(cur.get_next())
		else:
			vals[cur.get_data()] = 1
			prev = cur
		cur = cur.get_next()
def print_list(head):
	cur = head
	while(cur!=None):
		print cur.get_data()
		cur = cur.get_next()



tail = Node(6,None)
n5 = Node(0,tail)
n4 = Node(2, n5)
n3 = Node(3, n4)
n2 = Node(2, n3)
n1 = Node(1, n2)
head = Node(0, n1)

print_list(head)
removeDups(head)
print '\n\n'
print_list(head)


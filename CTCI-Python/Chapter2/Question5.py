'''
Sum Lists: You have two numbers represented by a linked list, where each node contains a single
digit. The digits are stored in reverse order, such that the 1 's digit is at the head of the list. Write a
function that adds the two numbers and returns the sum as a linked list.
EXAMPLE
Input: (7-> 1 -> 6) + (5 -> 9 -> 2).Thatis,617 + 295.
Output: 2 -> 1 -> 9. That is, 912.
FOLLOW UP
Suppose the digits are stored in forward order. Repeat the above problem.
EXAMPLE
Input: (6 -> 1 -> 7) + (2 -> 9 -> 5).Thatis,617 + 295.
Output: 9 -> 1 -> 2. That is, 912. 
'''

class Node(object):
	def __init__(self, data=None, next_node = None):
		self.data = data
		self.next = next_node

def sumLists(list1, list2):
	num1 = fromListToNumber(list1)[::-1]
	num2 = fromListToNumber(list2)[::-1]

	total = int(num1) + int(num2)

	return fromNumberToList(total)

def fromListToNumber(head):
	num = ''
	while head != None:
		num+=str(head.data)
		head = head.next
	return num

def fromNumberToList(num):
	ptr = Node()
	head = Node()
	for c in str(num):
		if head.data is None:
			head.data = c
			head.next = None
			ptr = head
		else:
			node = Node(c,None)
			ptr.next = node
			ptr = node
	if head.data is None:
		return None
	return head
def print_list(head):
	cur = head
	while(cur!=None):
		print cur.data
		cur = cur.next
	print '\n\n'

n5 = Node(2,None)
n4 = Node(9, n5)
n3 = Node(5, n4)
n2 = Node(6, None)
n1 = Node(1, n2)
n0 = Node(7, n1)

print_list(n0)
print_list(n3)

print_list(sumLists(n0,n3))

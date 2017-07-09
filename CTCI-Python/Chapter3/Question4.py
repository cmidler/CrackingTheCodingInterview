'''
Queue via Stacks: Implement a MyQueue class which implements a queue using two stacks. 
'''

class myQueue():
	def __init__(self):
		self.s1 = []
		self.s2 = []

	def enqueue(self,data):

		while self.s2:
			self.s1.append(self.s2.pop())
		self.s1.append(data)
		return data

	def peek(self):
		while self.s1:
			self.s2.append(self.s1.pop())

		if not self.s2:
			return None
		return self.s2[-1]

	def dequeue(self):
		val = self.peek()
		if val is None:
			return None
		return self.s2.pop()


queue = myQueue()
queue.enqueue(1)
queue.enqueue(2)
print queue.dequeue()
print queue.peek()
queue.enqueue(3)
queue.enqueue(4)
print queue.dequeue()
queue.enqueue(5)
print queue.dequeue()
print queue.dequeue()
print queue.dequeue()
print queue.dequeue()


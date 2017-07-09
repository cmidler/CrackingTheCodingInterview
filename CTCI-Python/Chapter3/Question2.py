'''
Stack Min: How would you design a stack which, in addition to push and pop, has a function min
which returns the minimum element? Push, pop and min should all operate in 0(1) time. 
'''
class StackNode():
	def __init__(self, data, minimum):
		self.data = data
		self.min = minimum

def peek(stack):
	if len(stack):
		return stack[-1]
	else:
		return None

def push(stack, data):
	last = peek(stack)
	if last is None:
		stack.append(StackNode(data,data))
	else:
		minimum = min(last.min, data)
		node = StackNode(data, minimum)
		stack.append(node)

def pop(stack):
	return stack.pop()

def minimum(stack):
	return peek(stack).min

def printStack(stack):
	for n in stack:
		print n.data

stack = []
push(stack,5)
push(stack,6)
push(stack,3)
push(stack,7)
printStack(stack)
print "min is " + str(minimum(stack))
print "popping " + str(pop(stack).data)
print "min is " +str(minimum(stack))
print "popping " + str(pop(stack).data)
print "min is " +str(minimum(stack))


'''
Towers of Hanoi: In the classic problem of the Towers of Hanoi, you have 3 towers and N disks of
different sizes which can slide onto any tower. The puzzle starts with disks sorted in ascending order
of size from top to bottom (Le., each disk sits on top of an even larger one). You have the following
constraints:
(1) Only one disk can be moved at a time.
(2) A disk is slid off the top of one tower onto another tower.
(3) A disk cannot be placed on top of a smaller disk.
Write a program to move the disks from the first tower to the last using stacks. 
'''

class Tower():
	def __init__(self, towerNumber, disks):
		self.stack = []
		self.number = towerNumber
		while disks>0:
			stack.append(disks)
			disks-=1

	def moveDisks(self,n, dest, buf):
		if n > 0:
			self.moveDisks(n-1, buf, dest)
			self.moveTopTo(dest)
			buf.moveDisks(n-1, dest, self)
	def moveTopTo(self, dest):
		disk = self.stack.pop()
		dest.add(disk)

	def peek(self):
		return self.stack[-1]

	def add(self, disk):
		if not self.stack or disk < self.peek():
			self.stack.append(disk)
		else:
			raise Exception("Tried moving bigger disk onto smaller")

n = 6;
towers = []
for x in xrange(3):
	towers.append(Tower(x,0))

for x in xrange(n,0,-1):
	towers[0].stack.append(x)

towers[0].moveDisks(n, towers[2], towers[1])


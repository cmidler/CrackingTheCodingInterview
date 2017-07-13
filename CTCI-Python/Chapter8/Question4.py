'''
Power Set: Write a method to return all subsets of a set. 
'''

def powerSet(originalSet):
	sets = getSets(originalSet, set())
	sets.add(None)
	return sets

def getSets(sets, setOfSets):
	if not sets:
		return None

	for s in sets:
		setOfSets = insertIntoSets(s, setOfSets)
	return setOfSets
		

def insertIntoSets(s, setOfSets):
	copy = setOfSets.copy()
	for tmp in setOfSets:
		newSet = tmp+s
		copy.add(newSet)
	setOfSets = copy
	setOfSets.add(s)
	return setOfSets

sets = set("test")
print powerSet(sets)
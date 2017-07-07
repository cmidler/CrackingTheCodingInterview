'''
Check Permutation: Given two strings, write a method to decide if one is a permutation of the
other. 
'''


def isPermutation(s1,s2):
	if (len(s1) != len(s2)):
		return False

	d1 = {}
	d2 = {}

	for c in s1:
		if c in d1:
			d1[c]+=1
		else:
			d1[c] = 1
	for c in s2:
		if c in d2:
			d2[c]+=1
		else:
			d2[c] = 1

	for k in d1.keys():
		if k not in d2 or d1[k] != d2[k]:
			return False
	return True

print isPermutation("test", "sett")
print isPermutation("tests", "sett")
print isPermutation("tests", "eswtt")
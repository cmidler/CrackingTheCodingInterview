'''
Palindrome Permutation: Given a string, write a function to check if it is a permutation of a palindrome.
A palindrome is a word or phrase that is the same forwards and backwards. A permutation
is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.
EXAMPLE
Input: Tact Coa
Output: True (permutations: "taco cat". "atco cta". etc.) 
'''

def isPalPerm(string):
	
	string = string.lower()
	string = string.replace(" ", "")
	isOdd = len(string) % 2
	
	dict = {}
	for c in string:
		if c in dict:
			dict[c] +=1
		else:
			dict[c] = 1
	oddCount = 0
	for k in dict.keys():
		if dict[k] %2:
			oddCount+=1

	if isOdd and oddCount == 1:
		return True
	elif not isOdd and oddCount == 0:
		return True
	else:
		return False

print isPalPerm("taco cat")
print isPalPerm("T acocta")
print isPalPerm("aaab")
print isPalPerm("abab")
print isPalPerm("aqwer")
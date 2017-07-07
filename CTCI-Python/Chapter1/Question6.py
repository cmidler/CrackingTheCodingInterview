'''
String Compression: Implement a method to perform basic string compression using the counts
of repeated characters. For example, the string aabcccccaaa would become a2b1c5a3. If the
"compressed" string would not become smaller than the original string, your method should return
the original string. You can assume the string has only uppercase and lowercase letters (a - z). 
'''

def sComp(s1):
	last = s1[0]
	reducedBy = 0
	count = 0
	s2 = ''
	for c in s1:
		if c == last:
			count +=1
		else:
			cS = str(count)
			s2 += last+cS
			reducedBy+=(count-len(cS)-1)
			count = 1
			last = c
	cS = str(count)
	s2 += last+cS
	reducedBy+=(count-len(cS)-1)

	if reducedBy>0:
		return s2
	else:
		return s1

print sComp('a')
print sComp('aa')
print sComp('aaa')
print sComp('aabcccccaaa')

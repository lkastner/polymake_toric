def all(L, f):
	for i in range(0, len(L)):
		if not f(L[i]):
			return false
	return true

def apply(L, f):
	result = []
	for i in range(0,len(L)):
		result.append(f(L[i]))
	return result

def unique(L):
	result=[]
	for i in range(0,len(L)):
		test = true
		for j in range(0, len(result)):
			if L[i] == result[j]:
				test = false
				break
		if test:
			result.append(L[i])
	return result

def positions(L, f):
	result = []
	for i in range(0, len(L)):
		if f(L[i]):
			result.append(i)
	return result

def select(L, f):
	result = []
	for i in range(0, len(L)):
		if f(L[i]):
			result.append(L[i])
	return result

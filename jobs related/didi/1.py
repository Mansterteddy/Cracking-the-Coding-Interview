def get_res(lst):
	
	max_res = max_end = lst[0]

	for i in xrange(1, len(lst)):
		if max_end < 0:
			max_end = lst[i]
		else:
			max_end += lst[i]
		#print "max_res: ", max_end
		max_res = max(max_res, max_end)

	return max_res

input_string = raw_input()

row = input_string.split(" ")

lst = []
for i in row:
	lst.append(int(i))

res = get_res(lst)
print res
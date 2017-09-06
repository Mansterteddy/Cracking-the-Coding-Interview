def partition(l, r):

	pivot = lst[l]
	i = l
	j = r

	while i < j:
		while pivot < lst[j] and i < j:
			j -= 1
		if i < j:
			lst[i] = lst[j]
			i += 1
		while pivot > lst[i] and i < j:
			i += 1
		if i < j:
			lst[j] = lst[i]
			j -= 1
	
	lst[i] = pivot
	return i


def K_sort(l, r, k):

	if l == r:
		return lst[l]

	i = partition(l, r)
	j = i - l

	if j == k:
		return lst[i]

	if(j < k):
		return K_sort(i+1, r, k-j-1)

	else:
		return K_sort(l, i-1, k)


input_string = raw_input()
K = raw_input()

row = input_string.split(" ")

lst = []
for i in row:
	lst.append(int(i))

print K_sort(0, len(lst) - 1, len(lst)-int(K))
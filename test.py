A = [1,2,3,4,5,6,7,8,9]

'''
for i in range(len(A)):
    idx = i - 1
    print(idx)
'''

'''
print(max(A))
print(max(A[0:5]))
'''
'''
for i in range(2, len(A)):
    print(max(A[0:i-1]))
'''

'''
A = [1,2,3]
B = [7,8,9]
A.extend(B)
print(A)            #[1,2,3,7,8,9]
A.append(B)
print(A)            #[1, 2, 3, 7, 8, 9, [7, 8, 9]]
'''

'''
for i in range(4, -1, -1):
    print(i)        # 4 3 2 1 0
'''

ret = []
ret.extend(1)

print(ret)
import numpy as np

arr = [3,34,4,12,5,2]

def rec_subset(arr, i, s):
    if s == 0:
        return True
    elif i == 0:
        return arr[0] == s
    elif arr[i] > s:
        return rec_subset(arr, i-1, s)
    else:
        A = rec_subset(arr, i-1,s-arr[i])
        B = rec_subset(arr,i-1,s)
        return A or B

def dp_subset(arr,S):
    subset = np.zeros((len(arr), S+1), dtype=bool)
    subset[:, 0] = True
    subset[0, :] = False
    subset[0, arr[0]] = True

    for i in range(1, len(arr)):
        for s in range(1, S+1):
            if arr[i] > s:
                subset[i,s] = subset[i-1,s]
            else:
                A = subset[i-1, s-arr[i]]
                B = subset[i-1, s]
                subset[i,s] = A or B
    r,c = subset.shape
    return subset[r-1, c-1]



print(rec_subset(arr, len(arr) - 1, 9))

print(dp_subset(arr, 9))
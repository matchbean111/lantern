import numpy as np

rr = [1,2,4,1,7,8,3]

def rec_opt(arr, i):
    if i == 0:
        return arr[0]
    elif i == 1:
        return max(arr[0],arr[1])
    else:
        A = rec_opt(arr,i-2) + arr[i]
        B = rec_opt(arr, i-1)
        return max(A,B)

# def dp_opt(arr, i):
#     opt = np.zeros()

res = rec_opt(arr, 6)
print(res)
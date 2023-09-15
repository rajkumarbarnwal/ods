print("Hello World")
n= 8
arr1 = [2,3,4,6,7,4,2,5,1,9,2,15,2,7,9,19]
max=arr1[0]
for i in range(len(arr1)):
    if(max < arr1[i]):
        max = arr1[i]
print(max) 
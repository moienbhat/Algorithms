def linear_search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return i  
    return -1  


array = [10, 25, 7, 30, 42]
target = 30

result = linear_search(array, target)
if result != -1:
    print(f"Element found at index {result}")
else:
    print("Element not found in the array")
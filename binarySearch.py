def binary_search(arr, target):
    left = 0
    right = len(arr) - 1

    while left <= right:
        mid = (left + right) // 2

        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return -1

# Taking array input from the user
arr = list(map(int, input("Enter the array elements separated by space: ").split()))
target = int(input("Enter the element to search: "))

# Sorting the array
arr.sort()

# Performing binary search
result = binary_search(arr, target)

if result != -1:
    print(f"Element found at index {result} (in the sorted array)")
else:
    print("Element not found in the array")

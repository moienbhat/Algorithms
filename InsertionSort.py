def insertionSort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1

        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1


        arr[j + 1] = key


arr = list(map(int, input("Enter numbers separated by spaces: ").split()))

insertionSort(arr)
print("Sorted Array: ", arr)
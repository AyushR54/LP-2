def selection_sort(arr):
    n = len(arr)
    
    for i in range(n):
        # Find the minimum element in the unsorted part of the array
        min_idx = i
        for j in range(i+1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        
        # Swap the found minimum element with the first element
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
        
    return arr

def greedy_selection_sort(arr):
    n = len(arr)
    sorted_arr = []
    
    for i in range(n):
        # Find the minimum element in the unsorted part of the array
        min_idx = 0
        for j in range(1, len(arr)):
            if arr[j] < arr[min_idx]:
                min_idx = j
        
        # Add the found minimum element to the sorted array and remove it from the original array
        sorted_arr.append(arr.pop(min_idx))
    
    return sorted_arr

# Accept user input for the array
arr = list(map(int, input("Enter the elements of the array separated by space: ").split()))

# Test the algorithms
print("Original Array:", arr)
print("Using Selection Sort:", selection_sort(arr.copy()))
print("Using Greedy Selection Sort:", greedy_selection_sort(arr.copy()))
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a dynamic array of integers
typedef struct
{
    int *data;    // Pointer to the array's elements
    int size;     // Number of elements currently stored
    int capacity; // Allocated memory capacity (in number of elements)
} dArray;

// Function to resize (expand) the dynamic array when full
void dArrRe(dArray *arr)
{
    int newCapacity = arr->capacity * 2; // Double the current capacity

    // Reallocate memory with the new capacity
    int *temp = realloc(arr->data, sizeof(int) * newCapacity);
    if (temp == NULL)
    {
        fprintf(stderr, "reallocation failed!\n");
        return;
    }

    // If realloc succeeds, update array fields
    arr->capacity = newCapacity;
    arr->data = temp;
}

// Initialize the dynamic array with a given capacity
void initArray(dArray *arr, int capacity)
{
    arr->data = malloc(sizeof(int) * capacity); // Allocate memory
    if (arr->data == NULL)
    {
        fprintf(stderr, "memory allocation failed!\n");
    }

    arr->size = 0;            // Start with zero elements
    arr->capacity = capacity; // Set initial capacity

    printf("array initialized to size: %d and capacity: %d\n", arr->size, arr->capacity);
}

// Append an integer to the dynamic array, resizing if needed
void appendI(dArray *arr, int value)
{
    // If array is full, resize it
    if (arr->size == arr->capacity)
    {
        dArrRe(arr);
        printf("expanding array to: %d\n", arr->capacity);

        // In case realloc fails and capacity didn’t increase
        if (arr->capacity == arr->size)
        {
            fprintf(stderr, "Cannot expand array, append failed.\n");
            return;
        }
    }

    // Store the new value at the end and increment size
    arr->data[arr->size] = value;
    arr->size++;
}

// Print the current contents of the dynamic array
void printArrData(dArray *arr)
{
    printf("Contents: ");
    for (int i = 0; i < arr->size; i++)
    {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

// Generate the nth Fibonacci number (iteratively)
int fibonacci(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    int a = 0, b = 1, result;
    for (int i = 2; i <= n; i++)
    {
        result = a + b;
        a = b;
        b = result;
    }
    return b;
}

// Get the value at a given index in the array
int getData(dArray *arr, int index)
{
    int value = arr->data[index];
    return value;
}

// Remove an element at a specific index and shift all elements after it left
void removeAt(dArray *arr, int index)
{
    // Bounds check
    if (index < 0 || index >= arr->size)
    {
        fprintf(stderr, "removeAt error: index %d out of bounds (size: %d)\n", index, arr->size);
        return;
    }

    // Shift elements to the left to fill the gap
    for (int i = index; i < arr->size - 1; i++)
    {
        arr->data[i] = arr->data[i + 1];
    }

    // Decrease size by 1
    arr->size--;
    printf("Removed element at index %d\n", index);
    printArrData(arr);
}

// Free all memory used by the array and reset its fields
void freeArray(dArray *arr)
{
    free(arr->data);  // Free the dynamically allocated memory
    arr->data = NULL; // Set pointer to NULL for safety
    arr->capacity = 0;
    arr->size = 0;

    printArrData(arr); // Optionally print the now-empty array
}

int main()
{
    dArray testArray;

    // Step 1: Initialize dynamic array with capacity of 10
    initArray(&testArray, 10);

    // Step 2: Fill the array with first 10 Fibonacci numbers
    for (int i = 0; i < 10; i++)
    {
        appendI(&testArray, fibonacci(i));
    }

    // Step 3: Print the initial array contents
    printf("\nInitial array:\n");
    printArrData(&testArray);

    // Step 4: Remove a few elements to test the shifting
    printf("\nRemoving element at index 3 (should be 2):\n");
    removeAt(&testArray, 3);

    printf("\nRemoving element at index 0 (should be 0):\n");
    removeAt(&testArray, 0);

    printf("\nRemoving element at last index (should be 21):\n");
    removeAt(&testArray, testArray.size - 1);

    // Step 5: Attempt to remove at an invalid index
    printf("\nTrying to remove at invalid index (out of bounds):\n");
    removeAt(&testArray, 100); // This should print an error

    // Step 6: Final array state after modifications
    printf("\nFinal array state:\n");
    printArrData(&testArray);

    // Step 7: Free memory used by the array
    freeArray(&testArray);

    return 0;
}

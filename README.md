
# 🔢 Dynamic Array in C

This is a simple C project that implements a dynamic (resizable) array for integers, similar to `std::vector` in C++. It supports:

- Dynamic resizing (reallocation)
- Appending integers
- Getting values by index
- Removing elements at a given index (with shifting)
- Memory management (freeing)

---

## 🧰 Features

### ✅ Dynamic Array Operations

| Function       | Description                                                |
| -------------- | ---------------------------------------------------------- |
| `initArray`    | Initializes the array with an initial capacity             |
| `appendI`      | Appends an integer to the end of the array                 |
| `dArrRe`       | Doubles the capacity when the array is full                |
| `getData`      | Retrieves the value at a specific index                    |
| `removeAt`     | Removes an element at a specific index and shifts the rest |
| `printArrData` | Prints the array contents and current size/capacity        |
| `freeArray`    | Frees the dynamically allocated memory                     |

---

## 🧪 Example Program

The `main()` function:

1. Initializes a dynamic array.
2. Appends the first 10 Fibonacci numbers.
3. Removes a few elements at various positions.
4. Prints the array at each step.

```c
int main()
{
    dArray testArray;
    initArray(&testArray, 10);

    for (int i = 0; i < 10; i++)
        appendI(&testArray, fibonacci(i));

    printArrData(&testArray);

    removeAt(&testArray, 3); // Remove index 3
    removeAt(&testArray, 0); // Remove index 0
    removeAt(&testArray, testArray.size - 1); // Remove last

    removeAt(&testArray, 100); // Invalid index test

    printArrData(&testArray);

    freeArray(&testArray);
    return 0;
}

```

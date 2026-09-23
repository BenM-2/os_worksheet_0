# OS Worksheet 0

## Task 1
To run task 1: 
``` bash
make task_1 && ./build/exec/task_1 
```
### Overview 
Create a pointer to the local variable n called ptr_to_n, and use it to increase the value of
n by one.Print the result.
> [!TIP]
> To print a pointer cast it to void * then use %p to print it like this printf("%p",(void *)ptr)
## Task 2
To run task 2: 
``` bash
make task_2 && ./build/exec/task_2
```
### Overview
Create an array that has 3 elements (10, 30, 2000), and declare a pointer to that array, and then a loop that iterates through the array, using the pointer, printing each element, and the pointer of that element.

## Task 3
To run task 3: 
``` bash
make task_3 && ./build/exec/task_3  
```
### Overview
Implement a function that takes two pointers, to the same type, along with a length parameter. If the pointers are not null, then check that the elements are the same, for length, and return true (1), otherwise false (0). Write a main function to test your function.


## Task 4 
To run task 4: 
``` bash
make task_4 && ./build/exec/task_4 foo.txt  
```
### Overview
Write a program that reads the following numbers from a file, and prints their sum.

foo.txt
``` 
10
20
30
40
54
```

## Task 5
To run task 5: 
``` bash
make task_5 && ./build/exec/task_5 
```
#### Overview
Implement a program that contains the swap function, and tests it works correclty. with the function signature 
``` c
void swap(void * x, void * y);
```
> [!NOTE]
> with this function signature it is impossible to make a generic swap without length due to void * discarding type qualifier and hence type length.A Full implementation can be done via a macro as shown in comments in task_5.c 

## Task 6
To run task 6: 
``` bash
make task_6 && ./build/exec/task_6 
```
### Overview
Implement a function to prints a 2D‑array, given a pointer to the array, and its corresponding
width and height with teh function signature 
``` c
void print_array(int * arr, int width, int height);
```

## Tic Tac Toe
To run TTT: 
``` bash
make TTT && ./build/exec/TTT 3  
```
### Overview 
Implement Tic Tac Toe 

### Grid Layout 
```
    0   1   2
    3   4   5
    6   7   8
```

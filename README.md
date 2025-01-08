Push Swap

Push Swap is a project that focuses on sorting algorithms and organizing code. It leverages previously made functions and offers a great opportunity to dive deep into linked lists. The goal is to sort a set of numbers using a limited set of commands while also learning how to manage data structures efficiently.

🚀 The Project
The idea behind Push Swap is to take a set of numbers and sort them with a few allowed operations. We work with two stacks: stack_a and stack_b. Initially, stack_a holds the set of numbers, and stack_b starts off empty.

To make things simpler and reusable, I first created a Makefile that links all the previously written functions together. This way, I can build the push_swap executable with a single command:

make
🛠️ Allowed Operations
You are restricted to using the following commands to manipulate the stacks:

sa (swap a): Swap the first two elements at the top of stack_a. Do nothing if there is only one or no elements.
sb (swap b): Swap the first two elements at the top of stack_b. Do nothing if there is only one or no elements.
ss: Perform sa and sb at the same time.
pa (push a): Take the first element from the top of stack_b and push it to the top of stack_a. Do nothing if stack_b is empty.
pb (push b): Take the first element from the top of stack_a and push it to the top of stack_b. Do nothing if stack_a is empty.
ra (rotate a): Shift up all elements of stack_a by one. The first element becomes the last one.
rb (rotate b): Shift up all elements of stack_b by one. The first element becomes the last one.
rr: Perform ra and rb at the same time.
rra (reverse rotate a): Shift down all elements of stack_a by one. The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack_b by one. The last element becomes the first one.
rrr: Perform rra and rrb at the same time.
💡 Learning Focus
The most challenging part of this project for me will likely be navigating through the linked lists, which is crucial for efficient stack manipulation. But I'm confident that with time and practice, I'll get there!


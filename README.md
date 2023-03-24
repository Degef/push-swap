# push-swap
42 Project Push Swap 

The rules
* You have 2 stacks named a and b.
* At the beginning:
* The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated.
* The stack b is empty.
* The goal is to sort in ascending order numbers into stack a. To do so you have the following operations at your disposal:

**sa** (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.

**sb** (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.

**ss** : sa and sb at the same time.

**pa** (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.

**pb** (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.

**ra** (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.

**rb** (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.

**rr** : ra and rb at the same time.

**rra** (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.

**rrb** (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.

**rrr** : rra and rrb at the same time.

## Result 100 numbers
<img width="721" alt="Screen Shot 2023-03-24 at 5 41 30 PM" src="https://user-images.githubusercontent.com/103037326/227542053-3cd510a0-7ee0-4da1-8d6b-7e2cea31a968.png">

## Result 500 numbers

<img width="722" alt="Screen Shot 2023-03-24 at 5 45 33 PM" src="https://user-images.githubusercontent.com/103037326/227542106-87e2519e-f396-470d-9497-e89e61ca4587.png">

## My Algorithm

1. I first joined all the contents inserted into one string separating by space. 
2. Then I chech if there is any invalid argument, which can be letter or anything outside number 
3. Then I check if there is duplicates and exit the program 
4. Then I create stack a based on the given numbers 
5. I partially used radix sorting technique. So I assign an index to each node in my stack. The index value is 
	the position that the specfic node should be place if they were sorted. So, now I can totally forget about the 
	real values and work only with the index number that I assigned. 

THE SORTING ALGORITHM SORTING STARTS FROM HERE
1. I check if the stack is already sorted. If so, simply exit else continue.  
2. check if the stack has two numbers. If so, do sa and exit. 
3. check if the stack has three numbers. If so, call the three numbers sorting 
   function and do the sorting. else continue
4. If stack_a has more than 3 elements then leave three items in stack_a and 
	send everything to stack_b using mid_point algorithm. Once all the elements 
	what are less than the first mid point are gone, we apply mid point algorith
	to the remaining onse. 
	the mid point algorithm find mean(mid pt) of stack a and send all that are less than it to b
	if the top is not less than a, send it to back using ra. 
5. Once only three elements are left on stack a, we will sort them using the three number sorting function. 
THE HIGHEST SORTING STARTS FROM HERE
while stack_b is not empty the following tasks will be repeated sequencailly
	1. find the current position of each element on stack a and stack b.
	2. Find total cost of putting the element to its position back in stack_a. which the cost of bringing the element to top of b
	   and the cost of find the position of the element in a and changing its position to be at the top of stack_a.
	3. So, now we have the costs of all the elements in b. Now we select the element with the least cost. 
	4. Finally we act the instructions of the element with list instructions

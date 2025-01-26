<div align="center">
	<picture>
		<img src="https://github.com/ayogun/42-project-badges/blob/main/badges/push_swapm.png" alt="42 The 'Push Swap' school project with a bonus badge.">
	</picture>  

<p><a href="https://www.hive.fi/en/curriculum">Hive (42 School Network)</a></p>  

<h1>Push Swap</h1> 

</div>

### Overview
The goal is to sort a stack of integers using:   
* Two stacks: stack A (initial stack) and stack B (temporary stack).  
* A limited set of operations to manipulate the stacks.  
* Limited number of moves (less than 5500 for set of 500 integers for highest grade).

### Solution
The solution uses a **circular buffer** for the stack implementation, improving performance. Sorting is achieved with a customised **quick sort algorithm**, designed to generate the required stack operations efficiently and minimise the number of moves. The approach was inspired by results shared by 42 School Seoul peers and this [article](https://medium.com/@ulysse.gerkens/push-swap-in-less-than-4200-operations-c292f034f6c0) by Ulysse Gerkens.   

<div align="center">
<picture>
		<img src="https://github.com/ipersids/ipersids/blob/main/assets/hive-repo-assets/push-swap.gif" alt="Push Swap algorithm visualisation" height=480>
</picture>  
</div>

### Allowed operations  
1) Push: move the top element between stacks.  
  * `pa`: Push the top element of `stack B` to `stack A`.  
  * `pb`: Push the top element of `stack A` to `stack B`.  
2) Swap: swap the first two elements of a stack.  
  * `sa`: Swap the first two elements of `stack A`.  
  * `sb`: Swap the first two elements of `stack B`.  
  * `ss`: Swap the first two elements of both stacks simultaneously.  
3) Rotate: rotate the stack upwards (the first element becomes the last).  
  * `ra`: Rotate `stack A`.  
  * `rb`: Rotate `stack B`.  
  * `rr`: Rotate both stacks simultaneously.  
4) Reverse Rotate: rotate the stack downwards (the last element becomes the first).  
  * `rra`: Reverse rotate `stack A`.  
  * `rrb`: Reverse rotate `stack B`.  
  * `rrr`: Reverse rotate both stacks simultaneously.

### Where to start  
1. Clone the repository:  
   ```bash
   git clone https://github.com/ipersids/hive-core-push-swap.git push-swap
   cd push-swap
   ```
2. Compile using Makefile:  
  * `make` — compile the push-swap program.  
  * `make bonus` — compile the checker program.  
  * `make clean` — clean up object files.  
  * `make fclean` — clean up executables and object files.  

3. Run the program:  
   ```bash
   ARG="-9 2 -5 1 8 3 -7 4 6 0"; ./push_swap $ARG
   ```
   or `./push_swap 4 5 7 1 9 3`, or `./push_swap 4 5 "7 1" 9 3` - both formats are supported.
5. Check the operation count:  
   ```bash
   ARG="-9 2 -5 1 8 3 -7 4 6 0"; ./push_swap $ARG | wc -l
   ``` 
7. Validate the output using the custome checker program:  
   ```bash
   ARG="-9 2 -5 1 8 3 -7 4 6 0"; ./push_swap $ARG | ./checker $ARG
   ```
   Output:  
   * `OK` if the numbers are correctly sorted by the given operations  
   * `KO` if the numbers aren't sorted correctly  
   * `Error\n` if there's an error :)  

______________  
Made by **Julia Persidskaia**.    
[LinkedIn](https://www.linkedin.com/in/iuliia-persidskaia/)  

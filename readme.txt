Dynamic Table -

Dynamic table shares the property of having its elements in contiguous memory locations with the
traditional array but, is different from it as the size of a dynamic table is not fixed. We can increase
as well as decrease the size of a dynamic table. When the table is full we use realloc and increase
the size of the table by some suitable factor (called the increase_factor) and when the no. of
elements in the table reaches a minimum threshold (called the decrease_at_factor) we again use
realloc to decrease the size of the table by a suitable factor (called the decrease_factor). Always the
decrease_factor = 1/increase_factor.




About repository -

This repository contains C implementation of Dynamic Table. The "functions.c" file includes code for
carrying out various functionalities of a dynamic table. These include -

	1) Inserting elements into the dynamic table.

	2) Deleting elements from the dynamic table.

	3) Displaying the contents of the dynamic table.

I have also added code to measure the time taken for carrying out these functionalities.
I have written the client code such that it uses various increase and decrease factors for comparisons.




Conclusions -

1) We find that there is no single increase_factor or decrease_at_factor which is best suited for all 
the scenarios.

2) The choice of increase_factor and decrease_at_factor is influenced by many things such as -

	* The sequence of operations
	* The no. of operations
	* The initial size of the table

3) The increase_factor should not be too high because in that case most of the table will remain
empty.

4) The decrease_at_factor should not be too high because allocating a new block of memory
locations and copying elements there is a costly operation. So, we should only reduce the table size
when it is essential.

Modify the inventory.c program of Section 16.3 by adding two new operations:
1) Save database in a specific file
2) Load the database from a specific file

Use the code d(dump) and r(restore), respectively. to represent thses operations,
The interaction with th user should have the following apparance.

Eneter operation code: d
Enter name of output file: inventory.dat

Enter operation code : r
Enter name of input file: inventory.dat

Hint: Use fwrite to write the array containing the parts to a binary file.
	  Use fread to restore the array by rading it from a file.

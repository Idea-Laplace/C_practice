/*
   size_t fread(void * restrict ptr,
				size_t size, size_t nmemb,
				FILE * restrict stream);
	size_t fwrite(const void *restrict ptr,
				size_t size, size_t nmemb,
				FILE * restrict steam);
	
	The fread and fwrite functions allow a program to read and
	write large blocks of data in a single step. fread and fwrite
	are used to primarily with binary streams, although with care, 
	it's possible to use them with text streams as well.

		fwirte is designed to copy an array 'from memory' 'to a stream'.
	The first argument in a call of fwrite is the array's address, the 
	second argument is the size of each array element(in byte), and the
	third argument is the number fo elements to write. The fourth argument
	is a file pointer, indicating where the data should be written. To 
	write the entire contents of the array a, for instance, we could use
	the following call of fwrite.

	fwrite(a, sizeof(*a), sizeof(a) / sizeof(*a), fp);

	There is no rule that we have to write the entire array; we could just
	as easily write any portion of it. fwrite returns the number of elements
	(not bytes) actually written. This number will bbe less than the third argument
	if a wirte error occurs.

	fread will rad the elements of an array from a stream. fread's arguments are
	similar to fwrite's; the array's address, the size of each element(in bytes),
	the number of elements to read, and a file pointer. To read the contents of afile
	int the array a, we might use the following call of fread:

	n = fread(a, sizeof(*a), sizeof(a) / sizeof(*a), fp);

	It's important to check fread's return value, which indicates the actual number of
	elements(not bytes) read. This number should 'equal' the third argument unless th
	end of the input file was reached or a read error occurred. The feof and ferror
	functions can be used to determine the reason for any shortage.

	*Be careful not to confuse second and third arguments.

	frwite is convenient for a program that needs to store data in a file before
	terminating. Later, the program (or another program, for that matter) can use
	fread to read the data back into memory. Despite appearances, the data doesn't
	need to be in array form: fread and fwrite work just as well with variables of
	all kinds. Structures, in particular, can be read by fread or wirtten by fwrite.
	To wirte a structure variable s to a file, for instance, we could use the following
	call of fwrite:

	fwrite(&s, sizeof(s), 1, fp);

	Be careful when using fwrite to write out structures that contain pointer values;
	these values aren't guaranteed to be valid when read back in.
	


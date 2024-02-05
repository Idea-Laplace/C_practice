/*
	int fgetpos(FILE * restrict stream,
				fpos_t * retrict pos);
	int fseek(FILE *stream, long int offset, int whence);
	int fsetpos(FILE *stream, const fpos_t *pos);
	long int ftell(RILE *stream);
	void rewind(FILE *stream);

	Every stream has an associated file position. When a file

	* What indicators that every stream has: error indicator, file position.
	
	is opened, the file position is set at the beginning fo the file.
	the file position is set at the beginning of the file.(if the file
	opened in append mode, however, the initial file position may be 
	at the beginning or end of the file, depending on the implementation).
	Then, when a read or write operation is performed, the file postion 
	advances automatically, allowing us to move through the file in a 
	sequential manner.

	Although sequential access is fine for many applications, some programs
	need the ability to jump around within a file, accesssing some data here
	and other data there, If a file contains a series of records, for example, 
	we might want to jump directly to a particular record and read it or update it.
	<stdio.h> supports this form of access by providing five functions that allow
	a program to determine the current file position for to change it.

	int fseek(RILE *stream, long offset, int whence);

	The fseek function changes the file position associated with th first
	arguement(a file pointer, say). The third argument specifies whether
	the new position is to be calculated with respect to the beginning of the file,
	the current position, or the end of the file. <stdio.h> defines 3 macros
	for this purpose:

	SEEK_SET Beginning of file.
	SEEK_CUR Current file position
	SEEK_END End of file

	The second argument is a (possibly negative) byte count. To move to the
	beginning of a file, for example, the seek direction would be SEEK_SET and
	the byte count would be zero:

	fseek(fp, 0L, SEEK_SET);

	To move to the end of a file, the seek direction would be SEEK_END:

	fseek(fp, 0L, SEEK_END);

	To move back 10bytes, the seek directio would be SEEK_CUR and the byte
	count would by -10:

	fseek(fp, -10L, SEEK_CUR);

	Note that the byte count has type long, so I've used 0L and -10L as arguments.
	(just 0 or -10 also would work because of implicit type casting);

	fseek returns 0, if an error occurs( the requested position doesn't exist, for example)
	fseek returns a nonzero value.

	The file positioning functions are best used with binary streams. by the way, C doesn't 
	prohibit programs from using them with text streams, but care is required because of 
	operating system differences. fseek in paricular is sensitiv to whether a stream is text or
	binary. For text streams, either
	1) offset must be zero or
	2) whence must by SEEK_SET and offset a value obtained by a previous call of ftell.

	in other words, we can only use fseek to move to the beginning or end of a text stream
	or to return to a place that was visited previously.

	THe ftell function returns the current file postion as a long integer(If an error occurs
	ftell returns -1L, and stores and error code in erron)
	The value returned by ftell may  be saved and later supplied to a call of fseek, 
	making it possible to return to a previous file position:

	long file_pos;
	...
	file_pos = ftell(fp);
	...
	fseek(fp, file_pos, SEEK_SET);
	If fp is a binary stream, the call ftell(fp) returns the current file position
	as a byte count, where zero represents the beginning of th fil. If fp is a text
	stream, however, ftell(fp) isn't necessarily a byte count. As a result, it's best
	not to perform arithmetic  on values returned by ftell. For example, it's not a good
	idea to subtract values by ftell to see how for apart two file positions are.





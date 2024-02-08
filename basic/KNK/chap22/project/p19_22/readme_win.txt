K.N.King C programming 2nd edition chapter22 project 19, p.588

(a) Write a program that converts a Windows text file to a UNIX text file.
	(see Section 22.1 for a discussion of the difference between Windows and
	 UNIX text files.)

(b) Write a program that converts a UNIX text file to a Windows text file.

In each case, have the program obtain the names of both files from the com-
-mand line.

Hint: Open the input file in "rb" mode and the output file in "wb" mode.

--------------------------------------------------------------------------------------
p.542

Text file are divided into lines.

Each line in a text file normally ends with one or two special characters;
the choice of characters depends on the operating system. In Windows, the
end-of-line marker is a carriage-return(\r, \x0d) followed immediately by
a line-feed character(\n, \x0a). In UNIX and newer versions of the Macin-
-tosh operating system(MacOS), the end-of-line marker is a single line-feed
charater. Older version of Mac OS use a single carriage return character.

Text files may contain a special end-of-file marker

Some operating systems allow a special byte to be used as a marker at the
end of a text file. In Windows, ther marker is '\x1a', which is ctrl + Z.
There's no requirement that ctrl-Z be present, but if it is, it marks the
end of the file; any bytes after ctrl-Z are to be ignored. The ctrl-Z con-
-vention is a holdover from DOS, which in turn inherited it from CP/M, an
early operating system for personal computers. Most other operating systems,
including UNIX, have no special end-of-file character.



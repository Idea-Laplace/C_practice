// Indicate which mode string is most likely to be passed to
// fopen(Maybe an abbreviation for file-open) in each of the
// following situations:

// (a) A database management system that opens a file containing
// records to be updated.
// Ans) "rb+"   binary, both reading and writing.

// (b) A mail program opoens a file of saved message so that it
// can add additional messages to the end.
// Ans) "a"  text, append.

// (c) A graphics program opens a file containing a picture to be 
// displayed on the screen.
// Ans) "rb"    binary, read only.

// (d) An operating system command interpreter opens a "shell script"
// (or "batch file") containing commands to be excuted.
// Ans) "r"   text, read only

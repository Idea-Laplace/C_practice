/* Write calls of fseeek that perform the following file-positioning
   operations on a binary file whose data is  arranged in 64-byte
   'records'.  Use fp as the file pointer in each case */

// (a) Move to the beginning  of record n.(Assume that the first record int the file is record 0.);
// fseek(fp, n * 64L, SEEK_SET);

// (b) Move to the beginning of the last record in the file.

// fseek(fp, -64L, SEEK_END); // EOF is also counted.

// (c) Move forward one record.

// fseek(fp, 64L, SEEK_CUR);

// (d) Movw backward two record.
// fseek(fp, -2 * 64L, SEEK_CUR);


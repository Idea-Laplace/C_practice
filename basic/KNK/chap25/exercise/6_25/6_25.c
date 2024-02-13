/* Modify the following program fragment by replacing as mant characters
   as possible by trigraph.

while ((orig_char = getchar()) != EOF) {
	new_char = orig_char ^ KEY;
	if (isprint(orig_char) && isprint(new_char))
		putchar(new_char);
	else
		putchar(orig_char);
}
while ((orig_char = getchar()) != EOF) ??<
	new_char = orig_char ??' KEY;
	if (isprint(orig_char) && isprint(new_char))
		putchar(new_char);
	else
		putchar(orig_char);
??>
*/

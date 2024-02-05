int main(void) {
	char ch = 77;
	short sh = 34;;

	sizeof(ch);
	sizeof(sh);
	sizeof(ch + sh);

	return 0;
}

/*
main:
	endbr64
	pushq	%rbp			
	movq	%rsp, %rbp      
	movb	$77, -3(%rbp)
	movw	$34, -2(%rbp)
	movl	$0, %eax
	popq	%rbp
	ret
*/

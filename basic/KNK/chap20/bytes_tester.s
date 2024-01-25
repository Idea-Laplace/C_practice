	.file	"main.c"
	.text
	.section	.rodata
	.align 8
.LC0:
	.string	"Error in malloc(): could not allocate memory."
	.align 8
.LC1:
	.string	"Type a process you want(i/f/d/p/q): "
.LC2:
	.string	"Enter an integer: "
.LC3:
	.string	"%d"
.LC4:
	.string	"Enter a real number(float): "
.LC5:
	.string	"%f"
.LC6:
	.string	"Enter a real number(double): "
.LC7:
	.string	"%lf"
	.align 8
.LC8:
	.string	"Bytes representation for selection.p:"
.LC9:
	.string	"Process terminated."
.LC10:
	.string	"Invalid input, ignored."
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$1, %edi
	call	malloc@PLT
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	testq	%rax, %rax
	jne	.L2
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$1, %edi
	call	exit@PLT
.L2:
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	call	getchar@PLT
	movl	%eax, -20(%rbp)
.L3:
	call	getchar@PLT
	cmpl	$10, %eax
	jne	.L3
	movl	-20(%rbp), %eax
	subl	$100, %eax
	cmpl	$13, %eax
	ja	.L4
	movl	%eax, %eax
	leaq	0(,%rax,4), %rdx
	leaq	.L6(%rip), %rax
	movl	(%rdx,%rax), %eax
	cltq
	leaq	.L6(%rip), %rdx
	addq	%rdx, %rax
	notrack jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L6:
	.long	.L10-.L6
	.long	.L4-.L6
	.long	.L9-.L6
	.long	.L4-.L6
	.long	.L4-.L6
	.long	.L8-.L6
	.long	.L4-.L6
	.long	.L4-.L6
	.long	.L4-.L6
	.long	.L4-.L6
	.long	.L4-.L6
	.long	.L4-.L6
	.long	.L7-.L6
	.long	.L5-.L6
	.text
.L8:
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-16(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
.L11:
	call	getchar@PLT
	cmpl	$10, %eax
	jne	.L11
	movl	-16(%rbp), %eax
	movl	%eax, %edi
	call	show_int@PLT
	jmp	.L12
.L9:
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-16(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC5(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
.L13:
	call	getchar@PLT
	cmpl	$10, %eax
	jne	.L13
	movl	-16(%rbp), %eax
	movd	%eax, %xmm0
	call	show_float@PLT
	jmp	.L12
.L10:
	leaq	.LC6(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-16(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC7(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
.L14:
	call	getchar@PLT
	cmpl	$10, %eax
	jne	.L14
	movq	-16(%rbp), %rax
	movq	%rax, %xmm0
	call	show_double@PLT
	jmp	.L12
.L7:
	leaq	.LC8(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	show_pointer@PLT
	jmp	.L12
.L5:
	leaq	.LC9(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L16
	jmp	.L17
.L4:
	leaq	.LC10(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	nop
.L12:
	jmp	.L2
.L17:
	call	__stack_chk_fail@PLT
.L16:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:

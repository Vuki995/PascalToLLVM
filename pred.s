	.text
	.file	"pred.ll"
	.globl	test                    # -- Begin function test
	.p2align	4, 0x90
	.type	test,@function
test:                                   # @test
	.cfi_startproc
# %bb.0:                                # %entry
	subq	$104, %rsp
	.cfi_def_cfa_offset 112
	movl	%edi, -124(%rsp)
	movl	%esi, -120(%rsp)
	movl	$4, hari+56(%rip)
	movb	$99, grad(%rip)
	movb	$1, te(%rip)
	movl	$4, -116(%rsp)
	movl	$4, %eax
	addq	$104, %rsp
	retq
.Lfunc_end0:
	.size	test, .Lfunc_end0-test
	.cfi_endproc
                                        # -- End function
	.globl	zbir                    # -- Begin function zbir
	.p2align	4, 0x90
	.type	zbir,@function
zbir:                                   # @zbir
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	%edi, (%rsp)
	testl	%edi, %edi
	je	.LBB1_1
# %bb.2:                                # %ifcont
	movl	(%rsp), %edi
	decl	%edi
	callq	zbir
	addl	(%rsp), %eax
	movl	%eax, 4(%rsp)
	popq	%rcx
	retq
.LBB1_1:                                # %then
	movl	$0, 4(%rsp)
	xorl	%eax, %eax
	popq	%rcx
	retq
.Lfunc_end1:
	.size	zbir, .Lfunc_end1-zbir
	.cfi_endproc
                                        # -- End function
	.globl	test1                   # -- Begin function test1
	.p2align	4, 0x90
	.type	test1,@function
test1:                                  # @test1
	.cfi_startproc
# %bb.0:                                # %entry
	subq	$96, %rsp
	.cfi_def_cfa_offset 104
	movl	hari+56(%rip), %eax
	movl	%eax, -124(%rsp)
	addq	$96, %rsp
	retq
.Lfunc_end2:
	.size	test1, .Lfunc_end2-test1
	.cfi_endproc
                                        # -- End function
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1083388723, fl(%rip)   # imm = 0x40933333
	movl	$4, hari+56(%rip)
	movl	$40, hari+68(%rip)
	movl	$4, ulica(%rip)
	movq	$ulica, provera2(%rip)
	movl	$.Lstr, %edi
	movl	$ulica, %esi
	xorl	%eax, %eax
	callq	printf
	movl	$.Lstr.1, %edi
	xorl	%eax, %eax
	callq	printf
	movl	$0, ili(%rip)
	movl	$.Lstr.2, %edi
	movl	$grad, %esi
	xorl	%eax, %eax
	callq	scanf
	movzbl	grad(%rip), %edi
	callq	putchar
	movl	hari+56(%rip), %edi
	movl	hari+68(%rip), %esi
	callq	test
	movl	%eax, ulica(%rip)
	jmp	.LBB3_1
	.p2align	4, 0x90
.LBB3_3:                                # %ifcont
                                        #   in Loop: Header=BB3_1 Depth=1
	movl	$8, %edi
	callq	zbir
	movl	%eax, %ecx
	movl	$.Lstr, %edi
	xorl	%eax, %eax
	movl	%ecx, %esi
	callq	printf
	movl	$.Lstr.1, %edi
	xorl	%eax, %eax
	callq	printf
	movl	$.Lstr.3, %edi
	xorl	%eax, %eax
	callq	printf
	movl	$.Lstr.1, %edi
	xorl	%eax, %eax
	callq	printf
	decl	ulica(%rip)
.LBB3_1:                                # %beforeloop
                                        # =>This Inner Loop Header: Depth=1
	movl	ulica(%rip), %eax
	cmpl	ili(%rip), %eax
	jle	.LBB3_4
# %bb.2:                                # %loop
                                        #   in Loop: Header=BB3_1 Depth=1
	movl	ulica(%rip), %esi
	movl	$.Lstr, %edi
	xorl	%eax, %eax
	callq	printf
	movl	$.Lstr.1, %edi
	xorl	%eax, %eax
	callq	printf
	cmpl	$1, ulica(%rip)
	jne	.LBB3_3
.LBB3_4:                                # %afterloop
	callq	test1
	xorl	%eax, %eax
	popq	%rcx
	retq
.Lfunc_end3:
	.size	main, .Lfunc_end3-main
	.cfi_endproc
                                        # -- End function
	.type	ber,@object             # @ber
	.comm	ber,8,8
	.type	hari,@object            # @hari
	.comm	hari,216,16
	.type	fl,@object              # @fl
	.comm	fl,4,4
	.type	provera,@object         # @provera
	.comm	provera,8,8
	.type	provera2,@object        # @provera2
	.comm	provera2,8,8
	.type	ulica,@object           # @ulica
	.comm	ulica,4,4
	.type	kuca,@object            # @kuca
	.comm	kuca,56,16
	.type	kucica,@object          # @kucica
	.comm	kucica,4,4
	.type	grad,@object            # @grad
	.comm	grad,1,1
	.type	te,@object              # @te
	.comm	te,1,1
	.type	ili,@object             # @ili
	.comm	ili,4,4
	.type	.Lstr,@object           # @str
	.section	.rodata.str1.1,"aMS",@progbits,1
.Lstr:
	.asciz	"%d"
	.size	.Lstr, 3

	.type	.Lstr.1,@object         # @str.1
.Lstr.1:
	.asciz	"\n"
	.size	.Lstr.1, 2

	.type	.Lstr.2,@object         # @str.2
.Lstr.2:
	.asciz	"%c"
	.size	.Lstr.2, 3

	.type	.Lstr.3,@object         # @str.3
.Lstr.3:
	.asciz	"\\n"
	.size	.Lstr.3, 3


	.section	".note.GNU-stack","",@progbits

	.file	"UnitTests.cpp"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"src/UnitTests.cpp"
.LC1:
	.string	"fourZeros.data[i] == 0"
	.text
	.p2align 4,,15
	.globl	_Z20testEmptyConstructorv
	.type	_Z20testEmptyConstructorv, @function
_Z20testEmptyConstructorv:
.LFB1577:
	.cfi_startproc
	subq	$24, %rsp
	.cfi_def_cfa_offset 32
	movq	%fs:40, %rax
	movq	%rax, 8(%rsp)
	xorl	%eax, %eax
	movq	8(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L8
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L8:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE1577:
	.size	_Z20testEmptyConstructorv, .-_Z20testEmptyConstructorv
	.p2align 4,,15
	.globl	_Z23testInitListConstructorv
	.type	_Z23testInitListConstructorv, @function
_Z23testInitListConstructorv:
.LFB1578:
	.cfi_startproc
	rep ret
	.cfi_endproc
.LFE1578:
	.size	_Z23testInitListConstructorv, .-_Z23testInitListConstructorv
	.p2align 4,,15
	.globl	_Z28testSingleElementConstructorv
	.type	_Z28testSingleElementConstructorv, @function
_Z28testSingleElementConstructorv:
.LFB1579:
	.cfi_startproc
	rep ret
	.cfi_endproc
.LFE1579:
	.size	_Z28testSingleElementConstructorv, .-_Z28testSingleElementConstructorv
	.section	.rodata.str1.1
.LC2:
	.string	"Testing constructors...\n"
.LC4:
	.string	"{ "
.LC5:
	.string	"} "
.LC8:
	.string	"All Tests Pass!\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB1580:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	leaq	.LC2(%rip), %rsi
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	leaq	_ZSt4cout(%rip), %rdi
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	leaq	_ZSt3cin(%rip), %r15
	subq	$72, %rsp
	.cfi_def_cfa_offset 128
	movq	%r15, %r14
	movq	%fs:40, %rax
	movq	%rax, 56(%rsp)
	xorl	%eax, %eax
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	call	_Z20testEmptyConstructorv
	vxorps	%xmm0, %xmm0, %xmm0
	leaq	32(%rsp), %rax
	movl	$0x00000000, 48(%rsp)
	movl	$0x00000000, 52(%rsp)
	movq	%rax, 8(%rsp)
	movq	%rax, %rbp
	vmovaps	%xmm0, 32(%rsp)
	.p2align 4,,10
	.p2align 3
.L16:
	leaq	24(%rbp), %r12
	movq	%rbp, %rbx
.L13:
	movq	%rbp, %rsi
	movq	%r14, %rdi
	call	_ZNSi10_M_extractIfEERSiRT_@PLT
	movq	(%rax), %rdx
	movq	-24(%rdx), %rdx
	testb	$5, 32(%rax,%rdx)
	jne	.L12
	addq	$4, %rbp
	cmpq	%r12, %rbp
	jne	.L13
.L12:
	movq	(%r15), %rax
	movq	-24(%rax), %rax
	testb	$5, 32(%r15,%rax)
	jne	.L14
	leaq	.LC4(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	leaq	31(%rsp), %r13
	leaq	_ZSt4cout(%rip), %rbp
	movl	$2, %edx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	.p2align 4,,10
	.p2align 3
.L15:
	vxorpd	%xmm0, %xmm0, %xmm0
	movq	%rbp, %rdi
	addq	$4, %rbx
	vcvtss2sd	-4(%rbx), %xmm0, %xmm0
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movl	$1, %edx
	movq	%r13, %rsi
	movq	%rbp, %rdi
	movb	$32, 31(%rsp)
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	cmpq	%rbx, %r12
	jne	.L15
	leaq	.LC5(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	movl	$2, %edx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	vxorps	%xmm1, %xmm1, %xmm1
	leaq	_ZSt4cout(%rip), %rdi
	vmovss	.LC7(%rip), %xmm2
	vmovss	.LC6(%rip), %xmm0
	vfmadd132ss	32(%rsp), %xmm1, %xmm0
	vfmadd231ss	36(%rsp), %xmm2, %xmm0
	vaddss	40(%rsp), %xmm0, %xmm0
	vmovss	.LC6(%rip), %xmm3
	vfmadd231ss	44(%rsp), %xmm3, %xmm0
	vfmadd231ss	48(%rsp), %xmm2, %xmm0
	vaddss	52(%rsp), %xmm0, %xmm0
	vcvtss2sd	%xmm0, %xmm0, %xmm0
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	leaq	30(%rsp), %rsi
	movl	$1, %edx
	movq	%rax, %rdi
	movb	$10, 30(%rsp)
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	8(%rsp), %rbp
	jmp	.L16
	.p2align 4,,10
	.p2align 3
.L14:
	leaq	.LC8(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	xorl	%eax, %eax
	movq	56(%rsp), %rcx
	xorq	%fs:40, %rcx
	jne	.L22
	addq	$72, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
.L22:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE1580:
	.size	main, .-main
	.p2align 4,,15
	.type	_GLOBAL__sub_I__Z20testEmptyConstructorv, @function
_GLOBAL__sub_I__Z20testEmptyConstructorv:
.LFB2104:
	.cfi_startproc
	leaq	_ZStL8__ioinit(%rip), %rdi
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	call	_ZNSt8ios_base4InitC1Ev@PLT
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rdi
	leaq	__dso_handle(%rip), %rdx
	leaq	_ZStL8__ioinit(%rip), %rsi
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	jmp	__cxa_atexit@PLT
	.cfi_endproc
.LFE2104:
	.size	_GLOBAL__sub_I__Z20testEmptyConstructorv, .-_GLOBAL__sub_I__Z20testEmptyConstructorv
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__Z20testEmptyConstructorv
	.section	.rodata
	.align 16
	.type	_ZZ20testEmptyConstructorvE19__PRETTY_FUNCTION__, @object
	.size	_ZZ20testEmptyConstructorvE19__PRETTY_FUNCTION__, 28
_ZZ20testEmptyConstructorvE19__PRETTY_FUNCTION__:
	.string	"void testEmptyConstructor()"
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.rodata.cst4,"aM",@progbits,4
	.align 4
.LC6:
	.long	1073741824
	.align 4
.LC7:
	.long	1077936128
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits

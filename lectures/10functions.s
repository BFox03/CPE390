	.file	"10functions.cc"
	.text
	.globl	_Z2f1yy
	.def	_Z2f1yy;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z2f1yy
_Z2f1yy:
.LFB4:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	16(%rbp), %rdx
	movq	24(%rbp), %rax
	addq	%rdx, %rax
	popq	%rbp
	ret
	.seh_endproc
	.globl	_Z2f2yy
	.def	_Z2f2yy;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z2f2yy
_Z2f2yy:
.LFB5:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	16(%rbp), %rax
	subq	24(%rbp), %rax
	popq	%rbp
	ret
	.seh_endproc
	.globl	_Z2f3yy
	.def	_Z2f3yy;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z2f3yy
_Z2f3yy:
.LFB6:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	16(%rbp), %rax
	imulq	24(%rbp), %rax
	popq	%rbp
	ret
	.seh_endproc
	.globl	_Z2f4yy
	.def	_Z2f4yy;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z2f4yy
_Z2f4yy:
.LFB7:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	16(%rbp), %rax
	movl	$0, %edx
	divq	24(%rbp)
	popq	%rbp
	ret
	.seh_endproc
	.globl	_Z2f5yy
	.def	_Z2f5yy;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z2f5yy
_Z2f5yy:
.LFB8:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	16(%rbp), %rax
	movl	$0, %edx
	divq	24(%rbp)
	movq	%rdx, %rax
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (Rev6, Built by MSYS2 project) 12.2.0"

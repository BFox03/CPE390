	.globl main
main:
	
	mov 0xDEADBEEF12345678, %rax
	mov 0xABBAF0BB0BBE98D1, %rax

	mov %rbx, %rcx
    and %rcx, %rax 

	mov %rbx, %rdx
    or %rdx, %rax

	mov %rbx, %rdx 
    xor %rsi, %rax




	ret

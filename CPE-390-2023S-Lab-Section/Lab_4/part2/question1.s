# Author: Brandon Fox
# Partner: Justin Ferber
	
	.globl main
main:
	mov	$0x12345678FEDCBA9, %rcx # F - 1111, D - 1101, 9 - 1001
	mov	$0x00000000F0F000F, %rdx # F - 1111, D - 1101, 9 - 1001
	call	f
	ret

	.globl f
f:
	mov %rcx, %rax
	not %rdx
	and %rdx, %rax

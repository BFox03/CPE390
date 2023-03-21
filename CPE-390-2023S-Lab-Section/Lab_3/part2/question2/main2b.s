	.globl main
main:
	mov $5, %rax
	mov $7, %rbx
	mov $9, %rcx

	# add
	leaq (%rax, %rbx), %rdx
	mov %rdx, %rdx

	# multiply
	mul %rcx        # This stores the anwer in rax and remainder in rdx so we must reset those
	mov $12, %rdx
	mov %rax, %rsi
	mov $5, %rax

	# subtract
	mov %rbx, %rdi
	sub %rax, %rdi

	# divide a = s / d
	mov $0, %rdx
	mov %rsi, %rax
	mov %rdi, %rcx
	div %rcx
	
	



	ret

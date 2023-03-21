.globl main

main:
    mov $3, %rax
    mov $4, %rbx
    leaq (%rax, %rbx), %rcx
    # leaq 14(%rax, %rbx, 8), %rcx # means 8 times inside plus outside, but can only mult by some const 8,4,2

# 2-operand architecture
    mov %rax, %rdx
    sub %rbx, %rdx # rdx = rax - rbx

# if you are willing to wipe out rax
    sub %rbx, %rax # rax = rax - rbx

    mov $0, %rax 
    # xor %rbx, %rbx # rbx = 0
    ret

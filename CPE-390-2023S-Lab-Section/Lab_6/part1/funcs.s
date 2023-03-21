# write your asm code here
	.globl _Z5counti
_Z5counti:                      # Question 1
    mov $1, %rdx                # rax = 20
                                # ended with rdx = 22
count:
    add $3, %rdx
    cmp %rcx, %rdx
    jl count
    ret


    .globl _Z5sumsqPKyj
_Z5sumsqPKyj:                   # Question 2
    xor %rax, %rax              # rcx = 9 1 2 4
    push %r10                   # rax = 102
    push %r11
    xor %r11, %r11

sumsq:
    mov (%rcx), %r10
    imul %r10, %r10
    add %r10, %rax
    add $8, %rcx
    add $1, %r11
    cmp %r11, %rdx
    jg sumsq

    pop %r11
    pop %r10
    ret


    .globl _Z4add1Pyj
_Z4add1Pyj:                     # Question 3
    push %r10                   #     rcx = 5 3 6 7 4 9
    push %r11                   # new rcx = 6 4 7 8 5 10
    xor %r10, %r10

add1:
    mov (%rcx), %r11
    add $1, %r11
    mov %r11, (%rcx)
    add $1, %r10
    add $8, %rcx
    cmp %r10, %rdx
    jg add1

    pop %r11
    pop %r10
    ret


    .globl _Z11replaceZeroy
_Z11replaceZeroy:               # Question 4
    mov $0x00000e70, %rax       # rcx =   1111 0010 1110 1011 1010 1011 1110    
    or %rcx, %rax               #     =   0000 0000 0000 0000 xxx0 0xxx 0000 
    ret                         # rax =   1111 0010 1110 1011 1110 1111 1110


    .globl _Z10replaceOney
_Z10replaceOney:                # Question 5
    mov $0xfffff00f, %rax       # rcx =   1111 0010 1110 1011 1010 1011 1110    
    and %rcx, %rax              #     =   0000 0000 0000 0000 xxx0 0xxx 0000 
    ret                         # rax =   1111 0010 1110 1011 0000 1000 1110


    .globl _Z7togglesy
_Z7togglesy:                    # Question 6
    mov $0x00000b30, %rax       # rcx =   1111 0010 1110 1011 1010 1011 1110    
    xor %rcx, %rax              #     =   0000 0000 0000 0000 xxx0 0xxx 0000 
    ret                         # rax =   1111 0010 1110 1011 0100 1100 1110
    

    .globl _Z8replaceDy
_Z8replaceDy:                   # Question 7
    push %r10                   # rcx = 0x987654321C9
    mov %rcx, %r10              # rax = 0x987654321D9
    mov %rcx, %rax
    mov $0xF0, %rdx
    and %rdx, %rax
    cmp $0xD0, %rdx
    jz replaceD
    add $0x10, %rcx
    jmp done
replaceD:
    add $1, %rcx
done:
    mov %rcx, %rax
    pop %r10
    ret

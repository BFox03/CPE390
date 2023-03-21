.globl main

main:
    mov $52, %rax # 32+16+4 = 00110100    0x34
    mov $37, %rbx # 32+4+1 =  00100101    0x25
#                            ========
    mov %rbx, %rcx
    and %rax, %rbx #          00100100    0x24    C++: x&y

    mov %rbx, %rdx
    or %rax, %rdx #           00110101    0x35    C++: x|y

    mov %rbx, %rdx 
    xor %rax, %rsi #          00010001    0x11    C++: x^y

    # ?not?                     11101110            C++: ~x          

    #0x2B | ~0x2B == 0xFF
    #00101011
    #11010100
    #========
    #11111111

    mov $0xDEADBEEF, %rdx
    and $0xFACEFEED, %rdx   # rdx = ________

    ret

    xor %rax, %rax # rax = 0
    # suppose register rbx = 1010101010101010101xxx
    # make all x bits 0
    mov $0xFFFFFFFFFFFFFFFF, %rdi
    and %rdi, $rbx # rbx does not change
    mov $0xFFFFFFFFFFFFFFF8, %rdi # last 3 digits are 000
    and %rdix, $rbx # rbx now has the last three digits as 0

    # suppose register rbx = 10 1010 10xx 100x x010 1xxx 
                                     1100 1110 0111 1000
    # make all the x bits 0
    mov $0xFFFFFFFFFFFFCE78, %rdi
    and %rdi, %rbx 

    # make all the x bits 1
    mov $0xFFFFFFFFFFFF3187, %rdi
    or %rdi, %rbx 

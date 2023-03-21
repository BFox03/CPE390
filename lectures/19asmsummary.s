    .globl main

main:
    #
    # arithmetic
    #
    add %rax, %rbx              # rbx = rbx + rax
    sub %rax, %rbx              # rbx = rbx - rax
    imul %rax, %rbx             # rbx = rbx * rax
    div %rcx                    # rdx:rax / rcx   rdx=remainder rax=divided (set rdx to zero before calculating)
    lea (%rax, %rbx), %rcx      # rcx = rax +rbx
    lea 16(%rax, %rbx, 8), %rcx # rcx = 16+rax + rbx*8

    # Boolean Operations
    and %rbx, %rsi              # rsi = rsi AND rbx
    or %rbx, %rsi               # rsi = rsi OR rbx (inclusive OR = rbx | rsi)
    not %rbx                    # rbx = NOT rbx
    xor %rax, %rax              # rax = rax XOR rax (zero) = rax ^ rax

    # Bit Shifting
    shl $5, %rsi                # << left shift by 5 (=*32)  [int x = 4; x <<= 3; 
    shr $3, %rdi                # >> right shift 3 (divide by 8)
    shl %rax, %rsi              # rsi <<= rax
    
    # signed bit shift
    sal $1, %rsi                # signed shift left
    sar $2, %rdi                # rdi = rdi >> 2 (signed)
    # signed shift prevserves the sign bit

    # rotate
    rol $4, %rax                # rotate left by 4 bits 
    ror $3, %rbx                # rotate rbx right by 3 bits
    
    mov $17, %ax               # 0000000000010001
    ror $4, %ax                # 0001000000000001
    mov $17, %ax               # 0000000000010001
    shr $4, %ax                # 0000000000000001

    # branching
    mov $100, %rcx
loop:
    # do this 100 times
    sub $1, %rcx
    jnz loop

    cmp $100, %rax              # compute rax - 100
    # jz                        # rax = 100
    # jnz                       # rax != 100
    # jl                        # rax < 100
    # jge                       # rax >= 100

    cmp $3, %rcx
    jge else

    j endif
else:
    # .else code
    # .if u dont have jump to end it will run this

endif:
    tst %rbx, %rax              # compute rax AND rbx

    tst $1, %rax                # rax AND 1 last bit (tell if even or odd)
    jz                          # rax AND 1 == 0
    jnz                         # rax AND 1 != 0 


    # .push n pop
    push %rsi                   # rsp = rsp - 8, mov %rsi, (%rsp)
    mov $9, %rsi                # rsi = 9
    pop %rsi                    # move (%rsp), %rsi  rsp = rsp + 8

    
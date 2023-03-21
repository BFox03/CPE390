    .globl main
main:
    mov    $6, %rcx
    mov    $7, %rdx
    call	f
    #rax should have the answer
    ret   


    .globl f
f:
   leaq (%rcx, %rdx), %rax
   shr %rax


   ret # %rax


global ft_strcmp

section .text

ft_strcmp:
    xor ecx, ecx

.loop:
    movzx eax, byte [rdi + rcx]
    movzx edx, byte [rsi + rcx]
    cmp eax, edx
    jne .end
    test eax, eax
    je .end
    inc rcx
    jmp .loop

.end:
    sub eax, edx
    ret

section .note.GNU-stack noalloc noexec nowrite progbits

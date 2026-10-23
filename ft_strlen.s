global ft_strlen

section .text

ft_strlen:
    xor eax, eax

.loop:
    cmp byte [rdi + rax], 0
    je .end
    inc rax
    jmp .loop

.end:
    ret

section .note.GNU-stack noalloc noexec nowrite progbits

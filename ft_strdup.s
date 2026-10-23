global ft_strdup
extern malloc
extern ft_strlen
extern ft_strcpy

section .text

ft_strdup:
    push rbx
    mov rbx, rdi

    call ft_strlen
    lea rdi, [rax + 1]

    call malloc wrt ..plt
    test rax, rax
    jz .end

    mov rdi, rax
    mov rsi, rbx
    call ft_strcpy

.end:
    pop rbx
    ret

section .note.GNU-stack noalloc noexec nowrite progbits

global ft_strcpy

section .text

ft_strcpy:
    mov rax, rdi

.loop:
    mov dl, [rsi]
    mov [rdi], dl
    inc rsi
    inc rdi
    test dl, dl
    jne .loop

    ret

section .note.GNU-stack noalloc noexec nowrite progbits

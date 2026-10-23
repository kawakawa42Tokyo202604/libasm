global ft_read
extern __errno_location

section .text

ft_read:
    xor eax, eax
    syscall

    test rax, rax
    jns .end

    neg eax
    push rax
    call __errno_location wrt ..plt
    pop rdx
    mov [rax], edx
    mov rax, -1

.end:
    ret

section .note.GNU-stack noalloc noexec nowrite progbits

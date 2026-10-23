global ft_calloc
extern malloc
extern __errno_location

section .text

ft_calloc:
    mov rax, rdi
    mul rsi
    jo .overflow

    push rax
    mov rdi, rax
    call malloc wrt ..plt
    pop rcx

    test rax, rax
    jz .end

    mov rdx, rax
    mov rdi, rax
    xor eax, eax
    rep stosb
    mov rax, rdx

.end:
    ret

.overflow:
    sub rsp, 8
    call __errno_location wrt ..plt
    mov dword [rax], 12
    add rsp, 8

    xor eax, eax
    ret

section .note.GNU-stack noalloc noexec nowrite progbits

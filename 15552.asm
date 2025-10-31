BITS 64
default rel

section .bss
inbuf:  resb 16777216
outbuf: resb 8388608

section .text
global main

main:
    push rbx
    push r12
    push r13
    push r14
    push r15
    sub rsp, 8
    
    lea rsi, [rel inbuf]
    lea r9, [rel inbuf + 16777216]
.read_loop:
    mov rdx, r9
    sub rdx, rsi
    xor eax, eax
    xor edi, edi
    syscall
    test rax, rax
    jle .read_done
    add rsi, rax
    cmp rsi, r9
    jb .read_loop
.read_done:
    mov r14, rsi
    lea r13, [rel inbuf]
    lea r12, [rel outbuf]
    
    call parse_int
    mov r15d, eax
    
.case_loop:
    test r15d, r15d
    jz .flush_and_return
    dec r15d
    
    call parse_int
    mov ebx, eax
    call parse_int
    add eax, ebx
    
    call print_int
    mov byte [r12], 10
    inc r12
    jmp .case_loop
    
.flush_and_return:
    mov eax, 1
    mov edi, 1
    lea rsi, [rel outbuf]
    mov rdx, r12
    sub rdx, rsi
    syscall
    
    add rsp, 8
    xor eax, eax
    pop r15
    pop r14
    pop r13
    pop r12
    pop rbx
    ret

parse_int:
    xor eax, eax
.skip:
    cmp r13, r14
    jae .done
    movzx edx, byte [r13]
    inc r13
    cmp dl, '0'
    jb .skip
    cmp dl, '9'
    ja .skip
    sub dl, '0'
    mov eax, edx
.digit:
    cmp r13, r14
    jae .done
    movzx edx, byte [r13]
    cmp dl, '0'
    jb .done
    cmp dl, '9'
    ja .done
    inc r13
    sub dl, '0'
    imul eax, 10
    add eax, edx
    jmp .digit
.done:
    ret

print_int:
    test eax, eax
    jnz .convert
    mov byte [r12], '0'
    inc r12
    ret
.convert:
    sub rsp, 16
    lea r8, [rsp + 16]
    mov ecx, 10
.conv_loop:
    xor edx, edx
    div ecx
    add dl, '0'
    dec r8
    mov [r8], dl
    test eax, eax
    jnz .conv_loop

    lea r9, [rsp + 16]
.copy_loop:
    cmp r8, r9
    jae .copy_done
    mov al, [r8]
    mov [r12], al
    inc r8
    inc r12
    jmp .copy_loop

.copy_done:
    add rsp, 16
    ret
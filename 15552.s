# ============================================================================
# Origin: translated 1:1 from Intel/NASM `15552.asm`.
# Syntax/Format: AT&T (GAS), Mach-O x86-64; entry = main (via CRT), BSS via .zerofill.
# Validation: matched against Intel version via `llvm-objdump` (Intel syntax) diff.
# Note: uses Linux x86-64 syscall numbers; macOS execution is not meaningful.
# Reg map: r13=rp, r14=rend, r12=wp, r15d=T, rbx=temp.
# ============================================================================
    .zerofill __DATA,__bss,inbuf,16777216,4   # 16 MiB BSS
    .zerofill __DATA,__bss,outbuf,8388608,4   # 8  MiB BSS
    .text
    .globl main
main:
    pushq %rbx
    pushq %r12
    pushq %r13
    pushq %r14
    pushq %r15
    subq  $8, %rsp

    leaq  inbuf(%rip), %rsi
    leaq  inbuf+16777216(%rip), %r9
.read_loop:
    movq  %r9, %rdx
    subq  %rsi, %rdx
    xorl  %eax, %eax          # SYS_read = 0
    xorl  %edi, %edi          # fd = 0
    syscall
    testq %rax, %rax
    jle   .read_done
    addq  %rax, %rsi
    cmpq  %r9, %rsi
    jb    .read_loop

.read_done:
    movq  %rsi, %r14
    leaq  inbuf(%rip), %r13
    leaq  outbuf(%rip), %r12

    call  parse_int
    movl  %eax, %r15d

.case_loop:
    testl %r15d, %r15d
    jz    .flush_and_return
    decl  %r15d

    call  parse_int
    movl  %eax, %ebx
    call  parse_int
    addl  %ebx, %eax

    call  print_int
    movb  $10, (%r12)
    incq  %r12
    jmp   .case_loop

.flush_and_return:
    movl  $1, %eax            # SYS_write
    movl  $1, %edi            # fd = 1
    leaq  outbuf(%rip), %rsi
    movq  %r12, %rdx
    subq  %rsi, %rdx
    syscall

    addq  $8, %rsp
    xorl  %eax, %eax
    popq  %r15
    popq  %r14
    popq  %r13
    popq  %r12
    popq  %rbx
    ret

# int parse_int(void)
parse_int:
    xorl  %eax, %eax
.skip:
    cmpq  %r14, %r13          # if r13 >= r14 → done
    jae   .done
    movzbl (%r13), %edx
    incq  %r13
    cmpb  $'0', %dl
    jb    .skip
    cmpb  $'9', %dl
    ja    .skip
    subb  $'0', %dl
    movl  %edx, %eax
.digit:
    cmpq  %r14, %r13
    jae   .done
    movzbl (%r13), %edx
    cmpb  $'0', %dl
    jb    .done
    cmpb  $'9', %dl
    ja    .done
    incq  %r13
    subb  $'0', %dl
    imull $10, %eax, %eax
    addl  %edx, %eax
    jmp   .digit
.done:
    ret

# void print_int(int eax)
print_int:
    testl %eax, %eax
    jnz   .convert
    movb  $'0', (%r12)
    incq  %r12
    ret
.convert:
    subq  $16, %rsp
    leaq  16(%rsp), %r8
    movl  $10, %ecx
.conv_loop:
    xorl  %edx, %edx
    divl  %ecx                # edx:eax / ecx
    addb  $'0', %dl
    decq  %r8
    movb  %dl, (%r8)
    testl %eax, %eax
    jnz   .conv_loop

    leaq  16(%rsp), %r9
.copy_loop:
    cmpq  %r9, %r8            # if r8 >= r9 → done
    jae   .copy_done
    movb  (%r8), %al
    movb  %al, (%r12)
    incq  %r8
    incq  %r12
    jmp   .copy_loop
.copy_done:
    addq  $16, %rsp
    ret
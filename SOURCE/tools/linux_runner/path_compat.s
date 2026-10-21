.text
.global _start
_start:
 cmpl $0x002e3a5a,(%rdi)
 jne original
 lea dot(%rip),%rdi
original:
 push %rbp
 mov %rsp,%rbp
 sub $0xd0,%rsp
 jmp 0x7047b35b
dot:
 .asciz "."

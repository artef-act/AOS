.section .text.entry
.global _start
.extern console_init


_start:
    la sp, stack_top     
    call console_init
    call main            
1:
    j 1b                 

.section .bss
.align 12
stack:
    .space 4096
stack_top:

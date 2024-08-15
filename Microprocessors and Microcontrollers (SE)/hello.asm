; Craig Da Gama 22co10
; ALP to display "Hello World!" on output device

section .data			; data segment
 msg db"Hello World!"		; "Hello World!" string
 len equ $-msg			; length of "Hello World!" string

section .text			; code segment
 global _start			; must be declared for linker
 _start:			; tell linker entry point
 mov edx, len			; message length
 mov ecx, msg			; message to write
 mov ebx, 1			; file descriptor(stdout)
 mov eax, 4			; system call number(system_write)
 int 80h			; call kernel

 mov eax,1			; system call number(system_exit)
 int 80h			; call kernel

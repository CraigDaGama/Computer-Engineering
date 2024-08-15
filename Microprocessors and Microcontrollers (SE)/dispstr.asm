; Craig Da Gama
; ALP to display 2 strings on output device

section .data					; data segment
 msg1 db"My name is Craig",13,10		; "Hello World!" string
 len1 equ $-msg1				; length of "My name is Craig" string
 
 msg2 db"This is my first 8386 program",13,10	; "This is my first 8386 program" string
 len2 equ $-msg2				; length of "Hello World!" string
	
section .text					; code segment
 global _start					; must be declared for linker
 _start:					; tell linker entry point
 mov edx, len1					; message length
 mov ecx, msg1					; message to write
 mov ebx, 1					; file descriptor(stdout)
 mov eax, 4					; system call number(system_write)
 int 80h					; call kernel

 mov edx, len2					; message length
 mov ecx, msg2					; message to write
 mov ebx, 1					; file descriptor(stdout)
 mov eax, 4					; system call number(system_write)
 int 80h					; call kernel


 mov eax,1					; system call number(system_exit)
 int 80h					; call kernel

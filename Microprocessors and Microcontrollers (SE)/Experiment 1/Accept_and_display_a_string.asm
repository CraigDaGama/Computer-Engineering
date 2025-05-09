section .data
    msg1 db 'Hello', 13, 10
    len1 equ $ - msg1

    msg2 db 'People', 13, 10
    len2 equ $ - msg2 

section .text
    global _start

_start:
    mov eax, 4
    mov ebx, 1
    mov ecx, msg1
    mov edx, len1
    int 80h

    mov eax, 4
    mov ebx, 1
    mov ecx, msg2
    mov edx, len2
    int 80h

    mov eax, 1
    int 80h
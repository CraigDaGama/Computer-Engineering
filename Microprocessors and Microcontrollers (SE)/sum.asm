; Craig Da Gama
; ALP to add two numbers in memeoy and display the sum to the user on the output device

; data segment
section .data			
 msg db"*** Basic Mathematical Operation",13,10			
 len equ $-msg

 msg1 db 10,13,"sum is:"
 len1 equ $-msg1

; used to initaialise variables without value
section .bss
 sum resb 1

section .text
 global _start					
 _start:	

 ; Display the string msg				
 mov edx, len					
 mov ecx, msg					
 mov ebx, 1					
 mov eax, 4					
 int 80h					

 ; Display the string message
 mov edx, len1					
 mov ecx, msg1					
 mov ebx, 1					
 mov eax, 4					
 int 80h					

 ; Addition
 mov ax, '6'				; ax<-36
 ; Converting ASCII 6 to decimal
 sub ax, '0'				; ax<-36-30<-06
 mov bx, '2'
 ; Converting ASCII 2 to decimal
 sub bx, '0'				; ax <- 32-30 <- 02
 add al, bl				; al <- 06+02 <- 08
 add ax, '0'				; ax <- 08+30 <- 38
 mov[sum], ax				; [sum] <- 38



 ; Display the sum
 mov ecx, sum
 mov edx, 1
 mov ebx, 1					
 mov eax, 4					
 int 80h		

 mov eax,1					
 int 80h					

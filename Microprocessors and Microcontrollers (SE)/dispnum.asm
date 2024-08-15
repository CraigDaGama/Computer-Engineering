; Craig Da Gama
; ALP to accept a number from user and display the number to the user on the output device

; data segment
section .data			
 msg db"Enter a number",13,10			
 len equ $-msg

 msg1 db 10,13,"Entered number is:"
 len1 equ $-msg1

; used to initaialise variables without value
section .bss
 sum resb 1
 num resb 1

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

 ; Taking input from user 
 mov eax, 3				
 mov ebx, 0
 mov ecx, num		
 mov edx, 2				
 int 80h				


 ; Display the sum
 mov ecx, num
 mov edx, 1
 mov ebx, 1					
 mov eax, 4					
 int 80h		

 mov eax,1					
 int 80h					

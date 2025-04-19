			ORG 0000h		; origem 0000h padrão
			SJMP INICIO		; vai para o label INICIO
			ORG 30h			; origem para INICIO do endereço 30h
			
			
	INICIO: MOV R0,#30h		; O valor de R0 passa a ser 30h
			MOV R3,#00		; Move o valor de A para B
				
				
	SALTO1: MOV A,@R0		; Atribui o endereço de R0 para A
			MOV B, A		; Move o valor de A para B
			MOV A, R3		; Move o valor de A para B
			CLR C			; Zera o valor do carry
			SUBB A,B		; SUBTRAI B do valor de A ( A - B) e o resultado fica em A
			JNC SALTO2		; Se o carry estiver em 0 ele desvia para SALTO2, caso seja 1 vai para a linha de baixo
			MOV R3,B		; Move o valor de A para B 


	SALTO2: INC R0			; Incrementa o valor de R0
			MOV B, R0		; Move o valor de A para B
			MOV A, #40h		; O valor de A passa a ser 40h
			CLR C			; Zera o valor de carry
			SUBB A,B		; SUBTRAI B do valor de A ( A - B) e o resultado fica em A
			JNC SALTO1		; Se o carry estiver em 0 ele desvia para SALTO1, caso seja 1 vai para a linha de baixo
			END				; finaliza o programa
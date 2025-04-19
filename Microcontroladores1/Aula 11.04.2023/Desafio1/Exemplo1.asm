		ORG 0000h			; origem em 0000h padrão de todos os programas
		SJMP INICIO			; da um pulo para início
		ORG 0030h			; vai para início a partir do endereço 0030h
			;diferença entre label e subrotina: unidade cumpre o que foi feito e vai pro proximo
			;a subrotina(ret) quando cumpre tudo vai para uma linha abaixode onde foi chamado
	
INICIO: MOV R1,#00			; VALOR de R1 passa a ser 00 e LABEL INICIO
		MOV R2,#00			; VALOR de R2 passa a ser 00
		MOV R3,#00			; VALOR de R3 passa a ser 00
		MOV A, P1			; VALOR de A passa a ser o de P1 
		MOV B,#100			; VALOR de B passa a ser 100
		MOV R4,A			; VALOR de R4 passa a ser o de A
		SUBB A,B			; SUBTRAI A por B e o resultado fica em A
		MOV A,R4			; VALOR de A passa a ser o de R4
		JC DEZENA			; da um desvio para a Dezena SE o carry(sobra da conta) for igual a 1, se não vai pra linha de baixo
		DIV AB				; DIVIDE A por B, o resultado fica em A e o resto fica em B
		MOV R1,A			; VALOR DE R1 passa a ser o de A
		MOV A,B				; VALOR DE A passa a ser o de B


DEZENA: MOV B,#10			; VALOR DE A passa a ser o de B
		MOV R4,A			; VALOR DE R4 passa a ser o de A
		SUBB A,B			; SUBTRAI o valor de B por A( A - B), onde o resultado fica em A
		MOV A,R4			; VALOR DE A passa a ser o de R4
		JC UNIDADE			; da um desvio para a Unidade SE o carry(sobra da conta) for igual a 1, se não vai pra linha de baixo
		DIV AB				; Divide A por B, o resultado fica em A e o resto fica em B
		MOV R2,A			; VALOR DE R2 passa a ser o de A
		MOV A,B				; VALOR DE A passa a ser o de B
UNIDADE: MOV R3,A			; VALOR DE R3 passa a ser o de A e LABEL INICIO
		END					; finaliza o programa
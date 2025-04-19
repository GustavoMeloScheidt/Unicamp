ORG 100h
MOV PSW	#00000000b
MOV R0,#32 ; banco 0
MOV PSW,#00001000b ;setou o RS0 em 1, igual fazer SETB RS0, pode usar CLR(clear) pra mudar pro bit 0
;a foto no celular mostra o PSW e seus bits, mostra todas as 4 combinações dos bancos, que é a junção de RS0 e RS1
MOV R0,#32 ; banco 1
MOV PSW,#00010000b
MOV R0,#32; adicionou o valor 32 decimal no banco 2
MOV PSW,#00011000b
MOV R0,#32 ;adicionou o valor 32 no registrador r0 do banco 3
END
	
	; CADA BANCO TEM 8 REGISTRADORES QUE INDEPENDEM UM DO OUTRO, O R0 DO BANCO 0 PODE SER "2" ENQUANTO O R0 DO BANCO 1 PODE SER "93"
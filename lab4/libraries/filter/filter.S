; filter.S
;
; FIR filter
;
#define NUM_TAPS 27
#define NUM_SAMPS 125

    .extern printRegs
    .extern q15mpy
    .extern fir1
    .extern input
    .extern output

    .global filter
filter:
    push r16    ;save registers so C doesn't get confused
    push r17
    push r28
    push r29

    ;insert your assembly language code below
    ;(you can invoke printRegs() with the asm instruction 'call printRegs')
	ldi r16, 26	;r16 is i
	ldi r18, NUM_SAMPS	;threshold is NUM_SAMPS
	ldi r17, 0 ;r17 is k
	ldi r19, 27	;r19 is the threshold of k

	outer_loop:
	cp r16, r18
	brge outerloop_exit

	ldi r26, 0
	ldi r27, 0
	ldi r17, 0
	sts (k), r17

	inner_loop:
	cp r17, r19
	brge innerloop_exit
	ldi r30, lo8(fir1)
	ldi r31, hi8(fir1)
	lds r17, k
	lsl r17 	;r 17 is doubled!!!! and it is changed!!!
	add r30, r17
	adc r31, r1
	ld r22, Z+ ;load hir1 into r25 r24
	ld r23, Z
	lsr r17


	ldi r30, lo8(input)
	ldi r31, hi8(input)
	lds r20, i
	sub r20, r17 ;i20 is i-k
	lsl r20
	add r30, r20
	adc r31, r1
	ld r24, Z+ ;put x in r24 r25
	ld r25, Z
	;lsr r20

	push r18
    push r19
    push r20
    push r26
    push r27
    call q15mpy
    pop r27
    pop r26
    pop r20
    pop r19
	pop r18

;	call printRegs
	add r26, r24
	adc r27, r25


	;call printRegs

	inc r17
	sts (k), r17
	;call printRegs
	jmp inner_loop
	innerloop_exit:



	ldi r30, lo8(output)
	ldi r31, hi8(output)
	lds r16, i
	lsl r16
	add r30, r16
	adc r31, r1
	st Z+, r26
	st Z, r27
	lsr r16

	;call printRegs
	inc r16
	sts (i), r16
	jmp outer_loop
	outerloop_exit:

    pop r29     ;restore registers saved earlier
    pop r28
    pop r17
    pop r16
    ret         ;return

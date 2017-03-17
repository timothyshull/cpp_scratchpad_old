	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.intel_syntax noprefix
	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
Lfunc_begin0:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception0
## BB#0:
	push	rbp
Ltmp6:
	.cfi_def_cfa_offset 16
Ltmp7:
	.cfi_offset rbp, -16
	mov	rbp, rsp
Ltmp8:
	.cfi_def_cfa_register rbp
	sub	rsp, 96
	mov	dword ptr [rbp - 4], 0
	mov	eax, 16
	mov	edi, eax
	call	__Znwm
	mov	rdi, rax
	mov	rcx, rax
Ltmp0:
	mov	esi, 4
	mov	edx, 5
	mov	qword ptr [rbp - 48], rdi ## 8-byte Spill
	mov	rdi, rax
	mov	qword ptr [rbp - 56], rcx ## 8-byte Spill
	call	__ZN9RectangleC1Eii
Ltmp1:
	jmp	LBB0_1
LBB0_1:
	mov	rax, qword ptr [rbp - 56] ## 8-byte Reload
	mov	qword ptr [rbp - 16], rax
	mov	ecx, 16
	mov	edi, ecx
	call	__Znwm
	mov	rdi, rax
	mov	rdx, rax
Ltmp3:
	mov	esi, 4
	mov	ecx, 5
	mov	qword ptr [rbp - 64], rdi ## 8-byte Spill
	mov	rdi, rax
	mov	qword ptr [rbp - 72], rdx ## 8-byte Spill
	mov	edx, ecx
	call	__ZN8TriangleC1Eii
Ltmp4:
	jmp	LBB0_2
LBB0_2:
	mov	rax, qword ptr [rbp - 72] ## 8-byte Reload
	mov	qword ptr [rbp - 40], rax
	mov	rdi, qword ptr [rbp - 16]
	call	__ZN7Polygon9printareaEv
	mov	rdi, qword ptr [rbp - 40]
	call	__ZN7Polygon9printareaEv
	mov	rax, qword ptr [rbp - 16]
	cmp	rax, 0
	mov	qword ptr [rbp - 80], rax ## 8-byte Spill
	je	LBB0_4
## BB#3:
	mov	rax, qword ptr [rbp - 80] ## 8-byte Reload
	mov	rcx, qword ptr [rax]
	mov	rdi, rax
	call	qword ptr [rcx + 8]
LBB0_4:
	mov	rax, qword ptr [rbp - 40]
	cmp	rax, 0
	mov	qword ptr [rbp - 88], rax ## 8-byte Spill
	je	LBB0_6
## BB#5:
	mov	rax, qword ptr [rbp - 88] ## 8-byte Reload
	mov	rcx, qword ptr [rax]
	mov	rdi, rax
	call	qword ptr [rcx + 8]
LBB0_6:
	xor	eax, eax
	add	rsp, 96
	pop	rbp
	ret
LBB0_7:
Ltmp2:
	mov	ecx, edx
	mov	qword ptr [rbp - 24], rax
	mov	dword ptr [rbp - 28], ecx
	mov	rdi, qword ptr [rbp - 48] ## 8-byte Reload
	call	__ZdlPv
	jmp	LBB0_9
LBB0_8:
Ltmp5:
	mov	ecx, edx
	mov	qword ptr [rbp - 24], rax
	mov	dword ptr [rbp - 28], ecx
	mov	rdi, qword ptr [rbp - 64] ## 8-byte Reload
	call	__ZdlPv
LBB0_9:
	mov	rdi, qword ptr [rbp - 24]
	call	__Unwind_Resume
Lfunc_end0:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table0:
Lexception0:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.asciz	"\303\200"              ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	65                      ## Call site table length
Lset0 = Lfunc_begin0-Lfunc_begin0       ## >> Call Site 1 <<
	.long	Lset0
Lset1 = Ltmp0-Lfunc_begin0              ##   Call between Lfunc_begin0 and Ltmp0
	.long	Lset1
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset2 = Ltmp0-Lfunc_begin0              ## >> Call Site 2 <<
	.long	Lset2
Lset3 = Ltmp1-Ltmp0                     ##   Call between Ltmp0 and Ltmp1
	.long	Lset3
Lset4 = Ltmp2-Lfunc_begin0              ##     jumps to Ltmp2
	.long	Lset4
	.byte	0                       ##   On action: cleanup
Lset5 = Ltmp1-Lfunc_begin0              ## >> Call Site 3 <<
	.long	Lset5
Lset6 = Ltmp3-Ltmp1                     ##   Call between Ltmp1 and Ltmp3
	.long	Lset6
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset7 = Ltmp3-Lfunc_begin0              ## >> Call Site 4 <<
	.long	Lset7
Lset8 = Ltmp4-Ltmp3                     ##   Call between Ltmp3 and Ltmp4
	.long	Lset8
Lset9 = Ltmp5-Lfunc_begin0              ##     jumps to Ltmp5
	.long	Lset9
	.byte	0                       ##   On action: cleanup
Lset10 = Ltmp4-Lfunc_begin0             ## >> Call Site 5 <<
	.long	Lset10
Lset11 = Lfunc_end0-Ltmp4               ##   Call between Ltmp4 and Lfunc_end0
	.long	Lset11
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.p2align	2

	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZN9RectangleC1Eii
	.weak_def_can_be_hidden	__ZN9RectangleC1Eii
	.p2align	4, 0x90
__ZN9RectangleC1Eii:                    ## @_ZN9RectangleC1Eii
	.cfi_startproc
## BB#0:
	push	rbp
Ltmp9:
	.cfi_def_cfa_offset 16
Ltmp10:
	.cfi_offset rbp, -16
	mov	rbp, rsp
Ltmp11:
	.cfi_def_cfa_register rbp
	sub	rsp, 16
	mov	qword ptr [rbp - 8], rdi
	mov	dword ptr [rbp - 12], esi
	mov	dword ptr [rbp - 16], edx
	mov	rdi, qword ptr [rbp - 8]
	mov	esi, dword ptr [rbp - 12]
	mov	edx, dword ptr [rbp - 16]
	call	__ZN9RectangleC2Eii
	add	rsp, 16
	pop	rbp
	ret
	.cfi_endproc

	.globl	__ZN8TriangleC1Eii
	.weak_def_can_be_hidden	__ZN8TriangleC1Eii
	.p2align	4, 0x90
__ZN8TriangleC1Eii:                     ## @_ZN8TriangleC1Eii
	.cfi_startproc
## BB#0:
	push	rbp
Ltmp12:
	.cfi_def_cfa_offset 16
Ltmp13:
	.cfi_offset rbp, -16
	mov	rbp, rsp
Ltmp14:
	.cfi_def_cfa_register rbp
	sub	rsp, 16
	mov	qword ptr [rbp - 8], rdi
	mov	dword ptr [rbp - 12], esi
	mov	dword ptr [rbp - 16], edx
	mov	rdi, qword ptr [rbp - 8]
	mov	esi, dword ptr [rbp - 12]
	mov	edx, dword ptr [rbp - 16]
	call	__ZN8TriangleC2Eii
	add	rsp, 16
	pop	rbp
	ret
	.cfi_endproc

	.globl	__ZN7Polygon9printareaEv
	.weak_definition	__ZN7Polygon9printareaEv
	.p2align	4, 0x90
__ZN7Polygon9printareaEv:               ## @_ZN7Polygon9printareaEv
	.cfi_startproc
## BB#0:
	push	rbp
Ltmp15:
	.cfi_def_cfa_offset 16
Ltmp16:
	.cfi_offset rbp, -16
	mov	rbp, rsp
Ltmp17:
	.cfi_def_cfa_register rbp
	sub	rsp, 16
	mov	qword ptr [rbp - 8], rdi
	mov	rdi, qword ptr [rbp - 8]
	mov	rax, qword ptr [rdi]
	call	qword ptr [rax + 16]
	mov	rdi, qword ptr [rip + __ZNSt3__14coutE@GOTPCREL]
	mov	esi, eax
	call	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEi
	mov	esi, 10
	mov	rdi, rax
	call	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_c
	mov	qword ptr [rbp - 16], rax ## 8-byte Spill
	add	rsp, 16
	pop	rbp
	ret
	.cfi_endproc

	.globl	__ZN9RectangleC2Eii
	.weak_def_can_be_hidden	__ZN9RectangleC2Eii
	.p2align	4, 0x90
__ZN9RectangleC2Eii:                    ## @_ZN9RectangleC2Eii
	.cfi_startproc
## BB#0:
	push	rbp
Ltmp18:
	.cfi_def_cfa_offset 16
Ltmp19:
	.cfi_offset rbp, -16
	mov	rbp, rsp
Ltmp20:
	.cfi_def_cfa_register rbp
	sub	rsp, 32
	mov	qword ptr [rbp - 8], rdi
	mov	dword ptr [rbp - 12], esi
	mov	dword ptr [rbp - 16], edx
	mov	rdi, qword ptr [rbp - 8]
	mov	rax, rdi
	mov	esi, dword ptr [rbp - 12]
	mov	edx, dword ptr [rbp - 16]
	mov	qword ptr [rbp - 24], rdi ## 8-byte Spill
	mov	rdi, rax
	call	__ZN7PolygonC2Eii
	mov	rax, qword ptr [rip + __ZTV9Rectangle@GOTPCREL]
	add	rax, 16
	mov	rdi, qword ptr [rbp - 24] ## 8-byte Reload
	mov	qword ptr [rdi], rax
	add	rsp, 32
	pop	rbp
	ret
	.cfi_endproc

	.globl	__ZN7PolygonC2Eii
	.weak_def_can_be_hidden	__ZN7PolygonC2Eii
	.p2align	4, 0x90
__ZN7PolygonC2Eii:                      ## @_ZN7PolygonC2Eii
	.cfi_startproc
## BB#0:
	push	rbp
Ltmp21:
	.cfi_def_cfa_offset 16
Ltmp22:
	.cfi_offset rbp, -16
	mov	rbp, rsp
Ltmp23:
	.cfi_def_cfa_register rbp
	mov	rax, qword ptr [rip + __ZTV7Polygon@GOTPCREL]
	add	rax, 16
	mov	qword ptr [rbp - 8], rdi
	mov	dword ptr [rbp - 12], esi
	mov	dword ptr [rbp - 16], edx
	mov	rdi, qword ptr [rbp - 8]
	mov	qword ptr [rdi], rax
	mov	edx, dword ptr [rbp - 12]
	mov	dword ptr [rdi + 8], edx
	mov	edx, dword ptr [rbp - 16]
	mov	dword ptr [rdi + 12], edx
	pop	rbp
	ret
	.cfi_endproc

	.globl	__ZN9RectangleD1Ev
	.weak_def_can_be_hidden	__ZN9RectangleD1Ev
	.p2align	4, 0x90
__ZN9RectangleD1Ev:                     ## @_ZN9RectangleD1Ev
	.cfi_startproc
## BB#0:
	push	rbp
Ltmp24:
	.cfi_def_cfa_offset 16
Ltmp25:
	.cfi_offset rbp, -16
	mov	rbp, rsp
Ltmp26:
	.cfi_def_cfa_register rbp
	sub	rsp, 16
	mov	qword ptr [rbp - 8], rdi
	mov	rdi, qword ptr [rbp - 8]
	call	__ZN9RectangleD2Ev
	add	rsp, 16
	pop	rbp
	ret
	.cfi_endproc

	.globl	__ZN9RectangleD0Ev
	.weak_def_can_be_hidden	__ZN9RectangleD0Ev
	.p2align	4, 0x90
__ZN9RectangleD0Ev:                     ## @_ZN9RectangleD0Ev
Lfunc_begin1:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception1
## BB#0:
	push	rbp
Ltmp30:
	.cfi_def_cfa_offset 16
Ltmp31:
	.cfi_offset rbp, -16
	mov	rbp, rsp
Ltmp32:
	.cfi_def_cfa_register rbp
	sub	rsp, 32
	mov	qword ptr [rbp - 8], rdi
	mov	rax, rdi
Ltmp27:
	mov	qword ptr [rbp - 32], rax ## 8-byte Spill
	call	__ZN9RectangleD1Ev
Ltmp28:
	jmp	LBB7_1
LBB7_1:
	mov	rax, qword ptr [rbp - 32] ## 8-byte Reload
	mov	rdi, rax
	call	__ZdlPv
	add	rsp, 32
	pop	rbp
	ret
LBB7_2:
Ltmp29:
	mov	ecx, edx
	mov	qword ptr [rbp - 16], rax
	mov	dword ptr [rbp - 20], ecx
	mov	rax, qword ptr [rbp - 32] ## 8-byte Reload
	mov	rdi, rax
	call	__ZdlPv
## BB#3:
	mov	rdi, qword ptr [rbp - 16]
	call	__Unwind_Resume
Lfunc_end1:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table7:
Lexception1:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.asciz	"\234"                  ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	26                      ## Call site table length
Lset12 = Ltmp27-Lfunc_begin1            ## >> Call Site 1 <<
	.long	Lset12
Lset13 = Ltmp28-Ltmp27                  ##   Call between Ltmp27 and Ltmp28
	.long	Lset13
Lset14 = Ltmp29-Lfunc_begin1            ##     jumps to Ltmp29
	.long	Lset14
	.byte	0                       ##   On action: cleanup
Lset15 = Ltmp28-Lfunc_begin1            ## >> Call Site 2 <<
	.long	Lset15
Lset16 = Lfunc_end1-Ltmp28              ##   Call between Ltmp28 and Lfunc_end1
	.long	Lset16
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.p2align	2

	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZN9Rectangle4areaEv
	.weak_def_can_be_hidden	__ZN9Rectangle4areaEv
	.p2align	4, 0x90
__ZN9Rectangle4areaEv:                  ## @_ZN9Rectangle4areaEv
	.cfi_startproc
## BB#0:
	push	rbp
Ltmp33:
	.cfi_def_cfa_offset 16
Ltmp34:
	.cfi_offset rbp, -16
	mov	rbp, rsp
Ltmp35:
	.cfi_def_cfa_register rbp
	mov	qword ptr [rbp - 8], rdi
	mov	rdi, qword ptr [rbp - 8]
	mov	eax, dword ptr [rdi + 8]
	imul	eax, dword ptr [rdi + 12]
	pop	rbp
	ret
	.cfi_endproc

	.globl	__ZN7PolygonD1Ev
	.weak_def_can_be_hidden	__ZN7PolygonD1Ev
	.p2align	4, 0x90
__ZN7PolygonD1Ev:                       ## @_ZN7PolygonD1Ev
	.cfi_startproc
## BB#0:
	push	rbp
Ltmp36:
	.cfi_def_cfa_offset 16
Ltmp37:
	.cfi_offset rbp, -16
	mov	rbp, rsp
Ltmp38:
	.cfi_def_cfa_register rbp
	sub	rsp, 16
	mov	qword ptr [rbp - 8], rdi
	mov	rdi, qword ptr [rbp - 8]
	call	__ZN7PolygonD2Ev
	add	rsp, 16
	pop	rbp
	ret
	.cfi_endproc

	.globl	__ZN7PolygonD0Ev
	.weak_def_can_be_hidden	__ZN7PolygonD0Ev
	.p2align	4, 0x90
__ZN7PolygonD0Ev:                       ## @_ZN7PolygonD0Ev
Lfunc_begin2:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception2
## BB#0:
	push	rbp
Ltmp42:
	.cfi_def_cfa_offset 16
Ltmp43:
	.cfi_offset rbp, -16
	mov	rbp, rsp
Ltmp44:
	.cfi_def_cfa_register rbp
	sub	rsp, 32
	mov	qword ptr [rbp - 8], rdi
	mov	rax, rdi
Ltmp39:
	mov	qword ptr [rbp - 32], rax ## 8-byte Spill
	call	__ZN7PolygonD1Ev
Ltmp40:
	jmp	LBB10_1
LBB10_1:
	mov	rax, qword ptr [rbp - 32] ## 8-byte Reload
	mov	rdi, rax
	call	__ZdlPv
	add	rsp, 32
	pop	rbp
	ret
LBB10_2:
Ltmp41:
	mov	ecx, edx
	mov	qword ptr [rbp - 16], rax
	mov	dword ptr [rbp - 20], ecx
	mov	rax, qword ptr [rbp - 32] ## 8-byte Reload
	mov	rdi, rax
	call	__ZdlPv
## BB#3:
	mov	rdi, qword ptr [rbp - 16]
	call	__Unwind_Resume
Lfunc_end2:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table10:
Lexception2:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.asciz	"\234"                  ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	26                      ## Call site table length
Lset17 = Ltmp39-Lfunc_begin2            ## >> Call Site 1 <<
	.long	Lset17
Lset18 = Ltmp40-Ltmp39                  ##   Call between Ltmp39 and Ltmp40
	.long	Lset18
Lset19 = Ltmp41-Lfunc_begin2            ##     jumps to Ltmp41
	.long	Lset19
	.byte	0                       ##   On action: cleanup
Lset20 = Ltmp40-Lfunc_begin2            ## >> Call Site 2 <<
	.long	Lset20
Lset21 = Lfunc_end2-Ltmp40              ##   Call between Ltmp40 and Lfunc_end2
	.long	Lset21
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.p2align	2

	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZN7PolygonD2Ev
	.weak_def_can_be_hidden	__ZN7PolygonD2Ev
	.p2align	4, 0x90
__ZN7PolygonD2Ev:                       ## @_ZN7PolygonD2Ev
	.cfi_startproc
## BB#0:
	push	rbp
Ltmp45:
	.cfi_def_cfa_offset 16
Ltmp46:
	.cfi_offset rbp, -16
	mov	rbp, rsp
Ltmp47:
	.cfi_def_cfa_register rbp
	mov	qword ptr [rbp - 8], rdi
	pop	rbp
	ret
	.cfi_endproc

	.globl	__ZN9RectangleD2Ev
	.weak_def_can_be_hidden	__ZN9RectangleD2Ev
	.p2align	4, 0x90
__ZN9RectangleD2Ev:                     ## @_ZN9RectangleD2Ev
	.cfi_startproc
## BB#0:
	push	rbp
Ltmp48:
	.cfi_def_cfa_offset 16
Ltmp49:
	.cfi_offset rbp, -16
	mov	rbp, rsp
Ltmp50:
	.cfi_def_cfa_register rbp
	sub	rsp, 16
	mov	qword ptr [rbp - 8], rdi
	mov	rdi, qword ptr [rbp - 8]
	call	__ZN7PolygonD2Ev
	add	rsp, 16
	pop	rbp
	ret
	.cfi_endproc

	.globl	__ZN8TriangleC2Eii
	.weak_def_can_be_hidden	__ZN8TriangleC2Eii
	.p2align	4, 0x90
__ZN8TriangleC2Eii:                     ## @_ZN8TriangleC2Eii
	.cfi_startproc
## BB#0:
	push	rbp
Ltmp51:
	.cfi_def_cfa_offset 16
Ltmp52:
	.cfi_offset rbp, -16
	mov	rbp, rsp
Ltmp53:
	.cfi_def_cfa_register rbp
	sub	rsp, 32
	mov	qword ptr [rbp - 8], rdi
	mov	dword ptr [rbp - 12], esi
	mov	dword ptr [rbp - 16], edx
	mov	rdi, qword ptr [rbp - 8]
	mov	rax, rdi
	mov	esi, dword ptr [rbp - 12]
	mov	edx, dword ptr [rbp - 16]
	mov	qword ptr [rbp - 24], rdi ## 8-byte Spill
	mov	rdi, rax
	call	__ZN7PolygonC2Eii
	mov	rax, qword ptr [rip + __ZTV8Triangle@GOTPCREL]
	add	rax, 16
	mov	rdi, qword ptr [rbp - 24] ## 8-byte Reload
	mov	qword ptr [rdi], rax
	add	rsp, 32
	pop	rbp
	ret
	.cfi_endproc

	.globl	__ZN8TriangleD1Ev
	.weak_def_can_be_hidden	__ZN8TriangleD1Ev
	.p2align	4, 0x90
__ZN8TriangleD1Ev:                      ## @_ZN8TriangleD1Ev
	.cfi_startproc
## BB#0:
	push	rbp
Ltmp54:
	.cfi_def_cfa_offset 16
Ltmp55:
	.cfi_offset rbp, -16
	mov	rbp, rsp
Ltmp56:
	.cfi_def_cfa_register rbp
	sub	rsp, 16
	mov	qword ptr [rbp - 8], rdi
	mov	rdi, qword ptr [rbp - 8]
	call	__ZN8TriangleD2Ev
	add	rsp, 16
	pop	rbp
	ret
	.cfi_endproc

	.globl	__ZN8TriangleD0Ev
	.weak_def_can_be_hidden	__ZN8TriangleD0Ev
	.p2align	4, 0x90
__ZN8TriangleD0Ev:                      ## @_ZN8TriangleD0Ev
Lfunc_begin3:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception3
## BB#0:
	push	rbp
Ltmp60:
	.cfi_def_cfa_offset 16
Ltmp61:
	.cfi_offset rbp, -16
	mov	rbp, rsp
Ltmp62:
	.cfi_def_cfa_register rbp
	sub	rsp, 32
	mov	qword ptr [rbp - 8], rdi
	mov	rax, rdi
Ltmp57:
	mov	qword ptr [rbp - 32], rax ## 8-byte Spill
	call	__ZN8TriangleD1Ev
Ltmp58:
	jmp	LBB15_1
LBB15_1:
	mov	rax, qword ptr [rbp - 32] ## 8-byte Reload
	mov	rdi, rax
	call	__ZdlPv
	add	rsp, 32
	pop	rbp
	ret
LBB15_2:
Ltmp59:
	mov	ecx, edx
	mov	qword ptr [rbp - 16], rax
	mov	dword ptr [rbp - 20], ecx
	mov	rax, qword ptr [rbp - 32] ## 8-byte Reload
	mov	rdi, rax
	call	__ZdlPv
## BB#3:
	mov	rdi, qword ptr [rbp - 16]
	call	__Unwind_Resume
Lfunc_end3:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table15:
Lexception3:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.asciz	"\234"                  ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	26                      ## Call site table length
Lset22 = Ltmp57-Lfunc_begin3            ## >> Call Site 1 <<
	.long	Lset22
Lset23 = Ltmp58-Ltmp57                  ##   Call between Ltmp57 and Ltmp58
	.long	Lset23
Lset24 = Ltmp59-Lfunc_begin3            ##     jumps to Ltmp59
	.long	Lset24
	.byte	0                       ##   On action: cleanup
Lset25 = Ltmp58-Lfunc_begin3            ## >> Call Site 2 <<
	.long	Lset25
Lset26 = Lfunc_end3-Ltmp58              ##   Call between Ltmp58 and Lfunc_end3
	.long	Lset26
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.p2align	2

	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZN8Triangle4areaEv
	.weak_def_can_be_hidden	__ZN8Triangle4areaEv
	.p2align	4, 0x90
__ZN8Triangle4areaEv:                   ## @_ZN8Triangle4areaEv
	.cfi_startproc
## BB#0:
	push	rbp
Ltmp63:
	.cfi_def_cfa_offset 16
Ltmp64:
	.cfi_offset rbp, -16
	mov	rbp, rsp
Ltmp65:
	.cfi_def_cfa_register rbp
	mov	eax, 2
	mov	qword ptr [rbp - 8], rdi
	mov	rdi, qword ptr [rbp - 8]
	mov	ecx, dword ptr [rdi + 8]
	imul	ecx, dword ptr [rdi + 12]
	mov	dword ptr [rbp - 12], eax ## 4-byte Spill
	mov	eax, ecx
	cdq
	mov	ecx, dword ptr [rbp - 12] ## 4-byte Reload
	idiv	ecx
	pop	rbp
	ret
	.cfi_endproc

	.globl	__ZN8TriangleD2Ev
	.weak_def_can_be_hidden	__ZN8TriangleD2Ev
	.p2align	4, 0x90
__ZN8TriangleD2Ev:                      ## @_ZN8TriangleD2Ev
	.cfi_startproc
## BB#0:
	push	rbp
Ltmp66:
	.cfi_def_cfa_offset 16
Ltmp67:
	.cfi_offset rbp, -16
	mov	rbp, rsp
Ltmp68:
	.cfi_def_cfa_register rbp
	sub	rsp, 16
	mov	qword ptr [rbp - 8], rdi
	mov	rdi, qword ptr [rbp - 8]
	call	__ZN7PolygonD2Ev
	add	rsp, 16
	pop	rbp
	ret
	.cfi_endproc

	.globl	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_c
	.weak_definition	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_c
	.p2align	4, 0x90
__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_c: ## @_ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_c
	.cfi_startproc
## BB#0:
	push	rbp
Ltmp69:
	.cfi_def_cfa_offset 16
Ltmp70:
	.cfi_offset rbp, -16
	mov	rbp, rsp
Ltmp71:
	.cfi_def_cfa_register rbp
	sub	rsp, 16
	mov	al, sil
	lea	rsi, [rbp - 9]
	mov	ecx, 1
	mov	edx, ecx
	mov	qword ptr [rbp - 8], rdi
	mov	byte ptr [rbp - 9], al
	mov	rdi, qword ptr [rbp - 8]
	call	__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m
	add	rsp, 16
	pop	rbp
	ret
	.cfi_endproc

	.globl	__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m
	.weak_definition	__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m
	.p2align	4, 0x90
__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m: ## @_ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m
Lfunc_begin4:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception4
## BB#0:
	push	rbp
Ltmp102:
	.cfi_def_cfa_offset 16
Ltmp103:
	.cfi_offset rbp, -16
	mov	rbp, rsp
Ltmp104:
	.cfi_def_cfa_register rbp
	sub	rsp, 416
	mov	qword ptr [rbp - 200], rdi
	mov	qword ptr [rbp - 208], rsi
	mov	qword ptr [rbp - 216], rdx
	mov	rsi, qword ptr [rbp - 200]
Ltmp72:
	lea	rdi, [rbp - 232]
	call	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEE6sentryC1ERS3_
Ltmp73:
	jmp	LBB19_1
LBB19_1:
	lea	rax, [rbp - 232]
	mov	qword ptr [rbp - 192], rax
	mov	rax, qword ptr [rbp - 192]
	mov	cl, byte ptr [rax]
	mov	byte ptr [rbp - 265], cl ## 1-byte Spill
## BB#2:
	mov	al, byte ptr [rbp - 265] ## 1-byte Reload
	test	al, 1
	jne	LBB19_3
	jmp	LBB19_26
LBB19_3:
	lea	rax, [rbp - 256]
	mov	rcx, qword ptr [rbp - 200]
	mov	qword ptr [rbp - 176], rax
	mov	qword ptr [rbp - 184], rcx
	mov	rax, qword ptr [rbp - 176]
	mov	rcx, qword ptr [rbp - 184]
	mov	qword ptr [rbp - 144], rax
	mov	qword ptr [rbp - 152], rcx
	mov	rax, qword ptr [rbp - 144]
	mov	rcx, qword ptr [rbp - 152]
	mov	rdx, qword ptr [rcx]
	mov	rdx, qword ptr [rdx - 24]
	add	rcx, rdx
	mov	qword ptr [rbp - 136], rcx
	mov	rcx, qword ptr [rbp - 136]
	mov	qword ptr [rbp - 128], rcx
	mov	rcx, qword ptr [rbp - 128]
	mov	rcx, qword ptr [rcx + 40]
	mov	qword ptr [rax], rcx
	mov	rsi, qword ptr [rbp - 208]
	mov	rax, qword ptr [rbp - 200]
	mov	rcx, qword ptr [rax]
	mov	rcx, qword ptr [rcx - 24]
	add	rax, rcx
	mov	qword ptr [rbp - 88], rax
	mov	rax, qword ptr [rbp - 88]
	mov	edi, dword ptr [rax + 8]
	mov	qword ptr [rbp - 280], rsi ## 8-byte Spill
	mov	dword ptr [rbp - 284], edi ## 4-byte Spill
## BB#4:
	mov	eax, dword ptr [rbp - 284] ## 4-byte Reload
	and	eax, 176
	cmp	eax, 32
	jne	LBB19_6
## BB#5:
	mov	rax, qword ptr [rbp - 208]
	add	rax, qword ptr [rbp - 216]
	mov	qword ptr [rbp - 296], rax ## 8-byte Spill
	jmp	LBB19_7
LBB19_6:
	mov	rax, qword ptr [rbp - 208]
	mov	qword ptr [rbp - 296], rax ## 8-byte Spill
LBB19_7:
	mov	rax, qword ptr [rbp - 296] ## 8-byte Reload
	mov	rcx, qword ptr [rbp - 208]
	add	rcx, qword ptr [rbp - 216]
	mov	rdx, qword ptr [rbp - 200]
	mov	rsi, qword ptr [rdx]
	mov	rsi, qword ptr [rsi - 24]
	add	rdx, rsi
	mov	rsi, qword ptr [rbp - 200]
	mov	rdi, qword ptr [rsi]
	mov	rdi, qword ptr [rdi - 24]
	add	rsi, rdi
	mov	qword ptr [rbp - 72], rsi
	mov	rsi, qword ptr [rbp - 72]
	mov	qword ptr [rbp - 304], rax ## 8-byte Spill
	mov	qword ptr [rbp - 312], rcx ## 8-byte Spill
	mov	qword ptr [rbp - 320], rdx ## 8-byte Spill
	mov	qword ptr [rbp - 328], rsi ## 8-byte Spill
	call	__ZNSt3__111char_traitsIcE3eofEv
	mov	rcx, qword ptr [rbp - 328] ## 8-byte Reload
	mov	esi, dword ptr [rcx + 144]
	mov	edi, eax
	call	__ZNSt3__111char_traitsIcE11eq_int_typeEii
	test	al, 1
	jne	LBB19_8
	jmp	LBB19_16
LBB19_8:
	mov	rax, qword ptr [rbp - 328] ## 8-byte Reload
	mov	qword ptr [rbp - 32], rax
	mov	byte ptr [rbp - 33], 32
	mov	rsi, qword ptr [rbp - 32]
Ltmp74:
	lea	rdi, [rbp - 48]
	call	__ZNKSt3__18ios_base6getlocEv
Ltmp75:
	jmp	LBB19_9
LBB19_9:
	lea	rax, [rbp - 48]
	mov	qword ptr [rbp - 24], rax
Ltmp76:
	mov	rsi, qword ptr [rip + __ZNSt3__15ctypeIcE2idE@GOTPCREL]
	mov	rdi, rax
	call	__ZNKSt3__16locale9use_facetERNS0_2idE
Ltmp77:
	mov	qword ptr [rbp - 336], rax ## 8-byte Spill
	jmp	LBB19_10
LBB19_10:
	mov	al, byte ptr [rbp - 33]
	mov	rcx, qword ptr [rbp - 336] ## 8-byte Reload
	mov	qword ptr [rbp - 8], rcx
	mov	byte ptr [rbp - 9], al
	mov	rdx, qword ptr [rbp - 8]
	mov	rsi, qword ptr [rdx]
	mov	rsi, qword ptr [rsi + 56]
	movsx	edi, byte ptr [rbp - 9]
Ltmp78:
	mov	dword ptr [rbp - 340], edi ## 4-byte Spill
	mov	rdi, rdx
	mov	r8d, dword ptr [rbp - 340] ## 4-byte Reload
	mov	qword ptr [rbp - 352], rsi ## 8-byte Spill
	mov	esi, r8d
	mov	rdx, qword ptr [rbp - 352] ## 8-byte Reload
	call	rdx
Ltmp79:
	mov	byte ptr [rbp - 353], al ## 1-byte Spill
	jmp	LBB19_14
LBB19_11:
Ltmp80:
	mov	ecx, edx
	mov	qword ptr [rbp - 56], rax
	mov	dword ptr [rbp - 60], ecx
Ltmp81:
	lea	rdi, [rbp - 48]
	call	__ZNSt3__16localeD1Ev
Ltmp82:
	jmp	LBB19_12
LBB19_12:
	mov	rax, qword ptr [rbp - 56]
	mov	ecx, dword ptr [rbp - 60]
	mov	qword ptr [rbp - 368], rax ## 8-byte Spill
	mov	dword ptr [rbp - 372], ecx ## 4-byte Spill
	jmp	LBB19_24
LBB19_13:
Ltmp83:
	mov	ecx, edx
	mov	rdi, rax
	mov	dword ptr [rbp - 376], ecx ## 4-byte Spill
	call	___clang_call_terminate
LBB19_14:
Ltmp84:
	lea	rdi, [rbp - 48]
	call	__ZNSt3__16localeD1Ev
Ltmp85:
	jmp	LBB19_15
LBB19_15:
	mov	al, byte ptr [rbp - 353] ## 1-byte Reload
	movsx	ecx, al
	mov	rdx, qword ptr [rbp - 328] ## 8-byte Reload
	mov	dword ptr [rdx + 144], ecx
LBB19_16:
	mov	rax, qword ptr [rbp - 328] ## 8-byte Reload
	mov	ecx, dword ptr [rax + 144]
	mov	dl, cl
	mov	byte ptr [rbp - 377], dl ## 1-byte Spill
## BB#17:
	mov	rdi, qword ptr [rbp - 256]
Ltmp86:
	mov	al, byte ptr [rbp - 377] ## 1-byte Reload
	movsx	r9d, al
	mov	rsi, qword ptr [rbp - 280] ## 8-byte Reload
	mov	rdx, qword ptr [rbp - 304] ## 8-byte Reload
	mov	rcx, qword ptr [rbp - 312] ## 8-byte Reload
	mov	r8, qword ptr [rbp - 320] ## 8-byte Reload
	call	__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_
Ltmp87:
	mov	qword ptr [rbp - 392], rax ## 8-byte Spill
	jmp	LBB19_18
LBB19_18:
	lea	rax, [rbp - 264]
	mov	rcx, qword ptr [rbp - 392] ## 8-byte Reload
	mov	qword ptr [rbp - 264], rcx
	mov	qword ptr [rbp - 80], rax
	mov	rax, qword ptr [rbp - 80]
	cmp	qword ptr [rax], 0
	jne	LBB19_25
## BB#19:
	mov	rax, qword ptr [rbp - 200]
	mov	rcx, qword ptr [rax]
	mov	rcx, qword ptr [rcx - 24]
	add	rax, rcx
	mov	qword ptr [rbp - 112], rax
	mov	dword ptr [rbp - 116], 5
	mov	rax, qword ptr [rbp - 112]
	mov	qword ptr [rbp - 96], rax
	mov	dword ptr [rbp - 100], 5
	mov	rax, qword ptr [rbp - 96]
	mov	edx, dword ptr [rax + 32]
	or	edx, 5
Ltmp88:
	mov	rdi, rax
	mov	esi, edx
	call	__ZNSt3__18ios_base5clearEj
Ltmp89:
	jmp	LBB19_20
LBB19_20:
	jmp	LBB19_21
LBB19_21:
	jmp	LBB19_25
LBB19_22:
Ltmp95:
	mov	ecx, edx
	mov	qword ptr [rbp - 240], rax
	mov	dword ptr [rbp - 244], ecx
	jmp	LBB19_29
LBB19_23:
Ltmp90:
	mov	ecx, edx
	mov	qword ptr [rbp - 368], rax ## 8-byte Spill
	mov	dword ptr [rbp - 372], ecx ## 4-byte Spill
	jmp	LBB19_24
LBB19_24:
	mov	eax, dword ptr [rbp - 372] ## 4-byte Reload
	mov	rcx, qword ptr [rbp - 368] ## 8-byte Reload
	mov	qword ptr [rbp - 240], rcx
	mov	dword ptr [rbp - 244], eax
Ltmp91:
	lea	rdi, [rbp - 232]
	call	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEE6sentryD1Ev
Ltmp92:
	jmp	LBB19_28
LBB19_25:
	jmp	LBB19_26
LBB19_26:
Ltmp93:
	lea	rdi, [rbp - 232]
	call	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEE6sentryD1Ev
Ltmp94:
	jmp	LBB19_27
LBB19_27:
	jmp	LBB19_31
LBB19_28:
	jmp	LBB19_29
LBB19_29:
	mov	rdi, qword ptr [rbp - 240]
	call	___cxa_begin_catch
	mov	rdi, qword ptr [rbp - 200]
	mov	rcx, qword ptr [rdi]
	mov	rcx, qword ptr [rcx - 24]
	add	rdi, rcx
Ltmp96:
	mov	qword ptr [rbp - 400], rax ## 8-byte Spill
	call	__ZNSt3__18ios_base33__set_badbit_and_consider_rethrowEv
Ltmp97:
	jmp	LBB19_30
LBB19_30:
	call	___cxa_end_catch
LBB19_31:
	mov	rax, qword ptr [rbp - 200]
	add	rsp, 416
	pop	rbp
	ret
LBB19_32:
Ltmp98:
	mov	ecx, edx
	mov	qword ptr [rbp - 240], rax
	mov	dword ptr [rbp - 244], ecx
Ltmp99:
	call	___cxa_end_catch
Ltmp100:
	jmp	LBB19_33
LBB19_33:
	jmp	LBB19_34
LBB19_34:
	mov	rdi, qword ptr [rbp - 240]
	call	__Unwind_Resume
LBB19_35:
Ltmp101:
	mov	ecx, edx
	mov	rdi, rax
	mov	dword ptr [rbp - 404], ecx ## 4-byte Spill
	call	___clang_call_terminate
Lfunc_end4:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table19:
Lexception4:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.asciz	"\253\201"              ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.ascii	"\234\001"              ## Call site table length
Lset27 = Ltmp72-Lfunc_begin4            ## >> Call Site 1 <<
	.long	Lset27
Lset28 = Ltmp73-Ltmp72                  ##   Call between Ltmp72 and Ltmp73
	.long	Lset28
Lset29 = Ltmp95-Lfunc_begin4            ##     jumps to Ltmp95
	.long	Lset29
	.byte	5                       ##   On action: 3
Lset30 = Ltmp74-Lfunc_begin4            ## >> Call Site 2 <<
	.long	Lset30
Lset31 = Ltmp75-Ltmp74                  ##   Call between Ltmp74 and Ltmp75
	.long	Lset31
Lset32 = Ltmp90-Lfunc_begin4            ##     jumps to Ltmp90
	.long	Lset32
	.byte	5                       ##   On action: 3
Lset33 = Ltmp76-Lfunc_begin4            ## >> Call Site 3 <<
	.long	Lset33
Lset34 = Ltmp79-Ltmp76                  ##   Call between Ltmp76 and Ltmp79
	.long	Lset34
Lset35 = Ltmp80-Lfunc_begin4            ##     jumps to Ltmp80
	.long	Lset35
	.byte	3                       ##   On action: 2
Lset36 = Ltmp81-Lfunc_begin4            ## >> Call Site 4 <<
	.long	Lset36
Lset37 = Ltmp82-Ltmp81                  ##   Call between Ltmp81 and Ltmp82
	.long	Lset37
Lset38 = Ltmp83-Lfunc_begin4            ##     jumps to Ltmp83
	.long	Lset38
	.byte	7                       ##   On action: 4
Lset39 = Ltmp84-Lfunc_begin4            ## >> Call Site 5 <<
	.long	Lset39
Lset40 = Ltmp89-Ltmp84                  ##   Call between Ltmp84 and Ltmp89
	.long	Lset40
Lset41 = Ltmp90-Lfunc_begin4            ##     jumps to Ltmp90
	.long	Lset41
	.byte	5                       ##   On action: 3
Lset42 = Ltmp91-Lfunc_begin4            ## >> Call Site 6 <<
	.long	Lset42
Lset43 = Ltmp92-Ltmp91                  ##   Call between Ltmp91 and Ltmp92
	.long	Lset43
Lset44 = Ltmp101-Lfunc_begin4           ##     jumps to Ltmp101
	.long	Lset44
	.byte	5                       ##   On action: 3
Lset45 = Ltmp93-Lfunc_begin4            ## >> Call Site 7 <<
	.long	Lset45
Lset46 = Ltmp94-Ltmp93                  ##   Call between Ltmp93 and Ltmp94
	.long	Lset46
Lset47 = Ltmp95-Lfunc_begin4            ##     jumps to Ltmp95
	.long	Lset47
	.byte	5                       ##   On action: 3
Lset48 = Ltmp94-Lfunc_begin4            ## >> Call Site 8 <<
	.long	Lset48
Lset49 = Ltmp96-Ltmp94                  ##   Call between Ltmp94 and Ltmp96
	.long	Lset49
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset50 = Ltmp96-Lfunc_begin4            ## >> Call Site 9 <<
	.long	Lset50
Lset51 = Ltmp97-Ltmp96                  ##   Call between Ltmp96 and Ltmp97
	.long	Lset51
Lset52 = Ltmp98-Lfunc_begin4            ##     jumps to Ltmp98
	.long	Lset52
	.byte	0                       ##   On action: cleanup
Lset53 = Ltmp97-Lfunc_begin4            ## >> Call Site 10 <<
	.long	Lset53
Lset54 = Ltmp99-Ltmp97                  ##   Call between Ltmp97 and Ltmp99
	.long	Lset54
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset55 = Ltmp99-Lfunc_begin4            ## >> Call Site 11 <<
	.long	Lset55
Lset56 = Ltmp100-Ltmp99                 ##   Call between Ltmp99 and Ltmp100
	.long	Lset56
Lset57 = Ltmp101-Lfunc_begin4           ##     jumps to Ltmp101
	.long	Lset57
	.byte	5                       ##   On action: 3
Lset58 = Ltmp100-Lfunc_begin4           ## >> Call Site 12 <<
	.long	Lset58
Lset59 = Lfunc_end4-Ltmp100             ##   Call between Ltmp100 and Lfunc_end4
	.long	Lset59
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.byte	0                       ## >> Action Record 1 <<
                                        ##   Cleanup
	.byte	0                       ##   No further actions
	.byte	1                       ## >> Action Record 2 <<
                                        ##   Catch TypeInfo 1
	.byte	125                     ##   Continue to action 1
	.byte	1                       ## >> Action Record 3 <<
                                        ##   Catch TypeInfo 1
	.byte	0                       ##   No further actions
	.byte	1                       ## >> Action Record 4 <<
                                        ##   Catch TypeInfo 1
	.byte	125                     ##   Continue to action 3
                                        ## >> Catch TypeInfos <<
	.long	0                       ## TypeInfo 1
	.p2align	2

	.section	__TEXT,__text,regular,pure_instructions
	.private_extern	__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_
	.globl	__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_
	.weak_definition	__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_
	.p2align	4, 0x90
__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_: ## @_ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_
Lfunc_begin5:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception5
## BB#0:
	push	rbp
Ltmp111:
	.cfi_def_cfa_offset 16
Ltmp112:
	.cfi_offset rbp, -16
	mov	rbp, rsp
Ltmp113:
	.cfi_def_cfa_register rbp
	sub	rsp, 736
	mov	al, r9b
	lea	r10, [rbp - 552]
	lea	r11, [rbp - 488]
	mov	qword ptr [rbp - 504], rdi
	mov	qword ptr [rbp - 512], rsi
	mov	qword ptr [rbp - 520], rdx
	mov	qword ptr [rbp - 528], rcx
	mov	qword ptr [rbp - 536], r8
	mov	byte ptr [rbp - 537], al
	mov	rcx, qword ptr [rbp - 504]
	mov	qword ptr [rbp - 472], r11
	mov	qword ptr [rbp - 480], -1
	mov	rdx, qword ptr [rbp - 472]
	mov	rsi, qword ptr [rbp - 480]
	mov	qword ptr [rbp - 456], rdx
	mov	qword ptr [rbp - 464], rsi
	mov	rdx, qword ptr [rbp - 456]
	mov	qword ptr [rdx], 0
	mov	rdx, qword ptr [rbp - 488]
	mov	qword ptr [rbp - 552], rdx
	mov	qword ptr [rbp - 448], r10
	cmp	rcx, 0
	jne	LBB20_2
## BB#1:
	mov	rax, qword ptr [rbp - 504]
	mov	qword ptr [rbp - 496], rax
	jmp	LBB20_29
LBB20_2:
	mov	rax, qword ptr [rbp - 528]
	mov	rcx, qword ptr [rbp - 512]
	sub	rax, rcx
	mov	qword ptr [rbp - 560], rax
	mov	rax, qword ptr [rbp - 536]
	mov	qword ptr [rbp - 344], rax
	mov	rax, qword ptr [rbp - 344]
	mov	rax, qword ptr [rax + 24]
	mov	qword ptr [rbp - 568], rax
	mov	rax, qword ptr [rbp - 568]
	cmp	rax, qword ptr [rbp - 560]
	jle	LBB20_4
## BB#3:
	mov	rax, qword ptr [rbp - 560]
	mov	rcx, qword ptr [rbp - 568]
	sub	rcx, rax
	mov	qword ptr [rbp - 568], rcx
	jmp	LBB20_5
LBB20_4:
	mov	qword ptr [rbp - 568], 0
LBB20_5:
	mov	rax, qword ptr [rbp - 520]
	mov	rcx, qword ptr [rbp - 512]
	sub	rax, rcx
	mov	qword ptr [rbp - 576], rax
	cmp	qword ptr [rbp - 576], 0
	jle	LBB20_9
## BB#6:
	mov	rax, qword ptr [rbp - 504]
	mov	rcx, qword ptr [rbp - 512]
	mov	rdx, qword ptr [rbp - 576]
	mov	qword ptr [rbp - 248], rax
	mov	qword ptr [rbp - 256], rcx
	mov	qword ptr [rbp - 264], rdx
	mov	rax, qword ptr [rbp - 248]
	mov	rcx, qword ptr [rax]
	mov	rcx, qword ptr [rcx + 96]
	mov	rsi, qword ptr [rbp - 256]
	mov	rdx, qword ptr [rbp - 264]
	mov	rdi, rax
	call	rcx
	cmp	rax, qword ptr [rbp - 576]
	je	LBB20_8
## BB#7:
	lea	rax, [rbp - 584]
	lea	rcx, [rbp - 240]
	mov	qword ptr [rbp - 224], rcx
	mov	qword ptr [rbp - 232], -1
	mov	rcx, qword ptr [rbp - 224]
	mov	rdx, qword ptr [rbp - 232]
	mov	qword ptr [rbp - 208], rcx
	mov	qword ptr [rbp - 216], rdx
	mov	rcx, qword ptr [rbp - 208]
	mov	qword ptr [rcx], 0
	mov	rcx, qword ptr [rbp - 240]
	mov	qword ptr [rbp - 584], rcx
	mov	qword ptr [rbp - 8], rax
	mov	qword ptr [rbp - 504], 0
	mov	rax, qword ptr [rbp - 504]
	mov	qword ptr [rbp - 496], rax
	jmp	LBB20_29
LBB20_8:
	jmp	LBB20_9
LBB20_9:
	cmp	qword ptr [rbp - 568], 0
	jle	LBB20_24
## BB#10:
	xor	esi, esi
	mov	eax, 24
	mov	edx, eax
	lea	rcx, [rbp - 608]
	mov	rdi, qword ptr [rbp - 568]
	mov	r8b, byte ptr [rbp - 537]
	mov	qword ptr [rbp - 72], rcx
	mov	qword ptr [rbp - 80], rdi
	mov	byte ptr [rbp - 81], r8b
	mov	rcx, qword ptr [rbp - 72]
	mov	rdi, qword ptr [rbp - 80]
	mov	r8b, byte ptr [rbp - 81]
	mov	qword ptr [rbp - 48], rcx
	mov	qword ptr [rbp - 56], rdi
	mov	byte ptr [rbp - 57], r8b
	mov	rcx, qword ptr [rbp - 48]
	mov	qword ptr [rbp - 40], rcx
	mov	rdi, qword ptr [rbp - 40]
	mov	qword ptr [rbp - 32], rdi
	mov	rdi, qword ptr [rbp - 32]
	mov	qword ptr [rbp - 24], rdi
	mov	rdi, qword ptr [rbp - 24]
	mov	r9, rdi
	mov	qword ptr [rbp - 16], r9
	mov	qword ptr [rbp - 656], rcx ## 8-byte Spill
	call	_memset
	mov	rsi, qword ptr [rbp - 56]
	mov	rdi, qword ptr [rbp - 656] ## 8-byte Reload
	movsx	edx, byte ptr [rbp - 57]
	call	__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6__initEmc
	lea	rcx, [rbp - 608]
	mov	rsi, qword ptr [rbp - 504]
	mov	qword ptr [rbp - 200], rcx
	mov	rcx, qword ptr [rbp - 200]
	mov	qword ptr [rbp - 192], rcx
	mov	rcx, qword ptr [rbp - 192]
	mov	qword ptr [rbp - 184], rcx
	mov	rdi, qword ptr [rbp - 184]
	mov	qword ptr [rbp - 176], rdi
	mov	rdi, qword ptr [rbp - 176]
	mov	qword ptr [rbp - 168], rdi
	mov	rdi, qword ptr [rbp - 168]
	movzx	eax, byte ptr [rdi]
	and	eax, 1
	cmp	eax, 0
	mov	qword ptr [rbp - 664], rsi ## 8-byte Spill
	mov	qword ptr [rbp - 672], rcx ## 8-byte Spill
	je	LBB20_12
## BB#11:
	mov	rax, qword ptr [rbp - 672] ## 8-byte Reload
	mov	qword ptr [rbp - 120], rax
	mov	rcx, qword ptr [rbp - 120]
	mov	qword ptr [rbp - 112], rcx
	mov	rcx, qword ptr [rbp - 112]
	mov	qword ptr [rbp - 104], rcx
	mov	rcx, qword ptr [rbp - 104]
	mov	rcx, qword ptr [rcx + 16]
	mov	qword ptr [rbp - 680], rcx ## 8-byte Spill
	jmp	LBB20_13
LBB20_12:
	mov	rax, qword ptr [rbp - 672] ## 8-byte Reload
	mov	qword ptr [rbp - 160], rax
	mov	rcx, qword ptr [rbp - 160]
	mov	qword ptr [rbp - 152], rcx
	mov	rcx, qword ptr [rbp - 152]
	mov	qword ptr [rbp - 144], rcx
	mov	rcx, qword ptr [rbp - 144]
	add	rcx, 1
	mov	qword ptr [rbp - 136], rcx
	mov	rcx, qword ptr [rbp - 136]
	mov	qword ptr [rbp - 128], rcx
	mov	rcx, qword ptr [rbp - 128]
	mov	qword ptr [rbp - 680], rcx ## 8-byte Spill
LBB20_13:
	mov	rax, qword ptr [rbp - 680] ## 8-byte Reload
	mov	qword ptr [rbp - 96], rax
	mov	rcx, qword ptr [rbp - 568]
	mov	rdx, qword ptr [rbp - 664] ## 8-byte Reload
	mov	qword ptr [rbp - 272], rdx
	mov	qword ptr [rbp - 280], rax
	mov	qword ptr [rbp - 288], rcx
	mov	rax, qword ptr [rbp - 272]
	mov	rsi, qword ptr [rax]
	mov	rsi, qword ptr [rsi + 96]
	mov	rdi, qword ptr [rbp - 280]
Ltmp105:
	mov	qword ptr [rbp - 688], rdi ## 8-byte Spill
	mov	rdi, rax
	mov	rax, qword ptr [rbp - 688] ## 8-byte Reload
	mov	qword ptr [rbp - 696], rsi ## 8-byte Spill
	mov	rsi, rax
	mov	rdx, rcx
	mov	rcx, qword ptr [rbp - 696] ## 8-byte Reload
	call	rcx
Ltmp106:
	mov	qword ptr [rbp - 704], rax ## 8-byte Spill
	jmp	LBB20_14
LBB20_14:
	jmp	LBB20_15
LBB20_15:
	mov	rax, qword ptr [rbp - 704] ## 8-byte Reload
	cmp	rax, qword ptr [rbp - 568]
	je	LBB20_20
## BB#16:
	lea	rax, [rbp - 328]
	mov	qword ptr [rbp - 312], rax
	mov	qword ptr [rbp - 320], -1
	mov	rax, qword ptr [rbp - 312]
	mov	rcx, qword ptr [rbp - 320]
	mov	qword ptr [rbp - 296], rax
	mov	qword ptr [rbp - 304], rcx
	mov	rax, qword ptr [rbp - 296]
	mov	qword ptr [rax], 0
	mov	rax, qword ptr [rbp - 328]
	mov	qword ptr [rbp - 712], rax ## 8-byte Spill
## BB#17:
	lea	rax, [rbp - 632]
	mov	rcx, qword ptr [rbp - 712] ## 8-byte Reload
	mov	qword ptr [rbp - 632], rcx
	mov	qword ptr [rbp - 336], rax
## BB#18:
	mov	qword ptr [rbp - 504], 0
	mov	rax, qword ptr [rbp - 504]
	mov	qword ptr [rbp - 496], rax
	mov	dword ptr [rbp - 636], 1
	jmp	LBB20_21
LBB20_19:
Ltmp107:
	mov	ecx, edx
	mov	qword ptr [rbp - 616], rax
	mov	dword ptr [rbp - 620], ecx
Ltmp108:
	lea	rdi, [rbp - 608]
	call	__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev
Ltmp109:
	jmp	LBB20_23
LBB20_20:
	mov	dword ptr [rbp - 636], 0
LBB20_21:
	lea	rdi, [rbp - 608]
	call	__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev
	mov	eax, dword ptr [rbp - 636]
	test	eax, eax
	mov	dword ptr [rbp - 716], eax ## 4-byte Spill
	je	LBB20_22
	jmp	LBB20_33
LBB20_33:
	mov	eax, dword ptr [rbp - 716] ## 4-byte Reload
	sub	eax, 1
	mov	dword ptr [rbp - 720], eax ## 4-byte Spill
	je	LBB20_29
	jmp	LBB20_32
LBB20_22:
	jmp	LBB20_24
LBB20_23:
	jmp	LBB20_30
LBB20_24:
	mov	rax, qword ptr [rbp - 528]
	mov	rcx, qword ptr [rbp - 520]
	sub	rax, rcx
	mov	qword ptr [rbp - 576], rax
	cmp	qword ptr [rbp - 576], 0
	jle	LBB20_28
## BB#25:
	mov	rax, qword ptr [rbp - 504]
	mov	rcx, qword ptr [rbp - 520]
	mov	rdx, qword ptr [rbp - 576]
	mov	qword ptr [rbp - 352], rax
	mov	qword ptr [rbp - 360], rcx
	mov	qword ptr [rbp - 368], rdx
	mov	rax, qword ptr [rbp - 352]
	mov	rcx, qword ptr [rax]
	mov	rcx, qword ptr [rcx + 96]
	mov	rsi, qword ptr [rbp - 360]
	mov	rdx, qword ptr [rbp - 368]
	mov	rdi, rax
	call	rcx
	cmp	rax, qword ptr [rbp - 576]
	je	LBB20_27
## BB#26:
	lea	rax, [rbp - 648]
	lea	rcx, [rbp - 408]
	mov	qword ptr [rbp - 392], rcx
	mov	qword ptr [rbp - 400], -1
	mov	rcx, qword ptr [rbp - 392]
	mov	rdx, qword ptr [rbp - 400]
	mov	qword ptr [rbp - 376], rcx
	mov	qword ptr [rbp - 384], rdx
	mov	rcx, qword ptr [rbp - 376]
	mov	qword ptr [rcx], 0
	mov	rcx, qword ptr [rbp - 408]
	mov	qword ptr [rbp - 648], rcx
	mov	qword ptr [rbp - 416], rax
	mov	qword ptr [rbp - 504], 0
	mov	rax, qword ptr [rbp - 504]
	mov	qword ptr [rbp - 496], rax
	jmp	LBB20_29
LBB20_27:
	jmp	LBB20_28
LBB20_28:
	mov	rax, qword ptr [rbp - 536]
	mov	qword ptr [rbp - 424], rax
	mov	qword ptr [rbp - 432], 0
	mov	rax, qword ptr [rbp - 424]
	mov	rcx, qword ptr [rax + 24]
	mov	qword ptr [rbp - 440], rcx
	mov	rcx, qword ptr [rbp - 432]
	mov	qword ptr [rax + 24], rcx
	mov	rax, qword ptr [rbp - 504]
	mov	qword ptr [rbp - 496], rax
LBB20_29:
	mov	rax, qword ptr [rbp - 496]
	add	rsp, 736
	pop	rbp
	ret
LBB20_30:
	mov	rdi, qword ptr [rbp - 616]
	call	__Unwind_Resume
LBB20_31:
Ltmp110:
	mov	ecx, edx
	mov	rdi, rax
	mov	dword ptr [rbp - 724], ecx ## 4-byte Spill
	call	___clang_call_terminate
LBB20_32:
Lfunc_end5:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table20:
Lexception5:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.asciz	"\274"                  ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	52                      ## Call site table length
Lset60 = Lfunc_begin5-Lfunc_begin5      ## >> Call Site 1 <<
	.long	Lset60
Lset61 = Ltmp105-Lfunc_begin5           ##   Call between Lfunc_begin5 and Ltmp105
	.long	Lset61
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset62 = Ltmp105-Lfunc_begin5           ## >> Call Site 2 <<
	.long	Lset62
Lset63 = Ltmp106-Ltmp105                ##   Call between Ltmp105 and Ltmp106
	.long	Lset63
Lset64 = Ltmp107-Lfunc_begin5           ##     jumps to Ltmp107
	.long	Lset64
	.byte	0                       ##   On action: cleanup
Lset65 = Ltmp108-Lfunc_begin5           ## >> Call Site 3 <<
	.long	Lset65
Lset66 = Ltmp109-Ltmp108                ##   Call between Ltmp108 and Ltmp109
	.long	Lset66
Lset67 = Ltmp110-Lfunc_begin5           ##     jumps to Ltmp110
	.long	Lset67
	.byte	1                       ##   On action: 1
Lset68 = Ltmp109-Lfunc_begin5           ## >> Call Site 4 <<
	.long	Lset68
Lset69 = Lfunc_end5-Ltmp109             ##   Call between Ltmp109 and Lfunc_end5
	.long	Lset69
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.byte	1                       ## >> Action Record 1 <<
                                        ##   Catch TypeInfo 1
	.byte	0                       ##   No further actions
                                        ## >> Catch TypeInfos <<
	.long	0                       ## TypeInfo 1
	.p2align	2

	.section	__TEXT,__text,regular,pure_instructions
	.private_extern	___clang_call_terminate
	.globl	___clang_call_terminate
	.weak_definition	___clang_call_terminate
	.p2align	4, 0x90
___clang_call_terminate:                ## @__clang_call_terminate
## BB#0:
	push	rax
	call	___cxa_begin_catch
	mov	qword ptr [rsp], rax    ## 8-byte Spill
	call	__ZSt9terminatev

	.globl	__ZNSt3__111char_traitsIcE11eq_int_typeEii
	.weak_definition	__ZNSt3__111char_traitsIcE11eq_int_typeEii
	.p2align	4, 0x90
__ZNSt3__111char_traitsIcE11eq_int_typeEii: ## @_ZNSt3__111char_traitsIcE11eq_int_typeEii
	.cfi_startproc
## BB#0:
	push	rbp
Ltmp114:
	.cfi_def_cfa_offset 16
Ltmp115:
	.cfi_offset rbp, -16
	mov	rbp, rsp
Ltmp116:
	.cfi_def_cfa_register rbp
	mov	dword ptr [rbp - 4], edi
	mov	dword ptr [rbp - 8], esi
	mov	esi, dword ptr [rbp - 4]
	cmp	esi, dword ptr [rbp - 8]
	sete	al
	and	al, 1
	movzx	eax, al
	pop	rbp
	ret
	.cfi_endproc

	.globl	__ZNSt3__111char_traitsIcE3eofEv
	.weak_definition	__ZNSt3__111char_traitsIcE3eofEv
	.p2align	4, 0x90
__ZNSt3__111char_traitsIcE3eofEv:       ## @_ZNSt3__111char_traitsIcE3eofEv
	.cfi_startproc
## BB#0:
	push	rbp
Ltmp117:
	.cfi_def_cfa_offset 16
Ltmp118:
	.cfi_offset rbp, -16
	mov	rbp, rsp
Ltmp119:
	.cfi_def_cfa_register rbp
	mov	eax, 4294967295
	pop	rbp
	ret
	.cfi_endproc

	.section	__DATA,__data
	.globl	__ZTV9Rectangle         ## @_ZTV9Rectangle
	.weak_def_can_be_hidden	__ZTV9Rectangle
	.p2align	3
__ZTV9Rectangle:
	.quad	0
	.quad	__ZTI9Rectangle
	.quad	__ZN9RectangleD1Ev
	.quad	__ZN9RectangleD0Ev
	.quad	__ZN9Rectangle4areaEv

	.section	__TEXT,__const
	.globl	__ZTS9Rectangle         ## @_ZTS9Rectangle
	.weak_definition	__ZTS9Rectangle
__ZTS9Rectangle:
	.asciz	"9Rectangle"

	.globl	__ZTS7Polygon           ## @_ZTS7Polygon
	.weak_definition	__ZTS7Polygon
__ZTS7Polygon:
	.asciz	"7Polygon"

	.section	__DATA,__data
	.globl	__ZTI7Polygon           ## @_ZTI7Polygon
	.weak_definition	__ZTI7Polygon
	.p2align	3
__ZTI7Polygon:
	.quad	__ZTVN10__cxxabiv117__class_type_infoE+16
	.quad	__ZTS7Polygon

	.globl	__ZTI9Rectangle         ## @_ZTI9Rectangle
	.weak_definition	__ZTI9Rectangle
	.p2align	4
__ZTI9Rectangle:
	.quad	__ZTVN10__cxxabiv120__si_class_type_infoE+16
	.quad	__ZTS9Rectangle
	.quad	__ZTI7Polygon

	.globl	__ZTV7Polygon           ## @_ZTV7Polygon
	.weak_def_can_be_hidden	__ZTV7Polygon
	.p2align	3
__ZTV7Polygon:
	.quad	0
	.quad	__ZTI7Polygon
	.quad	__ZN7PolygonD1Ev
	.quad	__ZN7PolygonD0Ev
	.quad	___cxa_pure_virtual

	.globl	__ZTV8Triangle          ## @_ZTV8Triangle
	.weak_def_can_be_hidden	__ZTV8Triangle
	.p2align	3
__ZTV8Triangle:
	.quad	0
	.quad	__ZTI8Triangle
	.quad	__ZN8TriangleD1Ev
	.quad	__ZN8TriangleD0Ev
	.quad	__ZN8Triangle4areaEv

	.section	__TEXT,__const
	.globl	__ZTS8Triangle          ## @_ZTS8Triangle
	.weak_definition	__ZTS8Triangle
__ZTS8Triangle:
	.asciz	"8Triangle"

	.section	__DATA,__data
	.globl	__ZTI8Triangle          ## @_ZTI8Triangle
	.weak_definition	__ZTI8Triangle
	.p2align	4
__ZTI8Triangle:
	.quad	__ZTVN10__cxxabiv120__si_class_type_infoE+16
	.quad	__ZTS8Triangle
	.quad	__ZTI7Polygon


.subsections_via_symbols

    .section	__TEXT,__text,regular,pure_instructions
    .macosx_version_min 10, 11
    .intel_syntax noprefix
    .globl	_main
    .align	4, 0x90
_main:                                  ## @main
Lfunc_begin0:
    .cfi_startproc
    .cfi_personality 155, ___gxx_personality_v0
    .cfi_lsda 16, Lexception0
## BB#0:
    push	rbp
Ltmp5:
    .cfi_def_cfa_offset 16
Ltmp6:
    .cfi_offset rbp, -16
    mov	rbp, rsp
Ltmp7:
    .cfi_def_cfa_register rbp
    sub	rsp, 544
    mov	rdi, qword ptr [rip + __ZNSt3__14coutE@GOTPCREL]
    lea	rax, [rbp - 424]
    mov	dword ptr [rbp - 420], 0
    mov	dword ptr [rbp - 424], 1
    mov	qword ptr [rbp - 432], rax
    mov	rax, qword ptr [rbp - 432]
    mov	esi, dword ptr [rax]
    call	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEi
    lea	rdi, [rip + __ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_]
    mov	qword ptr [rbp - 408], rax
    mov	qword ptr [rbp - 416], rdi
    mov	rdi, qword ptr [rbp - 408]
    call	qword ptr [rbp - 416]
    mov	rdi, qword ptr [rip + __ZNSt3__14coutE@GOTPCREL]
    mov	rcx, qword ptr [rbp - 432]
    mov	dword ptr [rcx], 3
    mov	rcx, qword ptr [rbp - 432]
    mov	esi, dword ptr [rcx]
    mov	qword ptr [rbp - 472], rax ## 8-byte Spill
    call	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEi
    lea	rcx, [rip + __ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_]
    mov	qword ptr [rbp - 392], rax
    mov	qword ptr [rbp - 400], rcx
    mov	rdi, qword ptr [rbp - 392]
    call	qword ptr [rbp - 400]
    mov	rdi, qword ptr [rip + __ZNSt3__14coutE@GOTPCREL]
    mov	rcx, qword ptr [rbp - 432]
    mov	rsi, rcx
    mov	qword ptr [rbp - 480], rax ## 8-byte Spill
    call	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEPKv
    lea	rcx, [rip + __ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_]
    mov	qword ptr [rbp - 376], rax
    mov	qword ptr [rbp - 384], rcx
    mov	rdi, qword ptr [rbp - 376]
    call	qword ptr [rbp - 384]
    mov	edx, 4
    mov	edi, edx
    lea	rcx, [rbp - 436]
    mov	dword ptr [rbp - 436], 4
    mov	qword ptr [rbp - 368], rcx
    mov	qword ptr [rbp - 488], rax ## 8-byte Spill
    call	__Znwm
    lea	rcx, [rbp - 448]
    lea	rsi, [rbp - 272]
    lea	rdi, [rbp - 296]
    lea	r8, [rbp - 336]
    mov	r9, rax
    mov	r10, qword ptr [rbp - 368]
    mov	qword ptr [rbp - 360], r10
    mov	r10, qword ptr [rbp - 360]
    mov	edx, dword ptr [r10]
    mov	dword ptr [rax], edx
    mov	qword ptr [rbp - 344], rcx
    mov	qword ptr [rbp - 352], r9
    mov	rax, qword ptr [rbp - 344]
    mov	r9, qword ptr [rbp - 352]
    mov	qword ptr [rbp - 328], rax
    mov	qword ptr [rbp - 336], r9
    mov	rax, qword ptr [rbp - 328]
    mov	qword ptr [rbp - 320], r8
    mov	r8, qword ptr [rbp - 320]
    mov	r8, qword ptr [r8]
    mov	qword ptr [rbp - 304], rax
    mov	qword ptr [rbp - 312], r8
    mov	rax, qword ptr [rbp - 304]
    mov	r8, qword ptr [rbp - 312]
    mov	qword ptr [rbp - 288], rax
    mov	qword ptr [rbp - 296], r8
    mov	rax, qword ptr [rbp - 288]
    mov	qword ptr [rbp - 280], rdi
    mov	rdi, qword ptr [rbp - 280]
    mov	rdi, qword ptr [rdi]
    mov	qword ptr [rbp - 264], rax
    mov	qword ptr [rbp - 272], rdi
    mov	rax, qword ptr [rbp - 264]
    mov	qword ptr [rbp - 256], rsi
    mov	rsi, qword ptr [rbp - 256]
    mov	rsi, qword ptr [rsi]
    mov	qword ptr [rax], rsi
    mov	qword ptr [rbp - 248], rcx
    mov	rax, qword ptr [rbp - 248]
    mov	qword ptr [rbp - 240], rax
    mov	rax, qword ptr [rbp - 240]
    mov	qword ptr [rbp - 232], rax
    mov	rax, qword ptr [rbp - 232]
    mov	rax, qword ptr [rax]
    mov	qword ptr [rbp - 496], rax ## 8-byte Spill
## BB#1:
    mov	rax, qword ptr [rbp - 496] ## 8-byte Reload
    mov	esi, dword ptr [rax]
Ltmp0:
    mov	rdi, qword ptr [rip + __ZNSt3__14coutE@GOTPCREL]
    call	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEi
Ltmp1:
    mov	qword ptr [rbp - 504], rax ## 8-byte Spill
    jmp	LBB0_2
LBB0_2:
    mov	rax, qword ptr [rbp - 504] ## 8-byte Reload
    mov	qword ptr [rbp - 112], rax
    lea	rcx, [rip + __ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_]
    mov	qword ptr [rbp - 120], rcx
    mov	rdi, qword ptr [rbp - 112]
Ltmp2:
    call	rcx
Ltmp3:
    mov	qword ptr [rbp - 512], rax ## 8-byte Spill
    jmp	LBB0_3
LBB0_3:                                 ## %_ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEPFRS3_S4_E.exit
    jmp	LBB0_4
LBB0_4:
    lea	rax, [rbp - 448]
    mov	dword ptr [rbp - 420], 0
    mov	qword ptr [rbp - 104], rax
    mov	rax, qword ptr [rbp - 104]
    mov	qword ptr [rbp - 96], rax
    mov	rax, qword ptr [rbp - 96]
    mov	qword ptr [rbp - 72], rax
    mov	qword ptr [rbp - 80], 0
    mov	rax, qword ptr [rbp - 72]
    mov	qword ptr [rbp - 64], rax
    mov	rcx, qword ptr [rbp - 64]
    mov	qword ptr [rbp - 56], rcx
    mov	rcx, qword ptr [rbp - 56]
    mov	rcx, qword ptr [rcx]
    mov	qword ptr [rbp - 88], rcx
    mov	rcx, qword ptr [rbp - 80]
    mov	qword ptr [rbp - 32], rax
    mov	rdx, qword ptr [rbp - 32]
    mov	qword ptr [rbp - 24], rdx
    mov	rdx, qword ptr [rbp - 24]
    mov	qword ptr [rdx], rcx
    cmp	qword ptr [rbp - 88], 0
    mov	qword ptr [rbp - 520], rax ## 8-byte Spill
    je	LBB0_8
## BB#5:
    mov	rax, qword ptr [rbp - 520] ## 8-byte Reload
    mov	qword ptr [rbp - 16], rax
    mov	rcx, qword ptr [rbp - 16]
    mov	qword ptr [rbp - 8], rcx
    mov	rcx, qword ptr [rbp - 8]
    mov	rdx, qword ptr [rbp - 88]
    mov	qword ptr [rbp - 40], rcx
    mov	qword ptr [rbp - 48], rdx
    mov	rcx, qword ptr [rbp - 48]
    cmp	rcx, 0
    mov	qword ptr [rbp - 528], rcx ## 8-byte Spill
    je	LBB0_7
## BB#6:
    mov	rax, qword ptr [rbp - 528] ## 8-byte Reload
    mov	rdi, rax
    call	__ZdlPv
LBB0_7:                                 ## %_ZNKSt3__114default_deleteIiEclEPi.exit.i.i.i.2
    jmp	LBB0_8
LBB0_8:                                 ## %_ZNSt3__110unique_ptrIiNS_14default_deleteIiEEED1Ev.exit3
    mov	eax, dword ptr [rbp - 420]
    add	rsp, 544
    pop	rbp
    ret
LBB0_9:
Ltmp4:
    lea	rcx, [rbp - 448]
    mov	esi, edx
    mov	qword ptr [rbp - 456], rax
    mov	dword ptr [rbp - 460], esi
    mov	qword ptr [rbp - 224], rcx
    mov	rax, qword ptr [rbp - 224]
    mov	qword ptr [rbp - 216], rax
    mov	rax, qword ptr [rbp - 216]
    mov	qword ptr [rbp - 192], rax
    mov	qword ptr [rbp - 200], 0
    mov	rax, qword ptr [rbp - 192]
    mov	qword ptr [rbp - 184], rax
    mov	rcx, qword ptr [rbp - 184]
    mov	qword ptr [rbp - 176], rcx
    mov	rcx, qword ptr [rbp - 176]
    mov	rcx, qword ptr [rcx]
    mov	qword ptr [rbp - 208], rcx
    mov	rcx, qword ptr [rbp - 200]
    mov	qword ptr [rbp - 152], rax
    mov	rdx, qword ptr [rbp - 152]
    mov	qword ptr [rbp - 144], rdx
    mov	rdx, qword ptr [rbp - 144]
    mov	qword ptr [rdx], rcx
    cmp	qword ptr [rbp - 208], 0
    mov	qword ptr [rbp - 536], rax ## 8-byte Spill
    je	LBB0_13
## BB#10:
    mov	rax, qword ptr [rbp - 536] ## 8-byte Reload
    mov	qword ptr [rbp - 136], rax
    mov	rcx, qword ptr [rbp - 136]
    mov	qword ptr [rbp - 128], rcx
    mov	rcx, qword ptr [rbp - 128]
    mov	rdx, qword ptr [rbp - 208]
    mov	qword ptr [rbp - 160], rcx
    mov	qword ptr [rbp - 168], rdx
    mov	rcx, qword ptr [rbp - 168]
    cmp	rcx, 0
    mov	qword ptr [rbp - 544], rcx ## 8-byte Spill
    je	LBB0_12
## BB#11:
    mov	rax, qword ptr [rbp - 544] ## 8-byte Reload
    mov	rdi, rax
    call	__ZdlPv
LBB0_12:                                ## %_ZNKSt3__114default_deleteIiEclEPi.exit.i.i.i
    jmp	LBB0_13
LBB0_13:                                ## %_ZNSt3__110unique_ptrIiNS_14default_deleteIiEEED1Ev.exit
    jmp	LBB0_14
LBB0_14:
    mov	rdi, qword ptr [rbp - 456]
    call	__Unwind_Resume
Lfunc_end0:
    .cfi_endproc
    .section	__TEXT,__gcc_except_tab
    .align	2
GCC_except_table0:
Lexception0:
    .byte	255                     ## @LPStart Encoding = omit
    .byte	155                     ## @TType Encoding = indirect pcrel sdata4
    .byte	41                      ## @TType base offset
    .byte	3                       ## Call site Encoding = udata4
    .byte	39                      ## Call site table length
Lset0 = Lfunc_begin0-Lfunc_begin0       ## >> Call Site 1 <<
    .long	Lset0
Lset1 = Ltmp0-Lfunc_begin0              ##   Call between Lfunc_begin0 and Ltmp0
    .long	Lset1
    .long	0                       ##     has no landing pad
    .byte	0                       ##   On action: cleanup
Lset2 = Ltmp0-Lfunc_begin0              ## >> Call Site 2 <<
    .long	Lset2
Lset3 = Ltmp3-Ltmp0                     ##   Call between Ltmp0 and Ltmp3
    .long	Lset3
Lset4 = Ltmp4-Lfunc_begin0              ##     jumps to Ltmp4
    .long	Lset4
    .byte	0                       ##   On action: cleanup
Lset5 = Ltmp3-Lfunc_begin0              ## >> Call Site 3 <<
    .long	Lset5
Lset6 = Lfunc_end0-Ltmp3                ##   Call between Ltmp3 and Lfunc_end0
    .long	Lset6
    .long	0                       ##     has no landing pad
    .byte	0                       ##   On action: cleanup
    .align	2

    .section	__TEXT,__textcoal_nt,coalesced,pure_instructions
    .private_extern	__ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_
    .globl	__ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_
    .weak_definition	__ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_
    .align	4, 0x90
__ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_: ## @_ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_
Lfunc_begin1:
    .cfi_startproc
    .cfi_personality 155, ___gxx_personality_v0
    .cfi_lsda 16, Lexception1
## BB#0:
    push	rbp
Ltmp13:
    .cfi_def_cfa_offset 16
Ltmp14:
    .cfi_offset rbp, -16
    mov	rbp, rsp
Ltmp15:
    .cfi_def_cfa_register rbp
    sub	rsp, 144
    mov	qword ptr [rbp - 72], rdi
    mov	rax, rdi
    mov	rcx, qword ptr [rdi]
    mov	rcx, qword ptr [rcx - 24]
    add	rdi, rcx
    mov	qword ptr [rbp - 32], rdi
    mov	byte ptr [rbp - 33], 10
    mov	rsi, qword ptr [rbp - 32]
    lea	rcx, [rbp - 48]
    mov	rdi, rcx
    mov	qword ptr [rbp - 80], rax ## 8-byte Spill
    mov	qword ptr [rbp - 88], rcx ## 8-byte Spill
    call	__ZNKSt3__18ios_base6getlocEv
    mov	rax, qword ptr [rbp - 88] ## 8-byte Reload
    mov	qword ptr [rbp - 24], rax
Ltmp8:
    mov	rsi, qword ptr [rip + __ZNSt3__15ctypeIcE2idE@GOTPCREL]
    mov	rdi, rax
    call	__ZNKSt3__16locale9use_facetERNS0_2idE
Ltmp9:
    mov	qword ptr [rbp - 96], rax ## 8-byte Spill
    jmp	LBB1_1
LBB1_1:                                 ## %_ZNSt3__19use_facetINS_5ctypeIcEEEERKT_RKNS_6localeE.exit.i
    mov	al, byte ptr [rbp - 33]
    mov	rcx, qword ptr [rbp - 96] ## 8-byte Reload
    mov	qword ptr [rbp - 8], rcx
    mov	byte ptr [rbp - 9], al
    mov	rdx, qword ptr [rbp - 8]
    mov	rsi, qword ptr [rdx]
    mov	rsi, qword ptr [rsi + 56]
    movsx	edi, byte ptr [rbp - 9]
Ltmp10:
    mov	dword ptr [rbp - 100], edi ## 4-byte Spill
    mov	rdi, rdx
    mov	r8d, dword ptr [rbp - 100] ## 4-byte Reload
    mov	qword ptr [rbp - 112], rsi ## 8-byte Spill
    mov	esi, r8d
    mov	rdx, qword ptr [rbp - 112] ## 8-byte Reload
    call	rdx
Ltmp11:
    mov	byte ptr [rbp - 113], al ## 1-byte Spill
    jmp	LBB1_3
LBB1_2:
Ltmp12:
    lea	rdi, [rbp - 48]
    mov	ecx, edx
    mov	qword ptr [rbp - 56], rax
    mov	dword ptr [rbp - 60], ecx
    call	__ZNSt3__16localeD1Ev
    mov	rdi, qword ptr [rbp - 56]
    call	__Unwind_Resume
LBB1_3:                                 ## %_ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE5widenEc.exit
    lea	rdi, [rbp - 48]
    call	__ZNSt3__16localeD1Ev
    mov	rdi, qword ptr [rbp - 80] ## 8-byte Reload
    mov	al, byte ptr [rbp - 113] ## 1-byte Reload
    movsx	esi, al
    call	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEE3putEc
    mov	rdi, qword ptr [rbp - 72]
    mov	qword ptr [rbp - 128], rax ## 8-byte Spill
    call	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEE5flushEv
    mov	rdi, qword ptr [rbp - 72]
    mov	qword ptr [rbp - 136], rax ## 8-byte Spill
    mov	rax, rdi
    add	rsp, 144
    pop	rbp
    ret
Lfunc_end1:
    .cfi_endproc
    .section	__TEXT,__gcc_except_tab
    .align	2
GCC_except_table1:
Lexception1:
    .byte	255                     ## @LPStart Encoding = omit
    .byte	155                     ## @TType Encoding = indirect pcrel sdata4
    .byte	41                      ## @TType base offset
    .byte	3                       ## Call site Encoding = udata4
    .byte	39                      ## Call site table length
Lset7 = Lfunc_begin1-Lfunc_begin1       ## >> Call Site 1 <<
    .long	Lset7
Lset8 = Ltmp8-Lfunc_begin1              ##   Call between Lfunc_begin1 and Ltmp8
    .long	Lset8
    .long	0                       ##     has no landing pad
    .byte	0                       ##   On action: cleanup
Lset9 = Ltmp8-Lfunc_begin1              ## >> Call Site 2 <<
    .long	Lset9
Lset10 = Ltmp11-Ltmp8                   ##   Call between Ltmp8 and Ltmp11
    .long	Lset10
Lset11 = Ltmp12-Lfunc_begin1            ##     jumps to Ltmp12
    .long	Lset11
    .byte	0                       ##   On action: cleanup
Lset12 = Ltmp11-Lfunc_begin1            ## >> Call Site 3 <<
    .long	Lset12
Lset13 = Lfunc_end1-Ltmp11              ##   Call between Ltmp11 and Lfunc_end1
    .long	Lset13
    .long	0                       ##     has no landing pad
    .byte	0                       ##   On action: cleanup
    .align	2

    .section	__TEXT,__textcoal_nt,coalesced,pure_instructions
    .private_extern	___clang_call_terminate
    .globl	___clang_call_terminate
    .weak_def_can_be_hidden	___clang_call_terminate
    .align	4, 0x90
___clang_call_terminate:                ## @__clang_call_terminate
## BB#0:
    push	rax
    call	___cxa_begin_catch
    mov	qword ptr [rsp], rax    ## 8-byte Spill
    call	__ZSt9terminatev


.subsections_via_symbols

	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 11, 0	sdk_version 12, 1
	.intel_syntax noprefix
	.globl	_Init                           ## -- Begin function Init
	.p2align	4, 0x90
_Init:                                  ## @Init
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	mov	qword ptr [rbp - 8], rdi
	mov	dword ptr [rbp - 12], 0
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	cmp	dword ptr [rbp - 12], 70
	jge	LBB0_4
## %bb.2:                               ##   in Loop: Header=BB0_1 Depth=1
	mov	rax, qword ptr [rbp - 8]
	movsxd	rcx, dword ptr [rbp - 12]
	mov	byte ptr [rax + rcx], 0
## %bb.3:                               ##   in Loop: Header=BB0_1 Depth=1
	mov	eax, dword ptr [rbp - 12]
	add	eax, 1
	mov	dword ptr [rbp - 12], eax
	jmp	LBB0_1
LBB0_4:
	mov	rax, qword ptr [rbp - 8]
	mov	dword ptr [rax + 72], 0
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function
	.globl	__print_number                  ## -- Begin function _print_number
	.p2align	4, 0x90
__print_number:                         ## @_print_number
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	sub	rsp, 16
	mov	qword ptr [rbp - 8], rdi
	mov	rax, qword ptr [rbp - 8]
	mov	eax, dword ptr [rax + 72]
	sub	eax, 1
	mov	dword ptr [rbp - 12], eax
LBB1_1:                                 ## =>This Inner Loop Header: Depth=1
	cmp	dword ptr [rbp - 12], 0
	jl	LBB1_4
## %bb.2:                               ##   in Loop: Header=BB1_1 Depth=1
	mov	rax, qword ptr [rbp - 8]
	movsxd	rcx, dword ptr [rbp - 12]
	movzx	esi, byte ptr [rax + rcx]
	lea	rdi, [rip + L_.str]
	mov	al, 0
	call	_printf
## %bb.3:                               ##   in Loop: Header=BB1_1 Depth=1
	mov	eax, dword ptr [rbp - 12]
	add	eax, -1
	mov	dword ptr [rbp - 12], eax
	jmp	LBB1_1
LBB1_4:
	lea	rdi, [rip + L_.str.1]
	mov	al, 0
	call	_printf
	add	rsp, 16
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function
	.globl	__max                           ## -- Begin function _max
	.p2align	4, 0x90
__max:                                  ## @_max
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	mov	dword ptr [rbp - 8], edi
	mov	dword ptr [rbp - 12], esi
	mov	eax, dword ptr [rbp - 8]
	cmp	eax, dword ptr [rbp - 12]
	jle	LBB2_2
## %bb.1:
	mov	eax, dword ptr [rbp - 8]
	mov	dword ptr [rbp - 4], eax
	jmp	LBB2_3
LBB2_2:
	mov	eax, dword ptr [rbp - 12]
	mov	dword ptr [rbp - 4], eax
LBB2_3:
	mov	eax, dword ptr [rbp - 4]
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function
	.globl	__min                           ## -- Begin function _min
	.p2align	4, 0x90
__min:                                  ## @_min
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	mov	dword ptr [rbp - 8], edi
	mov	dword ptr [rbp - 12], esi
	mov	eax, dword ptr [rbp - 8]
	cmp	eax, dword ptr [rbp - 12]
	jle	LBB3_2
## %bb.1:
	mov	eax, dword ptr [rbp - 12]
	mov	dword ptr [rbp - 4], eax
	jmp	LBB3_3
LBB3_2:
	mov	eax, dword ptr [rbp - 8]
	mov	dword ptr [rbp - 4], eax
LBB3_3:
	mov	eax, dword ptr [rbp - 4]
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function
	.globl	__add                           ## -- Begin function _add
	.p2align	4, 0x90
__add:                                  ## @_add
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	sub	rsp, 240
	mov	rax, qword ptr [rip + ___stack_chk_guard@GOTPCREL]
	mov	rax, qword ptr [rax]
	mov	qword ptr [rbp - 8], rax
	mov	qword ptr [rbp - 176], rdi
	mov	qword ptr [rbp - 184], rsi
	mov	qword ptr [rbp - 192], rdx
	mov	dword ptr [rbp - 196], ecx
	mov	dword ptr [rbp - 200], r8d
	mov	rsi, qword ptr [rbp - 184]
	lea	rdi, [rbp - 88]
	call	__copy
	mov	rsi, qword ptr [rbp - 176]
	lea	rdi, [rbp - 168]
	call	__copy
	mov	rdi, qword ptr [rbp - 192]
	call	_Init
	mov	word ptr [rbp - 202], 0
	mov	edi, dword ptr [rbp - 96]
	mov	esi, dword ptr [rbp - 16]
	add	esi, dword ptr [rbp - 196]
	call	__max
	mov	edi, eax
	mov	esi, 70
	call	__min
	mov	edx, eax
	lea	rax, [rbp - 88]
	lea	rcx, [rbp - 168]
	mov	dword ptr [rbp - 208], edx
	mov	qword ptr [rbp - 216], rcx
	mov	qword ptr [rbp - 224], rax
	mov	rax, qword ptr [rbp - 192]
	mov	qword ptr [rbp - 232], rax
	mov	ecx, dword ptr [rbp - 208]
	mov	rax, qword ptr [rbp - 192]
	mov	dword ptr [rax + 72], ecx
	mov	dword ptr [rbp - 236], 0
LBB4_1:                                 ## =>This Inner Loop Header: Depth=1
	mov	eax, dword ptr [rbp - 236]
	cmp	eax, dword ptr [rbp - 208]
	jge	LBB4_7
## %bb.2:                               ##   in Loop: Header=BB4_1 Depth=1
	mov	eax, dword ptr [rbp - 236]
	sub	eax, dword ptr [rbp - 196]
	cmp	eax, 0
	jge	LBB4_4
## %bb.3:                               ##   in Loop: Header=BB4_1 Depth=1
	mov	rax, qword ptr [rbp - 216]
	movsxd	rcx, dword ptr [rbp - 236]
	movzx	eax, byte ptr [rax + rcx]
                                        ## kill: def $ax killed $ax killed $eax
	mov	word ptr [rbp - 204], ax
	jmp	LBB4_5
LBB4_4:                                 ##   in Loop: Header=BB4_1 Depth=1
	mov	rax, qword ptr [rbp - 216]
	movsxd	rcx, dword ptr [rbp - 236]
	movzx	eax, byte ptr [rax + rcx]
                                        ## kill: def $ax killed $ax killed $eax
	movzx	eax, ax
	mov	rcx, qword ptr [rbp - 224]
	mov	edx, dword ptr [rbp - 236]
	sub	edx, dword ptr [rbp - 196]
	movsxd	rdx, edx
	movzx	edx, byte ptr [rcx + rdx]
	mov	ecx, dword ptr [rbp - 200]
                                        ## kill: def $cl killed $ecx
	shl	edx, cl
	mov	ecx, edx
                                        ## kill: def $cx killed $cx killed $ecx
	movzx	ecx, cx
	add	eax, ecx
	movzx	ecx, word ptr [rbp - 202]
	add	eax, ecx
                                        ## kill: def $ax killed $ax killed $eax
	mov	word ptr [rbp - 204], ax
LBB4_5:                                 ##   in Loop: Header=BB4_1 Depth=1
	mov	ax, word ptr [rbp - 204]
	mov	dl, al
	mov	rax, qword ptr [rbp - 232]
	movsxd	rcx, dword ptr [rbp - 236]
	mov	byte ptr [rax + rcx], dl
	movzx	eax, word ptr [rbp - 204]
	and	eax, -256
	sar	eax, 8
                                        ## kill: def $ax killed $ax killed $eax
	mov	word ptr [rbp - 202], ax
## %bb.6:                               ##   in Loop: Header=BB4_1 Depth=1
	mov	eax, dword ptr [rbp - 236]
	add	eax, 1
	mov	dword ptr [rbp - 236], eax
	jmp	LBB4_1
LBB4_7:
	cmp	dword ptr [rbp - 208], 70
	jge	LBB4_10
## %bb.8:
	movzx	eax, word ptr [rbp - 202]
	cmp	eax, 0
	je	LBB4_10
## %bb.9:
	mov	ax, word ptr [rbp - 202]
	mov	dl, al
	mov	rax, qword ptr [rbp - 232]
	movsxd	rcx, dword ptr [rbp - 208]
	mov	byte ptr [rax + rcx], dl
	mov	ecx, dword ptr [rbp - 208]
	add	ecx, 1
	mov	rax, qword ptr [rbp - 192]
	mov	dword ptr [rax + 72], ecx
LBB4_10:
	mov	rax, qword ptr [rip + ___stack_chk_guard@GOTPCREL]
	mov	rax, qword ptr [rax]
	mov	rcx, qword ptr [rbp - 8]
	cmp	rax, rcx
	jne	LBB4_12
## %bb.11:
	add	rsp, 240
	pop	rbp
	ret
LBB4_12:
	call	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function
	.globl	__copy                          ## -- Begin function _copy
	.p2align	4, 0x90
__copy:                                 ## @_copy
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	mov	qword ptr [rbp - 8], rdi
	mov	qword ptr [rbp - 16], rsi
	mov	rax, qword ptr [rbp - 16]
	mov	ecx, dword ptr [rax + 72]
	mov	rax, qword ptr [rbp - 8]
	mov	dword ptr [rax + 72], ecx
	mov	dword ptr [rbp - 20], 0
LBB5_1:                                 ## =>This Inner Loop Header: Depth=1
	cmp	dword ptr [rbp - 20], 70
	jae	LBB5_4
## %bb.2:                               ##   in Loop: Header=BB5_1 Depth=1
	mov	rax, qword ptr [rbp - 16]
	mov	ecx, dword ptr [rbp - 20]
                                        ## kill: def $rcx killed $ecx
	mov	dl, byte ptr [rax + rcx]
	mov	rax, qword ptr [rbp - 8]
	mov	ecx, dword ptr [rbp - 20]
                                        ## kill: def $rcx killed $ecx
	mov	byte ptr [rax + rcx], dl
## %bb.3:                               ##   in Loop: Header=BB5_1 Depth=1
	mov	eax, dword ptr [rbp - 20]
	add	eax, 1
	mov	dword ptr [rbp - 20], eax
	jmp	LBB5_1
LBB5_4:
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function
	.globl	__neg                           ## -- Begin function _neg
	.p2align	4, 0x90
__neg:                                  ## @_neg
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	sub	rsp, 112
	mov	rax, qword ptr [rip + ___stack_chk_guard@GOTPCREL]
	mov	rax, qword ptr [rax]
	mov	qword ptr [rbp - 8], rax
	mov	qword ptr [rbp - 96], rdi
	mov	qword ptr [rbp - 104], rsi
	mov	rsi, qword ptr [rbp - 96]
	lea	rdi, [rbp - 88]
	call	__copy
	mov	ecx, dword ptr [rbp - 16]
	mov	rax, qword ptr [rbp - 104]
	mov	dword ptr [rax + 72], ecx
	mov	dword ptr [rbp - 108], 0
LBB6_1:                                 ## =>This Inner Loop Header: Depth=1
	cmp	dword ptr [rbp - 108], 70
	jae	LBB6_6
## %bb.2:                               ##   in Loop: Header=BB6_1 Depth=1
	mov	eax, dword ptr [rbp - 108]
                                        ## kill: def $rax killed $eax
	movzx	eax, byte ptr [rbp + rax - 88]
	xor	eax, -1
	mov	dl, al
	mov	rax, qword ptr [rbp - 104]
	mov	ecx, dword ptr [rbp - 108]
                                        ## kill: def $rcx killed $ecx
	mov	byte ptr [rax + rcx], dl
	mov	rax, qword ptr [rbp - 104]
	mov	ecx, dword ptr [rbp - 108]
                                        ## kill: def $rcx killed $ecx
	movzx	eax, byte ptr [rax + rcx]
	cmp	eax, 0
	je	LBB6_4
## %bb.3:                               ##   in Loop: Header=BB6_1 Depth=1
	mov	ecx, dword ptr [rbp - 108]
	add	ecx, 1
	mov	rax, qword ptr [rbp - 104]
	mov	dword ptr [rax + 72], ecx
LBB6_4:                                 ##   in Loop: Header=BB6_1 Depth=1
	jmp	LBB6_5
LBB6_5:                                 ##   in Loop: Header=BB6_1 Depth=1
	mov	eax, dword ptr [rbp - 108]
	add	eax, 1
	mov	dword ptr [rbp - 108], eax
	jmp	LBB6_1
LBB6_6:
	mov	rdi, qword ptr [rip + __one@GOTPCREL]
	xor	r8d, r8d
	mov	rsi, qword ptr [rbp - 104]
	mov	rdx, qword ptr [rbp - 104]
	mov	ecx, r8d
	call	__add
	mov	rax, qword ptr [rip + ___stack_chk_guard@GOTPCREL]
	mov	rax, qword ptr [rax]
	mov	rcx, qword ptr [rbp - 8]
	cmp	rax, rcx
	jne	LBB6_8
## %bb.7:
	add	rsp, 112
	pop	rbp
	ret
LBB6_8:
	call	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function
	.globl	__sub                           ## -- Begin function _sub
	.p2align	4, 0x90
__sub:                                  ## @_sub
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	sub	rsp, 128
	mov	rax, qword ptr [rip + ___stack_chk_guard@GOTPCREL]
	mov	rax, qword ptr [rax]
	mov	qword ptr [rbp - 8], rax
	mov	qword ptr [rbp - 96], rdi
	mov	qword ptr [rbp - 104], rsi
	mov	qword ptr [rbp - 112], rdx
	mov	dword ptr [rbp - 116], ecx
	mov	dword ptr [rbp - 120], r8d
	mov	rsi, qword ptr [rbp - 104]
	lea	rdi, [rbp - 88]
	call	__copy
	mov	rdi, qword ptr [rbp - 104]
	lea	rsi, [rbp - 88]
	call	__neg
	mov	rdi, qword ptr [rbp - 96]
	mov	rdx, qword ptr [rbp - 112]
	mov	ecx, dword ptr [rbp - 116]
	mov	r8d, dword ptr [rbp - 120]
	lea	rsi, [rbp - 88]
	call	__add
	mov	rax, qword ptr [rbp - 112]
	mov	dword ptr [rax + 72], 0
	mov	dword ptr [rbp - 124], 0
LBB7_1:                                 ## =>This Inner Loop Header: Depth=1
	cmp	dword ptr [rbp - 124], 70
	jge	LBB7_6
## %bb.2:                               ##   in Loop: Header=BB7_1 Depth=1
	mov	rax, qword ptr [rbp - 112]
	movsxd	rcx, dword ptr [rbp - 124]
	movzx	eax, byte ptr [rax + rcx]
	cmp	eax, 0
	je	LBB7_4
## %bb.3:                               ##   in Loop: Header=BB7_1 Depth=1
	mov	ecx, dword ptr [rbp - 124]
	add	ecx, 1
	mov	rax, qword ptr [rbp - 112]
	mov	dword ptr [rax + 72], ecx
LBB7_4:                                 ##   in Loop: Header=BB7_1 Depth=1
	jmp	LBB7_5
LBB7_5:                                 ##   in Loop: Header=BB7_1 Depth=1
	mov	eax, dword ptr [rbp - 124]
	add	eax, 1
	mov	dword ptr [rbp - 124], eax
	jmp	LBB7_1
LBB7_6:
	mov	rax, qword ptr [rip + ___stack_chk_guard@GOTPCREL]
	mov	rax, qword ptr [rax]
	mov	rcx, qword ptr [rbp - 8]
	cmp	rax, rcx
	jne	LBB7_8
## %bb.7:
	add	rsp, 128
	pop	rbp
	ret
LBB7_8:
	call	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function
	.globl	_gt                             ## -- Begin function gt
	.p2align	4, 0x90
_gt:                                    ## @gt
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	mov	qword ptr [rbp - 16], rdi
	mov	qword ptr [rbp - 24], rsi
	mov	rax, qword ptr [rbp - 24]
	mov	eax, dword ptr [rax + 72]
	mov	rcx, qword ptr [rbp - 16]
	cmp	eax, dword ptr [rcx + 72]
	jle	LBB8_2
## %bb.1:
	mov	dword ptr [rbp - 4], 0
	jmp	LBB8_17
LBB8_2:
	mov	rax, qword ptr [rbp - 24]
	mov	eax, dword ptr [rax + 72]
	mov	rcx, qword ptr [rbp - 16]
	cmp	eax, dword ptr [rcx + 72]
	jge	LBB8_4
## %bb.3:
	mov	dword ptr [rbp - 4], 1
	jmp	LBB8_17
LBB8_4:
	jmp	LBB8_5
LBB8_5:
	mov	rax, qword ptr [rbp - 24]
	cmp	dword ptr [rax + 72], 0
	jne	LBB8_7
## %bb.6:
	mov	dword ptr [rbp - 4], 0
	jmp	LBB8_17
LBB8_7:
	mov	rax, qword ptr [rbp - 24]
	mov	eax, dword ptr [rax + 72]
	sub	eax, 1
	mov	dword ptr [rbp - 28], eax
LBB8_8:                                 ## =>This Inner Loop Header: Depth=1
	cmp	dword ptr [rbp - 28], 0
	jl	LBB8_16
## %bb.9:                               ##   in Loop: Header=BB8_8 Depth=1
	mov	rax, qword ptr [rbp - 24]
	movsxd	rcx, dword ptr [rbp - 28]
	movzx	eax, byte ptr [rax + rcx]
	mov	rcx, qword ptr [rbp - 16]
	movsxd	rdx, dword ptr [rbp - 28]
	movzx	ecx, byte ptr [rcx + rdx]
	cmp	eax, ecx
	jge	LBB8_11
## %bb.10:
	mov	dword ptr [rbp - 4], 1
	jmp	LBB8_17
LBB8_11:                                ##   in Loop: Header=BB8_8 Depth=1
	mov	rax, qword ptr [rbp - 24]
	movsxd	rcx, dword ptr [rbp - 28]
	movzx	eax, byte ptr [rax + rcx]
	mov	rcx, qword ptr [rbp - 16]
	movsxd	rdx, dword ptr [rbp - 28]
	movzx	ecx, byte ptr [rcx + rdx]
	cmp	eax, ecx
	jle	LBB8_13
## %bb.12:
	mov	dword ptr [rbp - 4], 0
	jmp	LBB8_17
LBB8_13:                                ##   in Loop: Header=BB8_8 Depth=1
	jmp	LBB8_14
LBB8_14:                                ##   in Loop: Header=BB8_8 Depth=1
	jmp	LBB8_15
LBB8_15:                                ##   in Loop: Header=BB8_8 Depth=1
	mov	eax, dword ptr [rbp - 28]
	add	eax, -1
	mov	dword ptr [rbp - 28], eax
	jmp	LBB8_8
LBB8_16:
	mov	dword ptr [rbp - 4], 0
LBB8_17:
	mov	eax, dword ptr [rbp - 4]
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function
	.globl	_ge                             ## -- Begin function ge
	.p2align	4, 0x90
_ge:                                    ## @ge
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	mov	qword ptr [rbp - 16], rdi
	mov	qword ptr [rbp - 24], rsi
	mov	rax, qword ptr [rbp - 24]
	mov	eax, dword ptr [rax + 72]
	mov	rcx, qword ptr [rbp - 16]
	cmp	eax, dword ptr [rcx + 72]
	jle	LBB9_2
## %bb.1:
	mov	dword ptr [rbp - 4], 0
	jmp	LBB9_17
LBB9_2:
	mov	rax, qword ptr [rbp - 24]
	mov	eax, dword ptr [rax + 72]
	mov	rcx, qword ptr [rbp - 16]
	cmp	eax, dword ptr [rcx + 72]
	jge	LBB9_4
## %bb.3:
	mov	dword ptr [rbp - 4], 1
	jmp	LBB9_17
LBB9_4:
	jmp	LBB9_5
LBB9_5:
	mov	rax, qword ptr [rbp - 24]
	cmp	dword ptr [rax + 72], 0
	jne	LBB9_7
## %bb.6:
	mov	dword ptr [rbp - 4], 1
	jmp	LBB9_17
LBB9_7:
	mov	rax, qword ptr [rbp - 24]
	mov	eax, dword ptr [rax + 72]
	sub	eax, 1
	mov	dword ptr [rbp - 28], eax
LBB9_8:                                 ## =>This Inner Loop Header: Depth=1
	cmp	dword ptr [rbp - 28], 0
	jl	LBB9_16
## %bb.9:                               ##   in Loop: Header=BB9_8 Depth=1
	mov	rax, qword ptr [rbp - 24]
	movsxd	rcx, dword ptr [rbp - 28]
	movzx	eax, byte ptr [rax + rcx]
	mov	rcx, qword ptr [rbp - 16]
	movsxd	rdx, dword ptr [rbp - 28]
	movzx	ecx, byte ptr [rcx + rdx]
	cmp	eax, ecx
	jge	LBB9_11
## %bb.10:
	mov	dword ptr [rbp - 4], 1
	jmp	LBB9_17
LBB9_11:                                ##   in Loop: Header=BB9_8 Depth=1
	mov	rax, qword ptr [rbp - 24]
	movsxd	rcx, dword ptr [rbp - 28]
	movzx	eax, byte ptr [rax + rcx]
	mov	rcx, qword ptr [rbp - 16]
	movsxd	rdx, dword ptr [rbp - 28]
	movzx	ecx, byte ptr [rcx + rdx]
	cmp	eax, ecx
	jle	LBB9_13
## %bb.12:
	mov	dword ptr [rbp - 4], 0
	jmp	LBB9_17
LBB9_13:                                ##   in Loop: Header=BB9_8 Depth=1
	jmp	LBB9_14
LBB9_14:                                ##   in Loop: Header=BB9_8 Depth=1
	jmp	LBB9_15
LBB9_15:                                ##   in Loop: Header=BB9_8 Depth=1
	mov	eax, dword ptr [rbp - 28]
	add	eax, -1
	mov	dword ptr [rbp - 28], eax
	jmp	LBB9_8
LBB9_16:
	mov	dword ptr [rbp - 4], 1
LBB9_17:
	mov	eax, dword ptr [rbp - 4]
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function
	.globl	_eq                             ## -- Begin function eq
	.p2align	4, 0x90
_eq:                                    ## @eq
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	mov	qword ptr [rbp - 16], rdi
	mov	qword ptr [rbp - 24], rsi
	mov	rax, qword ptr [rbp - 16]
	mov	eax, dword ptr [rax + 72]
	mov	rcx, qword ptr [rbp - 24]
	cmp	eax, dword ptr [rcx + 72]
	je	LBB10_2
## %bb.1:
	mov	dword ptr [rbp - 4], 0
	jmp	LBB10_9
LBB10_2:
	mov	dword ptr [rbp - 28], 0
LBB10_3:                                ## =>This Inner Loop Header: Depth=1
	mov	eax, dword ptr [rbp - 28]
	mov	rcx, qword ptr [rbp - 16]
	cmp	eax, dword ptr [rcx + 72]
	jge	LBB10_8
## %bb.4:                               ##   in Loop: Header=BB10_3 Depth=1
	mov	rax, qword ptr [rbp - 16]
	movsxd	rcx, dword ptr [rbp - 28]
	movzx	eax, byte ptr [rax + rcx]
	mov	rcx, qword ptr [rbp - 24]
	movsxd	rdx, dword ptr [rbp - 28]
	movzx	ecx, byte ptr [rcx + rdx]
	cmp	eax, ecx
	je	LBB10_6
## %bb.5:
	mov	dword ptr [rbp - 4], 0
	jmp	LBB10_9
LBB10_6:                                ##   in Loop: Header=BB10_3 Depth=1
	jmp	LBB10_7
LBB10_7:                                ##   in Loop: Header=BB10_3 Depth=1
	mov	eax, dword ptr [rbp - 28]
	add	eax, 1
	mov	dword ptr [rbp - 28], eax
	jmp	LBB10_3
LBB10_8:
	mov	dword ptr [rbp - 4], 1
LBB10_9:
	mov	eax, dword ptr [rbp - 4]
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function
	.globl	__mult                          ## -- Begin function _mult
	.p2align	4, 0x90
__mult:                                 ## @_mult
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	sub	rsp, 208
	mov	rax, qword ptr [rip + ___stack_chk_guard@GOTPCREL]
	mov	rax, qword ptr [rax]
	mov	qword ptr [rbp - 8], rax
	mov	qword ptr [rbp - 176], rdi
	mov	qword ptr [rbp - 184], rsi
	mov	qword ptr [rbp - 192], rdx
	mov	rsi, qword ptr [rbp - 176]
	lea	rdi, [rbp - 88]
	call	__copy
	mov	rsi, qword ptr [rbp - 184]
	lea	rdi, [rbp - 168]
	call	__copy
	mov	rdi, qword ptr [rbp - 192]
	call	_Init
	mov	dword ptr [rbp - 200], 0
LBB11_1:                                ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB11_3 Depth 2
	mov	eax, dword ptr [rbp - 200]
	cmp	eax, dword ptr [rbp - 16]
	jge	LBB11_10
## %bb.2:                               ##   in Loop: Header=BB11_1 Depth=1
	mov	dword ptr [rbp - 196], 1
	mov	dword ptr [rbp - 204], 0
LBB11_3:                                ##   Parent Loop BB11_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmp	dword ptr [rbp - 204], 8
	jge	LBB11_8
## %bb.4:                               ##   in Loop: Header=BB11_3 Depth=2
	movsxd	rax, dword ptr [rbp - 200]
	movzx	eax, byte ptr [rbp + rax - 88]
	and	eax, dword ptr [rbp - 196]
	cmp	eax, 0
	je	LBB11_6
## %bb.5:                               ##   in Loop: Header=BB11_3 Depth=2
	mov	rdi, qword ptr [rbp - 192]
	mov	rdx, qword ptr [rbp - 192]
	mov	ecx, dword ptr [rbp - 200]
	mov	r8d, dword ptr [rbp - 204]
	lea	rsi, [rbp - 168]
	call	__add
LBB11_6:                                ##   in Loop: Header=BB11_3 Depth=2
	mov	eax, dword ptr [rbp - 196]
	add	eax, dword ptr [rbp - 196]
	mov	dword ptr [rbp - 196], eax
## %bb.7:                               ##   in Loop: Header=BB11_3 Depth=2
	mov	eax, dword ptr [rbp - 204]
	add	eax, 1
	mov	dword ptr [rbp - 204], eax
	jmp	LBB11_3
LBB11_8:                                ##   in Loop: Header=BB11_1 Depth=1
	jmp	LBB11_9
LBB11_9:                                ##   in Loop: Header=BB11_1 Depth=1
	mov	eax, dword ptr [rbp - 200]
	add	eax, 1
	mov	dword ptr [rbp - 200], eax
	jmp	LBB11_1
LBB11_10:
	mov	rax, qword ptr [rip + ___stack_chk_guard@GOTPCREL]
	mov	rax, qword ptr [rax]
	mov	rcx, qword ptr [rbp - 8]
	cmp	rax, rcx
	jne	LBB11_12
## %bb.11:
	add	rsp, 208
	pop	rbp
	ret
LBB11_12:
	call	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function
	.globl	__div_helper                    ## -- Begin function _div_helper
	.p2align	4, 0x90
__div_helper:                           ## @_div_helper
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	sub	rsp, 128
	mov	rax, qword ptr [rip + ___stack_chk_guard@GOTPCREL]
	mov	rax, qword ptr [rax]
	mov	qword ptr [rbp - 8], rax
	mov	qword ptr [rbp - 96], rdi
	mov	qword ptr [rbp - 104], rsi
	mov	qword ptr [rbp - 112], rdx
	mov	qword ptr [rbp - 120], rcx
	mov	rdi, qword ptr [rbp - 104]
	mov	rsi, qword ptr [rbp - 96]
	call	_gt
	cmp	eax, 0
	jne	LBB12_2
## %bb.1:
	mov	rax, qword ptr [rbp - 104]
	movzx	eax, byte ptr [rax + 69]
	and	eax, 128
	cmp	eax, 0
	je	LBB12_3
LBB12_2:
	jmp	LBB12_5
LBB12_3:
	xor	r8d, r8d
	mov	rdi, qword ptr [rbp - 104]
	mov	rsi, qword ptr [rbp - 104]
	lea	rdx, [rbp - 88]
	mov	ecx, r8d
	call	__add
	mov	rdi, qword ptr [rbp - 96]
	mov	rdx, qword ptr [rbp - 112]
	mov	rcx, qword ptr [rbp - 120]
	lea	rsi, [rbp - 88]
	call	__div_helper
	xor	r8d, r8d
	mov	rdi, qword ptr [rbp - 120]
	mov	rsi, qword ptr [rbp - 120]
	mov	rdx, qword ptr [rbp - 120]
	mov	ecx, r8d
	call	__add
	xor	r8d, r8d
	mov	rdi, qword ptr [rbp - 112]
	mov	rsi, qword ptr [rbp - 104]
	lea	rdx, [rbp - 88]
	mov	ecx, r8d
	call	__add
	mov	rdi, qword ptr [rbp - 96]
	lea	rsi, [rbp - 88]
	call	_ge
	cmp	eax, 0
	je	LBB12_5
## %bb.4:
	xor	r8d, r8d
	mov	rdi, qword ptr [rbp - 112]
	mov	rsi, qword ptr [rbp - 104]
	mov	rdx, qword ptr [rbp - 112]
	mov	ecx, r8d
	call	__add
	mov	rsi, qword ptr [rip + __one@GOTPCREL]
	xor	r8d, r8d
	mov	rdi, qword ptr [rbp - 120]
	mov	rdx, qword ptr [rbp - 120]
	mov	ecx, r8d
	call	__add
LBB12_5:
	mov	rax, qword ptr [rip + ___stack_chk_guard@GOTPCREL]
	mov	rax, qword ptr [rax]
	mov	rcx, qword ptr [rbp - 8]
	cmp	rax, rcx
	jne	LBB12_7
## %bb.6:
	add	rsp, 128
	pop	rbp
	ret
LBB12_7:
	call	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function
	.globl	_is_negative                    ## -- Begin function is_negative
	.p2align	4, 0x90
_is_negative:                           ## @is_negative
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	mov	qword ptr [rbp - 8], rdi
	mov	rax, qword ptr [rbp - 8]
	movzx	eax, byte ptr [rax + 69]
	and	eax, 128
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function
	.globl	__div                           ## -- Begin function _div
	.p2align	4, 0x90
__div:                                  ## @_div
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	sub	rsp, 272
	mov	rax, qword ptr [rip + ___stack_chk_guard@GOTPCREL]
	mov	rax, qword ptr [rax]
	mov	qword ptr [rbp - 8], rax
	mov	qword ptr [rbp - 256], rdi
	mov	qword ptr [rbp - 264], rsi
	mov	qword ptr [rbp - 272], rdx
	lea	rdi, [rbp - 88]
	call	_Init
	mov	rdi, qword ptr [rbp - 272]
	call	_Init
	mov	rdi, qword ptr [rbp - 256]
	call	_is_negative
	cmp	eax, 0
	je	LBB14_2
## %bb.1:
	mov	rdi, qword ptr [rbp - 256]
	lea	rsi, [rbp - 168]
	call	__neg
	jmp	LBB14_3
LBB14_2:
	mov	rsi, qword ptr [rbp - 256]
	lea	rdi, [rbp - 168]
	call	__copy
LBB14_3:
	mov	rdi, qword ptr [rbp - 264]
	call	_is_negative
	cmp	eax, 0
	je	LBB14_5
## %bb.4:
	mov	rdi, qword ptr [rbp - 264]
	lea	rsi, [rbp - 248]
	call	__neg
	jmp	LBB14_6
LBB14_5:
	mov	rsi, qword ptr [rbp - 264]
	lea	rdi, [rbp - 248]
	call	__copy
LBB14_6:
	mov	rcx, qword ptr [rbp - 272]
	lea	rdi, [rbp - 168]
	lea	rsi, [rbp - 248]
	lea	rdx, [rbp - 88]
	call	__div_helper
	mov	rax, qword ptr [rip + ___stack_chk_guard@GOTPCREL]
	mov	rax, qword ptr [rax]
	mov	rcx, qword ptr [rbp - 8]
	cmp	rax, rcx
	jne	LBB14_8
## %bb.7:
	add	rsp, 272
	pop	rbp
	ret
LBB14_8:
	call	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function
	.globl	__modulo                        ## -- Begin function _modulo
	.p2align	4, 0x90
__modulo:                               ## @_modulo
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	sub	rsp, 368
	mov	rax, qword ptr [rip + ___stack_chk_guard@GOTPCREL]
	mov	rax, qword ptr [rax]
	mov	qword ptr [rbp - 8], rax
	mov	qword ptr [rbp - 336], rdi
	mov	qword ptr [rbp - 344], rsi
	mov	qword ptr [rbp - 352], rdx
	lea	rdi, [rbp - 248]
	call	_Init
	lea	rdi, [rbp - 328]
	call	_Init
	mov	dword ptr [rbp - 356], 0
	mov	rdi, qword ptr [rbp - 336]
	call	_is_negative
	cmp	eax, 0
	je	LBB15_2
## %bb.1:
	mov	rdi, qword ptr [rbp - 336]
	lea	rsi, [rbp - 248]
	call	__neg
	mov	dword ptr [rbp - 356], 1
	jmp	LBB15_3
LBB15_2:
	mov	rsi, qword ptr [rbp - 336]
	lea	rdi, [rbp - 248]
	call	__copy
LBB15_3:
	mov	rdi, qword ptr [rbp - 344]
	call	_is_negative
	cmp	eax, 0
	je	LBB15_5
## %bb.4:
	mov	rax, qword ptr [rip + ___stderrp@GOTPCREL]
	mov	rdi, qword ptr [rax]
	lea	rsi, [rip + L_.str.2]
	xor	eax, eax
                                        ## kill: def $al killed $al killed $eax
	call	_fprintf
	mov	edi, 1
	call	_exit
LBB15_5:
	mov	rsi, qword ptr [rbp - 344]
	lea	rdi, [rbp - 328]
	call	__copy
## %bb.6:
	mov	rdi, qword ptr [rbp - 352]
	call	_Init
	lea	rdi, [rbp - 248]
	lea	rsi, [rbp - 328]
	lea	rdx, [rbp - 88]
	call	__div
	lea	rdi, [rbp - 88]
	lea	rsi, [rbp - 328]
	lea	rdx, [rbp - 168]
	call	__mult
	xor	r8d, r8d
	mov	rdx, qword ptr [rbp - 352]
	lea	rdi, [rbp - 248]
	lea	rsi, [rbp - 168]
	mov	ecx, r8d
	call	__sub
	cmp	dword ptr [rbp - 356], 0
	je	LBB15_9
## %bb.7:
	mov	rax, qword ptr [rbp - 352]
	cmp	dword ptr [rax + 72], 0
	je	LBB15_9
## %bb.8:
	xor	r8d, r8d
	mov	rdi, qword ptr [rbp - 344]
	mov	rsi, qword ptr [rbp - 352]
	mov	rdx, qword ptr [rbp - 352]
	mov	ecx, r8d
	call	__sub
LBB15_9:
	mov	rax, qword ptr [rip + ___stack_chk_guard@GOTPCREL]
	mov	rax, qword ptr [rax]
	mov	rcx, qword ptr [rbp - 8]
	cmp	rax, rcx
	jne	LBB15_11
## %bb.10:
	add	rsp, 368
	pop	rbp
	ret
LBB15_11:
	call	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function
	.globl	__find_msb                      ## -- Begin function _find_msb
	.p2align	4, 0x90
__find_msb:                             ## @_find_msb
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	mov	al, dil
	mov	byte ptr [rbp - 1], al
	mov	dword ptr [rbp - 8], 1
	mov	dword ptr [rbp - 12], 0
	mov	dword ptr [rbp - 16], 0
LBB16_1:                                ## =>This Inner Loop Header: Depth=1
	cmp	dword ptr [rbp - 16], 8
	jge	LBB16_6
## %bb.2:                               ##   in Loop: Header=BB16_1 Depth=1
	movzx	eax, byte ptr [rbp - 1]
	and	eax, dword ptr [rbp - 8]
	cmp	eax, 0
	je	LBB16_4
## %bb.3:                               ##   in Loop: Header=BB16_1 Depth=1
	mov	eax, dword ptr [rbp - 16]
	mov	dword ptr [rbp - 12], eax
LBB16_4:                                ##   in Loop: Header=BB16_1 Depth=1
	mov	eax, dword ptr [rbp - 8]
	add	eax, dword ptr [rbp - 8]
	mov	dword ptr [rbp - 8], eax
## %bb.5:                               ##   in Loop: Header=BB16_1 Depth=1
	mov	eax, dword ptr [rbp - 16]
	add	eax, 1
	mov	dword ptr [rbp - 16], eax
	jmp	LBB16_1
LBB16_6:
	mov	eax, dword ptr [rbp - 12]
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function
	.globl	__modular_exp                   ## -- Begin function _modular_exp
	.p2align	4, 0x90
__modular_exp:                          ## @_modular_exp
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	sub	rsp, 64
	mov	qword ptr [rbp - 8], rdi
	mov	qword ptr [rbp - 16], rsi
	mov	qword ptr [rbp - 24], rdx
	mov	qword ptr [rbp - 32], rcx
	mov	rax, qword ptr [rbp - 32]
	mov	byte ptr [rax], 1
	mov	rax, qword ptr [rbp - 32]
	mov	dword ptr [rax + 72], 1
	mov	rax, qword ptr [rbp - 16]
	mov	eax, dword ptr [rax + 72]
	sub	eax, 1
	mov	dword ptr [rbp - 48], eax
LBB17_1:                                ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB17_5 Depth 2
	cmp	dword ptr [rbp - 48], 0
	jl	LBB17_12
## %bb.2:                               ##   in Loop: Header=BB17_1 Depth=1
	mov	rax, qword ptr [rbp - 16]
	movsxd	rcx, dword ptr [rbp - 48]
	movzx	edi, byte ptr [rax + rcx]
	call	__find_msb
	mov	dword ptr [rbp - 36], eax
	mov	dword ptr [rbp - 44], 7
	mov	eax, dword ptr [rbp - 48]
	mov	rcx, qword ptr [rbp - 16]
	mov	ecx, dword ptr [rcx + 72]
	sub	ecx, 1
	cmp	eax, ecx
	jne	LBB17_4
## %bb.3:                               ##   in Loop: Header=BB17_1 Depth=1
	mov	eax, dword ptr [rbp - 36]
	mov	dword ptr [rbp - 44], eax
LBB17_4:                                ##   in Loop: Header=BB17_1 Depth=1
	mov	ecx, dword ptr [rbp - 44]
                                        ## kill: def $cl killed $ecx
	mov	eax, 1
	shl	eax, cl
	mov	dword ptr [rbp - 40], eax
	mov	eax, dword ptr [rbp - 44]
	mov	dword ptr [rbp - 52], eax
LBB17_5:                                ##   Parent Loop BB17_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmp	dword ptr [rbp - 52], 0
	jl	LBB17_10
## %bb.6:                               ##   in Loop: Header=BB17_5 Depth=2
	mov	rdi, qword ptr [rbp - 32]
	mov	rsi, qword ptr [rbp - 32]
	mov	rdx, qword ptr [rbp - 32]
	call	__mult
	mov	rdi, qword ptr [rbp - 32]
	mov	rsi, qword ptr [rbp - 24]
	mov	rdx, qword ptr [rbp - 32]
	call	__modulo
	mov	rax, qword ptr [rbp - 16]
	movsxd	rcx, dword ptr [rbp - 48]
	movzx	eax, byte ptr [rax + rcx]
	and	eax, dword ptr [rbp - 40]
	cmp	eax, 0
	je	LBB17_8
## %bb.7:                               ##   in Loop: Header=BB17_5 Depth=2
	mov	rdi, qword ptr [rbp - 8]
	mov	rsi, qword ptr [rbp - 32]
	mov	rdx, qword ptr [rbp - 32]
	call	__mult
	mov	rdi, qword ptr [rbp - 32]
	mov	rsi, qword ptr [rbp - 24]
	mov	rdx, qword ptr [rbp - 32]
	call	__modulo
LBB17_8:                                ##   in Loop: Header=BB17_5 Depth=2
	mov	eax, dword ptr [rbp - 40]
	sar	eax, 1
	mov	dword ptr [rbp - 40], eax
## %bb.9:                               ##   in Loop: Header=BB17_5 Depth=2
	mov	eax, dword ptr [rbp - 52]
	add	eax, -1
	mov	dword ptr [rbp - 52], eax
	jmp	LBB17_5
LBB17_10:                               ##   in Loop: Header=BB17_1 Depth=1
	jmp	LBB17_11
LBB17_11:                               ##   in Loop: Header=BB17_1 Depth=1
	mov	eax, dword ptr [rbp - 48]
	add	eax, -1
	mov	dword ptr [rbp - 48], eax
	jmp	LBB17_1
LBB17_12:
	add	rsp, 64
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function
	.globl	__shift_right                   ## -- Begin function _shift_right
	.p2align	4, 0x90
__shift_right:                          ## @_shift_right
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	mov	qword ptr [rbp - 8], rdi
	mov	qword ptr [rbp - 16], rsi
	mov	dword ptr [rbp - 20], edx
	mov	dword ptr [rbp - 24], ecx
	mov	rax, qword ptr [rbp - 8]
	mov	eax, dword ptr [rax + 72]
	mov	dword ptr [rbp - 32], eax
	mov	dword ptr [rbp - 36], 0
LBB18_1:                                ## =>This Inner Loop Header: Depth=1
	mov	eax, dword ptr [rbp - 36]
	mov	rcx, qword ptr [rbp - 8]
	mov	ecx, dword ptr [rcx + 72]
	sub	ecx, dword ptr [rbp - 20]
	cmp	eax, ecx
	jge	LBB18_8
## %bb.2:                               ##   in Loop: Header=BB18_1 Depth=1
	mov	rax, qword ptr [rbp - 8]
	mov	ecx, dword ptr [rbp - 36]
	add	ecx, dword ptr [rbp - 20]
	movsxd	rcx, ecx
	movzx	eax, byte ptr [rax + rcx]
                                        ## kill: def $ax killed $ax killed $eax
	mov	word ptr [rbp - 26], ax
	movsx	eax, word ptr [rbp - 26]
	mov	ecx, dword ptr [rbp - 24]
                                        ## kill: def $cl killed $ecx
	sar	eax, cl
	mov	dl, al
	mov	rax, qword ptr [rbp - 16]
	movsxd	rcx, dword ptr [rbp - 36]
	mov	byte ptr [rax + rcx], dl
	cmp	dword ptr [rbp - 36], 0
	jle	LBB18_4
## %bb.3:                               ##   in Loop: Header=BB18_1 Depth=1
	mov	rax, qword ptr [rbp - 16]
	mov	ecx, dword ptr [rbp - 36]
	sub	ecx, 1
	movsxd	rcx, ecx
	movzx	eax, byte ptr [rax + rcx]
	movsx	edx, word ptr [rbp - 26]
	mov	ecx, dword ptr [rbp - 24]
                                        ## kill: def $cl killed $ecx
	mov	esi, 1
	shl	esi, cl
	mov	ecx, esi
	sub	ecx, 1
	and	edx, ecx
	mov	ecx, 8
	sub	ecx, dword ptr [rbp - 24]
                                        ## kill: def $cl killed $ecx
	shl	edx, cl
	mov	ecx, edx
	or	eax, ecx
	mov	dl, al
	mov	rax, qword ptr [rbp - 16]
	mov	ecx, dword ptr [rbp - 36]
	sub	ecx, 1
	movsxd	rcx, ecx
	mov	byte ptr [rax + rcx], dl
LBB18_4:                                ##   in Loop: Header=BB18_1 Depth=1
	mov	rax, qword ptr [rbp - 16]
	movsxd	rcx, dword ptr [rbp - 36]
	movzx	eax, byte ptr [rax + rcx]
	cmp	eax, 0
	je	LBB18_6
## %bb.5:                               ##   in Loop: Header=BB18_1 Depth=1
	mov	eax, dword ptr [rbp - 36]
	mov	dword ptr [rbp - 32], eax
LBB18_6:                                ##   in Loop: Header=BB18_1 Depth=1
	jmp	LBB18_7
LBB18_7:                                ##   in Loop: Header=BB18_1 Depth=1
	mov	eax, dword ptr [rbp - 36]
	add	eax, 1
	mov	dword ptr [rbp - 36], eax
	jmp	LBB18_1
LBB18_8:
	mov	ecx, dword ptr [rbp - 32]
	add	ecx, 1
	mov	rax, qword ptr [rbp - 16]
	mov	dword ptr [rax + 72], ecx
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function
	.globl	__compose                       ## -- Begin function _compose
	.p2align	4, 0x90
__compose:                              ## @_compose
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	sub	rsp, 64
	mov	qword ptr [rbp - 8], rdi
	mov	qword ptr [rbp - 16], rsi
	mov	qword ptr [rbp - 24], rdx
	mov	qword ptr [rbp - 32], rcx
	mov	dword ptr [rbp - 40], 0
	mov	dword ptr [rbp - 44], 1
	mov	dword ptr [rbp - 48], 0
LBB19_1:                                ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB19_5 Depth 2
	xor	eax, eax
                                        ## kill: def $al killed $al killed $eax
	mov	ecx, dword ptr [rbp - 48]
	mov	rdx, qword ptr [rbp - 8]
	cmp	ecx, dword ptr [rdx + 72]
	mov	byte ptr [rbp - 61], al         ## 1-byte Spill
	jge	LBB19_3
## %bb.2:                               ##   in Loop: Header=BB19_1 Depth=1
	cmp	dword ptr [rbp - 44], 0
	setne	al
	mov	byte ptr [rbp - 61], al         ## 1-byte Spill
LBB19_3:                                ##   in Loop: Header=BB19_1 Depth=1
	mov	al, byte ptr [rbp - 61]         ## 1-byte Reload
	test	al, 1
	jne	LBB19_4
	jmp	LBB19_12
LBB19_4:                                ##   in Loop: Header=BB19_1 Depth=1
	mov	dword ptr [rbp - 36], 1
	mov	dword ptr [rbp - 52], 0
LBB19_5:                                ##   Parent Loop BB19_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmp	dword ptr [rbp - 52], 8
	jge	LBB19_10
## %bb.6:                               ##   in Loop: Header=BB19_5 Depth=2
	mov	rax, qword ptr [rbp - 8]
	movsxd	rcx, dword ptr [rbp - 48]
	movzx	eax, byte ptr [rax + rcx]
	and	eax, dword ptr [rbp - 36]
	cmp	eax, 0
	je	LBB19_8
## %bb.7:                               ##   in Loop: Header=BB19_1 Depth=1
	mov	dword ptr [rbp - 44], 0
	jmp	LBB19_10
LBB19_8:                                ##   in Loop: Header=BB19_5 Depth=2
	mov	eax, dword ptr [rbp - 40]
	add	eax, 1
	mov	dword ptr [rbp - 40], eax
	mov	eax, dword ptr [rbp - 36]
	add	eax, dword ptr [rbp - 36]
	mov	dword ptr [rbp - 36], eax
## %bb.9:                               ##   in Loop: Header=BB19_5 Depth=2
	mov	eax, dword ptr [rbp - 52]
	add	eax, 1
	mov	dword ptr [rbp - 52], eax
	jmp	LBB19_5
LBB19_10:                               ##   in Loop: Header=BB19_1 Depth=1
	jmp	LBB19_11
LBB19_11:                               ##   in Loop: Header=BB19_1 Depth=1
	mov	eax, dword ptr [rbp - 48]
	add	eax, 1
	mov	dword ptr [rbp - 48], eax
	jmp	LBB19_1
LBB19_12:
	mov	eax, dword ptr [rbp - 40]
	cdq
	mov	ecx, 8
	idiv	ecx
	mov	dword ptr [rbp - 56], eax
	mov	eax, dword ptr [rbp - 40]
	cdq
	idiv	ecx
	mov	dword ptr [rbp - 60], edx
	mov	ecx, dword ptr [rbp - 60]
                                        ## kill: def $cl killed $ecx
	mov	eax, 1
	shl	eax, cl
	mov	dl, al
	mov	rax, qword ptr [rbp - 24]
	movsxd	rcx, dword ptr [rbp - 56]
	mov	byte ptr [rax + rcx], dl
	mov	ecx, dword ptr [rbp - 56]
	add	ecx, 1
	mov	rax, qword ptr [rbp - 24]
	mov	dword ptr [rax + 72], ecx
	mov	rdi, qword ptr [rbp - 8]
	mov	rsi, qword ptr [rbp - 16]
	mov	edx, dword ptr [rbp - 56]
	mov	ecx, dword ptr [rbp - 60]
	call	__shift_right
	mov	ecx, dword ptr [rbp - 56]
	shl	ecx, 3
	add	ecx, dword ptr [rbp - 60]
	mov	rax, qword ptr [rbp - 32]
	mov	dword ptr [rax], ecx
	add	rsp, 64
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function
	.globl	__extended_euclid               ## -- Begin function _extended_euclid
	.p2align	4, 0x90
__extended_euclid:                      ## @_extended_euclid
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	sub	rsp, 128
	mov	rax, qword ptr [rip + ___stack_chk_guard@GOTPCREL]
	mov	rax, qword ptr [rax]
	mov	qword ptr [rbp - 8], rax
	mov	qword ptr [rbp - 96], rdi
	mov	qword ptr [rbp - 104], rsi
	mov	qword ptr [rbp - 112], rdx
	mov	qword ptr [rbp - 120], rcx
	mov	qword ptr [rbp - 128], r8
	mov	rax, qword ptr [rbp - 104]
	cmp	dword ptr [rax + 72], 0
	jne	LBB20_2
## %bb.1:
	mov	rdi, qword ptr [rbp - 112]
	mov	rsi, qword ptr [rbp - 96]
	call	__copy
	mov	rax, qword ptr [rbp - 120]
	mov	dword ptr [rax + 72], 1
	mov	rax, qword ptr [rbp - 120]
	mov	byte ptr [rax], 1
	jmp	LBB20_3
LBB20_2:
	mov	rdi, qword ptr [rbp - 96]
	mov	rsi, qword ptr [rbp - 104]
	lea	rdx, [rbp - 88]
	call	__modulo
	mov	rdi, qword ptr [rbp - 104]
	mov	rdx, qword ptr [rbp - 112]
	mov	rcx, qword ptr [rbp - 120]
	mov	r8, qword ptr [rbp - 128]
	lea	rsi, [rbp - 88]
	call	__extended_euclid
	mov	rdi, qword ptr [rbp - 96]
	mov	rsi, qword ptr [rbp - 104]
	lea	rdx, [rbp - 88]
	call	__div
	mov	rdi, qword ptr [rbp - 128]
	lea	rdx, [rbp - 88]
	mov	rsi, rdx
	call	__mult
	xor	r8d, r8d
	mov	rdi, qword ptr [rbp - 120]
	lea	rdx, [rbp - 88]
	mov	rsi, rdx
	mov	ecx, r8d
	call	__sub
	mov	rdi, qword ptr [rbp - 120]
	mov	rsi, qword ptr [rbp - 128]
	call	__copy
	mov	rdi, qword ptr [rbp - 128]
	lea	rsi, [rbp - 88]
	call	__copy
LBB20_3:
	mov	rax, qword ptr [rip + ___stack_chk_guard@GOTPCREL]
	mov	rax, qword ptr [rax]
	mov	rcx, qword ptr [rbp - 8]
	cmp	rax, rcx
	jne	LBB20_5
## %bb.4:
	add	rsp, 128
	pop	rbp
	ret
LBB20_5:
	call	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function
	.globl	__inverse                       ## -- Begin function _inverse
	.p2align	4, 0x90
__inverse:                              ## @_inverse
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	sub	rsp, 192
	mov	rax, qword ptr [rip + ___stack_chk_guard@GOTPCREL]
	mov	rax, qword ptr [rax]
	mov	qword ptr [rbp - 8], rax
	mov	qword ptr [rbp - 176], rdi
	mov	qword ptr [rbp - 184], rsi
	mov	qword ptr [rbp - 192], rdx
	lea	rdi, [rbp - 88]
	call	_Init
	mov	rdi, qword ptr [rbp - 176]
	mov	rsi, qword ptr [rbp - 184]
	mov	rcx, qword ptr [rbp - 192]
	lea	rdx, [rbp - 168]
	lea	r8, [rbp - 88]
	call	__extended_euclid
	mov	rdi, qword ptr [rbp - 192]
	mov	rsi, qword ptr [rbp - 184]
	mov	rdx, qword ptr [rbp - 192]
	call	__modulo
	mov	rax, qword ptr [rip + ___stack_chk_guard@GOTPCREL]
	mov	rax, qword ptr [rax]
	mov	rcx, qword ptr [rbp - 8]
	cmp	rax, rcx
	jne	LBB21_2
## %bb.1:
	add	rsp, 192
	pop	rbp
	ret
LBB21_2:
	call	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function
	.globl	__random                        ## -- Begin function _random
	.p2align	4, 0x90
__random:                               ## @_random
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	sub	rsp, 32
	mov	qword ptr [rbp - 8], rdi
	mov	qword ptr [rbp - 16], rsi
	mov	rdi, qword ptr [rbp - 16]
	call	_Init
	mov	dword ptr [rbp - 20], 0
LBB22_1:                                ## =>This Inner Loop Header: Depth=1
	mov	eax, dword ptr [rbp - 20]
	mov	rcx, qword ptr [rbp - 8]
	cmp	eax, dword ptr [rcx + 72]
	jge	LBB22_6
## %bb.2:                               ##   in Loop: Header=BB22_1 Depth=1
	call	_rand
	mov	dl, al
	mov	rax, qword ptr [rbp - 16]
	movsxd	rcx, dword ptr [rbp - 20]
	mov	byte ptr [rax + rcx], dl
	mov	rax, qword ptr [rbp - 16]
	movsxd	rcx, dword ptr [rbp - 20]
	movzx	eax, byte ptr [rax + rcx]
	cmp	eax, 0
	je	LBB22_4
## %bb.3:                               ##   in Loop: Header=BB22_1 Depth=1
	mov	ecx, dword ptr [rbp - 20]
	add	ecx, 1
	mov	rax, qword ptr [rbp - 16]
	mov	dword ptr [rax + 72], ecx
LBB22_4:                                ##   in Loop: Header=BB22_1 Depth=1
	jmp	LBB22_5
LBB22_5:                                ##   in Loop: Header=BB22_1 Depth=1
	mov	eax, dword ptr [rbp - 20]
	add	eax, 1
	mov	dword ptr [rbp - 20], eax
	jmp	LBB22_1
LBB22_6:
	mov	rdi, qword ptr [rbp - 16]
	mov	rsi, qword ptr [rbp - 8]
	mov	rdx, qword ptr [rbp - 16]
	call	__modulo
	mov	rax, qword ptr [rbp - 16]
	cmp	dword ptr [rax + 72], 0
	jne	LBB22_8
## %bb.7:
	mov	rsi, qword ptr [rip + __one@GOTPCREL]
	mov	rdi, qword ptr [rbp - 16]
	call	__copy
LBB22_8:
	add	rsp, 32
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d, "

L_.str.1:                               ## @.str.1
	.asciz	"\n"

	.comm	__one,76,2                      ## @_one
L_.str.2:                               ## @.str.2
	.asciz	"Can't compute modulo with a negative base\n"

	.comm	__minus_one,76,2                ## @_minus_one
.subsections_via_symbols

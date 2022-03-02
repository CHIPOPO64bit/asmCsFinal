IDEAL
MODEL small
STACK 100h

DATASEG
;variables here
_DEFAULT_SIZE equ 70d
_MAX_STRING equ 31d
_MAX_SEGMENT equ 32d
_CARRY_MASK equ 255d
_CARRY_MASK_LENGTH equ 8d
_BASE_UNIT equ 8d

CODESEG

COMMENT @
/**
 * init number
 * @param _ptr number pointer
 * @Complexity O(log(n))
 */
 @
proc Init 
endp Init


start:
    mov ax, @data
    mov ds, ax
	xor ax, ax
    mov dx, offset string
    mov ah, 9h
    int 21h

    mov ax, 13h
    int 10h

    mov cx, 100h;
    ; init 
    mov ax,0h
    int 33h
    LOOPA:

    ; display cursor

    mov ax,1h
    int 33h


    ; mov ah, 2
    ; mov dl, cl
    ; int 21h
    
    cmp cx, 0
    dec cx
    JGE LOOPA
    mov dx, offset string
    mov ah, 9h
    int 21h




exit:
    mov ax, 4c00h
    int 21h
END start
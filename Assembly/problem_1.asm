.data
strA: 		.asciiz "Original Array:\n"
strB: 		.asciiz "Second Array:\n"
newline: 	.asciiz "\n"
space : 	.asciiz " "
Original: 	.word 200, 270, 250, 100
			.word 205, 230, 105, 235
			.word 190, 95, 90, 205
			.word 80, 205, 110, 215
Second: 	.space 64

# Abuse of copy/paste lol
# It will be easier to describe what the code below does than to make
# individual comments. The code pulls each matrix element from the
# original array and places it as its designated place in the second
# matrix.  While the original array is accessed, each element is output,
# and every four outputs a newline is output. The second matrix is then
# accessed in order, and the same process is performed.
# FWIW I ran into no bugs while putting this together, just some repetitive
# copy/pasting.

.align 2
.globl main
.text
main:
	la $t0, Original
	la $t1, Second
	li $v0, 4
	la $a0, strA
	syscall
	lw $t2, 0($t0)
	li $v0, 1
	add $a0, $t2, $zero
	syscall
	li $v0, 4
	la $a0, space
	syscall
	sw $t2, 0($t1)
	lw $t2, 4($t0)
	li $v0, 1
	add $a0, $t2, $zero
	syscall
	li $v0, 4
	la $a0, space
	syscall
	sw $t2, 16($t1)
	lw $t2, 8($t0)
	li $v0, 1
	add $a0, $t2, $zero
	syscall
	li $v0, 4
	la $a0, space
	syscall
	sw $t2, 32($t1)
	lw $t2, 12($t0)
	li $v0, 1
	add $a0, $t2, $zero
	syscall
	li $v0, 4
	la $a0, space
	syscall
	sw $t2, 48($t1)
	lw $t2, 16($t0)
	li $v0, 4
	la $a0, newline
	syscall
	li $v0, 1
	add $a0, $t2, $zero
	syscall
	li $v0, 4
	la $a0, space
	syscall
	sw $t2, 4($t1)
	lw $t2, 20($t0)
	li $v0, 1
	add $a0, $t2, $zero
	syscall
	li $v0, 4
	la $a0, space
	syscall
	sw $t2, 20($t1)
	lw $t2, 24($t0)
	li $v0, 1
	add $a0, $t2, $zero
	syscall
	li $v0, 4
	la $a0, space
	syscall
	sw $t2, 36($t1)
	lw $t2, 28($t0)
	li $v0, 1
	add $a0, $t2, $zero
	syscall
	li $v0, 4
	la $a0, space
	syscall
	sw $t2, 52($t1)
	lw $t2, 32($t0)
	li $v0, 4
	la $a0, newline
	syscall
	li $v0, 1
	add $a0, $t2, $zero
	syscall
	li $v0, 4
	la $a0, space
	syscall
	sw $t2, 8($t1)
	lw $t2, 36($t0)
	li $v0, 1
	add $a0, $t2, $zero
	syscall
	li $v0, 4
	la $a0, space
	syscall
	sw $t2, 24($t1)
	lw $t2, 40($t0)
	li $v0, 1
	add $a0, $t2, $zero
	syscall
	li $v0, 4
	la $a0, space
	syscall
	sw $t2, 40($t1)
	lw $t2, 44($t0)
	li $v0, 1
	add $a0, $t2, $zero
	syscall
	li $v0, 4
	la $a0, space
	syscall
	sw $t2, 56($t1)
	lw $t2, 48($t0)
	li $v0, 4
	la $a0, newline
	syscall
	li $v0, 1
	add $a0, $t2, $zero
	syscall
	li $v0, 4
	la $a0, space
	syscall
	li $v0, 4
	la $a0, space
	syscall
	sw $t2, 12($t1)
	lw $t2, 52($t0)
	li $v0, 1
	add $a0, $t2, $zero
	syscall
	li $v0, 4
	la $a0, space
	syscall
	sw $t2, 28($t1)
	lw $t2, 56($t0)
	li $v0, 1
	add $a0, $t2, $zero
	syscall
	li $v0, 4
	la $a0, space
	syscall
	sw $t2, 44($t1)
	lw $t2, 60($t0)
	li $v0, 1
	add $a0, $t2, $zero
	syscall
	li $v0, 4
	la $a0, space
	syscall
	sw $t2, 60($t1)
	li $v0, 4
	la $a0, newline
	syscall
	syscall
	la $a0, strB
	syscall
	li $v0, 1
	lw $t2, 0($t1)
	add $a0, $t2, $zero
	syscall
	li $v0, 4
	la $a0, space
	syscall
	li $v0, 1
	lw $t2, 4($t1)
	add $a0, $t2, $zero
	syscall
	li $v0, 4
	la $a0, space
	syscall
	li $v0, 1
	lw $t2, 8($t1)
	add $a0, $t2, $zero
	syscall
	li $v0, 4
	la $a0, space
	syscall
	li $v0, 1
	lw $t2, 12($t1)
	add $a0, $t2, $zero
	syscall
	li $v0, 4
	la $a0, newline
	syscall
	li $v0, 1
	lw $t2, 16($t1)
	add $a0, $t2, $zero
	syscall
	li $v0, 4
	la $a0, space
	syscall
	li $v0, 1
	lw $t2, 20($t1)
	add $a0, $t2, $zero
	syscall
	li $v0, 4
	la $a0, space
	syscall
	li $v0, 1
	lw $t2, 24($t1)
	add $a0, $t2, $zero
	syscall
	li $v0, 4
	la $a0, space
	syscall
	li $v0, 1
	lw $t2, 28($t1)
	add $a0, $t2, $zero
	syscall
	li $v0, 4
	la $a0, newline
	syscall
	li $v0, 1
	lw $t2, 32($t1)
	add $a0, $t2, $zero
	syscall
	li $v0, 4
	la $a0, space
	syscall
	li $v0, 1
	lw $t2, 36($t1)
	add $a0, $t2, $zero
	syscall
	li $v0, 4
	la $a0, space
	syscall
	li $v0, 1
	lw $t2, 40($t1)
	add $a0, $t2, $zero
	syscall
	li $v0, 4
	la $a0, space
	syscall
	li $v0, 1
	lw $t2, 44($t1)
	add $a0, $t2, $zero
	syscall
	li $v0, 4
	la $a0, newline
	syscall
	li $v0, 1
	lw $t2, 48($t1)
	add $a0, $t2, $zero
	syscall
	li $v0, 4
	la $a0, space
	syscall
	li $v0, 1
	lw $t2, 52($t1)
	add $a0, $t2, $zero
	syscall
	li $v0, 4
	la $a0, space
	syscall
	li $v0, 1
	lw $t2, 56($t1)
	add $a0, $t2, $zero
	syscall
	li $v0, 4
	la $a0, space
	syscall
	li $v0, 1
	lw $t2, 60($t1)
	add $a0, $t2, $zero
	syscall
	li $v0, 4
	la $a0, space
	syscall
	li $v0, 10
	syscall
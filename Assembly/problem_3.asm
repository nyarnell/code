.data
strA: .asciiz "Please enter the nth Fibonacci number to be displayed:\n"
strB: .asciiz ", "
errmsg: .asciiz "Enter a positive integer please\n"

.globl main
.text
main:
	li $v0, 4				# Display a string syscall
	la $a0, strA			# String location
	syscall					# "Please enter the nth Fibonacci number to be displayed:\n"
	li $v0, 5				# Take in value from user
	syscall
	bltz $v0, error
	add $a0, $v0, $zero		# Move user input to $a0
	add $a1, $v0, $zero		# And to $a1 for later

	jal fibonacci 			# Jump and link to come back here later

	li $v0, 10
	syscall					# Quit

fibonacci:
	addi $t0, $zero, 1
	beqz $a0, zero 			# User entered zero
	beq $a0, $t0, one 		# User entered one
	add $t1, $zero, $zero	# $t1 = 0
	add $t2, $zero, $zero	# $t2 = 0
	addi $t3, $zero, 1 		# $t3 = 1
	addi $t4, $zero, 2 		# $t4 = 2
	li $v0, 1
	add $a0, $t1, $zero
	syscall 				# Output first fibonacci number (0)
	li $v0, 4
	la $a0, strB
	syscall					# Add comma and spacing
	li $v0, 1
	add $a0, $t3, $zero
	syscall 				# Output second fibonacci number (1)
	#li $v0, 4
	#la $a0, strB
	#syscall
	#addi $a1, $zero, -1

loop:
	bge $t4, $a1, end 		# Go to end if $t4 is equal to $a1
	li $v0, 4 				
	la $a0, strB
	syscall					# Add comma and spacing
	add $t1, $t2, $t3		# $t1 = $t2 + $t3
	li $v0, 1
	add $a0, $t1, $zero
	syscall					# Output $t1 (fibonacci number)
	add $t2, $zero, $t3		# $t2 = $t3
	add $t3, $zero, $t1		# $t3 = $t1
	addi $t4, $t4, 1 		# $t4++
	j loop

error:
	li $v0, 4
	la $a0, errmsg
	syscall
	j end

end:
	jr $ra

zero:
	li $v0, 1
	add $a0, $zero, $zero
	syscall					# Output 0, no spacing
	jr $ra

one:
	li $v0, 1
	add $a0, $zero, $zero
	syscall					# Output 0
	li $v0, 4
	la $a0, strB
	syscall					# Output spacing
	li $v0, 1
	addi $a0, $zero, 1
	syscall 				# Output 1
	jr $ra
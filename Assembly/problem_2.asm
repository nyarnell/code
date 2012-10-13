.data
strA: .asciiz "Please enter your choice to skip numbers (1-4)\n"
numsum: .asciiz "Sum is "
errmsg: .asciiz "That's not a valid number\n"
Numbers:	.byte 100, -7, 11, 25, -66, 99, -1, 34, 12, 22, -2, -7, 100, 11, 4, 67, 2, -90, 22, 2, 56, 3, -89, 12, -10, 21, 10, -25, -6, 9, 111, 34, 12, 22, -2, -17, 100, 111, -4, 7, 14, -19, -2, 29, 36, 31, -79, 2

# Two numbers in Numbers have been changed: 144 to 104 and -190 to -100. This change was mentioned in class.

.globl main
.text
main:
	li $v0, 4 				# Display a string syscall
	la $a0, strA			# String location
	syscall					# "Please enter your choice to skip numbers (1-4)\n"
	li $v0, 5				# Take in value from user
	syscall
	la $s0, Numbers 		# Load Numbers into $s0
	li $t6, 47				# Initialize counter to 47 - number of numbers in Numbers
	li $t0, 1
	beq $v0, $t0 Loop1		# Check if user entered 1
	li $t0, 2
	beq $v0, $t0, Loop2		# Check if user entered 2
	li $t0, 3
	beq $v0, $t0, Loop3		# Check if user entered 3
	li $t0, 4
	beq $v0, $t0, Loop4		# Check if user entered 4
	li $v0, 4
	la $a0, errmsg 			# Else user entered invalid number
	syscall
	j exit

Loop1:
	lb $t1, 0($s0)			# Load a number into $t1
	add $s1, $s1, $t1		# Add the number in $t1 to the total in $s1
	addi $s0, $s0, 1 		# Increment $s0 to the next byte / number
	addi $t6, $t6, -1 		# Decrement $t6 (counter)
	bgtz $t6, Loop1			# Loop if $t6>0
	li $v0, 4 				# String display syscall
	la $a0, numsum			# "Sum is "
	syscall
	li $v0, 1 				# Print integer syscall
	add $a0, $s1, $zero		# Load total from $s1
	syscall
	j exit

Loop2:
	lb $t1, 0($s0)			# Load a number into $t1
	add $s1, $s1, $t1		# Add the number in $t1 to the total in $s1
	addi $s0, $s0, 2 		# Increment $s0 to the next byte / number
	addi $t6, $t6, -2 		# Decrement $t6 (counter)
	bgtz $t6, Loop2			# Loop if $t6>0
	li $v0, 4 				# String display syscall
	la $a0, numsum			# "Sum is "
	syscall
	li $v0, 1 				# Print integer syscall
	add $a0, $s1, $zero		# Load total from $s1
	syscall
	j exit

Loop3:
	lb $t1, 0($s0)			# Load a number into $t1
	add $s1, $s1, $t1		# Add the number in $t1 to the total in $s1
	addi $s0, $s0, 3 		# Increment $s0 to the next byte / number
	addi $t6, $t6, -3 		# Decrement $t6 (counter)
	bgtz $t6, Loop3			# Loop if $t6>0
	li $v0, 4 				# String display syscall
	la $a0, numsum			# "Sum is "
	syscall
	li $v0, 1 				# Print integer syscall
	add $a0, $s1, $zero		# Load total from $s1
	syscall
	j exit

Loop4:
	lb $t1, 0($s0)			# Load a number into $t1
	add $s1, $s1, $t1		# Add the number in $t1 to the total in $s1
	addi $s0, $s0, 4 		# Increment $s0 to the next byte / number
	addi $t6, $t6, -4 		# Decrement $t6 (counter)
	bgtz $t6, Loop4			# Loop if $t6>0
	li $v0, 4 				# String display syscall
	la $a0, numsum			# "Sum is "
	syscall
	li $v0, 1 				# Print integer syscall
	add $a0, $s1, $zero		# Load total from $s1
	syscall
	j exit

exit:
	li $v0, 10
	syscall
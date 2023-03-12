.data
prompt: .asciz "Prime max: "
newline: .asciz "\n"
.text
is_prime:
	li 	t2, 1
	ble	a0, t2, return_false
	li	t2, 2
	li	t3, 3
	beq	a0, t2, return_true
	beq	a0, t3, return_true
	rem	t4, a0, t2
	beqz	t4, return_false
	rem	t4, a0, t3
	beqz	t4, return_false
	li	t2, 5	# i = 5
	prime_loop:
		mul	t4, t2, t2  #i * i
		bgt	t4, a0, return_true # i * i >= n
		rem	t4, a0, t2
		beqz	t4, return_false
		addi	t4, t2, 2
		rem	t4, a0, t4
		beqz	t4, return_false
		addi	t2, t2, 6
		j prime_loop
	return_true:
		li	t2, 1
		mv	a0, t2
		ret
	return_false:
		li	t2, 0
		mv	a0, t2
		ret
.global main
main:
	addi 	sp, sp, -16
	sd	ra, 0(sp)
	sd	s0, 8(sp)
	li	a7, 4
	la 	a0, prompt
	ecall
	li	a7, 5
	ecall
	mv	s0, a0
	li	t0, 1
	for_loop_start:
		bge	t0, s0, program_exit
		mv	a0, t0
		call 	is_prime
		beqz	a0, skip_print
		li	a7, 1
		mv	a0, t0
		ecall
		li	a7, 4
		la	a0, newline
		ecall
	skip_print:
		addi	t0, t0, 1
		j for_loop_start
	program_exit:
		li	a7, 10
		ecall
proctype A(chan q1, q2){
	int x;
	chan c1;
	q1?c1;
	c1!10;
	q2?c1;
	c1?x;
	printf("x = %d!!\n", x);
}

proctype B(chan c1, c2){
	int x;
	do
		 :: c1?x;
		 x = x*2+1;
		 c2!x;
	od;
}

init{
	chan q1 = [0] of {chan};
	chan q2 = [0] of {chan};
	chan c1 = [0] of {int};
	chan c2 = [0] of {int};
	run A(q1, q2);
	run B(c1, c2);

	q1!c1;
	q2!c2;
}
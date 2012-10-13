proctype A(chan q1){
	chan q2;
	q1?q2;
	q2!123;
}

proctype B(chan qforb){
	int x;
	qforb?x;
	printf("x = %d!!\n", x);
}

init{
	chan qname = [0] of {chan};
	chan qforb = [0] of {int};

	run A(qname);
	run B(qforb);

	qname!qforb;
}

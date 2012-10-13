proctype A(chan q1, qforb) {
	int x;
	chan c;
	q1?c;
	do
	:: qforb?x;
	:: x = x*2;
	:: c!x;
	od
}

proctype A2(chan qforb){
	int x = 15;
	qforb!x;
	int y;
	do
	:: qforb?y;
	:: y == 2*x -> x = x+10;
		y = x;
	:: qforb!x;
	od
}



init {
	chan qname = [1] of { chan };
	chan qforb = [1] of { int };

	run A(qname, qforb);
	run A2(qforb);

	qname!qforb
}
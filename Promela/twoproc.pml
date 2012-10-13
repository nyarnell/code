proctype A() {
	int a = 10;
	chan c = [0] of {int};
	c!a;
	run B(c);
	c?a;
}

proctype B(chan c){
	int b;
	do
	::	c?b;
	:: 	b = b*2;
	::	c!b;
	od;
}

init {
	run A();
}
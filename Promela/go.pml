proctype Go() {
	printf("GO GO: %d\n", _pid);
}

init {
	printf("go process, my pid is %d\n", _pid);
	int lastpid;
	lastpid = run Go();
	printf("my last pid was: %d\n", lastpid);
}
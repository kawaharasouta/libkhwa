#include<time.h>

void micro_sleep(){
	struct timespec ts;
	ts.tv_sec = 0;
	ts.tv_nsec = 100;
	nanosleep(&ts, NULL);
}

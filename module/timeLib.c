#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 255
long get_unixtimestamp()
{
	long get_unix_time_stamp;
	struct timeval tv;
	gettimeofday(&tv, NULL);
	get_unix_time_stamp = tv.tv_sec;
	return get_unix_time_stamp;
}
char* get_full_datetime()
{
	char* test;
	test = malloc(SIZE*sizeof(char));
	time_t rawtime;
    	struct tm * timeinfo;
	time (&rawtime);
	timeinfo = localtime (&rawtime);
	strcpy(test, asctime (timeinfo));
  	return test;
}
char* get_short_date()
{
	char *buffer;
	buffer = malloc(SIZE*sizeof(char));
	time_t curtime;
	struct tm *loctime;
	/* Получить текущие время. */
	curtime = time (NULL);
	/* Переобразование в местное время. */
	loctime = localtime (&curtime);
	strftime (buffer, SIZE, "%D", loctime);
	return buffer;
}
char* get_timems()
{
	char *timeBuffer;
	char *buffer;
	buffer = malloc(SIZE*sizeof(char));
	timeBuffer = malloc(SIZE*sizeof(char));
	time_t curtime;
	struct tm *loctime;
	struct timeval tim;
	gettimeofday(&tim, NULL);
	/* Получить текущие время. */
	curtime = time (NULL);
	/* Переобразование в местное время. */
	loctime = localtime (&curtime);
	strftime (timeBuffer, SIZE, "%T.", loctime);
	long ms = tim.tv_usec/1000;
	snprintf ( buffer, SIZE, "%s%ld",timeBuffer, ms );
	free(timeBuffer);
	return buffer;
}
void set_time(int hour, int min, int sec)
{
	time_t mytime = time(0);
    	struct tm* tm_ptr = localtime(&mytime);
	struct timeval tim;
	struct timezone tzome;
	gettimeofday(&tim, &tzome);
    	if (tm_ptr)
    	{
        	tm_ptr->tm_hour = hour;
        	tm_ptr->tm_min = min;
        	tm_ptr->tm_sec = sec;
        	const struct timeval tv = {mktime(tm_ptr), 0};
        	int status = settimeofday(&tv, &tzome);
        	printf("%d",status);
    	}
}


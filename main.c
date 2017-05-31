#include"timeapi.h"
#include"stdlib.h"
int main()
{
	long get_unix_time_stamp = get_unixtimestamp();
	char* get_full_date = get_full_datetime();
	char* get_shortdate = get_short_date();
	char* get_time_ms = get_timems();
	printf("Seconds since Jan. 1, 1970: %ld\n", get_unix_time_stamp);
	printf("The current local time is: %s", get_full_date);
	printf("Today is %s\n",get_shortdate);
	printf("The time is %s\n",get_time_ms);
	set_time(11,02,12);
	free(get_full_date);
	free(get_short_date);
	free(get_time_ms);
	return 0;
}


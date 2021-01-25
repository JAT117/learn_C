//Bit Fields and Bit Masks
/* Lang = C
Used for compact data (for example, packet size limitations)

options
Flags
Attributes

Used to compact space
Individual bits represent something


look at open():

	#include <fnctl.h>

	int:
		open(const char *path, int oflag, ...);
		

	int fd = open(filename, O_RDONLY | O_SHLOCK);
				00000000000000000001000000000000
 */
//ex1: Log messages to file

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <fnctl.h>

#define TS_BUF_LENGTH 30

//Define options
#define LOG_TIME   		0x01 //0b00000001
#define LOG_DATE   		0x02 //0b00000010
#define LOG_USER   		0x04 //0b00000100
#define LOG_COUNT  		0x08 //0b00001000
#define LOG_ALL    		0XFF //0b11111111 //combinations of options
#define LOG_FULLTIME    0X03 //0b00000011 //pair of options like date and time

void logmsg(FILE *fp, char *message, uint8_t options){
	static uint64_t logcount = 0;
	
	time_t time_val;
	char timestamp[TS_BUF_LENGTH];
	char datestamp[TS_BUF_LENGTH];
	struct tm* tm_info;
	
	time_val = time(NULL);
	tm_info = localtime(&time_val)
	
	strftime(datestamp, TS_BUF_LENGTH, "%F (%a)", tm_info);
	strftime(timestamp, TS_BUF_LENGTH, "%H:%M:%S", tm_info);
	
	if (options & LOG_COUNT)
		fprint(fp, "%lli,", ++logcount);
	if (options & LOG_DATE)
		fprint(fp, "%s,", datestamp);
	if (options & LOG_TIME)
		fprint(fp, "%s," ,timestamp);
	if (options & LOG_USER)
		fprint(fp, "%s," getlogin());
	fprint(fp, "%s,", message);
}

int main(){
	logmsg(stdout, "Things are good.", 0);
	logmsg(stdout, "Things are not good.", LOG_USER | LOG_DATE);
	logmsg(stdout, "Things are bad.", LOG_TIME | LOG_USER | LOG_COUNT);
	logmsg(stdout, "HELP.", LOG_COUNT);
	logmsg(stdout, "HELP.", LOG_ALL);
	logmsg(stdout, "HELP.", LOG_FULLTIME);
}


//ex2: Save memory space on numerals

#include <stdio.h>

struct counters{
	unsigned int little:2;
	unsigned int medium:4;
	unsigned int large:6;
}__attribute__((packed)); //struct packing

#define NUM_LOOPS 50

int main(){
	struct counters counts;
	counts.little = 0;
	counts.medium = 0;
	counts.large  = 0;
	
	for (int i = 0; i < NUM_LOOPS; i++){
		counts.little++;
		counts.medium++;
		counts.large++;  
		printf("%d,%d,%d\n", counts.little, counts.medium, counts.large);
	}
	
	printf("Sizeof counts = %lu\n", sizeof(counts));
}


//ex3: make bit field act like an array of bits

#include <stdio.h>
#include <stdint.h>

uint64_t array_of_bits = 0; //bit array_of_bits[64]; is not possible in C

#define SET_BIT(BF, N) BF |= ((uint64_t)0x0000000000000001 << N)
#define CLR_BIT(BF, N) BF &= ~((uint64_t)0x0000000000000001 << N)
#define CLR_BIT(BF, N) ((BF >> N) & 0x1)

int main(){
	SET_BIT(array_of_bits,0);
	SET_BIT(array_of_bits,2);
	SET_BIT(array_of_bits,0);
	SET_BIT(array_of_bits,7);
	SET_BIT(array_of_bits,45);
	
	CLR_BIT(array_of_bits, 7);
	
	for(int i = 0, i < 64, i++)
	{
		if (IS_BIT_SET(array_of_bits, i))
		{
			printf("+");
		}
		else
		{
			printf(".");
		}
	}
	printf("\n");
}


//////////////////////////
//Bit Masks

//Binary pattern to modify another binary pattern

//Set bit 3 to 1
x |= (0x00000001 << 3)

//clear bit 3 to 1
x &= ~(0x00000001 << 3)

//Toggle bits
XOR ^=
	0b00100000
  ^=0b00001000
	----------
	0b00101000

x ^= 0b00001000; instead of if (x & (0x1 << x))
								x &= ~(0x1 <<3);
							else
								x |= (0x1 << 3);


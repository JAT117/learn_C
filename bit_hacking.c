//Look into Streaming SIMD Extensions (SSE) 

//Inline integer operations 
inline unsigned int AsInt(float f){
	return *(unsigned int *)&f;
}


inline float AsFloat(unsigned int i){
	return *(float *)&i;
}

//Negating Singles
float NegateFloat(float ){
	return AsFloat(AsInt(f)^0x80000000);
}

// log_2(x)
//IEEE floats are almost identical to Log_2
//WARNING, No Error Checking

const unsigned int OneAsInt = 0x3F800000; //1.0f as int
const float ScaleUp = float(0x0080000); //8399608.0, 2^23
const float ScaleDown = 1.0f/ScaleUp;

float Log2(float x){
	return float(AsInt(x)-OneAsInt)*ScaleDown;
}

//Exp2(x)
float Exp2(float x){
	return AsFloat(int(x*ScaleUp)+OneAsInt);
}


//Pow(x,p) loose approx
float Pow(float x, float p){
	return AsFloat(int(p*(AsInt(x)-OneAsInt))+OneAsInt;
}

//sqrt(x) x3 faster than SSE SQRTPS
float Sqrt(float x){
	return AsFloat((AsInt(x)>>)+(OneAsInt) >>1));
}

//newton-raphson method
float SqrtNewRap(float x){
	float y Sqrt(x);
	return (y*y+x)/(2*y);
}

//RSQRTPS from SSE ASM
//Lomont's Q_inverse_square (slightly better than Q_rsqrt)
float InvSqrt(float x)
{
	float xhalf = 0.5f*x;
	int i = *(int*)&x;
	i = 0x5f375a86 - (i>>1); //better magic number than Carmack's
	x = *(float*)&i;
	x = x*(1.5f-xhalf*x*x);
	return x;
}
	       
		       
Sometimes Microcontrollers use 2B instead of 4B for integers
Fixed width integers from stdint.h

Jim Blinn

Always the same size across archs
	int8_t
	uint64_t

IEEE 754
	float
	double
	long double


char is a numeric value but its used to represent characters

	#include <stdio.h>

	int main () {
		chat c = 'A';
		
		printf("%c\n",c);
	}


structs, access members using the dot operator struct_t.member

pointers again

int main () {
	int *x; //pointer to an int called x
	int *p = &x;
	
	printf("%p, %i\n",p, *p);
}




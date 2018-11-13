#include "assignment.h"
#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "string.h"

void main(){
	
	char* info;
	double x[3] = {-1,2,-3};
	double parametro_de_restricao = 4;
	
	info = metodoDoGradiente(funcao_penalizada, x, 50, parametro_de_restricao);
	
	for (int i = 0; i < 3; i++)
	{
		printf("%f\n", x[i]);
	}
	printf("%s\n", info);
}
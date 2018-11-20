#include "assignment.h"
#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "string.h"

#define NUM 3

void main(){
	
	char* info;
	double x[3] = {-3,-2,-1};
	double parametro_de_restricao = 10.0;
	double x0[3];

	for (int i = 0; i < NUM; i++)
	{
		x0[i] = x[i];
	}

	info = metodoDoGradiente(funcao_penalizada, x, 5000, parametro_de_restricao);

	printf("x0:\n");
	for (int i = 0; i < NUM; i++)
	{
		printf("%f\n", x0[i]);
	}
	
	printf("\n");
	printf("x* tq f(x*) é mínimo:\n");
	for (int i = 0; i < NUM; i++)
	{
		printf("%f\n", x[i]);
	}

	double delta[3] = {0.0,0.0,0.0};
	printf("\nValor Esperado:\n");
	for (int i = 0; i < NUM; i++)
	{
		printf("%f\n", -1.0/sqrt(3));
		delta[i] = x[i] + 1.0/sqrt(3);
	}

	printf("\n||Erro Absoluto||2 = %f\n", norm2(delta ,NUM));

	printf("\nf(x*) = %f\n", funcao_penalizada(x, 0.0));
	printf("%s\n", info);
}
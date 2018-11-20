#include "assignment.h"
#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "string.h"

#define NUM 3

void main(){
	
	char* info;
	double x[3] = {0.0,0.0,0.0};
	double parametro_de_restricao = 4.0;
	double x0[3];

	for (int i = 0; i < NUM; i++)
	{
		x0[i] = x[i];
	}

	info = metodoDoGradiente(funcao_penalizada, x, 5000, parametro_de_restricao);

	printf("x0:\n");
	for (int i = 0; i < NUM; i++)
	{
		printf("(%f)\n", x0[i]);
	}
	
	printf("\n");
	printf("x* tq f(x*) é mínimo:\n");
	for (int i = 0; i < NUM; i++)
	{
		printf("(%f)\n", x[i]);
	}

	int k = 0;
	double delta[3] = {0.0,0.0,0.0};
	double d[3] = {0.0,0.0,0.0};
	double comp[3] = {-1.0,0.0,0.0};

	printf("\nValor Esperado:\n");
	for (int i = 0; i < NUM; i++)
	{
		for (int j = 0; j < NUM; ++j)
		{
			d[j] = x[j];
		}

		d[i] += 1;
		delta[i] = norm2(d,NUM);
		if (delta[i] < delta[k]){
			comp[k] = 0.0;
			k = i;
			comp[k] = -1.0;
		}
	}

	for (int i = 0; i < NUM; ++i)
	{
		printf("%f\n", comp[i]);
	}

	double fx1 = funcao_penalizada(x, 0.0);
	double fx0 = funcao_penalizada(comp, 0.0);

	printf("\n||Erro Absoluto(x)||2 = %f\n", delta[k]);
	
	printf("Erro Absoluto(f(x)) = %f\n", fabs(fx1-fx0));

	printf("\nf(x*) = %f\n", fx1);
	printf("Condição de parada: %s\n", info);
}
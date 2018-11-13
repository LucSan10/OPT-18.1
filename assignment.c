#include "stdlib.h"
#include "stdio.h"
#include "math.h"

#define NUM 3

// função max() -> retorna o máximo entre 2 elementos
#define max(a,b) \
	({__typeof__ (a) _a = (a);\
	__typeof__ (b) _b = (b);\
	_a > _b ? _a : _b;})

// tipo restricao (de restricao) -> aceita variáveis (array de doubles)
typedef double (*restricao)(double*);

// tipo func (função que será minimizada) -> aceita variáveis (array de doubles),
// um parâmetro de penalidade e uma função de restricao
typedef double (*funcao)(double*, double, restricao);


// soma de vetores: vetor1 + vetor2
double* soma_de_vetores(double* vetor1, double* vetor2, int size){
	double* resultado = calloc(size, sizeof(double));
	
	for (int i = 0; i < size; i++)
	{
		resultado[i] = vetor1[i] + vetor2[i];
	}

	return resultado;
}

// multiplicação vetorial: vetor1 * vetor2
double multiplicacao_de_vetores(double* vetor1, double* vetor2, int size){
	double resultado = 0.0;
	
	for (int i = 0; i < size; i++)
	{
		resultado += vetor1[i] * vetor2[i];
	}

	return resultado;
}

// soma de vetor e escalar: vetor1 + escalar
double* soma_com_escalar(double* vetor1, double escalar, int size){
	double* resultado = calloc(size, sizeof(double));
	
	for (int i = 0; i < size; i++)
	{
		resultado[i] = vetor1[i] + escalar;
	}

	return resultado;
}

// multiplicação de vetor e escalar: escalar * vetor
double* multiplicacao_com_escalar(double* vetor1, double escalar, int size){
	double* resultado = calloc(size, sizeof(double));
	
	for (int i = 0; i < size; i++)
	{
		resultado[i] = vetor1[i] * escalar;
	}

	return resultado;
}

// comparação entre escalar e vetor:
// se todo elemento de um vetor == escalar, então retorna 1
int comparacao_com_escalar(double* vetor1, double escalar, int size){
	int resultado = 1;

	for (int i = 0; i < size; i++)
	{
		resultado = resultado && (vetor1[i] == escalar);
	}

	return resultado;
}

// função de restricao: (x1^2) + (x2^2) + (x3^2) - 1 = 0
double funcao_de_restricao(double* variaveis){
	return pow(variaveis[0], 2.0) + pow(variaveis[1], 2.0) + pow(variaveis[2], 2.0) - 1;
}

// função a ser minimizada
double funcao(double* variaveis, double parametro_de_restricao, restricao funcao_de_restricao){
	double resultado = pow(variaveis[0], 3.0) + pow(variaveis[1], 3.0) + pow(variaveis[2], 3.0);
	double restricao = funcao_de_restricao(variaveis);

	restricao = pow(restricao, 2);
	return resultado + parametro_de_restricao*restricao;
}



double* gradiente(double* variaveis, double parametro_de_restricao, restricao funcao_de_restricao){
	double* gradiente;
	gradiente = (double*) calloc(3, sizeof(double));
	
	double t = 4*parametro_de_restricao*funcao_de_restricao(variaveis);
	for (int i = 0; i < 3; i++)
	{
		grad[i] = 3*pow(variaveis[i], 2) + variaveis[i]*t;
	}
	
	return gradiente;
}

double** segundo_gradiente(double* variaveis, double parametro_de_restricao, restricao funcao_de_restricao){
	double** segundo_gradiente;
	segundo_gradiente = (double**) calloc(3, sizeof(double*));
	
	double t = 4*parametro_de_restricao*funcao_de_restricao(variaveis);
	for (int i = 0; i < 3; i++)
	{
		segundo_gradiente[i] = (double*) calloc(3, sizeof(double));
		
		double temp = 8*variaveis[i]*parametro_de_restricao;
		segundo_gradiente[i][i] = 6*variaveis[i] + temp*variaveis[i] + t;
		
		for (int j = 0; j < i; j++)
		{
			double temp2 = temp*variaveis[j];
			segundo_gradiente[i][j] = temp*variaveis[j];
			segundo_gradiente[j][i] = temp*variaveis[j];
		}
	}
	
	return segundo_gradiente;
}

/*double* buscaDeArmijo(func f, double* variaveis, double t, double* gradiente, double y, double parametro_de_restricao){
	double resultadoReduzido, resultado, comparador, reducaoProporcional;

	double* temp = multiplicacao_com_escalar(gradiente, -t, 3);
	double eta = 0.25;
	double gamma = 0.8;
	int k = 1;
	double* x;

	x = soma_de_vetores(variaveis, temp, 3);
	resultadoReduzido = f(x, parametro_de_restricao);
	resultado = f(variaveis, parametro_de_restricao);
	reducaoProporcional = eta*t*y;
	comparador = resultado + reducaoProporcional;

	while (resultadoReduzido > comparador){
		temp = multiplicacao_com_escalar(temp, gamma, 3);
		x = soma_de_vetores(variaveis, temp, 3);
		resultadoReduzido = f(x, parametro_de_restricao);
		reducaoProporcional *= t;
		comparador = resultado + reducaoProporcional;
		k++;
	}
	return x;
}

void metodoDoGradiente(func f, double* variaveis, int reps, int parada, double parametro_de_restricao){
	double y;
	double beta = 3.0;
	double variaveis0[3] = {0,0,0};

	for (int k = 0; k < reps; k++){
		double delta = 0.0;
		double* grad = gradiente(variaveis);

		if(parada == 1 && comparacao_com_escalar(grad, 0, 3)) break;
		
		y = -(multiplicacao_de_vetores(grad, grad, 3));

		double* x = buscaDeArmijo(f, variaveis, 1.0, grad, y, parametro_de_restricao);
		
		for (int i = 0; i < 3; i++){
			variaveis0[i] = variaveis[i];
			variaveis[i] = x[i];
			delta += variaveis[i] - variaveis0[i];
		}

		if (parada == 0 && delta < 1.0e-04) break;
		parametro_de_restricao *= beta;
	}
}*/

void main(){
	
	double x[3] = {1,2,3};
	double parametro_de_restricao = 9;
	
	double res = funcao(x, parametro_de_restricao, funcao_de_restricao);
	printf("%f\n", res);
	
	printf("\n");

	double* grad = gradiente(x, parametro_de_restricao, funcao_de_restricao);
	for (int i = 0; i < 3; i++)
	{
		printf("%f\n", grad[i]);
	}

	printf("\n");
	
	double** secGrad = segundoGradiente(x, parametro_de_restricao, funcao_de_restricao);
	for (int i = 0; i < 3; i++)
	{	
		for (int j = 0; j < 2; j++)
		{
			printf("%f,\t", secGrad[i][j]);
		}
		printf("%f\n", secGrad[i][2]);
	}
}
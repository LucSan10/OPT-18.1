#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "string.h"

#define NUM 3

// função max() -> retorna o máximo entre 2 elementos
#define max(a,b) \
	({__typeof__ (a) _a = (a);\
	__typeof__ (b) _b = (b);\
	_a > _b ? _a : _b;})

// tipo func (função que será minimizada) -> aceita variáveis (array de doubles),
// um parâmetro de penalidade e uma função de restricao
typedef double (*funcao)(double*, double);


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
double funcao_penalizada(double* variaveis, double parametro_de_restricao){
	double resultado = pow(variaveis[0], 3.0) + pow(variaveis[1], 3.0) + pow(variaveis[2], 3.0);
	double restricao = funcao_de_restricao(variaveis);

	restricao = pow(restricao, 2.0);
	return resultado + parametro_de_restricao*restricao;
	return resultado;
}


double norm2(double* vetor, int size){
	double resultado = 0;
	for (int i = 0; i < size; i++){
		resultado += pow(vetor[i], 2);
	}
	return sqrt(resultado);
}


double* gradiente(double* variaveis, double parametro_de_restricao, int size){
	double* gradiente;
	gradiente = (double*) calloc(size, sizeof(double));
	
	double t = 4*parametro_de_restricao*funcao_de_restricao(variaveis);
	for (int i = 0; i < size; i++)
	{
		gradiente[i] = 3*pow(variaveis[i], 2) + variaveis[i]*t;
	}
	
	return gradiente;
}


/*
double** segundo_gradiente(double* variaveis, double parametro_de_restricao){
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
*/

double* busca_de_armijo(funcao funcao_penalizada, double* variaveis, double* gradiente, double parametro_de_restricao, int* k){
    // resultado = f(x');
    // resultadoReduzido = f(x' + td);
	// reducaoProporcional = η * t * ∇f(x')T * d;
	// comparador = f(x') + η * t * ∇f(x')T * d;
	// variáveis = x';
	// gradienteT_d = ∇f(x')T * d.
	printf("Iniciando Busca de Armijo\n");
    double resultado, resultadoReduzido, reducaoProporcional, comparador;
    double t = 1;

    // temp = td (no método do Gradiente -> t * -(∇f(x')T))
    double* temp = multiplicacao_com_escalar(gradiente, -t, NUM);
    
    // η
    double eta = 0.25;
    
    // γ
    double gamma = 0.8;

    // x' + td
    double* xtd;
	xtd = soma_de_vetores(variaveis, temp, NUM);
	
    resultado = funcao_penalizada(variaveis, parametro_de_restricao);
	resultadoReduzido = funcao_penalizada(xtd, parametro_de_restricao);
	reducaoProporcional = eta*multiplicacao_de_vetores(gradiente, temp, NUM);
	
	comparador = resultado + reducaoProporcional;
    while (resultadoReduzido > comparador)
    {
	    temp = multiplicacao_com_escalar(temp, gamma, NUM);
	    free(xtd);
	    xtd = soma_de_vetores(variaveis, temp, NUM);
	    resultadoReduzido = funcao_penalizada(xtd, parametro_de_restricao);
	    reducaoProporcional *= gamma;
	    comparador = resultado + reducaoProporcional;
	    (*k)++;
	}
	return xtd;
}



char* metodoDoGradiente(funcao funcao_penalizada, double* variaveis, int repeticoes, double parametro_de_restricao){
	printf("\n");
	double beta = 5.0;
	double fx0, fx1;
	double variaveis0[NUM] = {0.0,0.0,0.0};
	
	int j = 0;
	fx0 = funcao_penalizada(variaveis0, parametro_de_restricao);

	for (int k = 0; k < repeticoes; k++){
		double delta[NUM] = {0.0,0.0,0.0};
		double fdelta = 0.0;
		double* grad = gradiente(variaveis, parametro_de_restricao, NUM);
		printf("∇f(x):\n");
		for (int i = 0; i < NUM; i++)
		{
			printf("%f\n", grad[i]);
		}

		double* x = busca_de_armijo(funcao_penalizada, variaveis, grad, parametro_de_restricao, &j);

		fx1 = funcao_penalizada(x, parametro_de_restricao);

		for (int i = 0; i < NUM; i++){
			variaveis0[i] = variaveis[i];
			variaveis[i] = x[i];
			delta[i] = variaveis[i] - variaveis0[i];
		}
		fdelta = fx1-fx0;

		printf("\nx[k-1]:\n");
		for (int i = 0; i < NUM; i++)
		{
			printf("%f\n", variaveis0[i]);
		}

		printf("\n");
		printf("Iterações totais da Busca de Armijo: %d\n", j);
		printf("Iterações totais do Método do Gradiente: %d\n\n", k);
		
		printf("Δx = \n");
		for (int i = 0; i < NUM; i++)
		{
			printf("%f\n", delta[i]);
		}

		double norm = norm2(delta, NUM);
		printf("\n||Δx||2 = %f\n", norm);

		printf("\nΔ(f(x)) = %f\n\n--------------------------------------------\n\n", fdelta);

		if (norm <= 1.0e-7) return "||Δx||2 = 0";
		if (fabs(fdelta) <= 1.0e-7) return "Δ(f(x)) = 0";
		parametro_de_restricao *= beta;
		fx0 = fx1;
	}
	return "Número de iterações excedidas";
}

/*
void main(){
	
	double x[3] = {1,2,3};
	double parametro_de_restricao = 4;
	
	double res = funcao_penalizada(x, parametro_de_restricao);
	printf("%f\n", res);
	
	printf("\n");

	double* grad = gradiente(x, parametro_de_restricao);

	for (int i = 0; i < 3; i++)
	{
		printf("%f\n", grad[i]);
	}

	printf("\n");
	
	double** secGrad = segundo_gradiente(x, parametro_de_restricao);
	
	for (int i = 0; i < 3; i++)
	{	
		for (int j = 0; j < 2; j++)
		{
			printf("%f,\t", secGrad[i][j]);
		}
		printf("%f\n", secGrad[i][2]);
	}

	printf("\n");

	double gradT_d = -(multiplicacao_de_vetores(grad, grad, 3));
	double t = 1;
	double* temp = multiplicacao_com_escalar(grad, -t, 3);
	double* armijo = busca_de_armijo(funcao_penalizada, x, grad, gradT_d, parametro_de_restricao);

	for (int i = 0; i < 3; i++)
	{
		printf("%f\n", armijo[i]);
	}
	/*
	printf("%f\n\n", gradT_d);
	
	// η
    double eta = 0.8;
    
    // γ
    double gamma = 0.5;

    int k = 0;

	double* xtd = soma_de_vetores(x, temp, 3);

	printf("\n");

	double reducaoProporcional = eta*t*gradT_d;

	printf("%f\n\n", reducaoProporcional);

	double resultadoReduzido = funcao_penalizada(xtd, parametro_de_restricao);
    double resultado = funcao_penalizada(x, parametro_de_restricao);

    printf("%f, %f\n", resultado, resultadoReduzido);
	/*
	for (int i = 0; i < 3; i++)
	{
		printf("%f\n", gradT_d);
	}
}*/
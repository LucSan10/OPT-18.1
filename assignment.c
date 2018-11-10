#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define NUM 3
#define max(a,b) ({ typeof (a) _a = (a); typeof (b) _b = (b); _a > _b ? _a : _b; })

typedef double (*func)(double*, double);

double* vectorSum(double* x1, double* x2, int size){
	double* res = calloc(size, sizeof(double));
	for (int i = 0; i < size; i++) res[i] = x1[i] + x2[i];
	return res;
}

double vectorMult(double* x1, double* x2, int size){
	double res = 0.0;
	for (int i = 0; i < size; i++) res += x1[i] * x2[i];
	return res;
}

double* scalarSum(double* x1, double scalar, int size){
	double* res = calloc(size, sizeof(double));
	for (int i = 0; i < size; i++) res[i] = x1[i] + scalar;
	return res;
}

double* scalarMult(double* x1, double scalar, int size){
	double* res = calloc(size, sizeof(double));
	for (int i = 0; i < size; i++) res[i] = x1[i] * scalar;
	return res;
}

int scalarEqual(double* x1, double scalar, int size){
	int res = 1;
	for (int i = 0; i < size; i++) res = res && (x1[i] == scalar);
	return res;
}



double funcao(double* vars, double rho){
	double resultado = pow(vars[0], 3.0) + pow(vars[1], 3.0) + pow(vars[2], 3.0);
	double restricao = pow(vars[0], 2.0) + pow(vars[1], 2.0) + pow(vars[2], 2.0) - 1;
	restricao = max(0, pow(restricao, 2));
	return resultado + rho*restricao;
}



double* gradiente(double* vars){
	double* grad;
	grad = (double*) calloc(3, sizeof(double));
	for (int i = 0; i < 3; i++) grad[i] = 3*pow(vars[i], 2);
	return grad;
}

double** segundoGradiente(double* vars){
	double** segGrad;
	segGrad = (double**) calloc(3, sizeof(double*));
	for (int i = 0; i < 3; i++){
		segGrad[i] = (double*) calloc(3, sizeof(double));
		segGrad[i][i] = 6*vars[i];
	}
	return segGrad;
}

double* buscaDeArmijo(func f, double* vars, double t, double* gradiente, double y, double rho){
	double resultadoReduzido, resultado, comparador, reducaoProporcional;

	double* temp = scalarMult(gradiente, -t, 3);
	double eta = 0.25;
	double gamma = 0.8;
	int k = 1;
	double* x;

	x = vectorSum(vars, temp, 3);
	resultadoReduzido = f(x, rho);
	resultado = f(vars, rho);
	reducaoProporcional = eta*t*y;
	comparador = resultado + reducaoProporcional;

	while (resultadoReduzido > comparador){
		temp = scalarMult(temp, gamma, 3);
		x = vectorSum(vars, temp, 3);
		resultadoReduzido = f(x, rho);
		reducaoProporcional *= t;
		comparador = resultado + reducaoProporcional;
		k++;
	}
	return x;
}

void metodoDoGradiente(func f, double* vars, int reps, int parada, double rho){
	double y;
	double beta = 3.0;
	double vars0[3] = {0,0,0};

	for (int k = 0; k < reps; k++){
		double delta = 0.0;
		double* grad = gradiente(vars);

		if(parada == 1 && scalarEqual(grad, 0, 3)) break;
		
		y = -(vectorMult(grad, grad, 3));

		double* x = buscaDeArmijo(f, vars, 1.0, grad, y, rho);
		
		for (int i = 0; i < 3; i++){
			vars0[i] = vars[i];
			vars[i] = x[i];
			delta += vars[i] - vars0[i];
		}

		if (parada == 0 && delta < 1.0e-04) break;
		rho *= beta;
	}
}

int main(){
	double x[3] = {0.0,2.0,40.0};
	metodoDoGradiente(funcao, x, 10000, 0, 4.0);
	for (int i = 0; i < 3; i++) printf("%f\n", x[i]);
}
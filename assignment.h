typedef double (*funcao)(double*, double);

double* soma_de_vetores(double* vetor1, double* vetor2, int size);

double multiplicacao_de_vetores(double* vetor1, double* vetor2, int size);

double* soma_com_escalar(double* vetor1, double escalar, int size);

double* multiplicacao_com_escalar(double* vetor1, double escalar, int size);

int comparacao_com_escalar(double* vetor1, double escalar, int size);

double funcao_de_restricao(double* variaveis);

double funcao_penalizada(double* variaveis, double parametro_de_restricao);

double* gradiente(double* variaveis, double parametro_de_restricao);

double* busca_de_armijo(funcao funcao_penalizada, double* variaveis, double* gradiente, double parametro_de_restricao);

char* metodoDoGradiente(funcao funcao_penalizada, double* variaveis, int repeticoes, double parametro_de_restricao);
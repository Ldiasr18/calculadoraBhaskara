#include <stdio.h>
#include <math.h>
#include <string.h>

void criaEq(float num, char *sufixo, int primeiro)
{
	if(fabs(num) == 0)
	{
		return;
	}

	//verifica se é inteiro.
	int inteiro = (fabs(num - (int)num) < 0.0001);

	//pega valor absoluto.
	float absNum = fabs(num);

	//remove o positivo do primeiro valor e caso seja zero.
	if(!primeiro && num > 0)
	{
		printf("+");
	}

	if(num < 0)
	{
		printf("-");
	}

	//para aparecer o "c" caso o valor seja 1.
	if(strcmp(sufixo, "") == 0)
	{
		inteiro ? printf("%d", (int)absNum) : printf("%.2f", absNum);
	}
	//verifica se o valor é diferente de 1 para aparecer na eq.
	else if (absNum != 1)
	{
		inteiro ? printf("%d", (int)absNum) : printf("%.2f", absNum);
	}

	printf("%s", sufixo);
}

float calcDelta(float a,float b,float c)
{
	float delta = (pow(b, 2)) - 4*a*c;

	printf("Delta: ");
	fabs(delta - (int)delta < 0.0001) ? printf("%d", (int)delta) : printf("%.2f", delta);
	printf("\n");

	return delta;
}


void imprimeRaiz(float raiz)
{
	(fabs(raiz - (int)raiz)) < 0.0001 ? printf("%d", (int)raiz) : printf("%.2f", raiz);
}

void calcRaiz(float a, float b, float delta)
{
	if(delta < 0)
	{
		printf("Não existe raiz real. \n");
		return;
	}
	else if(delta == 0)
	{
		float x = ((-1 * b) /(2 *a));
		printf("x1 = x2 = ");
		imprimeRaiz(x);
		printf("\n");
	}
	else
	{
		float x1 = (((-1 * b) + sqrt(delta)) / (2*a));
		printf("x1= ");
		imprimeRaiz(x1);
	        printf("\nx2= ");

		float x2 = (((-1 * b) - sqrt(delta)) / (2*a));
		imprimeRaiz(x2);
		printf("\n");
	}
}


void main()
{
	float a, b, c, delta;
	printf("Digite o valor de a: \n");
	scanf("%f", &a);

	while(a == 0)
	{
		printf("Valor inválido para equação de segundo grau\n Por favor digite um valor válido:\n");
		scanf("%f", &a);
	}

	printf("Digite o valor de b: \n");
	scanf("%f", &b);
	printf("Digite o valor de c: \n");
	scanf("%f", &c);

	//mostra a equação
	printf("Equação: ");
	criaEq(a, "x²", 1);
	criaEq(b, "x", 0);
	criaEq(c,"", 0);
	printf("=0\n");

	//mostra delta
	delta = calcDelta(a, b, c);
	calcRaiz(a, b, delta);
}


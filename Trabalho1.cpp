#include <iostream>
#include <stdlib.h> //números aleatórios
#include <ctime> //calcular tempo
#include<locale> 

using namespace std;

void bubbles(int tam, int A[]) //tam -> tamanho do vetor; A[] -> vetor
{
	int tempo, x, y;  //tempo -> tempo; x -> contador; y -> posição do vetor

	for(x = tam - 1; x >= 1; x--)
	{
		for(y = 0; y < x; y++)
		{
			if(A[y] > A[y + 1])
			{
				tempo = A[y];
				A[y] = A[y + 1];
				A[y + 1] = tempo;
			}

		}
	}

}

void insertions(int tam, int A[] ) //tam -> tamanho do vetor; A[] -> vetor
{
	int x, y, c; //x -> contador; y -> posição do vetor

	for(y = 2; y < tam; y++)
	{
		c = A[y];
		x = y - 1;
		while((x >= 0) && (A[x] > c))
		{
			A[x + 1] = A[x];
			x = x - 1;
		}
		A[x + 1] = c;
	}
}

void selections(int tam, int A[]) //tam -> tamanho do vetor; A[] -> vetor
{
	int m, n, x, y; //x -> contador; y -> posição do vetor

	for(x = 0; x <= tam - 1; x++)
	{
		m = x;
		for(y = x + 1; y <= tam; y++)
		{
			if(A[y] < A[m])
			{
				m = y;
			}
		}
		n = A[m];
		A[m] = A[x];
		A[x] = n;
	}

}

void mostra(int A[], int tam)
{

	for (int i = 0; i < tam; i++ )
	{
		cout << A[i] << endl;
	}
}

int main ()
{

	int op, tamanho, vet[100];
	double t;
	
	setlocale(LC_ALL, "Portuguese");

	cout << "Entre com o tamanho do vetor: " << endl;
	cin >> tamanho;

	do
	{
		cout << "1 - Gerar dados " << endl;
		cout << "2 - Ordenação Bubble Sort " << endl;
		cout << "3 - Ordenação Insertion Sort " << endl;
		cout << "4 - Ordenação Selection Sort " << endl;
		cout << "5 - Fim do Programa " << endl;

		cin >> op;

		time_t t1, t2; //calcula tempo de execução

		switch(op)
		{

		case 1:
		{

			for(int t = 0; t < tamanho; t++) //contador
			{
				vet[t] = rand()%100 + 1; // gera valores aleatórios
			}

			mostra(vet, tamanho);
		}
		break;

		case 2:
		{

			//cout<<" Vetor ordenado - Bubble Sort: "<<bubbles(tamanho, vet)<<endl;
			bubbles(tamanho, vet);

			time(&t1); //tempo de início de execução

			time(&t2); //tempo final de execução

			t = (int)difftime(t2, t1); //diferença de tempo de execução

			cout << "Tempo de execucao do algoritomo: " << t << " s" << endl;
			mostra(vet, tamanho);

		}
		break;

		case 3:
		{

			//cout<<" Vetor ordenado - Insertion Sort: "<<insertions(tamanho, vet)<<endl;
			insertions(tamanho, vet);

			time(&t1); //tempo de início de execução
			time(&t2); //tempo final de execução

			t = (int)difftime(t2, t1); //diferença de tempo de execução

			cout << "Tempo de execucao do algoritomo: " << t << " s" << endl;
			mostra(vet, tamanho);

		}
		break;

		case 4:
		{

			//cout<<" Vetor ordenado - Selection Sort: "<<selections(tamanho, vet);;<<endl;
			selections(tamanho, vet);

			time(&t1); //tempo de início de execução


			time(&t2); //tempo final de execução

			t = (int)difftime(t2, t1); //diferença de tempo de execução

			cout << "Tempo de execucao do algoritomo: " << t << " s" << endl;
			mostra(vet, tamanho);

		}
		break;

		default:
		{

			cout << "Finalizando... " << endl;

		}
		break;

		}
	}
	while(op != 5);

	return 0;

}








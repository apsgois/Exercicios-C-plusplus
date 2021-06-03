#include <iostream>


using namespace std;

struct deque 
{
	int frente, fim, cap; 
	double *info;		  
};


void init(deque *d, int c)
{
	d->frente = NULL;		 
	d->fim = -1;			 
	d->cap = c;				 
	d->info = new double[c]; 
}

bool isEmpty(deque *d) 
{
	int vazio = d->fim == -1;
	return vazio;
}

bool isFull(deque *d) 
{
	int cheio = d->fim == d->cap - 1;
	return cheio;
}

void insertFront(deque *d, double v) 
{
	if (d->fim == -1)
	{
		d->fim++;
		d->info[d->fim] = v;
	}

	else
	{
		for (int i = d->fim; i >= d->frente; i--)
		{
			double aux = d->info[i];
			d->info[i + 1] = aux;
		}
		d->info[d->frente] = v;
		d->fim++;
	}
}

void insertRear(deque *d, double v) 
{
	d->fim++;
	d->info[d->fim] = v;
}

double deleteFront(deque *d) 
{
	double del  = d->info[d->frente];

	if (d->fim == 0)
		d->fim--;

	else
	{
		for (int i = d->frente + 1; i <= d->fim; i++)
		{
			double aux = d->info[i];
			d->info[i - 1] = aux;
		}
		d->fim--;
	}

	return del;
}

double deleteRear(deque *d) 
{
	double aux = d->info[d->fim];

	d->fim--;

	return aux;
}

double getFront(deque *d) 
{
	return d->info[d->frente];
}

double getRear(deque *d) 
{
	return d->info[d->fim];
}

int main()
{
	deque d; 
	int cap; 

	cout << "Qual o tamanho do deque? ";
	cin >> cap;

	init(&d, cap); 

	int op; 

	do
	{
		cout << " "<<endl;
		cout << "Deque do tamanho ->" << cap << " " <<endl;
		cout << "Opcoes" << endl;
		cout << "1 - Inserir valor na frente "<<endl;
		cout << "2 - Inserir valor no final "<<endl;
		cout << "3 - Deletar valor da frente "<<endl;
		cout << "4 - Deletar valor do final "<<endl;
		cout << "5 - Ver valor da frente "<<endl;
		cout << "6 - Ver valor do final "<<endl;
		cout << "0 - Sair"<<endl;
		cin >> op;

		
		switch (op)
		{

		case 1: 

			if (isFull(&d) == true)
				cout << "Deque cheio! \n";
			else
			{
				double v;
				cout << "Valor a incluir: ";
				cin >> v;
				insertFront(&d, v); 
				cout << "Valor " << v << " incluido no inicio"<<endl;
			}
			break;

		
		case 2:

			if (isFull(&d) == true)
				cout << "Deque cheio!"<<endl;
			else
			{
				double v;
				cout << "Valor a incluir: "<<endl;
				cin >> v;
				insertRear(&d, v); 
				cout << "Valor " << v << " incluido no fim "<<endl;
			}
			break;

		case 3: 
			
			if (isEmpty(&d) == true)
				cout << "Deque vazio! "<<endl;
			else
			{
				double v = deleteFront(&d);
				cout << "Valor " << v << " removido do inicio"<<endl;
			}
			break;

		
		case 4:
			
			if (isEmpty(&d) == true)
				cout << "Deque vazio! "<<endl;
			else
			{
				double v = deleteRear(&d);
				cout << "Valor " << v << " removido do fim "<<endl;
			}
			break;

		case 5: 

			if (isEmpty(&d) == true)
				cout << "Deque vazio!"<<endl;
			else
			{
				double v = getFront(&d);
				cout << "Valor inicial = " << v << endl;
			}
			break;

		case 6: 
			
			if (isEmpty(&d) == true)
				cout << "Deque vazio!"<<endl;
			else
			{
				double v = getRear(&d);
				cout << "Valor final = " << v << endl;
			}
			break;

		case 0: 
			
			cout << "Sair";
			break;

		default:
			
			cout << "Digite novamente"<<endl;
			break;
		}
	} while (op != 0);
}

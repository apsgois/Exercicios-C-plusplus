#include <iostream>
#include <iomanip>

#define m 19

using namespace std;


//indicando que a tagbela est� vazia.
void init (int tabela [])
{
	for(int i = 0; i < m; i++)
		tabela[i] = -1;
}

int sondagem_quadratica(int k, int i)
{
	int h;
	h = k % m;
	return (h + 1 * i + 3 * i * i) % m;
}

int hash_insert(int info, int tabela[])
{
	int i;//numero de colos�es
	int j;// posi��es
	int k; //chave
	k = info;
	i = 0; // n�o tem colis�o ainda.
	do
	{
		j = sondagem_quadratica(k, j); // testar se tem colis�o calculo a posi��o
		if(tabela[j] == -1) // identifica se est� vazio
		{
			tabela[j] = info; //  insere a info na tabela
			return j;// retorno a posi��o
		}
		i++;
	}
	while(i < m);
	return -1;
}
int hash_search(int info, int tabela[])
{
	int i;//numero de colos�es
	int j;// posi��es
	int k; //chave
	k = info;
	i = 0; // n�o tem colis�o ainda.
	do
	{
		j = sondagem_quadratica(k, i); // calcula a posi��o  pode colocar qualquer tipo de sondagem.  voc� tem que usar a mesma sondagem que usou no hashing insert.
		if(tabela[j] = info) // identifica se achei a informa��o
		{
			return j;// retorno a posi��o
		}
		i++;
	}
	while(i < m && tabela[j] != = -1);
	return -1;
}

int main()
{

	int tabela[m];
	init (tabela);
	cin >> info;

	for(int i = 0; i < 100; i++)
	{
		if(i = 1)
		{
			cout << "Digite o n�mero do telefone" << endl;
			cin >> info;
			hash_insert(int info, int tabela[]);
		}
		if else (i = 2)
			{
				cout << "Entre com o numero de telefone" << endl;
				cin >> info;
				hash_surch(int info, int tabela[]);
			}
		else
			cout << " " <<
		}



		 return 0;
}

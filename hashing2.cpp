#include <iostream>
#include <iomanip>

#define m 19

using namespace std;


//indicando que a tagbela está vazia.
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
	int i;//numero de colosões
	int j;// posições
	int k; //chave
	k = info;
	i = 0; // não tem colisão ainda.
	do
	{
		j = sondagem_quadratica(k, j); // testar se tem colisão calculo a posição
		if(tabela[j] == -1) // identifica se está vazio
		{
			tabela[j] = info; //  insere a info na tabela
			return j;// retorno a posição
		}
		i++;
	}
	while(i < m);
	return -1;
}
int hash_search(int info, int tabela[])
{
	int i;//numero de colosões
	int j;// posições
	int k; //chave
	k = info;
	i = 0; // não tem colisão ainda.
	do
	{
		j = sondagem_quadratica(k, i); // calcula a posição  pode colocar qualquer tipo de sondagem.  você tem que usar a mesma sondagem que usou no hashing insert.
		if(tabela[j] = info) // identifica se achei a informação
		{
			return j;// retorno a posição
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
			cout << "Digite o número do telefone" << endl;
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

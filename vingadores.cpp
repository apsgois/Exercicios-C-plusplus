#include <iostream>
#include <cstring> // strlen e strcmp

using namespace std;

#define m 20 // especificar o tamanho 

struct heroi
{
	char nome[30];
	char endereco[30];
	char habilidade[30];
	char sexo[30];
	char email[30];
	int status;

};

int sondagem_linear(int k, int i)
{
	int h;
	h = k % m;
	return (h + i) % m;
}

int sondagem_quadratica(int k, int i)
{
	int h;
	h = k % m;
	return (h + 1 * i + 3 * i * i) % m;
}

int hashing_duplo(int k, int i)
{
	int h1, h2;
	h1 = k % m;
	h2 = 1 + (k % (m - 1));
	return (h1 + i * h2) % m;
}

int calcula_chave(heroi info)
{
	int k;
	k = 0;
	for(int i = 0; i < (int)strlen(info.nome); i++) //  strlen tamanhjo da funçao
	{
		k = k + (int)info.nome[i];
	}
	return k; // soma das letras
};
              

int hash_insert(heroi info, heroi tabela[])
{
	int i;// numero de colisoes 
	int j;// posicoes 
	int k;// chave 
	k=calcula_chave(info);// k- info 
	i=0;
	do
	{
		j=sondagem_linear(k,i);// mesmo que serch 
		if(tabela[j].status != 1)// tabela de j ==-1
		{
			tabela[j]=info;
			tabela[j].status = 1; // marcando como ocupada
			return j;
		}
		i++;
	}while(i<m);
	
	return -1;
}

int hash_search( heroi info, heroi tabela[])
{
	int i;// numero de colisoes 
	int j;// posicoes 
	int k;// chave 
	k=calcula_chave(info); // tem que ser a mesma funcao da insert 
	i=0; // nao tem colisao 
	do
	{
		j=sondagem_linear(k,i);// mesmo que insert, se for diferente e tiver colisao da ruim. 
		if(strcmp(info.nome, tabela[j].nome) == 0 && strcmp(info.email, tabela[j].email) == 0 && tabela[j].status == 1)// o1 e para informar qu estava ocupado 
			return j;
		i++;
	}while(i < m && tabela[j].status != 0);
	
	return -1;
}
int hash_search_remove( heroi info, heroi tabela[])
{
	int i;// numero de colisoes 
	int j;// posicoes 
	int k;// chave 
	k=calcula_chave(info); // tem que ser a mesma funcao da insert 
	i=0; // nao tem colisao
	do
	{
		j=sondagem_linear(k,i);// mesmo que insert, se for diferente e tiver colisao da ruim. 
		if(strcmp(info.nome, tabela[j].nome) == 0 && tabela[j].status == 1)// o1 e para informar qu estava ocupado 
			return j;
		i++;
	}while(i < m && tabela[j].status != 0);
	
	return -1;
}


void hash_remove(heroi info, heroi tabela[])
{
	int posicao; // posicao da info removida
	posicao = hash_search_remove(info, tabela);
	if(posicao != -1){
		tabela[posicao].status = 2;
		cout<<"Heroi removido com sucesso\n"; 
	}
	else {
		cout<<"Heroi nao presente na tabela"<<endl; 
	}
}

void init(heroi tabela[])
{
	for(int i = 0; i<m; i++)
		tabela[i].status = 0; // inicialmente todas as posicoes vazias
}




int main()
{
	heroi tabela[m];
	init (tabela);
	int N; // numero de op
	int op;
	char nome[30], endereco[30], habilidade[30], sexo[30], email[30];
	heroi info;


    cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> op;
		if (op == 1) // cadastro
		{
			cin.ignore();
			cin.getline(nome, 30);
			cin.getline(endereco, 30);
			cin.getline(habilidade, 30);
			cin.getline(sexo, 30);
			cin.getline(email, 30);

			strcpy(info.nome, nome);
			strcpy(info.endereco, endereco);
			strcpy(info.habilidade, habilidade);
			strcpy(info.sexo, sexo);
			strcpy(info.email, email);

			int ins = hash_insert(info, tabela);
			if(ins != -1)
			{
				cout << "Heroi inserido com sucesso" << endl;	// inseri na posicao
			}
			else
			{
				cout << "Tabela cheia" << endl; // estava lotada.
			}



		}
		else if (op == 2) // pesquiisa
		{

			cin.ignore();
			cin.getline(nome, 30);
			cin.getline(email, 30);

			strcpy(info.nome, nome);
			strcpy(info.email, email);

			int busca;
			busca = hash_search(info, tabela);
			if(busca != -1)
			{
				cout<<tabela[busca].nome<<endl;
				cout<<tabela[busca].endereco<<endl;
				cout<<tabela[busca].habilidade<<endl;
				cout<<tabela[busca].sexo<<endl;
				cout<<tabela[busca].email<<endl;
				
			}
			else
			{
				cout << "Heroi nao encontrado" << endl;
			}

		}
		else // remocao
		{

			cin.ignore();
			cin.getline(nome,30);
			strcpy(info.nome, nome);
			hash_remove(info, tabela); 
			
		}


	}

}











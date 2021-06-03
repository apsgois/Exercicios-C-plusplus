#include <iostream>
#include <cstring> // strlen e strcmp

using namespace std;

#define m 19 // especificar o tamanho 

struct musica{
	char nome[30];
	char autor[30];
	int duracao;
	int status;
	/*
	0 - posicao vazia
	1 - posicao ocupada
	2 - posicao removida
	*/
};

int sondagem_linear(int k, int i)
{
	int h;
	h = k%m;
	return (h+i)%m;
}

int sondagem_quadratica(int k, int i)
{
	int h;
	h = k%m;
	return (h + 1*i + 3*i*i)%m;
}

int hashing_duplo(int k, int i){
	int h1,h2;
	h1 = k%m;
	h2 = 1 + (k% (m-1));
	return (h1 + i*h2) % m;
}

int calcula_chave(musica info)
{
	int k;
	k = 0;
	for(int i=0; i<(int)strlen(info.nome); i++)//  strlen tamanhjo da funçao 
	{
		k = k + (int)info.nome[i];
	}
	return k; // soma das letras 
};

int hash_insert(musica info, musica tabela[])
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

int hash_search(musica info, musica tabela[])
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

void hash_remove(musica info, musica tabela[])
{
	int posicao; // posicao da info removida
	posicao = hash_search(info, tabela);
	if(posicao != -1)
		tabela[posicao].status = 2;
}

void init(musica tabela[])
{
	for(int i = 0; i<m; i++)
		tabela[i].status = 0; // inicialmente todas as posicoes vazias
}



int main(){
	musica tabela[m];
	init(tabela);
	char nome[30];
	char autor[30];
	int duracao;
	
	musica info;
	cin.getline(nome,30);
	cin.getline(autor,30);
	cin>>duracao; 
	
	info.duracao=duracao; // sempre copiar pra informacao 
	strcpy(info.nome,nome);
	strcpy(info.autor,autor);
	
	int ins=hash_insert(info,tabela);
	if(ins!=-1)
	{
	cout<<"Info inseridana posicao"<<ins<<endl;	// inseri na posicao 
	}
	else
	{
		cout<<"Não foi possivel inseir"<<endl;// estava lotada. 
	}
	
}












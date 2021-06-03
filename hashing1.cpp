#include <iostream>
#include <iomanip>

using namespace std;

#define m 19 // tabela com 19 posi��es.




//indicando que a tagbela est� vazia. 
void init (int tabela [])
{
	for(int i=0;i<m;i++)
		tabela[i]=-1;
} 
// h'(k,i)= (h(k)+i)% m 
int sondagem_linear(int k, int i)
{
	int h; 
	h=k%m;// k mod m 
	return (h+i)%m;
	
}
// h'(k,i)=(h(k)+c1*i+c2+i^2)%m
//c1= 2, c2= 3
int sondagem_quadratica(int k, int i)
{
	int h; 
	h=k%m; 
	return (h+1*i+3*i*i)%m;
}

//h'(k,i)=(h(k)+h2(k)*i)%m
int hashing_duplo(int k, int i) // double hashing 
{
	int h,h2;
	h=k%m;
	h2=1+k%(m-1);
	return (h+h2*i)%m;
}



// retornar -1 se a tabela estiver cheia 
// retornar a posicao em q a iinfo foi inserida 
int hash_insert(int info, int tabela[])
{
	   int i;//numero de colos�es 
	   int j;// posi��es 
	   int k; //chave 
	   k=info; 
	   i=0; // n�o tem colis�o ainda. 
	   do{
		   j= sondagem_linear(k,j); // testar se tem colis�o calculo a posi��o 
		   if(tabela[j]==-1)// identifica se est� vazio
		   {
		   	tabela[j]= info;//  insere a info na tabela 
		   	return j;// retorno a posi��o 
		   }
		   i++; 
	   }while(i<m);	
	   return -1;
}
// retornar -1 se o valor n�o estiver na tabela. 
// retornar a posicao em q a info foi inserida 

int hash_search(int info, int tabela[])
{
	   int i;//numero de colos�es 
	   int j;// posi��es 
	   int k; //chave 
	   k=info; 
	   i=0; // n�o tem colis�o ainda. 
	   do{
		   j= sondagem_linear(k,i); // calcula a posi��o  pode colocar qualquer tipo de sondagem.  voc� tem que usar a mesma sondagem que usou no hashing insert.  
		   if(tabela[j]=info)// identifica se achei a informa��o 
		   {
		   	return j;// retorno a posi��o 
		   }
		   i++; 
	   }while(i<m && tabela[j] !==-1);	
	   return -1;
}

int main ()
{
	int tabela[m];
	init (tabela);
	cin>>info;
	hash_insert(int info, int tabela[]);
	cin>> info; 
	hash_search(int info, int tabela[]); 
	
	
	
	
}
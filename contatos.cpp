#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define m 19

using namespace std;

int sondagem_quadratica(int k, int i)
{
int h;
h = k % m;
return (h + i + i * i * 3) % m;
}

int hash_insert(int info, int tabela[])
{
int k; //chave
int i; //número de colisões
int j; //posição
k = info;
i = 0;

do
{
j = sondagem_quadratica(k, i);
if(tabela[j] == -1)
{
tabela[j] = info;
return j;
}
i++;
}
while(i < m);
return -1;
}

int hash_search(int info, int tabela[])
{
int k;
int i;
int j;
k = info;
i = 0;

do
{
j = sondagem_quadratica(k, i);
if(tabela[j] == k)
{
return j;
}
i++;
}
while(i < m && tabela[j != -1]);
return -1;
}

void init(int tabela[])
{
for(int i = 0; i < m; i++)
{
tabela[i] = -1; //vazio
}
}

int main()
{
int op, qtd, info;
int tabela[m];
init(tabela);
int menu;

cin >> qtd;
for(int i = 0; i < qtd; i++)
{
cin >> op;
switch (op)
{
case 1:
cin >> info;
hash_insert(info, tabela);
break;
case 2:
cin >> info;
if(hash_search(info, tabela) != -1)
{
  cout << "O numero esta na tabela" <<endl;
}
else
{
  cout << "O numero nao esta na tabela" << endl;
}
break;
case 3:
for(int i = 0; i<m; i++)
  if(tabela[i] != -1)
      cout << tabela[i] << endl;
break;
}
}

return 0;
}

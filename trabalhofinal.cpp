#include <iostream>
#include <string>

#define VAZIO NULL

using namespace std;

typedef struct No
{

	string dados;
	struct No* esq;
	struct No* dir;
} arvore;

arvore* criar( string dados, arvore* esq, arvore* dir)
{
	arvore* arv = new arvore;
	arv->dados = dados;
	arv->esq = esq;
	arv->dir = dir;
	return arv;
}

arvore* destruir(arvore* arv)
{
	if (arv != VAZIO)
	{
		destruir(arv->esq);
		destruir(arv->dir);
		delete arv;
	}
	return VAZIO;
}

void preOrdem(arvore* arv)
{
	if (arv == VAZIO)
		return;
	cout << arv->dados << endl;
	preOrdem(arv->esq);
	preOrdem(arv->dir);
}

void emOrdem(arvore* arv)
{
	if (arv == VAZIO)
		return;
	emOrdem(arv->esq);
	cout << arv->dados << endl;
	emOrdem(arv->dir);
}

void posOrdem(arvore* arv)
{
	if (arv == VAZIO)
		return;
	posOrdem(arv->esq);
	posOrdem(arv->dir);
	cout << arv->dados << endl;
}

arvore* buscar(arvore* arv, string v)
{
	if (arv == VAZIO)
	{
		cout << "no vazio" << endl;
		return VAZIO;
	}
	else if (v < arv->dados)
	{
		cout << "saindo de " << arv->dados << " buscando aa esquerda" << endl;
		return buscar(arv->esq, v);
	}
	else if (v > arv->dados)
	{
		cout << "saindo de " << arv->dados << " buscando aa direita" << endl;
		return buscar(arv->dir, v);
	}
	else
	{
		cout << "achei! " << arv->dados << endl;
		return arv;
	}
}

arvore* inserir(arvore* arv, string v)
{
	if (arv == VAZIO)
		arv = criar(v, VAZIO, VAZIO);
	else if (v < arv->dados)
		arv->esq = inserir(arv->esq, v);
	else
		arv->dir = inserir(arv->dir, v);
	return arv;
}
void contador(arvore* arv, int& cFolhas, int& cNos)
{
	if(arv == NULL)
	{
		return;
	}


	cNos++;

	if(arv->dir == NULL && arv->esq == NULL)
	{


		cFolhas++;
	}

	contador(arv->esq, cFolhas, cNos);
	contador(arv->dir, cFolhas, cNos);
}

int comparar(string aux, string aux1)
{
	cout << "Comparando as palavras " << aux1 << " e " << aux << endl;
	int aux3;

	if(aux.size() < aux1.size())
	{
		aux3 = aux.size();
	}
	else
	{
		aux3 = aux1.size();
		if(aux.size() > aux1.size())
		{
			cout << "A palavra " << aux1 << " é antes" << endl;
		}
		else
		{
			cout << "A palavra tem o mesmo tamanho" << endl;
		}

	}

	for(int i = 0; i < aux3; i++)
	{
		if(int(aux[i]) > int(aux1[i]))
		{
			return 0;
		}
		else if(int(aux[i]) < int(aux1[i]))
		{
			return 1;
		}
	}

	return 2;
}

arvore* remover(arvore* arv, string v)
{
	// arvore vazia
	if (arv == VAZIO)
	{
		cout << "no vazio" << endl;
		return VAZIO;
	}
	// valor a ser removido eh menor que o do no atual
	// ou seja, esta localizado na subarvore da esquerda
	else if (v < arv->dados)
	{
		cout << "saindo de " << arv->dados << " buscando aa esquerda" << endl;
		arv->esq = remover(arv->esq, v);
	}
	// valor a ser removido eh maior que o do no atual
	// ou seja, esta localizado na subarvore da direita
	else if (v > arv->dados)
	{
		cout << "saindo de " << arv->dados << " buscando aa direita" << endl;
		arv->dir = remover(arv->dir, v);
	}
	// encontrou o no a remover
	else
	{
		// caso 1: no sem filhos
		if (arv->esq == VAZIO && arv->dir == VAZIO)
		{
			//cout << "estou em " << arv->dados << " caso 1: nao tenho filhos" << endl;
			delete arv;
			arv = VAZIO;
		}
		// caso 2: no so tem um filho
		// caso 2.1: so tem o filho da direita
		else if (arv->esq == VAZIO)
		{
			//cout << "estou em " << arv->dados << " caso 2.1: so tenho filho maior" << endl;
			arvore* aux = arv;
			arv = arv->dir;
			delete aux;
		}
		// caso 2.2: so tem o filho da esquerda
		else if (arv->dir == VAZIO)
		{
			//cout << "estou em " << arv->dados << " caso 2.2: so tenho filho menor" << endl;
			arvore* aux = arv;
			arv = arv->esq;
			delete aux;
		}
		// caso 3: no tem dois filhos
		else
		{
			//cout << "estou em " << arv->dados << " caso 3: tenho dois filhos" << endl;
			arvore* aux = arv->esq;
			//cout << "buscando maior valor da subarvore aa esquerda" << endl;
			while (aux->dir != VAZIO)
				aux = aux->dir;
			//cout << "trocando " << aux->dados << " por " << v << endl;
			arv->dados = aux->dados; // troca os valores
			aux->dados = v;
			arv->esq = remover(arv->esq, v);
		}
	}
	return arv;
}
bool estaVazia(arvore* arv)
{
	if(arv == NULL)
	{
		cout << "A arvore esta vazia!" << endl;
	}

	return arv == NULL;
}
bool ehEstritamenteBinaria(arvore* arv)
{
	if(arv == NULL)
	{
		cout << " Não existe" << endl;
		return false;
	}
	else if(arv->esq == NULL && arv->dir == NULL)
	{
		return true;
	}
	else if(arv->esq != NULL && arv->dir != NULL)
	{
		return (ehEstritamenteBinaria(arv->esq) && ehEstritamenteBinaria(arv->dir));
	}
	else
	{
		return false;
	}
}
bool ehQuaseCompleta(arvore* arv)
{
	int cFolhas = 0;
	int cNos = 0;

	contador(arv, cFolhas, cNos);

	if(cFolhas % 2 == 0 && 2 * cFolhas == cNos - 1)
	{
		return true;
	}

	else if(cFolhas % 2 != 0 && 2 * cFolhas - 1 == cNos - 1)
	{
		return true;
	}
	return false;
}
bool ehCompletaCheia(arvore* arv)
{
	if(arv == NULL)
	{
		cout << "arvore vazia" << endl;
		return false;
	}

	else if(arv->esq == NULL && arv->dir == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}


int main()
{
	int opcao;
	string d;
	bool sair = false;
	arvore* arv = VAZIO;
	while(!sair)
	{

		// criar(): inicialização da árvore.
		cout << "1-Sair: " << endl;
		//buscar(): busca de um elemento na árvore.
		cout << "2- Inserir " << endl;
		//inserir(): inserção de um elemento na árvore.
		cout << "3- Buscar elemento:: " << endl;
		//remover(): remove um elemento da lista.
		cout << "4-Remove: " << endl;
		//estaVazia(): retorna um booleano indicando se a árvore está vazia.
		cout << "5-Está vazia? " << endl;
		//ehEstritamenteBinaria(): retorna um booleano indicando se a árvore é estritamente binária.
		cout << "6-Eh estritamente binaria? " << endl;
		//ehQuaseCompleta(): retorna um booleano indicando se a árvore é quase completa.
		cout << "7-Eh quase completa? " << endl;
		//ehCompletaCheia(): retorna um booleano indicando se a árvore é completa (cheia).
		cout << "8-Eh completa cheia? " << endl;
		//preOrdem(): visita e imprime os elementos da árvore em PRÉ-ORDEM (“RED”).
		cout << "9-Pre- ordem: " << endl;
		//emOrdem(): visita e imprime os elementos da árvore EM-ORDEM (“ERD”).
		cout << "10-Em ordem: " << endl;
		//posOrdem(): visita e imprime os elementos da árvore em PÓS-ORDEM (“EDR”).
		cout << "11-Pos ordem: " << endl;
		cin >> opcao;
		switch (opcao)
		{
		case 1:
			cout << "Sair";
			sair = true;
			break;

		case 2:
			cout << "Inserir: " << endl;
			cin >> d;
			arv = inserir(arv, d);
			break;

		case 3:
			cout << "Buscar elemento:" << endl;
			cin >> d;
			if(buscar(arv, d));
			cout << "Existe" << endl;
			break;

		case 4:
			cout << "Remove: " << endl;
			cin >> d;
			arv = remover(arv, d);
			break;
		case 5:
			cout << "Esta vazia " << endl;
			ehEstritamenteBinaria(arv);
			break;
		case 6:
			cout << "Eh estritamente binaria" << endl;
			if(ehCompletaCheia(arv))
				cout << "Sim" << endl;
			else
				cout << "Nao" << endl;
			break;
		case 7:
			cout << "Eh quase completa  " << endl;
			if (ehQuaseCompleta(arv))
			{
			cout << "A arvore eh quase completa " << endl;
			}
		 	else
				cout << "A arvore nao eh quase completa " << endl;
			break;
		case 8:
			cout << "Eh completa cheia? " << endl;
			if(ehCompletaCheia(arv))
			cout << "A arvore eh completa" << endl;
			else 
				cout << "A arvore NAO eh completa " << endl;
			break;
		case 9:
			cout << "Pre- ordem: " << endl;
			preOrdem(arv);
			break;

		case 10:
			cout << "Em ordem:  " << endl;
			emOrdem(arv);
			break;
		case 11:
			cout << "Pos ordem: " << endl;
			posOrdem(arv);
			break;

		}

	}

}

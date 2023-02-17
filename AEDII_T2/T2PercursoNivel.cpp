#include <iostream>
#include <queue>

using namespace std;

struct No {       //struct para armazenar os valores, e dois ponteiro que representam o filho de esquerda e da direta da arvore
	int valor;
	No *esquerda;
	No *direita; 
};

No *NovoNo(int valor) {
    
	No *temp = new No;      //cria novo Nó 
	temp->valor = valor;     //inicializa o valor com o paramêtro passado
	temp->esquerda = NULL;  //atribui NULL aos filhos para indicar que não há filhos
	temp->direita = NULL;
	return temp;
}

No* insere(No* raiz, int valor) {   //recebe por parametro a raiz e o valor do novo nó
    if (raiz == NULL) {             // se a raiz é nula a arvore esta vazia e um novo nó é criado sendo o valor fornecido a raiz da arvore
        raiz = NovoNo(valor);       
    } else                          // se não a função verifica se o valor é menor ou maior do que o valor do nó atual
    if (valor <= raiz->valor) {     //se menor chama recursivamente para sub-arvore da esquerda
        raiz->esquerda = insere(raiz->esquerda, valor);
    } 
    else {                                          //se maior chama recursivamente para sub-arvore da direita
        raiz->direita = insere(raiz->direita, valor); 
    }
    return raiz;                    //retorna a raiz atualizada
}

void PercursoNivel(No *raiz) {
    cout << "Percurso por nivel: ";
	if(!raiz)       //se vazia retorna
		return;
		
	queue<No*> fila;    //cria uma fila para armazenar os nós a serem visitados
	fila.push(raiz);       //nó raiz primeiro adicionado
	
	while(!fila.empty())   //enquanto a fila nao estiver vazia 
	{
		No *temp = fila.front();   //pega o primeiro valor da fila
		fila.pop();                //remove o valor do inicio
		cout<<temp->valor<<" ";     //o valor é armazenado em 'temp' e impresso
                                    //os filhos do valor de temp sao adicionados a fila, se eles existirem
		if(temp->esquerda!=NULL)
			fila.push(temp->esquerda);
		if(temp->direita!=NULL)
			fila.push(temp->direita);

	}
}

int main() {
    No* raiz = NULL;
    int n;
    cout << "Digite o numero de nos da arvore: ";
    cin >> n;
    cout << "Digite os valores dos nos separados por espaco: ";
    for (int i = 0; i < n; i++) {
        int valor;
        cin >> valor;
        raiz = insere(raiz, valor);
    }                 
	
	PercursoNivel(raiz);

	return 0;
}
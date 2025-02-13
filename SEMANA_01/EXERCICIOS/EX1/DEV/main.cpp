#include <iostream>
#include <string>

using namespace std;

/*
1 -  Faça uma função que recebe uma certa medida e ajusta ela percentualmente entre dois valores mínimo e máximo e retorna esse valor
*/

float converteSensor(float vins, float vmin, float vmax){
  float converte;
  if (vins < vmin || vins > vmax || vmax < vmin){
    cout << "Valores inválidos." << endl;
  } else {
    converte = ((vins - vmin) / (vmax - vmin));
    };
  converte = converte * 100;
  return (converte);
};

/*
// Descomente a função main abaixo para testar o exercício 1
int main(){
  cout << "Teste Ex 1" << endl;
	cout << converteSensor(100,100,400) << endl;
  //valor esperado: 0
  
	cout << converteSensor(400,100,400) << endl;
  //valor esperado: 1
  
	cout << converteSensor(250,100,400) << endl;
  //valor esperado: 0.5
}
*/

// ----------------------------------------------------------

/*
2 - Faça uma função que simule a leitura de um sensor lendo o valor do teclado ao final a função retorna este valor
*/


int leSensor(){
    int valor;
    cin >> valor;
    return valor;
}


/*
// Descomente a função main abaixo para testar o exercício 2
int main(){
  cout << "Digite o Comando (0 ou 1):";
	int cmd = leComando();
	cout << "Comando Recebido: " << cmd << endl;
}
*/

// ----------------------------------------------------------

/*
3 - Faça uma função que armazena uma medida inteira qualquer em um vetor fornecido. Note que como C não possui vetores nativos da linguagem, lembre-se que você precisa passar o valor máximo do vetor assim como a última posição preenchida.
Evite também que, por acidente, um valor seja escrito em uma área de memória fora do vetor
*/


int insereVetor(int elemento, int valorMax, int lastPos, int * Vetor) {
  if (elemento > valorMax) {
    cout << "Erro: valorMax: " << valorMax << ", lastPos + 1 " << elemento << ": 10" << endl;
  } 
  else {
  lastPos = lastPos + 1;
  Vetor[elemento] = lastPos;
  }
  return lastPos;
}

/*
// Descomente a função main abaixo para testar o exercício 3
int main(){
  int valorMax = 10;
  int lastPos = -1;
  int Numbers[valorMax];
  
  insereVetor(9, valorMax, lastPos, Numbers);
  lastPos = lastPos + 1;

  insereVetor(8, valorMax, lastPos, Numbers);
  lastPos = lastPos + 1;

  insereVetor(7, valorMax, lastPos, Numbers);
  lastPos = lastPos + 1;

  insereVetor(6, valorMax, lastPos, Numbers);
  lastPos = lastPos + 1;

  insereVetor(5, valorMax, lastPos, Numbers);
  lastPos = lastPos + 1;

  insereVetor(4, valorMax, lastPos, Numbers);
  lastPos = lastPos + 1;

  insereVetor(3, valorMax, lastPos, Numbers);
  lastPos = lastPos + 1;
  
  insereVetor(2, valorMax, lastPos, Numbers);
  lastPos = lastPos + 1;

  insereVetor(1, valorMax, lastPos, Numbers);
  lastPos = lastPos + 1;

  insereVetor(0, valorMax, lastPos, Numbers);
  lastPos = lastPos + 1;

  insereVetor(100, valorMax, lastPos, Numbers);
  // valor esperado: mensagem de erro "Erro: valorMax: 10, lastPos + 1 (indice): 10"
  
  cout << Numbers[0] << endl; // valor esperado: 9
  cout << Numbers[1] << endl; // valor esperado: 8
  cout << Numbers[2] << endl; // valor esperado: 7
  cout << Numbers[3] << endl; // valor esperado: 6
  cout << Numbers[4] << endl; // valor esperado: 5
  cout << Numbers[5] << endl; // valor esperado: 4
  cout << Numbers[6] << endl; // valor esperado: 3
  cout << Numbers[7] << endl; // valor esperado: 2
  cout << Numbers[8] << endl; // valor esperado: 1
  cout << Numbers[9] << endl; // valor esperado: 0
}
*/

// ----------------------------------------------------------

/*
4 - Faça duas funções que recebem um vetor com 4 posições que contém o valor da distância de um pequeno robô até cada um dos seus 4 lados.
A primeira função deve retornar a direção de maior distância ("Direita", "Esquerda", "Frente", "Tras") e a segunda função deve retornar esta maior distância.
*/


string dirMaiorDist(int * Vetor){
  float max = Vetor[0];
    for (int i = 0; i < 4; i++) {
      if(max < Vetor[i]) {
        max = Vetor[i];
      }
    }
    if (max == Vetor[0]) {
      return "Direita";
    } else if (max == Vetor[1]) {
      return "Esquerda";
    } else if (max == Vetor[2]) {
      return "Frente";
    } else {
      return "Tras";
    }
}

int maiorDist(int * Vetor){
    for (int i = 0; i < 4; i++) {
      if(Vetor[0] < Vetor[i]) {
        Vetor[0] = Vetor[i];
      }
    }
  return Vetor[0];
}

/*
// Descomente a função main abaixo para testar o exercício 3
int main(){
  //Considere que os valores sempre serão distintos
  //Considere valores de distância inteiros entre 0 e 100
  
  // "Direita", "Esquerda", "Frente", "Tras"
  int posicoes [4] = {0, 20, 100, 50};
  
  cout << dirMaiorDist(posicoes) << endl;
  //valor esperado: Frente

  cout << maiorDist(posicoes) << endl;
  //valor esperado: 100


  // "Direita", "Esquerda", "Frente", "Tras"
  int posicoes2 [4] = {95, 70, 80, 50};
  
  cout << dirMaiorDist(posicoes2) << endl;
  //valor esperado: Direita

  cout << maiorDist(posicoes2) << endl;
  //valor esperado: 95


  // "Direita", "Esquerda", "Frente", "Tras"
  int posicoes3 [4] = {10, 0, 50, 60};
  
  cout << dirMaiorDist(posicoes3) << endl;
  //valor esperado: Tras

  cout << maiorDist(posicoes3) << endl;
  //valor esperado: 60


  // "Direita", "Esquerda", "Frente", "Tras"
  int posicoes4 [4] = {54, 55, 30, 0};
  
  cout << dirMaiorDist(posicoes4) << endl;
  //valor esperado: Esquerda

  cout << maiorDist(posicoes4) << endl;
  //valor esperado: 55
}
*/

// ----------------------------------------------------------

// 5 - Faça uma função que pergunta ao usuário se ele deseja continuar o mapeamento e retorna verdadeiro ou falso


int leComando(){
  int parar;
  cout << "Gostaria de continuar o mapeamento? (1 para SIM, 0 para NAO)" << endl;
  cin >> parar;
  return parar;
}

/*
// Descomente a função main abaixo para testar o exercício 5

int main(){
  int continuar = 1;
  
  while (continuar == 1){
    continuar = continuar();
  }
  //A função deve perguntar: "Digite 1 para parar o mapeamento!"
  //Se o usuário digitar 1, deve sair do loop while declarado acima
  // Em caso contrário, continua no loop acima e pergunta novamente

  return 1;
}
*/

// ----------------------------------------------------------

/*
6 - Escreva uma função que vai "dirigindo" virtualmente um robô e através de 4 sensores em cada um dos 4 pontos do robo ("Direita", "Esquerda", "Frente", "Tras"). 
A cada passo, ele verifica as distâncias aos objetos e vai mapeando o terreno para uma movimentação futura. 
Ele vai armazenando estas distancias em um vetor fornecido como parâmetro e retorna a ultima posicao preenchida do vetor.
Esta função deve ir lendo os 4 sensores até que um comando de pare seja enviado.
Para simular os sensores e os comandos de pare, use as funções já construídas nos ítens anteriores e em um looping contínuo até que um pedido de parada seja enviado pelo usuário.
A função final deve utilizar as funções declaradas acima para ler os sensores e o movimento do robô e no final percorrer o vetor e mostrar o movimento a cada direção na maior distância a cada movimento.
*/

// Defina as funções aqui


//      Complete a função com a chamada das funções já criadas
int dirige(int *v,int maxv){
	int maxVetor = maxv;
	int* vetorMov = v;
	int posAtualVetor = 0;
	int dirigindo = 1;		
	while(dirigindo){		
    cout << "Vetor " << vetorMov[0] << endl;
    cout << "Valor do sensor na direita: ";
		int medida = leSensor();
		medida = converteSensor(medida,0,830);
    cout << medida << endl;
		posAtualVetor = insereVetor(0, maxVetor, medida, vetorMov);
    posAtualVetor = posAtualVetor + 1;

    cout << "Valor do sensor na esquerda: ";
    medida = leSensor();
		medida = converteSensor(medida,0,830);
		posAtualVetor = insereVetor(1, maxVetor, medida, vetorMov);
    posAtualVetor = posAtualVetor + 1;

    cout << "Valor do sensor na frente: ";
    medida = leSensor();
		medida = converteSensor(medida,0,830);
		posAtualVetor = insereVetor(2, maxVetor, medida, vetorMov);
    posAtualVetor = posAtualVetor + 1;
    

    cout << "Valor do sensor atrás: ";
    medida = leSensor();
		medida = converteSensor(medida,0,830);
		posAtualVetor = insereVetor(3, maxVetor, medida, vetorMov);
    posAtualVetor = posAtualVetor + 1;
    
		dirigindo = leComando();		
	}
	return posAtualVetor;
}


// O trecho abaixo irá utilizar as funções acima para ler os sensores e o movimento
// do robô e no final percorrer o vetor e mostrar o movimento a cada direção baseado 
// na maior distância a cada movimento

void percorre(int *v,int tamPercorrido){		
	int *vetorMov = v;
	int maiorDir = 0;
	
	for(int i = 0; i < tamPercorrido; i += 4){
		string direcao = dirMaiorDist(&(vetorMov[i]));
    int distancia = maiorDist(&(vetorMov[i]));
    
		cout << "Movimentando em " << distancia << "% para a direção " << direcao << endl;
	}
}

int main(int argc, char** argv) {
	int maxVetor = 100;
	int vetorMov[maxVetor*4];
	int posAtualVet = 0;
	
	posAtualVet = dirige(vetorMov,maxVetor);
	percorre(vetorMov,posAtualVet);
	
	return 0;
}

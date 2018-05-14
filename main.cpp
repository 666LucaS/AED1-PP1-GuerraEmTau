/* Projeto Prático 1 de AED1
 Nome: Guerra em Tau
Alunos: Lucas Da Silva Lima  1515080170 , Nicolas Fernandes de Lima 1615080429
*/
#include <iostream>
using namespace std;
class Capturado{
private:
  string nome, raca;
  unsigned long int forca;
public:
    Capturado(){
      nome = "";
      raca = "";
      forca = 0;
    }
    string getNome(){
      return nome;
    }
    void setNome(string nome){
      this->nome = nome;
    }
    string getRaca(){
      return raca;
    }
    void setRaca(string raca){
      this->raca = raca;
    }
    unsigned long int getForca(){
      return forca;
    }
    void setForca(unsigned long int forca){
      this->forca = forca;
    }
    void mostraCapturados(){
      cout << "(" << getNome() << ", " << getRaca() << ", " << getForca() << ")";
    }
};


template<typename Tipo>
class NoFila{
private:
  NoFila<Tipo> *prox;
  Tipo item;
public:

  NoFila();
  NoFila(Tipo item);

  NoFila<Tipo> * getProx(){
    return prox;
  }
  void setProx(NoFila<Tipo> * prox){
    this->prox = prox;
  }

  Tipo getItem(){
    return item;
  }
  void setItem(Tipo item){
    this->item = item;
  }
};

template<typename Tipo>
NoFila<Tipo>::NoFila(){
  prox = NULL;
}

template<typename Tipo>
NoFila<Tipo>::NoFila(Tipo item){
  this->item = item;
  prox = NULL;
}

template<typename Tipo>
class FilaDinamica{
private:
  NoFila<Tipo> *frente, *tras;
  int contaItens;
public:
  FilaDinamica();

  NoFila<Tipo> * getFrente(){
    return frente;
  }
  void setFrente(NoFila<Tipo> * frente){
    this->frente = frente;
  }
  NoFila<Tipo> * getTras(){
    return tras;
  }
  void setTras(NoFila<Tipo> * tras){
    this->tras = tras;
  }
  int getContaItens(){
    return contaItens;
  }

  bool filaVazia();
  void enfileira(Tipo);
  void desenfileira();
  void mostraFila();
  Tipo itemFrente();
};


template<typename Tipo>
FilaDinamica<Tipo>::FilaDinamica(){
  frente = new NoFila<Tipo>();
  frente->setProx(NULL);
  tras = frente;
  contaItens = 0;
}

template<typename Tipo>
void FilaDinamica<Tipo>::enfileira(Tipo item){
  tras->setProx(new NoFila<Tipo>());
  tras = tras->getProx();
  tras->setItem(item);
  tras->setProx(NULL);
  contaItens++;
}

template<typename Tipo>
void FilaDinamica<Tipo>::desenfileira(){
  NoFila<Tipo> * aux  = frente;
  Tipo item;
  frente = frente->getProx();
  item = frente->getItem();
  delete aux;
}

template<typename Tipo>
void FilaDinamica<Tipo>::mostraFila(){
  NoFila<Tipo> * i  =  frente->getProx();
  cout << "Soldados Capturados: ";
  while(i!=NULL){
    i->getItem().mostraCapturados();
    i = i->getProx();
  }
  cout << endl;
}

template<typename Tipo>
Tipo FilaDinamica<Tipo>::itemFrente(){
  return getFrente()->getItem();
}

template<typename Tipo>
bool FilaDinamica<Tipo>::filaVazia(){
  return frente == tras;
}


class Soldado{
private:
  string nome, raca;
  unsigned long int forca;
  FilaDinamica<Capturado> * capturados;
public:
  Soldado(){
    nome = "";
    raca = "";
    forca = 0;
    capturados = new FilaDinamica<Capturado>();
  }
  string getNome(){
    return nome;
  }
  void setNome(string nome){
    this->nome = nome;
  }
  string getRaca(){
    return raca;
  }
  void setRaca(string raca){
    this->raca = raca;
  }
  unsigned long int getForca(){
    return forca;
  }
  void setForca(unsigned long int forca){
    this->forca = forca;
  }
  FilaDinamica<Capturado> * getCapturados(){
    return capturados;
  }
  void setCapturados(FilaDinamica<Capturado> * capturados){
    this->capturados = capturados;
  }
  void mostraSoldado(){
    cout << "[" << getNome() <<" "<< getRaca() << " ";
  }
  void mostraSoldadoTotal(){
    cout << "[" << getNome() <<" "<< getRaca() << " " << getForca() << "]" << endl;
    getCapturados()->mostraFila();
  }
};


template<typename Tipo>
class NoPilha{
private:
  NoPilha<Tipo> * prox;
  Tipo item;
public:

    NoPilha();
    NoPilha(Tipo item);

    NoPilha<Tipo> * getProx(){
      return prox;
    }
    void setProx(NoPilha<Tipo> * prox){
      this->prox = prox;
    }
    Tipo getItem(){
      return item;
    }
    void setItem(Tipo item){
      this->item = item;
    }
};
template<typename Tipo>
NoPilha<Tipo>::NoPilha(){
  prox = NULL;
}

template<typename Tipo>
NoPilha<Tipo>::NoPilha(Tipo item){
  this->item = item;
  prox = NULL;
}

template<typename Tipo>
class PilhaDinamica{
private:
  NoPilha<Tipo> * topo , *fundo;
  int contaItens;
public:
  PilhaDinamica();

  NoPilha<Tipo> * getTopo(){
    return topo;
  }
  void setTopo(NoPilha<Tipo> * topo){
    this->topo = topo;
  }
  NoPilha<Tipo> * getFundo(){
    return fundo;
  }
  void setFundo(NoPilha<Tipo> * fundo){
    this->fundo = fundo;
  }
  int getContaItens(){
    return contaItens;
  }
  void setContaItems(int contaItens){
    this->contaItens = contaItens;
  }

  void empilha(Tipo);
  void desempilha();
  void mostraPilha();
  Tipo itemTopo();
  bool pilhaVazia();
};

template<typename Tipo>
PilhaDinamica<Tipo>::PilhaDinamica(){
  fundo = new NoPilha<Tipo>();
  fundo->setProx(NULL);
  topo = fundo;
  contaItens = 0;
}

template<typename Tipo>
void PilhaDinamica<Tipo>::empilha(Tipo item){
  NoPilha<Tipo> * aux = new NoPilha<Tipo>();
  topo->setItem(item);
  aux->setProx(topo);
  topo = aux;
  contaItens++;
}

template<typename Tipo>
void PilhaDinamica<Tipo>::desempilha(){
  Tipo item;
  NoPilha<Tipo> * aux = new NoPilha<Tipo>();
  aux = topo;
  topo = topo->getProx();
  item = topo->getItem();
  delete aux;
}

template<typename Tipo>
void PilhaDinamica<Tipo>::mostraPilha(){
  NoPilha<Tipo> * i = topo->getProx();
  while(i!= NULL){
    i->getItem().mostraSoldadoTotal();
    i = i->getProx();
  }

}
template<typename Tipo>
Tipo PilhaDinamica<Tipo>::itemTopo(){
  return getTopo()->getItem();
}

template<typename Tipo>
bool PilhaDinamica<Tipo>:: pilhaVazia(){
  return topo == fundo;
}

class MapaDeBatalha{
private:
  PilhaDinamica<Soldado> * tropa;
public:
  MapaDeBatalha(){
    tropa = new PilhaDinamica<Soldado>();
  }
  PilhaDinamica<Soldado> * getTropa(){
    return tropa;
  }
  void setTropa(PilhaDinamica<Soldado> * tropa){
    this->tropa = tropa;
  }

};

template <typename Tipo>
class NoLista{
private:
  Tipo item;
  NoLista<Tipo> * prox;
public:

  NoLista(){
    prox = NULL;
  }
  NoLista(Tipo item){
    this->item = item;
    prox = NULL;
  }

  NoLista<Tipo> * getProx(){
    return prox;
  }
  void setProx(NoLista<Tipo> * prox){
    this->prox = prox;
  }
  Tipo getItem(){
    return item;
  }
  void setItem(Tipo item){
    this->item = item;
  }

};

template<typename Tipo>
class ListaDinamica{
private:
  int contaItens;
  NoLista<Tipo> * prim,* ult;
public:
  ListaDinamica();

  NoLista<Tipo> * getPrim(){
    return prim;
  }
  void setPrim(NoLista<Tipo> * prim){
    this->prim = prim;
  }
  NoLista<Tipo> * getUlt(){
    return ult;
  }
  void setUlt(NoLista<Tipo> * ult){
    this->ult = ult;
  }
  int getContaItens(){
    return contaItens;
  }
  void setContaItens(int contaItens){
    this->contaItens = contaItens;
  }



  void insere(Tipo);
  NoLista<Tipo>* pred(NoLista<Tipo>*);
  bool listaVazia();
  NoLista<Tipo>* busca(Tipo);
  void remove(NoLista<Tipo>*);
  void print();

};
template <typename Tipo>
ListaDinamica<Tipo>::ListaDinamica() {
    prim = new NoLista<Tipo>();
    prim->setProx(NULL);
    ult = prim;
    contaItens = 0;
}


template <typename Tipo>
void ListaDinamica<Tipo>::insere(Tipo item){
  ult->setProx(new NoLista<Tipo>());
  ult = ult->getProx();
  ult->setProx(NULL);
  ult->setItem(item);
  contaItens++;

}

template<typename Tipo>
NoLista<Tipo> * ListaDinamica<Tipo>::pred(NoLista<Tipo> * r){
    NoLista<Tipo>* p = prim;
    while (p->getProx() != r) {
      p = p->getProx();
    }
    return p;
}

template<typename Tipo>
bool ListaDinamica<Tipo>::listaVazia(){
  return prim == ult;
}

template<typename Tipo>
NoLista<Tipo> * ListaDinamica<Tipo>::busca(Tipo item){
  NoLista<Tipo> * p = prim->getProx();
  while(p != NULL && p->getItem().getNome() != item.getNome() && p->getItem().getRaca() != item.getRaca()) {
    p = p->getProx();
  }
  return p;
}

template<typename Tipo>
void ListaDinamica<Tipo>::remove(NoLista<Tipo> * r){
  if(listaVazia() || r == NULL || r == prim){
    cout << "Impossível Remover" << endl;
  }
  else{
    NoLista<Tipo> * p = pred(r);
    p->setProx(r->getProx());
    if(p->getProx() == NULL) ult = p;
    delete r;

  }
}

template<typename Tipo>
void ListaDinamica<Tipo>::print(){
  NoLista<Tipo> * p = prim->getProx();
  while(p!=NULL){
    p->getItem().mostraSoldadoTotal();
    p = p->getProx();
    cout << endl;
  }
}


template<typename Tipo>
class Hash{
private:
  unsigned long int TAM;
  ListaDinamica<Tipo> * listaColisao;
public:
  unsigned long int getTAM(){
    return TAM;
  }
  void setTAM(unsigned long int TAM){
    this->TAM = TAM;
  }
  ListaDinamica<Tipo> *getListaColisao(){
    return listaColisao;
  }
  void setListaColisao(ListaDinamica<Tipo> * listaColisao){
    this->listaColisao = listaColisao;
  }

  Hash(int);
  void insereTabela(Tipo);
  unsigned long int buscaTabela(Tipo);
  void removeTabela(Tipo);
  void mostraTabela();
  unsigned long int potencia(int, int);
  unsigned long int hashing(string);
};

template<typename Tipo>
Hash<Tipo>::Hash(int TAM){
  this->TAM = TAM;
  listaColisao = new ListaDinamica<Tipo>[TAM];
}

template<typename Tipo>
unsigned long int Hash<Tipo>::potencia(int base, int expoente){
  unsigned long int acumulapot = 1;
  for(int i = 0; i < expoente; i ++){
    acumulapot *= base;
    acumulapot %= getTAM();
  }
  return acumulapot;

}

template<typename Tipo>
unsigned long int Hash<Tipo>::hashing(string nomeERaca){
  int somaNomeRaca = 0, expoente;
  unsigned long int salvaValorASC = 0;
  somaNomeRaca = (int)(nomeERaca.size());
  expoente = somaNomeRaca - 1;
  for(int i = 0; i < somaNomeRaca; i++){
    salvaValorASC += ((int)(tolower(nomeERaca[i])) * potencia(31,expoente))%getTAM();
    expoente--;
  }
  return salvaValorASC%getTAM();

}
template<typename Tipo>
void Hash<Tipo>::insereTabela(Tipo item){
  string nome, raca, nomeERaca;
  nome = item.getNome();
  raca = item.getRaca();
  nomeERaca = nome+raca;
  unsigned long int posicao;
  posicao = hashing(nomeERaca);
  listaColisao[posicao].insere(item);
}

template<typename Tipo>
unsigned long int Hash<Tipo>::buscaTabela(Tipo item){
  string nome,raca;
  unsigned long int posicao;
  nome = item.getNome();
  raca = item.getRaca();
  posicao = hashing(nome+raca);
  return posicao;
}

template<typename Tipo>
void Hash<Tipo>::removeTabela(Tipo item){
  NoLista<Tipo> * aux;
  int posicaoItem = buscaTabela(item);
  aux = listaColisao[posicaoItem].busca(item);
  listaColisao[posicaoItem].remove(aux);
  delete aux;
}

template<typename Tipo>
void Hash<Tipo>::mostraTabela(){
    cout << "TABELA" << endl;
    for (int i = 0; i < TAM; i ++){
      cout << "item " << i << endl;
      listaColisao[i].print();
      cout << endl;
    }
}



int tamanho(string infoCapturados){
  int tamanho = (int)(infoCapturados.size());
  if(tamanho != 0){
    return tamanho;
  }
  return 0;
}

int qntdEspaco(string infoCapturados){
  int contaEspacos = 0;
  for(int i = 0 ; i < tamanho(infoCapturados); i ++){
    if(infoCapturados[i] == ' '){
      contaEspacos++;
    }
  }
  return contaEspacos;
}

int * vetEspaco(string infoCapturados){
  int contador = 0 ;
  int * posicaoEspaco = new int[qntdEspaco(infoCapturados)];
  for(int j = 0; j < tamanho(infoCapturados); j ++){
    if(infoCapturados[j] == ' '){
      posicaoEspaco[contador] = j;
      contador++;
    }
  }
  return posicaoEspaco;
}


string * vetCapturados(string infoCapturados){
  string concatena;
  string * vetAux;
  int tam = qntdEspaco(infoCapturados);
  if(tam == 0){
    return NULL;
  }
  int * espacos = vetEspaco(infoCapturados);
  vetAux = new string[tam];
  for(int i = 0; i < tam-1; i++){
    concatena = "";
    for(int j = espacos[i] ; j < espacos[i+1]; j++){
      concatena += infoCapturados[j];
    }
    vetAux[i] = concatena;
  }
  concatena = "";
  for(int i = espacos[tam-1]; i<tamanho(infoCapturados) ; i++){
    concatena += infoCapturados[i];
  }
  vetAux[tam-1] = concatena;
  return vetAux;
}


PilhaDinamica<Soldado> * ordenaTropa(PilhaDinamica<Soldado> * ordenarPilha){
  if(ordenarPilha->getContaItens() > 1){
    PilhaDinamica<Soldado> * aux = new PilhaDinamica<Soldado>();
    NoPilha<Soldado> * copiaConteudo = ordenarPilha->getTopo()->getProx();
    Soldado soldadoAux;
    while(copiaConteudo != NULL){
      aux->empilha(copiaConteudo->getItem());
      copiaConteudo = copiaConteudo->getProx();
      ordenarPilha->desempilha();
    }
    int qntdItensPilha = aux->getContaItens();
    Soldado * vetSoldado = new Soldado[qntdItensPilha];
    NoPilha<Soldado> * copiaParaVetor = aux->getTopo()->getProx();
    int contador = 0;
    while(copiaParaVetor != NULL){
      vetSoldado[contador] = copiaParaVetor->getItem();
      copiaParaVetor = copiaParaVetor->getProx();
      aux->desempilha();
      contador++;
    }
    for(int i = 0; i < qntdItensPilha ; i ++){
      for(int j = i ; j < qntdItensPilha ; j++){
        if(vetSoldado[i].getForca() >= vetSoldado[j].getForca()){
          soldadoAux = vetSoldado[i];
          vetSoldado[i] = vetSoldado[j];
          vetSoldado[j] = soldadoAux;
        }
      }
    }
    for(int i = 0; i < qntdItensPilha; i++){
      ordenarPilha->empilha(vetSoldado[i]);
    }
    delete [] vetSoldado;
    delete copiaConteudo;
    delete copiaParaVetor;
    delete aux;
    return ordenarPilha;
  }
  return  ordenarPilha;
}

MapaDeBatalha * ordenaTabuleiro(MapaDeBatalha * tabuleiro, int TAM){
  for(int i = 0; i < TAM; i ++){
    if(!tabuleiro[i].getTropa()->pilhaVazia()){
      tabuleiro[i].setTropa(ordenaTropa(tabuleiro[i].getTropa()));
    }
  }
  return tabuleiro;
}

bool verificaPosicao(int coordFinal){
  return (coordFinal>=0 && coordFinal<=3)? true: false;
}


int * mova(int coordI1, int coordJ1, int coordI2, int coordJ2){
  int coordFinalI, coordFinalJ;
  int TAM = 2;
  int * vetCoordenadasFinal;
  if(coordI2>=coordI1 && coordJ2>=coordJ1){
    coordFinalI = coordI2-coordI1;
    coordFinalJ = coordJ2-coordJ1;
  }else if(coordI2<coordI1 && coordJ2>=coordJ1){
    coordFinalI = coordI1-coordI2;
    coordFinalJ = coordJ2-coordJ1;
  }else if (coordI2>=coordI1 && coordJ2<coordJ1){
    coordFinalI = coordI2-coordI1;
    coordFinalJ = coordJ1-coordJ2;
  }else{
    coordFinalI = coordI1-coordI2;
    coordFinalJ = coordJ1-coordJ2;
  }

  vetCoordenadasFinal = new int[TAM];
  vetCoordenadasFinal[0] = coordFinalI;
  vetCoordenadasFinal[1] = coordFinalJ;
  return vetCoordenadasFinal;
}

MapaDeBatalha * formaTropa(MapaDeBatalha * tabuleiro, int ijInicial, int ijFinal){
  PilhaDinamica<Soldado>  pilhaAux = *tabuleiro[ijInicial].getTropa();
  while(!pilhaAux.pilhaVazia()){
    Soldado soldadoAux2 = pilhaAux.getTopo()->getProx()->getItem();
    tabuleiro[ijFinal].getTropa()->empilha(soldadoAux2);
    pilhaAux.desempilha();
  }
  tabuleiro[ijFinal].setTropa(ordenaTropa(tabuleiro[ijFinal].getTropa()));
  tabuleiro[ijInicial].setTropa(new PilhaDinamica<Soldado>());
  return tabuleiro;
}

MapaDeBatalha * deslocamento(MapaDeBatalha * tabuleiro, int ijInicial, int ijFinal){
  tabuleiro[ijFinal] = tabuleiro[ijInicial];
  tabuleiro[ijInicial].setTropa(new PilhaDinamica<Soldado>());
  return tabuleiro;
}

unsigned long int forcaCapturados (Soldado * soldadoLider){
  unsigned long int acumulaForca = 0;
  if(!(soldadoLider->getCapturados()->filaVazia())){
    NoFila<Capturado> * percorreFila = soldadoLider->getCapturados()->getFrente()->getProx();
    while(percorreFila != NULL){
      acumulaForca += percorreFila->getItem().getForca();
      percorreFila = percorreFila->getProx();
    }
    return acumulaForca;
  }
  return acumulaForca;
}

unsigned long int forcaUnidade (PilhaDinamica<Soldado> * unidadeTatica){
  unsigned long int acumulaForca = 0;
  NoPilha<Soldado> * percorrePilha = unidadeTatica->getTopo()->getProx();
  if(!(unidadeTatica->pilhaVazia())){
    while(percorrePilha != NULL){
      acumulaForca += percorrePilha->getItem().getForca();
      percorrePilha = percorrePilha->getProx();
    }
    return acumulaForca;
  }
  return acumulaForca;
}

long double forcaParaComparacao (PilhaDinamica<Soldado> * unidadeTatica){
  long double acumulaForca = 0;
  NoPilha<Soldado> * percorrePilha = unidadeTatica->getTopo()->getProx();
  if(!(unidadeTatica->pilhaVazia())){
    while(percorrePilha != NULL){
      acumulaForca += ( long double)percorrePilha->getItem().getForca();
      percorrePilha = percorrePilha->getProx();
    }
    return acumulaForca;
  }
  return acumulaForca;
}

MapaDeBatalha * realizaAtaque(MapaDeBatalha * tabuleiro, PilhaDinamica<Soldado> * tropaAtacada, Hash<Soldado> * santuario){
  Soldado * soldadoAux = new Soldado();
  string nome, raca;
  unsigned long int forca;
    nome = tropaAtacada->getTopo()->getProx()->getItem().getCapturados()->getFrente()->getProx()->getItem().getNome();
    raca = tropaAtacada->getTopo()->getProx()->getItem().getCapturados()->getFrente()->getProx()->getItem().getRaca();
    forca = tropaAtacada->getTopo()->getProx()->getItem().getCapturados()->getFrente()->getProx()->getItem().getForca();
    tropaAtacada->getTopo()->getProx()->getItem().getCapturados()->desenfileira();
    soldadoAux->setNome(nome);
    soldadoAux->setRaca(raca);
    soldadoAux->setForca(forca);
    santuario->insereTabela(*soldadoAux);
    delete soldadoAux;
  return tabuleiro;
}

MapaDeBatalha * realizaCaptura(MapaDeBatalha * tabuleiro, PilhaDinamica<Soldado> * tropaAtacante,PilhaDinamica<Soldado> * tropaAtacada){
    Capturado * capturadoAux = new Capturado();
    string nome, raca;
    unsigned long int forca;
    nome = tropaAtacada->getTopo()->getProx()->getItem().getNome();
    raca = tropaAtacada->getTopo()->getProx()->getItem().getRaca();
    forca = tropaAtacada->getTopo()->getProx()->getItem().getForca();
    tropaAtacada->desempilha();
    capturadoAux->setNome(nome);
    capturadoAux->setRaca(raca);
    capturadoAux->setForca(forca);
    Soldado * soldadoAux4 = new Soldado();
    soldadoAux4->setNome(tropaAtacante->getTopo()->getProx()->getItem().getNome());
    soldadoAux4->setRaca(tropaAtacante->getTopo()->getProx()->getItem().getRaca());
    soldadoAux4->setForca(tropaAtacante->getTopo()->getProx()->getItem().getForca());
    soldadoAux4->setCapturados(tropaAtacante->getTopo()->getProx()->getItem().getCapturados());
    soldadoAux4->setForca(soldadoAux4->getForca()+forca);
    soldadoAux4->getCapturados()->enfileira(*capturadoAux);
    tropaAtacante->desempilha();
    tropaAtacante->empilha(*soldadoAux4);
    delete soldadoAux4;
    delete capturadoAux;
    return tabuleiro;
}

unsigned long int consultaSantuario(Soldado soldadoAux, Hash<Soldado> * santuario){
  unsigned long int acumulaForca = 0;
  string nome, raca;
  nome = soldadoAux.getNome();
  raca = soldadoAux.getRaca();
  unsigned long int salvaPosicao = santuario->buscaTabela(soldadoAux);
  if(!(santuario->getListaColisao()[salvaPosicao].listaVazia())){
    NoLista<Soldado> * percorreLista = santuario->getListaColisao()[salvaPosicao].getPrim();
    while(percorreLista != NULL){
      if (percorreLista->getProx() == NULL) {
        break;
      }
      acumulaForca += percorreLista->getProx()->getItem().getForca();
      percorreLista = percorreLista->getProx();
      }
    }
  return acumulaForca;
}

void eliminacaoESupremacia(MapaDeBatalha * tabuleiro, int TAM, string racaEliminada){
  int supremaciaIANTECO = 0, supremaciaUMASHI = 0, supremaciaAZURI = 0;
  for(int i = 0; i < TAM; i++){
    if(!tabuleiro[i].getTropa()->pilhaVazia()){
      if(tabuleiro[i].getTropa()->getTopo()->getProx()->getItem().getRaca() == "UMASHI"){
        supremaciaUMASHI = 1;
      }
      else if(tabuleiro[i].getTropa()->getTopo()->getProx()->getItem().getRaca() == "AZURI"){
        supremaciaAZURI = 1;
      }
      else if(tabuleiro[i].getTropa()->getTopo()->getProx()->getItem().getRaca() == "IANTECO"){
        supremaciaIANTECO = 1;
      }
    }
  }
  if(supremaciaIANTECO == 1 && supremaciaAZURI == 0 && supremaciaUMASHI == 0){
    cout << racaEliminada << " foi eliminada" << endl;
    cout << "IANTECO tem supremacia sobre Tau!" << endl;
  }
  else if(supremaciaIANTECO == 0 && supremaciaAZURI == 1 && supremaciaUMASHI == 0){
    cout << racaEliminada << " foi eliminada" << endl;
    cout << "AZURI tem supremacia sobre Tau!" << endl;
  }
  else if(supremaciaIANTECO == 0 && supremaciaAZURI == 0 && supremaciaUMASHI == 1){
    cout << racaEliminada << " foi eliminada" << endl;
    cout << "UMASHI tem supremacia sobre Tau!" << endl;
  }
  else if(supremaciaIANTECO == 1 && supremaciaAZURI == 1 && supremaciaUMASHI == 0){
    cout << "UMASHI foi eliminada" << endl;
  }
  else if(supremaciaIANTECO == 0 && supremaciaAZURI == 1 && supremaciaUMASHI == 1){
    cout << "IANTECO foi eliminada" << endl;
  }
  else if(supremaciaIANTECO == 1 && supremaciaAZURI == 0 && supremaciaUMASHI == 1){
    cout << "AZURI foi eliminada" << endl;
  }

}

unsigned long int potencia1(int base, int expoente){
unsigned long int acumulapot = 1;
  for(int i = 0; i < expoente; i ++){
    acumulapot *= base;
  }
  return acumulapot;
}

unsigned long int conversaoParaInt(string forca){
  int tam = (int)(forca.size());
  unsigned long int resultado = 0;
  int expoente = 0;
  for(int i = tam-1; i>0; i--){
    resultado += ((int)(forca[i] - '0') * potencia1(10,expoente));
    expoente++;
  }
  return resultado;
}

class Entrada{
private:
  string operacao, operacao1;
  int TAM;
  int tamTabela;
  MapaDeBatalha * tabuleiro;
  Hash<Soldado> * santuario;

public:
  Entrada();
  void entradaUniTatica();
  void entradaSantuario();
  void entradaComandos();
};
Entrada::Entrada(){
  operacao = "";
  operacao1 = "";
  TAM = 100;
  tamTabela = 43;
  tabuleiro = new MapaDeBatalha[TAM];
  santuario = new Hash<Soldado>(tamTabela);
}

void Entrada::entradaUniTatica(){
  Soldado * soldado = new Soldado();
  string nomeSoldado, racaSoldado, infoCapturados;
  unsigned long int forcaSoldado, forcaCaturados;
  int posicaoI, posicaoJ, mapeiaPosVet;
  cin >> nomeSoldado >> racaSoldado >> posicaoI >> posicaoJ >> forcaSoldado;
  getline(cin, infoCapturados);
  string * capturadosVetor = vetCapturados(infoCapturados);
  mapeiaPosVet = 10*posicaoI + posicaoJ;

  if(posicaoI < 10 && posicaoJ < 10){
    soldado->setNome(nomeSoldado);
    soldado->setRaca(racaSoldado);
    soldado->setForca(forcaSoldado);
    for(int i = 0; i<qntdEspaco(infoCapturados); i += 3){
      Capturado * soldadoCap = new Capturado();
      soldadoCap->setNome(capturadosVetor[i]);
      soldadoCap->setRaca(capturadosVetor[i+1]);
      soldadoCap->setForca(conversaoParaInt(capturadosVetor[i+2]));

      soldado->getCapturados()->enfileira(*soldadoCap);
    }
    forcaCaturados = forcaCapturados(soldado);
    soldado->setForca(soldado->getForca()+forcaCaturados);
    tabuleiro[mapeiaPosVet].getTropa()->empilha(*soldado);
    delete soldado;
    cin >> operacao;

  }
  else{
    cin >> operacao;
  }
  while(operacao != "STO"){
    if(operacao == "UTA"){
      Soldado * soldado = new Soldado();
      string nomeSoldado, racaSoldado, infoCapturados;
      unsigned long int forcaSoldado, forcaCaturados;
      int posicaoI, posicaoJ, mapeiaPosVet;

      cin >> nomeSoldado >> racaSoldado >> posicaoI >> posicaoJ >> forcaSoldado;
      getline(cin, infoCapturados);
      string * capturadosVetor = vetCapturados(infoCapturados);

      mapeiaPosVet = 10*posicaoI + posicaoJ;

      if(posicaoI < 10 && posicaoJ < 10){
        soldado->setNome(nomeSoldado);
        soldado->setRaca(racaSoldado);
        soldado->setForca(forcaSoldado);
        for(int i = 0; i<qntdEspaco(infoCapturados); i += 3){
          Capturado * soldadoCap = new Capturado();
          soldadoCap->setNome(capturadosVetor[i]);
          soldadoCap->setRaca(capturadosVetor[i+1]);
          soldadoCap->setForca(conversaoParaInt(capturadosVetor[i+2]));
          soldado->getCapturados()->enfileira(*soldadoCap);
          delete soldadoCap;
        }

        forcaCaturados = forcaCapturados(soldado);
        soldado->setForca(soldado->getForca()+forcaCaturados);
        tabuleiro[mapeiaPosVet].getTropa()->empilha(*soldado);

        delete soldado;
        cin >> operacao;
      }
      else{
        cin >> operacao;
      }
    }
  }
}

void Entrada::entradaSantuario(){
  if(operacao == "STO"){
    tabuleiro = ordenaTabuleiro(tabuleiro,TAM);
    string nomeMorto, racaMorto;
    unsigned long int forcaMorto;
    cin >> nomeMorto;
    while(nomeMorto != "CMD"){
      cin >> racaMorto >> forcaMorto;
      Soldado * sold = new Soldado();
      sold->setNome(nomeMorto);
      sold->setRaca(racaMorto);
      sold->setForca(forcaMorto);
      santuario->insereTabela(*sold);
      delete sold;
      cin >> nomeMorto;
    }
    operacao = nomeMorto;
  }
}

void Entrada::entradaComandos(){
  while(operacao1!="FIM"){
    if(operacao == "CMD"){
      cin >> operacao1;
      if(operacao1 == "MOVA"){
        int coordI1,coordI2,coordJ1,coordJ2;
        cin >> coordI1 >> coordJ1 >> coordI2 >> coordJ2;
        if((coordI1>=0 && coordI1<=9) && (coordJ1>=0 && coordJ1<=9) && (coordI2>=0 && coordI2<=9) && (coordJ2>=0 && coordJ2<=9)){
          int * variacaoPosicao;
          int ijInicial, ijFinal;
          variacaoPosicao = mova(coordI1,coordJ1,coordI2,coordJ2);
          ijInicial = 10*coordI1+coordJ1;
          ijFinal = 10*coordI2+coordJ2;
          if(!tabuleiro[ijInicial].getTropa()->pilhaVazia()){
            if(verificaPosicao(variacaoPosicao[0]) && verificaPosicao(variacaoPosicao[1]) && (variacaoPosicao[0]+variacaoPosicao[1] == 3)){
              if(tabuleiro[ijFinal].getTropa()->pilhaVazia()){
                deslocamento(tabuleiro, ijInicial, ijFinal);
              }
              else if(tabuleiro[ijFinal].getTropa()->getTopo()->getProx()->getItem().getRaca() == tabuleiro[ijInicial].getTropa()->getTopo()->getProx()->getItem().getRaca()){
                tabuleiro = formaTropa(tabuleiro,ijInicial, ijFinal);
              }
              else if (tabuleiro[ijInicial].getTropa()->getTopo()->getProx()->getItem().getRaca() != tabuleiro[ijFinal].getTropa()->getTopo()->getProx()->getItem().getRaca()){
                long double forcaAtacado, forcaAtacante;
                forcaAtacante = forcaParaComparacao(tabuleiro[ijInicial].getTropa());
                forcaAtacado = forcaParaComparacao(tabuleiro[ijFinal].getTropa());

                if(forcaAtacante > forcaAtacado){
                  NoPilha<Soldado> * percorrePilha = tabuleiro[ijFinal].getTropa()->getTopo()->getProx();
                  NoFila<Capturado> * percorreFila = tabuleiro[ijFinal].getTropa()->getTopo()->getProx()->getItem().getCapturados()->getFrente()->getProx();
                  if(percorreFila != NULL){
                    tabuleiro = realizaAtaque(tabuleiro,tabuleiro[ijFinal].getTropa(), santuario);
                    cout << "Ataque bem sucedido" << endl;
                  }
                  else{
                    if(percorrePilha !=NULL){
                      tabuleiro = realizaCaptura(tabuleiro,tabuleiro[ijInicial].getTropa(),tabuleiro[ijFinal].getTropa());
                      cout << "Ataque bem sucedido" << endl;
                      if(tabuleiro[ijFinal].getTropa()->pilhaVazia()){
                        string nome, raca, racaEliminada;
                        racaEliminada = tabuleiro[ijFinal].getTropa()->getTopo()->getItem().getRaca();
                        tabuleiro[ijFinal] = tabuleiro[ijInicial];
                        tabuleiro[ijInicial].setTropa(new PilhaDinamica<Soldado>());
                        nome = tabuleiro[ijFinal].getTropa()->getTopo()->getProx()->getItem().getNome();
                        raca = tabuleiro[ijFinal].getTropa()->getTopo()->getProx()->getItem().getRaca();
                        cout << "unidade " << nome << "+" << raca << " avanca para " << "(" << (int)ijFinal/10 << ", " << ijFinal%10 << ")" << endl;
                        eliminacaoESupremacia(tabuleiro,TAM,racaEliminada);
                      }
                    }
                  }
                }
                else if(forcaAtacante <= forcaAtacado*2/3){
                  long double forcaAdicional = (long double)(consultaSantuario(tabuleiro[ijInicial].getTropa()->getTopo()->getProx()->getItem(), santuario)) * 0.7;
                  if(forcaAtacante+forcaAdicional > forcaAtacado){
                    NoPilha<Soldado> * percorrePilha = tabuleiro[ijFinal].getTropa()->getTopo()->getProx();
                    NoFila<Capturado> * percorreFila = tabuleiro[ijFinal].getTropa()->getTopo()->getProx()->getItem().getCapturados()->getFrente()->getProx();
                    if(percorreFila != NULL){
                      tabuleiro = realizaAtaque(tabuleiro,tabuleiro[ijFinal].getTropa(), santuario);
                      cout << "Ataque bem sucedido" << endl;
                    }
                    else{
                      if(percorrePilha!= NULL){
                        tabuleiro = realizaCaptura(tabuleiro,tabuleiro[ijInicial].getTropa(),tabuleiro[ijFinal].getTropa());
                        cout << "Ataque bem sucedido" << endl;
                        if(tabuleiro[ijFinal].getTropa()->pilhaVazia()){
                          string nome, raca, racaEliminada;
                          racaEliminada = tabuleiro[ijFinal].getTropa()->getTopo()->getItem().getRaca();
                          tabuleiro[ijFinal] = tabuleiro[ijInicial];
                          tabuleiro[ijInicial].setTropa(new PilhaDinamica<Soldado>());
                          nome = tabuleiro[ijFinal].getTropa()->getTopo()->getProx()->getItem().getNome();
                          raca = tabuleiro[ijFinal].getTropa()->getTopo()->getProx()->getItem().getRaca();
                          cout << "unidade " << nome << "+" << raca << " avanca para " << "(" << (int)ijFinal/10 << ", " << ijFinal%10 << ")" << endl;
                          eliminacaoESupremacia(tabuleiro,TAM,racaEliminada);
                        }
                      }
                    }
                  }
                  else if(forcaAtacante+forcaAdicional < forcaAtacado){
                    NoPilha<Soldado> * percorrePilha = tabuleiro[ijInicial].getTropa()->getTopo()->getProx();
                    NoFila<Capturado> * percorreFila = tabuleiro[ijInicial].getTropa()->getTopo()->getProx()->getItem().getCapturados()->getFrente()->getProx();
                    if(percorreFila != NULL){
                      tabuleiro = realizaAtaque(tabuleiro,tabuleiro[ijInicial].getTropa(), santuario);
                      cout << "Contra-ataque!" << endl;
                    }
                    else{
                      if(percorrePilha!= NULL){
                        tabuleiro = realizaCaptura(tabuleiro,tabuleiro[ijFinal].getTropa(),tabuleiro[ijInicial].getTropa());
                        cout << "Contra-ataque!" << endl;
                        if (tabuleiro[ijInicial].getTropa()->pilhaVazia()){
                          string nome, raca, racaEliminada;
                          racaEliminada = tabuleiro[ijInicial].getTropa()->getTopo()->getItem().getRaca();
                          tabuleiro[ijInicial] = tabuleiro[ijFinal];
                          tabuleiro[ijFinal].setTropa(new PilhaDinamica<Soldado>());
                          nome = tabuleiro[ijInicial].getTropa()->getTopo()->getProx()->getItem().getNome();
                          raca = tabuleiro[ijInicial].getTropa()->getTopo()->getProx()->getItem().getRaca();
                          cout << "unidade " << nome << "+" << raca << " avanca para " << "(" << (int)ijInicial/10 << ", " << ijInicial%10 << ")" << endl;
                          eliminacaoESupremacia(tabuleiro,TAM,racaEliminada);
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      if(operacao1  == "FORCA"){
        int coordI,coordJ;
        unsigned long int forcaUta;
        cin >> coordI >> coordJ;
        if((coordI>=0 && coordI<=9) && (coordJ>=0 && coordJ<=9)){
          NoPilha<Soldado> * percorrePilha = tabuleiro[10*coordI+coordJ].getTropa()->getTopo()->getProx();
          if(percorrePilha == NULL){
            cout << "-1" << endl;
          }
          else{
            forcaUta = forcaUnidade(tabuleiro[10*coordI+coordJ].getTropa());
            cout << forcaUta << endl;
          }
        }
        else{
          cout << "-1" << endl;
        }
      }
      if(operacao1 == "FORCA_RACA"){
        string nomeRaca = "";
        cin >> nomeRaca;
        unsigned long int acumulaForcaRaca = 0;
        for(int i = 0 ; i < TAM; i ++){
          if(!(tabuleiro[i].getTropa()->pilhaVazia())){
            if(nomeRaca == tabuleiro[i].getTropa()->getTopo()->getProx()->getItem().getRaca()){
              acumulaForcaRaca+=forcaUnidade(tabuleiro[i].getTropa());
            }
          }
        }
        cout << acumulaForcaRaca << endl;
      }
      if(operacao1 == "TERR"){
        int coordI, coordJ, mapeiaPosicao;
        cin >> coordI >> coordJ;
        if((coordI>=0 && coordI<=9) && (coordJ>=0 && coordJ<=9)){
          mapeiaPosicao = 10*coordI + coordJ;
          PilhaDinamica<Soldado> * aux = new PilhaDinamica<Soldado>();
          NoPilha<Soldado> * copiaConteudo = tabuleiro[mapeiaPosicao].getTropa()->getTopo()->getProx();
          while(copiaConteudo != NULL){
            aux->empilha(copiaConteudo->getItem());
            copiaConteudo = copiaConteudo->getProx();
          }
          if(aux->getContaItens() == 1){
            NoPilha<Soldado> * verificaPilha = tabuleiro[mapeiaPosicao].getTropa()->getTopo();
            if(verificaPilha->getProx() != NULL){
              tabuleiro[mapeiaPosicao].getTropa()->getTopo()->getProx()->getItem().mostraSoldado();
              unsigned long int forcaTropa = tabuleiro[mapeiaPosicao].getTropa()->getTopo()->getProx()->getItem().getForca();
              cout << forcaTropa << "]";
              cout << endl;
            }
            else if (verificaPilha != NULL){
              tabuleiro[mapeiaPosicao].getTropa()->getTopo()->getItem().mostraSoldado();
              unsigned long int forcaTropa = tabuleiro[mapeiaPosicao].getTropa()->getTopo()->getItem().getForca();
              cout << forcaTropa << "]";
              cout << endl;
            }
          }
          else if(aux->getContaItens() > 1){
            cout << "[";
            tabuleiro[mapeiaPosicao].getTropa()->getTopo()->getProx()->getItem().mostraSoldado();
            unsigned long int forcaTropa = forcaUnidade(tabuleiro[mapeiaPosicao].getTropa());
            cout << forcaTropa << "]";
            cout << "]" << endl;
          }
          else{
            cout << "[ ]" << endl;
          }
          delete aux;
        }
        else{
          cout << "[ ]" << endl;
        }
      }
      if(operacao1 == "MAX_ATAQUE"){
        ListaDinamica<unsigned long int> forcaObtida;
        int coordI1, coordJ1, ijInicial, coordI2, coordJ2;
        cin >> coordI1 >> coordJ1;
        ijInicial = 10*coordI1+coordJ1;
        if((coordI1>=0 && coordI1<=9) && (coordJ1>=0 && coordJ1<=9)){
          if(!tabuleiro[ijInicial].getTropa()->pilhaVazia()){
            int contaPilhasVazias = 0, contaPerdeAlguns = 0;
            int * variacaoPosicao;
            for(int i = 0 ; i < TAM; i ++){
              coordI2 = (int)(i/10);
              coordJ2 = i%10;
              variacaoPosicao = mova(coordI1,coordJ1,coordI2,coordJ2);
              int ijFinal = 10*coordI2+coordJ2;
              if(!(tabuleiro[ijFinal].getTropa()->pilhaVazia())){
                if(verificaPosicao(variacaoPosicao[0]) && verificaPosicao(variacaoPosicao[1]) && variacaoPosicao[0]+variacaoPosicao[1] == 3){
                  if(tabuleiro[ijInicial].getTropa()->getTopo()->getProx()->getItem().getRaca() != tabuleiro[ijFinal].getTropa()->getTopo()->getProx()->getItem().getRaca()){
                    contaPilhasVazias++;
                    long double forcaAtacante, forcaAtacado;
                    forcaAtacante = forcaParaComparacao(tabuleiro[ijInicial].getTropa());
                    forcaAtacado = forcaParaComparacao(tabuleiro[ijFinal].getTropa());
                    Soldado * soldadoAux3 = new Soldado();
                    soldadoAux3->setNome(tabuleiro[ijFinal].getTropa()->getTopo()->getProx()->getItem().getNome());
                    soldadoAux3->setRaca(tabuleiro[ijFinal].getTropa()->getTopo()->getProx()->getItem().getRaca());
                    soldadoAux3->setForca(tabuleiro[ijFinal].getTropa()->getTopo()->getProx()->getItem().getForca());
                    if(forcaAtacante>forcaAtacado){
                      contaPerdeAlguns++;
                      if(tabuleiro[ijFinal].getTropa()->getTopo()->getProx()->getItem().getCapturados()->filaVazia()){
                        forcaObtida.insere((unsigned long int)forcaAtacante + tabuleiro[ijFinal].getTropa()->getTopo()->getProx()->getItem().getForca());
                      }
                      else{
                        forcaObtida.insere((unsigned long int)forcaAtacante + forcaCapturados(soldadoAux3));
                      }
                    }
                    else if (forcaAtacante <= forcaAtacado*2/3){
                      long double forcaAdicional = (long double)(consultaSantuario(tabuleiro[ijInicial].getTropa()->getTopo()->getProx()->getItem(), santuario)) * 0.7;
                      if(forcaAtacante+forcaAdicional > forcaAtacado){
                        contaPerdeAlguns++;
                        if(tabuleiro[ijFinal].getTropa()->getTopo()->getProx()->getItem().getCapturados()->filaVazia()){
                          forcaObtida.insere((unsigned long int)forcaAtacante + tabuleiro[ijFinal].getTropa()->getTopo()->getProx()->getItem().getForca());
                        }
                        else{
                          forcaObtida.insere((unsigned long int)forcaAtacante + forcaCapturados(soldadoAux3));
                        }
                      }
                    }
                    delete soldadoAux3;
                  }
                }
              }
            }
            if(contaPilhasVazias == 0 ){
              cout << "-1" << endl;
            }
            else if (contaPerdeAlguns == 0){
              cout << forcaUnidade(tabuleiro[ijInicial].getTropa()) << endl;
            }
            else{
              int qntdForcas = forcaObtida.getContaItens();
              unsigned long int * vetForcas = new unsigned long int[qntdForcas];
              unsigned long int forcaMax;
              int cont = 0;
              NoLista<unsigned long int> * percorreLista = forcaObtida.getPrim()->getProx();
              while(percorreLista!= NULL){
                vetForcas[cont] = percorreLista->getItem();
                cont++;
                percorreLista = percorreLista->getProx();
              }
              forcaMax = vetForcas[0];
              for(int i = 0; i < qntdForcas; i++){
                if(forcaMax <= vetForcas[i]){
                  forcaMax = vetForcas[i];
                }
              }
              cout << forcaMax << endl;
              delete [] vetForcas;
            }
          }
          else{
            cout << "-1" << endl;
          }
        }
        else{
          cout << "-1" << endl;
        }
      }
    }
  }
}

int main(){
  Entrada entrada;
  entrada.entradaUniTatica();
  entrada.entradaSantuario();
  entrada.entradaComandos();
  return 0;
}

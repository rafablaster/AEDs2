/*	
	Victor Hugo Tozzo Filho	- 2020.1.08.018
	Pedro Henrique Alves Barbosa - 2022.1.08.043
	Rafael Silva Fortuna- 2022.1.08.026	
	
        !!!!!!AVISO IMPORTANTE!!!!!!
        Nesta implementação de lista encadiada, 
        o primeiro slot (o primeiro nó da lista), ficará sempre vazio, contendo valores nulos
        ou seja a lista começa a partir do segundo nó
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

struct Veiculo{
    string modelo;
    string marca;
    string versao;
    string ano;
    string kilometragem;
    string motor;
    string consumo;
    string moua;
    string direcao;
    string cor;
    string portas;
    string placa;
    float preco;
    struct Veiculo *prox;
};

struct Cabecalho{
    int tam;
    struct Veiculo *inicio;    
};

int resultado;

void imprime(Cabecalho *exemplo){
        Veiculo *percorredor;
        percorredor = exemplo->inicio;
        while (percorredor != NULL){
            cout << percorredor->modelo << " ";
            cout << percorredor->marca << " ";
            cout << percorredor->versao << " ";
            cout << percorredor->ano << " ";
            cout << percorredor->kilometragem << " "; 
            cout << percorredor->motor << " "; 
            cout << percorredor->consumo << " "; 
            cout << percorredor->moua << " "; 
            cout << percorredor->direcao << " "; 
            cout << percorredor->cor << " "; 
            cout << percorredor->portas << " ";
            cout << percorredor->placa << " ";  
            cout << percorredor->preco << endl;
            percorredor = percorredor->prox;
            } 
cout << "-------------------------------------------------------------------------------\n";
}

void imprime_placa(Cabecalho *placas){
    Veiculo *percorredor;
        percorredor = placas->inicio;
        while (percorredor != NULL){
            cout << percorredor->placa << " - " << percorredor->modelo << "\n";
            percorredor = percorredor->prox;
        }
}

void busca(Cabecalho *cabeca, string placaexemplo){
    Veiculo *percorredor;
    percorredor = cabeca->inicio->prox;
    int pos = 1;
    while (pos <= cabeca->tam){
        if(percorredor->placa != placaexemplo){
        percorredor = percorredor->prox;
        pos++;
        }else if(percorredor->placa == placaexemplo){
            cout << "Carro encontrado na posição " << pos <<  endl;
            resultado = pos;
            pos = cabeca->tam+1;
            }else cout << "Tem essa placa aqui não, fiotão.";
    }
}

void exclui(Cabecalho *cabeca,string placaexemplo){
    Veiculo *percorredor;
    Veiculo *ant;
    percorredor = cabeca->inicio;
    while(percorredor->placa != placaexemplo){
        ant =percorredor;
        percorredor = percorredor->prox;
    }
    ant->prox = percorredor->prox;
    free(percorredor);   
    cabeca->tam--;
}

void insere_inicio(Cabecalho *cabeca , string modelo,string marca,string versao,string ano,string kilometragem,string motor,string consumo,string moua,string direcao,string cor,string portas,string placa,float preco){
    Veiculo *novo = new Veiculo;
    novo->modelo = modelo;
    novo->marca = marca;
    novo->versao = versao;
    novo->ano = ano;
    novo->kilometragem = kilometragem;
    novo->motor = motor;
    novo->consumo = consumo;
    novo->moua = moua;
    novo->direcao = direcao;
    novo->cor = cor;
    novo->portas = portas;
    novo->placa = placa;
    novo->preco = preco;
    novo->prox = cabeca->inicio->prox;
    cabeca->inicio->prox = novo;
    cabeca->tam++;
    cout<<"veiculo inserido no inicio da lista "  << endl;
}

void insere_fim(Cabecalho *cabeca , string modelo,string marca,string versao,string ano,string kilometragem,string motor,string consumo,string moua,string direcao,string cor,string portas,string placa,float preco){
    Veiculo *novo = new Veiculo;
    novo->modelo = modelo;
    novo->marca = marca;
    novo->versao = versao;
    novo->ano = ano;
    novo->kilometragem = kilometragem;
    novo->motor = motor;
    novo->consumo = consumo;
    novo->moua = moua;
    novo->direcao = direcao;
    novo->cor = cor;
    novo->portas = portas;
    novo->placa = placa;
    novo->preco = preco;
    Veiculo *percorredor;
    percorredor = cabeca->inicio;
    while(percorredor->prox != NULL){percorredor = percorredor->prox;}
    percorredor->prox = novo;
    novo->prox = NULL;
    cabeca->tam++;
    cout<<"veiculo inserido no fim da lista "  << endl;
}


void inserir_ordenado(Cabecalho *placas, string placa, string modelo){
    Veiculo *aux, *novo = new Veiculo;

    if(novo){
        novo->placa = placa;
        novo->modelo = modelo;
        if(placas->inicio == NULL){ 
            novo->prox = NULL;
            placas->inicio = novo;
        }
        else if(novo->placa < placas->inicio->placa){ 
            novo->prox = placas->inicio;
            placas->inicio = novo;
        }
        else{
            aux = placas->inicio;
            while(aux->prox && novo->placa > aux->prox->placa)
                aux = aux->prox;
            novo->prox = aux->prox;
            aux->prox = novo;
        }
    }
    else
        printf("Erro ao alocar memoria!\n");
}

void ordena_placa(Cabecalho *cabeca, Cabecalho *placas){
    Veiculo *percorredor;
    percorredor = cabeca->inicio->prox;
    while (percorredor != NULL){
        inserir_ordenado(placas,percorredor->placa,percorredor->modelo);
        percorredor = percorredor->prox;
    }
}

void encerra_lista(Cabecalho *cabeca) {
	Veiculo *ant = cabeca->inicio;
	Veiculo *pont = cabeca->inicio;
	while(ant != NULL){
		pont = ant->prox;
		delete(ant);
		ant = pont;
	}
	delete(cabeca);
        cout << "-As listas/pilhas/filas foram desalocadas."<<endl;
}
void insere_fim(Cabecalho *pilha, string direcao, string modelo, string moua){
      Veiculo *percorredor, *novo = new Veiculo;
      novo->direcao = direcao;
      novo->modelo = modelo;
      novo->moua = moua;
      novo->prox = NULL;
      if (pilha->tam == 0){
        novo->direcao = direcao;
        novo->modelo = modelo;
        pilha->inicio = novo;
        pilha->tam++;
      }else{
        percorredor = pilha->inicio; 
        while (percorredor->prox != NULL){
        percorredor = percorredor->prox;
        }
        novo->direcao = direcao;
        percorredor->prox = novo;
        pilha->tam++;
        }
        //cout<<"Carro Inserido" <<  endl;
            
}
void remove_fim(Cabecalho *pilha){
    Veiculo *percorredor, *ant, *antant;
    percorredor = pilha->inicio;
    ant = percorredor;
    while (percorredor->prox != NULL){
        ant = percorredor;
        percorredor = percorredor->prox;
    }
        if(pilha->tam > 0){
            ant->prox = NULL;
            free(percorredor);
            pilha->tam--;
            //cout << "Ultimo elemento da lista removido!\n";
        }else
        {
           // cout << "lista vazia\n";
        }
        
}

void cria_pilha(Cabecalho *cabeca, Cabecalho *pilha){
  Veiculo *percorredor, *per2;
  percorredor = cabeca->inicio->prox;
  while (percorredor != NULL){
    if (percorredor->direcao == "Hidráulica"){
        insere_fim(pilha,percorredor->direcao, percorredor->modelo, percorredor->moua);
    }else{ 
        remove_fim(pilha);}
    percorredor = percorredor->prox;
  }
  per2 = pilha->inicio;
  while (per2 != NULL){
    cout << per2->direcao<< " - "<< per2->modelo <<" - "<< per2->moua << endl;
    per2 = per2->prox;
  }
}

void remove_inicio(Cabecalho *fila){
    Veiculo *primeiro;
        if(fila->tam > 0){
            primeiro = fila->inicio;
            fila->inicio = fila->inicio->prox; 
            free(primeiro);
            fila->tam--;
            //cout << "Primeiro elemento da lista removido!\n";
        }else
        {
            //cout << "pilha vazia\n";
        }
        
}
void cria_fila(Cabecalho *cabeca, Cabecalho *fila){
    Veiculo *novo, *perc, *aux = fila->inicio;
    Veiculo *percorredor = cabeca->inicio->prox;
    int tam = 0;
    while (percorredor != NULL){
        if(percorredor->moua == "Automático"){
            insere_fim(fila,percorredor->direcao,percorredor->modelo,percorredor->moua);
        }else{
            remove_inicio(fila);
        }
        percorredor = percorredor->prox;
    }
    perc = fila->inicio;
    while (perc != NULL){
        cout << perc->direcao<< " - "<< perc->modelo <<" - "<< perc->moua << endl;
        perc = perc->prox;
    }
    cout << "\nFila de carros construida!\n" << endl;
}

void salva(Cabecalho *exemplo){
    ofstream myfile("BD_veiculos_2.txt");
        if(myfile.is_open()){
        Veiculo *percorredor;
        percorredor = exemplo->inicio->prox;
        while(percorredor != NULL ){
            myfile << percorredor->modelo << " ";
            myfile << percorredor->marca << " ";
            myfile << percorredor->versao << " ";
            myfile << percorredor->ano << " ";
            myfile << percorredor->kilometragem << " "; 
            myfile << percorredor->motor << " "; 
            myfile << percorredor->consumo << " "; 
            myfile << percorredor->moua << " "; 
            myfile << percorredor->direcao << " "; 
            myfile << percorredor->cor << " "; 
            myfile << percorredor->portas << " ";
            myfile << percorredor->placa << " ";  
            if(percorredor->prox==NULL)
            {myfile << percorredor->preco;} 
            else
            myfile << percorredor->preco << endl;
            percorredor = percorredor->prox;
        }}
}

int main(int argc, char**argv){
    string line;
    ifstream myfile("BD_veiculos_2.txt");

    Cabecalho *cabeca = new Cabecalho;
    Cabecalho *placas = new Cabecalho;
    Cabecalho *pilha  = new Cabecalho;
    pilha->tam = 0;
    Cabecalho *fila   = new Cabecalho;
    fila->tam = 0;

    Veiculo *bd;
    cabeca->inicio = new Veiculo;
    bd = cabeca->inicio;
    if(myfile.is_open()){
        while (!myfile.eof()){
            bd->prox = new Veiculo;
            bd = bd->prox;

            myfile >> bd->modelo;
            myfile >> bd->marca;
            myfile >> bd->versao;
            myfile >> bd->ano;
            myfile >> bd->kilometragem; 
            myfile >> bd->motor; 
            myfile >> bd->consumo; 
            myfile >> bd->moua; 
            myfile >> bd->direcao; 
            myfile >> bd->cor;
            myfile >> bd->portas;
            myfile >> bd->placa; 
            myfile >> bd->preco;
            
            cabeca->tam++;
        }
        myfile.close();

    int resp, caso, caso1, caso3;
    string modelo,marca,versao,ano,kilometragem,motor,consumo,moua,direcao,cor,portas,placa;
    float preco;

    do{
        cout << " Digite : (1) para buscar\n Digite : (2) para adicionar\n Digite : (3) para relatórios\n Digite : (4) para empilhar carros (hidraulico add, eletrico rm)\n Digite : (5) para enfileirar carros (automatico add, manual rm)\n Digite : (6) para sair\n";
        cin >> caso;
        switch (caso){
        case 1:
            cout << "Digite a placa a ser buscada\n";
            cin >> placa;
            busca(cabeca,placa);
            cout << "Deseja excluir?\n Sim ! exclui essa lata velha - digite(1).\n Não, nuca, não exlua, pf! - digite(2)\n";
            cin >> caso1;
            if(caso1 == 1){
                exclui(cabeca,placa);
            }
            break;
        case 2:
            cout << "Digite modelo\n";
                     cin >> modelo;
            cout << "Digite marca\n";
                     cin >> marca;
            cout << "Digite versao\n";
                     cin >> versao;
            cout << "Digite ano\n";
                     cin >> ano;
            cout << "Digite kilometragem\n";
                     cin >> kilometragem;
            cout << "Digite motor\n";
                     cin >> motor;
            cout << "Digite consumo\n";
                     cin >> consumo;
            cout << "Digite moua\n";
                     cin >> moua;
            cout << "Digite direcao\n";
                     cin >> direcao;
            cout << "Digite cor\n";
                     cin >> cor;
            cout << "Digite portas\n";
                     cin >> portas;
            cout << "Digite placa\n";
                     cin >> placa;
            cout << "Digite preco (em float, ex: 12345.00)\n";
                     cin >> preco;

            cout << "adicionando......\n";
            insere_fim(cabeca,modelo,marca,versao,ano,kilometragem,motor,consumo,moua,direcao,cor,portas,placa,preco);
        break;
        case 3:
            cout << "Mostrar os veiculos = digite (1)\nOrdenar os veiculos pelas placas = digite (2)\n";
            cin >> caso3;
            if(caso3 == 1){
                imprime(cabeca);
                }else 
                ordena_placa(cabeca,placas);
                imprime_placa(placas);
        break;
        case 4:
        cria_pilha(cabeca,pilha);
        break;
        case 5:
        cria_fila(cabeca,fila);
        break;
        case 6:
            salva(cabeca);
            resp = 1;
        break;
        default:
            break;
        }
    } while (resp != 1);
    encerra_lista(cabeca); encerra_lista(placas);encerra_lista(pilha); encerra_lista(fila);
    }else
        cout << "unable to open the file";}

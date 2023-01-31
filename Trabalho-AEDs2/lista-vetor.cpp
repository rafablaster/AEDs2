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

};

Veiculo *bd[50];
float vetprecos[50];
float vex[11];
string vetplacas[50];

int r = -2;
int newtam;

void imprime(Veiculo *bd[],int tam){
    for(int j = 0; j < tam; j++ ){
            cout << bd[j]->modelo << " ";
            cout << bd[j]->marca << " ";
            cout << bd[j]->versao << " ";
            cout << bd[j]->ano << " ";
            cout << bd[j]->kilometragem << " "; 
            cout << bd[j]->motor << " "; 
            cout << bd[j]->consumo << " "; 
            cout << bd[j]->moua << " "; 
            cout << bd[j]->direcao << " "; 
            cout << bd[j]->cor << " "; 
            cout << bd[j]->portas << " ";
            cout << bd[j]->placa << " ";  
            cout << bd[j]->preco << endl; 
        }
}
void imprime1(Veiculo *bd[],int tam,int j){
            cout << bd[j]->modelo << " ";
            cout << bd[j]->marca << " ";
            cout << bd[j]->versao << " ";
            cout << bd[j]->ano << " ";
            cout << bd[j]->kilometragem << " "; 
            cout << bd[j]->motor << " "; 
            cout << bd[j]->consumo << " "; 
            cout << bd[j]->moua << " "; 
            cout << bd[j]->direcao << " "; 
            cout << bd[j]->cor << " "; 
            cout << bd[j]->portas << " ";
            cout << bd[j]->placa << " ";  
            cout << bd[j]->preco << endl; 
}
int busca(Veiculo *bd[],int tam,string exemplo){
    //BUSCA    
    for(int j = 0; j < tam; j++ ){
        //oq vai ser buscado (placa)
        if (bd[j]->placa == exemplo){
            r = j;
            cout << "\nEncontrado na posição = " << j+1 << ".\n";
            j = tam;
        }if(j == tam-1 && r == -2){ 
        r = -1;
        }  
    }
return r;
}
int exclui(Veiculo *bd[],int *tam,string ex){
    cout << "buscando..." <<endl;
    bd[busca(bd,*tam,ex)];
    bd[r] = NULL;
    for (int i = r; i < *tam; i++){
        bd[i] = bd[i+1];
    }
    bd[*tam] = NULL;
    *tam = *tam-1;
    cout << "cvetprecoso na posição "<< r <<" excluido!\n";
    return 0;
}

int insere(Veiculo *bd[], int *tam,string model,string marc,string ver,string an,string mot,string kilo,string con,string mou,string dire,string tinta,string port,string plac,float prec){  
        if(*tam > 49){
        cout << "\nOps.......\nParece que n vai dar não, ta lotado!\n\n";
        } 
        if (bd[*tam] == NULL && *tam < 50){
            bd[*tam] = new Veiculo; 
            bd[*tam]->modelo = model;
            bd[*tam]->marca = marc;
            bd[*tam]->versao = ver;
            bd[*tam]->ano = an;
            bd[*tam]->motor = mot; 
            bd[*tam]->kilometragem = kilo; 
            bd[*tam]->consumo = con; 
            bd[*tam]->moua = mou; 
            bd[*tam]->direcao = dire; 
            bd[*tam]->cor = tinta; 
            bd[*tam]->portas = port;  
            bd[*tam]->placa = plac; 
            bd[*tam]->preco = prec;    
        *tam = *tam +1;
    }
    return 0;   
}
int ordprecos(Veiculo *bd[],int tam,float vetprecos[]){
    for (int i = 0; i < tam; i++){
       vetprecos[i] = bd[i]->preco;  
    }
    sort(&vetprecos[0],&vetprecos[tam]);
    return 0;
} 
int ordplacas(Veiculo *bd[],int tam,string vetplacas[]){
    for (int i = 0; i < tam; i++){
        vetplacas[i]=bd[i]->placa;
    }
    sort(&vetplacas[0],&vetplacas[tam]);
    return 0;
}

void dezprox(float vetprecos[], int tam, float x,int k){
    for (int i = 0; i < tam; i++){
       vetprecos[i] = bd[i]->preco;  
    }
	priority_queue<pair<int, int> > pq;
	for (int i = 0; i < k; i++)
		pq.push({ abs(vetprecos[i] - x), i });
	for (int i = k; i < tam; i++) {
		float diff = abs(vetprecos[i] - x);
		if (diff > pq.top().first)
			continue;
		pq.pop();
		pq.push({ diff, i });}
	while (pq.empty() == false) {
        for(int j = 0; j < tam; j++ ){
        if (bd[j]->preco == vetprecos[pq.top().second]){
            imprime1(bd,tam,j);
            j = tam;}}
		pq.pop();}
}
void salva(Veiculo *bd[], int tam){
    ofstream myfile("BD_veiculos_2.txt");
        if(myfile.is_open()){
        for(int j = 0; j < tam; j++ ){
            myfile << bd[j]->modelo << " ";
            myfile << bd[j]->marca << " ";
            myfile << bd[j]->versao << " ";
            myfile << bd[j]->ano << " ";
            myfile << bd[j]->kilometragem << " "; 
            myfile << bd[j]->motor << " "; 
            myfile << bd[j]->consumo << " "; 
            myfile << bd[j]->moua << " "; 
            myfile << bd[j]->direcao << " "; 
            myfile << bd[j]->cor << " "; 
            myfile << bd[j]->portas << " ";
            myfile << bd[j]->placa << " ";  
            if(bd[j]==bd[tam-1])
            {myfile << bd[j]->preco;} 
            else
            myfile << bd[j]->preco << endl;
        }}
}

int main(int argc, char**argv){
    string line;
    ifstream myfile("BD_veiculos_2.txt");
    int tam = 0;
    if(myfile.is_open()){
        while (!myfile.eof())
        {
            bd[tam] = new Veiculo;          
            myfile >> bd[tam]->modelo ;
            myfile >> bd[tam]->marca ;
            myfile >> bd[tam]->versao;
            myfile >> bd[tam]->ano;
            myfile >> bd[tam]->kilometragem; 
            myfile >> bd[tam]->motor; 
            myfile >> bd[tam]->consumo; 
            myfile >> bd[tam]->moua; 
            myfile >> bd[tam]->direcao; 
            myfile >> bd[tam]->cor; 
            myfile >> bd[tam]->portas;  
            myfile >> bd[tam]->placa; 
            myfile >> bd[tam]->preco;
        
        tam++;
        }
        myfile.close();
        imprime(bd,tam);
    for(int i = tam; i < 50;i++){
        bd[i] = NULL;
    }

    int c;

    while(c != 5){  
    int condition;
    cout << "q q manda, patrão?\n1 = busca(exluir/infos/precos_prox). \n2 = adicionar um outro veiculo \n3 = mostrar as placas ordenadas. \n4 = ver lista atual de todos os veiculos.\n5 = SAIR \n ";
    cin >> condition;
    string md;
    string mar;
    string ver;
    string year;
    string kms;
    string pot;
    string con;
    string moa;
    string dir;
    string color;
    string door;
    string plaq;
    float price;

        int expression;
        string exemplim;
    switch (condition)
    {
    case 1:
        cout << "\nqual a placa do carro?\n";
        cin >> exemplim;
        busca(bd,tam,exemplim);
        cout << "\n1 - exibir infos \n2 - excluir \n3 - mostrar dez preços proximos\n";
        cin >> expression;
        switch (expression)
        {
        case 1:
            imprime1(bd,tam,r);
            break;
        case 2:
            exclui(bd,&tam,exemplim);
            break;
        case 3:
            dezprox(vetprecos,tam,vetprecos[r],10);
            break;
        default:cout << "?";
            break;
        }
    break;
    case 2:
        cout << "INSIRA: modelo:";cin >> md;
        cout << "INSIRA: marca:";cin >> mar;
        cout << "INSIRA: versao (ex:hat sedan SUV....):";cin >> ver;
        cout << "INSIRA: ano:";cin >> year;
        cout << "INSIRA: kilometragem:";cin >> kms;
        cout << "INSIRA: motor(ex: 1.0 2.0 1.6....):";cin >> pot;
        cout << "INSIRA: flex? gasolina?:";cin >>con;
        cout << "INSIRA: manual ou automatico?:";cin >> moa;
        cout << "INSIRA: direção?:";cin >> dir;
        cout << "INSIRA: cor:";cin >> color;
        cout << "INSIRA: n de portas:";cin >> door;
        cout << "INSIRA: placa:";cin >> plaq;
        cout << "INSIRA: preço (EM FLOAT) ex: 1234.00 :";cin >> price;
        insere(bd,&tam,md,mar,ver,year,kms,pot,con,moa,dir,color,door,plaq,price);
        break;
    case 3:
        ordplacas(bd,tam,vetplacas);
        for (int i = 0; i < tam; i++){
        cout << vetplacas[i] <<"\n";}
        break;
    case 4:
        imprime(bd,tam);
        break;
    case 5:
    printf("flw");
        salva(bd,tam);
        c=5;
        break;
    default:
        printf("?");
        break;
    }}
    cout << "LISTA FINAL DE VEICULOS\n-----------------------------\n";
    imprime(bd,tam);
    
    }else
        cout << "unable to open the file";}

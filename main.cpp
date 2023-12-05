/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;
void resultado(bool t){
    if(t == true){
        cout << "Você venceu o jogo! Parabéns..." << endl;
        } else cout << "Não foi dessa vez...Tente novamente" << endl;
}
int main() {
cout << "#Bem-vindos ao jogo do Silvio Santos!" << endl;
int erros = 0;
char respCorreta[40];
char respGamer; // respGamer = resposta do jogador;
char forca[40];
int P;
char dica[80];

string juntaletra;
bool jogoGanho = false; // ela vai indicar se o jogador ganhou ou nn

cout << "O tema é: " ;
cin >> dica;
cout << "Digite apenas uma letra por vez" << endl;
cout << "palavra: ";
cin >> respCorreta;
system("clear");
int N = strlen(respCorreta);// conta as letras de respCorreta
cout << "A palavra tem " << N << " letras" << endl;
cout << "Advinhe:" << endl;

    for (int i = 0; i < N; i++) {
        forca[i] = '_';// estou preenchendo a variável forca com _
        cout << "_ "; // não dá certo imprimir forca[i] porque os _ vão ficar juntos
}
cout << endl;

    while (erros < N*2 && !jogoGanho) { // loop para ler as letras até a quantidade de erros atingida ou até a pessoa ganhar
      cin >> respGamer;
      bool acertou = false;// para verificar se acertou a letra
    for (int l = 0; l < N; l++) {
        if (respCorreta[l] == respGamer && forca[l] ) {
          forca[l] = respGamer;
            acertou = true;
          if(acertou == true){
            P+=100;
        }
    }
 }
   cout << "Você tem " << P << " reais" << endl;
    if (!acertou) {
       erros++;
    }
    
    juntaletra = "";
    for (int k = 0; k < N; k++) {
       juntaletra += forca[k];
       juntaletra += " ";
    }

 cout << juntaletra << endl;

    if (strcmp(respCorreta, forca) == 0) {// quando igualamos a 0 significa que as strings são iguais
       jogoGanho = true;
       resultado(jogoGanho);
       ofstream fout; //objeto fout pra escrita
       fout.open("dadosdosjogadores.txt", ios_base::app); //arquivo para guardar dados
       string nome;
       cout << "Digite seu nome aí, por favor: ";
       cin >> nome;
       fout << nome << ": R$" << P << ",00" << endl; // guarda valor e nome
       fout.close();
        }
    }

    if (jogoGanho==false) {
       resultado(jogoGanho);
    }

    

    return 0;
}
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "sistema.h"
#include "executor.h"

using namespace std;

int main() {
  // inicialização do sistema
  Sistema sistema;
  Executor executor(sistema);

  cout << "------------------------------------------------------ * * * -----------------------------------------------------------" << endl;
  cout << "                               Bem vindo(a) ao Concord, digite o comando desejado." << endl;
  cout << "------------------------------------------------------ * * * -----------------------------------------------------------" << endl;

  // o executor recebe o cin e o cout. Ele os utilizará para ler as linhas
  // de comando, executar o método correto em "sistema" e exibir as mensagens

  executor.iniciar(cin, cout);

  return 0;
}

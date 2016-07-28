#include <iostream>
#include "quiz.h"
#include "conexaoDb.h"

using namespace std;

int main()

{


   quiz* a =new quiz(1,1,2);

   a->telaDePergunta(a->Perguntas[0], 1);
   a->telaDePergunta(a->Perguntas[1], 2);

    return 0;
}

#include <iostream>
#include "quiz.h"

using namespace std;

int main()
{

   quiz* a =new quiz(1,1,1);

for(int i=0 ; i < (a->Perguntas).size(); i++){
    cout << (a->Perguntas[i]).getCorreta() << endl;

}

    return 0;
}

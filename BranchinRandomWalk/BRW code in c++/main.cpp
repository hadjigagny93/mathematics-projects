#include "brw.cpp"
int main (){
BRW test(0,0);
test.ajoute_enfant();
std::ofstream fichier("testsansconditioneqp.txt");
test.generation(40,fichier);
fichier.close();



}

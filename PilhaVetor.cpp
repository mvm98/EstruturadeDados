#include <iostream>
using namespace std;

const int MAX = 100;

class PilhaVetor {
private:
    int topo;
    int elementos[MAX];

public:
    PilhaVetor() {
        topo = -1;
    }

    void push(int valor) {
        if (topo == MAX - 1) {
            cout << "Erro: a pilha esta cheia" << endl;
            return;
        }
        topo++;
        elementos[topo] = valor;
    }

    void pop() {
        if (topo == -1) {
            cout << "Erro: a pilha esta vazia" << endl;
            return;
        }
        topo--;
    }

    int top() {
        if (topo == -1) {
            cout << "Erro: a pilha esta vazia" << endl;
            return -1;
        }
        return elementos[topo];
    }

    bool vazia() {
        return topo == -1;
    }

    int tamanho() {
        return topo + 1;
    }
};

int main() {
    PilhaVetor pilhaV;

    pilhaV.push(1);
    pilhaV.push(2);
    pilhaV.push(3);

    cout << "Topo pilhaV: " << pilhaV.top() << endl;
    pilhaV.pop();

    cout << "Topo pilhaV: " << pilhaV.top() << endl;
    pilhaV.pop();

    cout << "Topo pilhaV: " << pilhaV.top() << endl;
    pilhaV.pop();

    cout << "Vazia pilhaV: " << pilhaV.vazia() << endl;
    cout << "Tamanho pilhaV: " << pilhaV.tamanho() << endl;

    return 0;
}

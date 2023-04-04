#include <iostream>

using namespace std;

// Implementa��o do n� da lista encadeada
class No {
public:
    int data;
    No* proximo;

    No(int val) {
        data = val;
        proximo = nullptr;
    }
};

// Implementa��o da pilha utilizando lista encadeada
class ListaEncadeada {
private:
    No* Notopo;

public:
    ListaEncadeada() {
        Notopo = nullptr;
    }

    void push(int item) {
        No* NovoNo = new No(item);
        NovoNo->proximo = Notopo;
        Notopo = NovoNo;
    }

    void pop() {
        if (!vazia()) {
            No* temp = Notopo;
            Notopo = Notopo->proximo;
            delete temp;
        }
    }

    int topo() {
        if (!vazia()) {
            return Notopo->data;
        } else {
            cout << "A pilha est� vazia!" << endl;
            return -1;
        }
    }

    bool vazia() {
        return Notopo == nullptr;
    }

    int tamanho() {
        int count = 0;
        No* temp = Notopo;
        while (temp != nullptr) {
            count++;
            temp = temp->proximo;
        }
        return count;
    }
};

int main() {
    ListaEncadeada Lista;
    cout << "Pilha est� vazia? " << (Lista.vazia() ? "Sim" : "N�o") << endl;
    Lista.push(3);
    Lista.push(2);
    Lista.push(1);
    cout << "Topo da pilha: " << Lista.topo() << endl;
    cout << "Tamanho da pilha: " << Lista.tamanho() << endl;
    Lista.pop();
    cout << "Topo da pilha ap�s remo��o: " << Lista.topo() << endl;
    Lista.pop();
    Lista.pop();
    cout << "Pilha est� vazia? " << (Lista.vazia() ? "Sim" : "N�o") << endl;
    return 0;
}

#include <iostream>

using namespace std;

// Implementação do nó da lista encadeada
class No {
public:
    int data;
    No* proximo;

    No(int val) {
        data = val;
        proximo = nullptr;
    }
};

// Implementação da pilha utilizando lista encadeada
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
            cout << "A pilha está vazia!" << endl;
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
    cout << "Pilha está vazia? " << (Lista.vazia() ? "Sim" : "Não") << endl;
    Lista.push(3);
    Lista.push(2);
    Lista.push(1);
    cout << "Topo da pilha: " << Lista.topo() << endl;
    cout << "Tamanho da pilha: " << Lista.tamanho() << endl;
    Lista.pop();
    cout << "Topo da pilha após remoção: " << Lista.topo() << endl;
    Lista.pop();
    Lista.pop();
    cout << "Pilha está vazia? " << (Lista.vazia() ? "Sim" : "Não") << endl;
    return 0;
}

#include <iostream>
#include <cstdlib>
using namespace std;

bool turnoDeX = false;

char tablero[][3] = {{'_', '_', '_'},
                     {'_', '_', '_'},
                     {'_', '_', '_'},
};

class Tree {
private:
  struct {
    char situacion[][3] = {{'_', '_', '_'},
                           {'_', '_', '_'},
                           {'_', '_', '_'},
    };
    Node* parent;
    Node* one;
    Node* two;
    Node* three;
    Node* four;
    Node* five;
    Node* six;
    Node* seven;
    Node* eight;
    Node* nine;
  };
  Node* root;
  void destroyRecursive(Node* p);
  void Crear_arbol(Node* &p, Node* &ptr, char element);
public:
  Tree();
  ~Tree();
};

Tree::Tree() {
  root = nullptr;
}

Tree::destroyRecursive(Node* p) {
  if (p != nullptr) {
    destroyRecursive(p->one);
    destroyRecursive(p->two);
    destroyRecursive(p->three);
    destroyRecursive(p->four);
    destroyRecursive(p->five);
    destroyRecursive(p->six);
    destroyRecursive(p->seven);
    destroyRecursive(p->eight);
    destroyRecursive(p->nine);
    delete p;
  }
}

Tree::~Tree() {
  destroyRecursive(root);
}

Tree::Crear_arbol(Node* &p, Node* &ptr, char element) {
  if (ptr == nullptr) {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
          if (ptr->situacion[i][j] == "_") {
            Node* nNode = new Node;
            nNode -> situacion[i][j] = element;
          }
      }
    }
  }
}

char hayGanador() {
    //validacion horizontal
    for (int i = 0; i < 3; i++) {
        if (tablero[i][0] != '_' && tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2]) {
            return tablero[i][0];
        }
    }
    //validacion vertical
    for (int i = 0; i < 3; i++) {
        if (tablero[0][i] != '_' && tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i]) {
            return tablero[0][i];
        }
    }
    //validacion diagonal izquierda a derecha
    if (tablero[0][0] != '_' && tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2])
        return tablero[0][0];

    //validacion diagonal derecha a izquierda
    if (tablero[0][2] != '_' && tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0])
        return tablero[0][2];
}

bool hayEmpate() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tablero[i][j] == '_') {
                return false;
            }
        }
    }
    return true;
}

void mostrarTablero() {
    char jugador = turnoDeX ? 'X' : 'O';
    int fila = 0;
    int columna = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << tablero[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "Turno de " << jugador << endl;
    cout << "En que fila desea jugar: ";
    cin >> fila;
    fila--;
    cout << "En que columna desea jugar: ";
    cin >> columna;
    columna--;
    tablero[fila][columna] = jugador;
    char ganador = hayGanador();
    if (ganador != '_') {
        cout << "Ha ganado " << ganador << endl;
        exit(0);
    }
    if (hayEmpate()) {
        cout << "Hay un empate " << endl;
        exit(0);
    }
    turnoDeX = !turnoDeX;
}

int main() {
    while(true) {
        mostrarTablero();
    }
    return 0;
}

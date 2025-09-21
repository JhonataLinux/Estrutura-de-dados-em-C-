#include <bits/stdc++.h>
using namespace std;

struct Pedido {
    string id;
    string cliente;
};

list<Pedido> pendentes;  // mantém ordem de inserção
unordered_map<string, list<Pedido>::iterator> idx; // id -> nó na lista

string ltrim(string s) {
    size_t i = s.find_first_not_of(" \t\r\n");
    return (i == string::npos) ? "" : s.substr(i);
}

void listar() {
    if (pendentes.empty()) {
        cout << "Pendentes: (nenhum)\n";
        return;
    }
    cout << "Pendentes:\n";
    for (const auto& p : pendentes) {
        cout << "- " << p.id << " | " << p.cliente << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Comandos: ADD <id> <cliente> | DONE <id> | LIST | EXIT\n";

    string linha;
    while (true) {
        cout << "> ";
        if (!getline(cin, linha)) break;
        if (linha.empty()) continue;

        istringstream iss(linha);
        string cmd;
        iss >> cmd;
        for (auto& c : cmd) c = toupper(static_cast<unsigned char>(c));

        if (cmd == "ADD") {
            string id;
            if (!(iss >> id)) {
                cout << "Uso: ADD <id> <cliente>\n";
                continue;
            }
            string cliente;
            getline(iss, cliente);            // resto da linha
            cliente = ltrim(cliente);
            if (cliente.empty()) {
                cout << "Uso: ADD <id> <cliente>\n";
                continue;
            }
            if (idx.count(id)) {
                cout << "ID '" << id << "' ja cadastrado.\n";
            } else {
                pendentes.push_back({id, cliente});
                idx[id] = prev(pendentes.end());
                cout << "Cadastrado: " << id << " | " << cliente << "\n";
            }
        }
        else if (cmd == "DONE") {
            string id;
            if (!(iss >> id)) {
                cout << "Uso: DONE <id>\n";
                continue;
            }
            auto it = idx.find(id);
            if (it == idx.end()) {
                cout << "Pedido '" << id << "' nao encontrado.\n";
            } else {
                cout << "Entregue: " << it->second->id
                     << " | " << it->second->cliente << "\n";
                pendentes.erase(it->second);
                idx.erase(it);
                listar(); // mostra pendentes após a entrega
            }
        }
        else if (cmd == "LIST") {
            listar();
        }
        else if (cmd == "EXIT" || cmd == "QUIT") {
            break;
        }
        else {
            cout << "Comando invalido.\n";
        }
    }
    return 0;
}

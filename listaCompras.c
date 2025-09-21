#include <bits/stdc++.h>
using namespace std;

string to_lower(string s){
    for(char &c : s) c = tolower((unsigned char)c);
    return s;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<string, long long> lista; // ordena por item (alfabética)

    cout << "Comandos: ADD <item> <qtd> | REM <item> [qtd] | LIST | EXIT\n";
    string line;
    while (true){
        cout << "> ";
        if (!getline(cin, line)) break;
        if (line.empty()) continue;

        istringstream iss(line);
        string cmd; iss >> cmd;
        for(char &c: cmd) c = toupper((unsigned char)c);

        if (cmd == "ADD"){
            string item; long long qtd;
            if (!(iss >> item >> qtd)){ cout << "Uso: ADD <item> <qtd>\n"; continue; }
            if (qtd <= 0) continue;
            item = to_lower(item);
            lista[item] += qtd;
        }
        else if (cmd == "REM" || cmd == "REMOVE"){
            string item; long long qtd;
            if (!(iss >> item)){ cout << "Uso: REM <item> [qtd]\n"; continue; }
            item = to_lower(item);
            if (!lista.count(item)){ cout << "Item nao encontrado\n"; continue; }
            if (iss >> qtd){                    // remove parcial
                if (qtd <= 0) continue;
                long long &v = lista[item];
                v -= qtd;
                if (v <= 0) lista.erase(item);  // zera -> remove
            } else {
                lista.erase(item);              // sem qtd -> remove tudo
            }
        }
        else if (cmd == "LIST"){
            if (lista.empty()) cout << "(vazio)\n";
            else for (auto &p : lista) cout << p.first << ": " << p.second << "\n";
        }
        else if (cmd == "EXIT" || cmd == "QUIT"){
            break;
        }
        else {
            cout << "Comando invalido\n";
        }
    }
    return 0;
}

#include <iostream>
#include <stdlib.h>
using namespace std;
char jucator, inamic;
bool win(char tabla[3][3]){
if( (tabla[0][0] == tabla[0][1] && tabla[0][1] == tabla[0][2] && (tabla[0][0] == 'X' || tabla[0][0] == '0')) ||
(tabla[1][0] == tabla[1][1] && tabla[1][1] == tabla[1][2] && (tabla[1][0] == 'X' || tabla[1][0] == '0')) ||
(tabla[2][0] == tabla[2][1] && tabla[2][1] == tabla[2][2] && (tabla[2][0] == 'X' || tabla[2][0] == '0')) ||
(tabla[0][0] == tabla[1][0] && tabla[1][0] == tabla[2][0] && (tabla[0][0] == 'X' || tabla[0][0] == '0')) ||
(tabla[0][1] == tabla[1][1] && tabla[1][1] == tabla[2][1] && (tabla[0][1] == 'X' || tabla[0][1] == '0')) ||
(tabla[0][2] == tabla[1][2] && tabla[1][2] == tabla[2][2] && (tabla[0][2] == 'X' || tabla[0][2] == '0')) ||
(tabla[0][0] == tabla[1][1] && tabla[1][1] == tabla[2][2] && (tabla[0][0] == 'X' || tabla[0][0] == '0')) ||
(tabla[0][2] == tabla[1][1] && tabla[1][1] == tabla[2][0] && (tabla[0][2] == 'X' || tabla[0][2] == '0')) ){
    return true;
}
return false;
}
int minimax(char tabla[3][3], char player, int adancime){
int availSpots = 0, i, j, score, minscore = 2, maxscore = -2, movei, movej;
if(win(tabla) == true && player == jucator){
    return 1;
}
if(win(tabla) == true && player == inamic){
    return -1;
}
for(i = 0; i < 3; i++){
    for(j = 0; j < 3; j++){
        if(tabla[i][j] == '_'){
            availSpots++;
            i = 3;
            break;
        }
    }
}
if(availSpots == 0){
    return 0;
}
for(i = 0; i < 3; i++){
    for(j = 0; j < 3; j++){
        if(tabla[i][j] == '_'){
            if(player == inamic){
                tabla[i][j] = inamic;
                score = minimax(tabla, jucator, adancime + 1);
                if(maxscore < score){
                    maxscore = score, movei = i, movej = j;
                }
            }
            if(player == jucator){
                tabla[i][j] = jucator;
                score = minimax(tabla, inamic, adancime + 1);
                if(minscore > score){
                    minscore = score;
                    minscore = score, movei = i, movej = j;
                }
            }
            tabla[i][j] = '_';
        }
    }
}
if(adancime == 0){
    tabla[movei][movej] = inamic;
}
if(player == inamic){
    return maxscore;
}
if(player == jucator){
    return minscore;
}
}
void mutare1(char tabla[3][3]){
int i, j, alegere = 1;
string pozitie;
system("CLS");
cout << '\n' << '\n' << "  1 2 3" << '\n';
for(i = 0; i < 3; i++){
    for(j = 0; j < 3; j++){
        if(i == 0 && j == 0){
            cout << "A ";
        }
        if(i == 1 && j == 0){
            cout << "B ";
        }
        if(i == 2 && j == 0){
            cout << "C ";
        }
        cout << tabla[i][j] << ' ';
    }
    cout << '\n';
}
cout << '\n' << '\n' << "Alege coordonatele pentru X(ex: A1): ";
cin >> pozitie;
while(pozitie != "A1" && pozitie != "a1" && pozitie != "A2" && pozitie != "a2" && pozitie != "A3" && pozitie != "a3" && pozitie != "B1" &&
pozitie != "b1" && pozitie != "B2" && pozitie != "b2" && pozitie != "B3" && pozitie != "b3" && pozitie != "C1" && pozitie != "c1" &&
pozitie != "C2" && pozitie != "c2" && pozitie != "C3" && pozitie != "c3"){
    cout << '\n' << "Pozitia nu este valida, alege o pozitie libera din A1, A2, A3, B1, B2, B3, C1, C2, C3: ";
    cin >> pozitie;
}
while(alegere == 1){
if(pozitie == "A1" || pozitie == "a1"){
    if(tabla[0][0] == '_'){
    tabla[0][0] = 'X';
    alegere = 0;
    }else{
    cout << '\n' << "Pozitia este ocupata, alege una libera: ";
    cin >> pozitie;
    }
}
if(pozitie == "A2" || pozitie == "a2"){
    if(tabla[0][1] == '_'){
    tabla[0][1] = 'X';
    alegere = 0;
    }else{
    cout << '\n' << "Pozitia este ocupata, alege una libera: ";
    cin >> pozitie;
    }
}
if(pozitie == "A3" || pozitie == "a3"){
    if(tabla[0][2] == '_'){
    tabla[0][2] = 'X';
    alegere = 0;
    }else{
    cout << '\n' << "Pozitia este ocupata, alege una libera: ";
    cin >> pozitie;
    }
}
if(pozitie == "B1" || pozitie == "b1"){
    if(tabla[1][0] == '_'){
    tabla[1][0] = 'X';
    alegere = 0;
    }else{
    cout << '\n' << "Pozitia este ocupata, alege una libera: ";
    cin >> pozitie;
    }
}
if(pozitie == "B2" || pozitie == "b2"){
    if(tabla[1][1] == '_'){
    tabla[1][1] = 'X';
    alegere = 0;
    }else{
    cout << '\n' << "Pozitia este ocupata, alege una libera: ";
    cin >> pozitie;
    }
}
if(pozitie == "B3" || pozitie == "b3"){
    if(tabla[1][2] == '_'){
    tabla[1][2] = 'X';
    alegere = 0;
    }else{
    cout << '\n' << "Pozitia este ocupata, alege una libera: ";
    cin >> pozitie;
    }
}
if(pozitie == "C1" || pozitie == "c1"){
    if(tabla[2][0] == '_'){
    tabla[2][0] = 'X';
    alegere = 0;
    }else{
    cout << '\n' << "Pozitia este ocupata, alege una libera: ";
    cin >> pozitie;
    }
}
if(pozitie == "C2" || pozitie == "c2"){
    if(tabla[2][1] == '_'){
    tabla[2][1] = 'X';
    alegere = 0;
    }else{
    cout << '\n' << "Pozitia este ocupata, alege una libera: ";
    cin >> pozitie;
    }
}
if(pozitie == "C3" || pozitie == "c3"){
    if(tabla[2][2] == '_'){
    tabla[2][2] = 'X';
    alegere = 0;
    }else{
    cout << '\n' << "Pozitia este ocupata, alege una libera: ";
    cin >> pozitie;
    }
}
}
}
void mutare2(char tabla[3][3]){
int i, j, alegere = 1;
string pozitie;
system("CLS");
cout << '\n' << '\n' << "  1 2 3" << '\n';
for(i = 0; i < 3; i++){
    for(j = 0; j < 3; j++){
        if(i == 0 && j == 0){
            cout << "A ";
        }
        if(i == 1 && j == 0){
            cout << "B ";
        }
        if(i == 2 && j == 0){
            cout << "C ";
        }
        cout << tabla[i][j] << ' ';
    }
    cout << '\n';
}
cout << '\n' << '\n' << "Alege coordonatele pentru 0(ex: A1): ";
cin >> pozitie;
while(pozitie != "A1" && pozitie != "a1" && pozitie != "A2" && pozitie != "a2" && pozitie != "A3" && pozitie != "a3" && pozitie != "B1" &&
pozitie != "b1" && pozitie != "B2" && pozitie != "b2" && pozitie != "B3" && pozitie != "b3" && pozitie != "C1" && pozitie != "c1" &&
pozitie != "C2" && pozitie != "c2" && pozitie != "C3" && pozitie != "c3"){
    cout << '\n' << "Pozitia nu este valida, alege o pozitie libera din A1, A2, A3, B1, B2, B3, C1, C2, C3";
}
while(alegere == 1){
if(pozitie == "A1" || pozitie == "a1"){
    if(tabla[0][0] == '_'){
    tabla[0][0] = '0';
    alegere = 0;
    }else{
    cout << '\n' << "Pozitia este ocupata, alege una libera: ";
    cin >> pozitie;
    }
}
if(pozitie == "A2" || pozitie == "a2"){
    if(tabla[0][1] == '_'){
    tabla[0][1] = '0';
    alegere = 0;
    }else{
    cout << '\n' << "Pozitia este ocupata, alege una libera: ";
    cin >> pozitie;
    }
}
if(pozitie == "A3" || pozitie == "a3"){
    if(tabla[0][2] == '_'){
    tabla[0][2] = '0';
    alegere = 0;
    }else{
    cout << '\n' << "Pozitia este ocupata, alege una libera: ";
    cin >> pozitie;
    }
}
if(pozitie == "B1" || pozitie == "b1"){
    if(tabla[1][0] == '_'){
    tabla[1][0] = '0';
    alegere = 0;
    }else{
    cout << '\n' << "Pozitia este ocupata, alege una libera: ";
    cin >> pozitie;
    }
}
if(pozitie == "B2" || pozitie == "b2"){
    if(tabla[1][1] == '_'){
    tabla[1][1] = '0';
    alegere = 0;
    }else{
    cout << '\n' << "Pozitia este ocupata, alege una libera: ";
    cin >> pozitie;
    }
}
if(pozitie == "B3" || pozitie == "b3"){
    if(tabla[1][2] == '_'){
    tabla[1][2] = '0';
    alegere = 0;
    }else{
    cout << '\n' << "Pozitia este ocupata, alege una libera: ";
    cin >> pozitie;
    }
}
if(pozitie == "C1" || pozitie == "c1"){
    if(tabla[2][0] == '_'){
    tabla[2][0] = '0';
    alegere = 0;
    }else{
    cout << '\n' << "Pozitia este ocupata, alege una libera: ";
    cin >> pozitie;
    }
}
if(pozitie == "C2" || pozitie == "c2"){
    if(tabla[2][1] == '_'){
    tabla[2][1] = '0';
    alegere = 0;
    }else{
    cout << '\n' << "Pozitia este ocupata, alege una libera: ";
    cin >> pozitie;
    }
}
if(pozitie == "C3" || pozitie == "c3"){
    if(tabla[0][0] == '_'){
    tabla[0][0] = '0';
    alegere = 0;
    }else{
    cout << '\n' << "Pozitia este ocupata, alege una libera: ";
    cin >> pozitie;
    }
}
}
}
int main(){
char tabla[3][3];
int i, j, victorie = 1, verificare;
char semn;
for(i = 0; i < 3; i++){
    for(j = 0; j < 3; j++){
        tabla[i][j] = '_';
    }
}
cout << '\n' << "Alege semnul (X sau 0): ";
cin >> semn;
while(semn != 'X' && semn != 'x' && semn != '0'){
    cout << '\n' << "Alege intre 0 si x: ";

    cin >> semn;
}
if(semn == 'X' || semn == 'x'){
    ::jucator = 'X';
    ::inamic = '0';
}
if(semn == '0'){
    ::jucator = '0';
    ::inamic = 'X';
}
cout << '\n' << '\n' << "  1 2 3" << '\n';
for(i = 0; i < 3; i++){
    for(j = 0; j < 3; j++){
        if(i == 0 && j == 0){
            cout << "A ";
        }
        if(i == 1 && j == 0){
            cout << "B ";
        }
        if(i == 2 && j == 0){
            cout << "C ";
        }
        cout << tabla[i][j] << ' ';
    }
    cout << '\n';
}
cout << '\n' << '\n' << "Alege coordonatele pentru 0(ex: A1): ";
while(victorie == 1){
    verificare = 0;
    if(jucator == 'X'){
        mutare1(tabla);
    }
    minimax(tabla, inamic, 0);
    if(win(tabla) == true){
        system("CLS");
        cout << "Ai pierdut !";
        cout << '\n' << '\n' << "  1 2 3" << '\n';
        for(i = 0; i < 3; i++){
            for(j = 0; j < 3; j++){
                if(i == 0 && j == 0){
                    cout << "A ";
                    }
                if(i == 1 && j == 0){
                    cout << "B ";
                    }
                if(i == 2 && j == 0){
                    cout << "C ";
                    }
                cout << tabla[i][j] << ' ';
            }
        cout << '\n';
        }
        break;
    }
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            if(tabla[i][j] == '_'){
                verificare = 1;
                break;
            }
        }
    }
    if(verificare == 0){
        cout << '\n' << "Egalitate" << '\n';
        cout << '\n' << '\n' << "  1 2 3" << '\n';
        for(i = 0; i < 3; i++){
            for(j = 0; j < 3; j++){
                if(i == 0 && j == 0){
                    cout << "A ";
                    }
                if(i == 1 && j == 0){
                    cout << "B ";
                    }
                if(i == 2 && j == 0){
                    cout << "C ";
                    }
                cout << tabla[i][j] << ' ';
            }
        cout << '\n';
        }
        break;
    }
    if(jucator == '0'){
        mutare2(tabla);
    }
    if(win(tabla) == true){
        system("CLS");
        cout << "Ai pierdut !";
        cout << '\n' << '\n' << "  1 2 3" << '\n';
        for(i = 0; i < 3; i++){
            for(j = 0; j < 3; j++){
                if(i == 0 && j == 0){
                    cout << "A ";
                    }
                if(i == 1 && j == 0){
                    cout << "B ";
                    }
                if(i == 2 && j == 0){
                    cout << "C ";
                    }
                cout << tabla[i][j] << ' ';
            }
        cout << '\n';
        }
        break;
    }
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            if(tabla[i][j] == '_'){
                verificare = 1;
                break;
            }
        }
    }
    if(verificare == 0){
        cout << '\n' << "Egalitate" << '\n';
        cout << '\n' << '\n' << "  1 2 3" << '\n';
        for(i = 0; i < 3; i++){
            for(j = 0; j < 3; j++){
                if(i == 0 && j == 0){
                    cout << "A ";
                    }
                if(i == 1 && j == 0){
                    cout << "B ";
                    }
                if(i == 2 && j == 0){
                    cout << "C ";
                    }
                cout << tabla[i][j] << ' ';
            }
        cout << '\n';
        }
        break;
    }
}
return 0;
}

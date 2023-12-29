#include <iostream>
#include <string>
#include <windows.h>
#include "Pokemon.h"

using namespace std;

class Game {
    public:

    string prc = "[PROFESSOR Carvalho] ";
    
    Pokemon pokemons[3];

    //Nosso Pokemon
    Pokemon selectedPokemon;
    int hp = 0;

    //Pokemon Adversário
    Pokemon selectedEnemy;
    int enemyHp = 0;

    void gameStart() {
        cout << prc << "Ola jovem treinador, por favor, escolha o seu pokemon inicial. " << endl;
        cout << prc << "Voce pode escolher entre os pokemons abaixo: \n" << endl;

        cout << "[POKEMON] 0. Charmander" << endl;
        cout << "[POKEMON] 1. Bulbasaur" << endl;
        cout << "[POKEMON] 2. Squirtle \n" << endl;

        int yourSelect;
        cin >> yourSelect;
        switch (yourSelect) {
            case 0:
                selectedPokemon = pokemons[0];
                selectedEnemy = pokemons[2];
            break;
            case 1:
                selectedPokemon = pokemons[1];
                selectedEnemy = pokemons[0];
            break;
            case 2:
                selectedPokemon = pokemons[2];
                selectedEnemy = pokemons[1];
            break;
        }

        hp = selectedPokemon.getHP();
        enemyHp = selectedEnemy.getHP();

            cout << "[POKEMON] Voce escolheu o '" << selectedPokemon.getName() << "'! Parabens!!!\n" << endl;

            cout << prc<< "Voce deseja entrar em uma batalha contra: Any ?" << endl;
            cout << prc<< "1. Sim 2. Nao" << endl;
            int acceptable = 0;
            cin >> acceptable;
            switch (acceptable) {
                case 1:
                startBattle();
                break;
                default:
                const char* linkOpen = "https://ih1.redbubble.net/image.3409070062.4731/raf,750x1000,075,t,fafafa:ca443f4786.jpg";
                ShellExecuteA(NULL, "open", linkOpen, NULL, NULL, SW_SHOWNORMAL);
                break;
            }
    }

    void startBattle() {
             cout << prc << "Uma lendaria batalha inicia-se meu caro treinador!" << endl;
             cout << prc << "[Voce] Vai " << selectedPokemon.getName() << "!" << endl;
             cout << prc << "[Any] Vai " << selectedEnemy.getName() << endl;
             cout << prc << "["<< selectedPokemon.getName() <<"] Zrummm!! \n" << endl;

        
            repeatAttack();
    }

    void repeatAttack() {
        if (enemyHp <= 0) {
             cout << prc << "Parabens, voce venceu esta batalha! :D\n" << endl;
             return;
        }

        if (hp <= 0) {
             cout << prc << "Parabens, voce perdeu esta batalha! :(\n" << endl;
        }

             cout << prc << "Escolha um dos ataques do seu pokemon: \n" << endl;
             cout << "0." << selectedPokemon.getAttack(0) << endl;
             cout << "1." << selectedPokemon.getAttack(1) << endl;
             cout << "2." << selectedPokemon.getAttack(2) << endl;

             string selectedAttack;
             cin >> selectedAttack;
             attack(selectedAttack);
    }

    void loadPokemons() {
        string charmanderAttacks[3] = {"Cuspe de Fogo", "Rajada de Fogo", "Arranhão"};
        int charmanderAttacksDamage[3] = {5, 3, 4};
        Pokemon first = Pokemon(17, "Charmander");
        first.setAttacks(charmanderAttacks[0], charmanderAttacks[1], charmanderAttacks[2]);
        first.setAttacksDamage(charmanderAttacksDamage[0], charmanderAttacksDamage[1], charmanderAttacksDamage[2]);
        
        string bulbasaurAttacks[3] = {"Chicote", "Absorver", "Mordida"};
        int bulbasaurAttacksDamage[3] = {4, 2, 6};
        Pokemon second = Pokemon(16, "Bulbasaur");
        second.setAttacks(bulbasaurAttacks[0], bulbasaurAttacks[1], bulbasaurAttacks[2]);
        second.setAttacksDamage(bulbasaurAttacksDamage[0], bulbasaurAttacksDamage[1], bulbasaurAttacksDamage[2]);
        
        string squirtleAttacks[3] = {"Casca grossa", "Jato dagua", "Redemoinho"};
        int squirtleAttacksDamage[3] = {4, 6, 3};
        Pokemon third = Pokemon(19, "Squirtle");
        third.setAttacks(squirtleAttacks[0], squirtleAttacks[1], squirtleAttacks[2]);
        third.setAttacksDamage(squirtleAttacksDamage[0], squirtleAttacksDamage[1], squirtleAttacksDamage[2]);
        
        pokemons[0] = first;
        pokemons[1] = second;
        pokemons[2] = third;
    }

    void attack(string attack) {
        std::string type = attack;
        int damage;

        if (type.compare(selectedPokemon.getAttack(0))) {
            damage = selectedPokemon.getAttackDamage(0);
        } else if (type.compare(selectedPokemon.getAttack(1))) {
            damage = selectedPokemon.getAttackDamage(1);
        } else if (type.compare(selectedPokemon.getAttack(2))) {
            damage = selectedPokemon.getAttackDamage(2);
        }

        enemyHp -= damage;
        cout << prc << "Vida do Adversario: " << enemyHp << "HP \n" << endl;
        repeatAttack();
    }
};

int main(int argc, char const *argv[])
{
    Game game;
    game.loadPokemons();
    game.gameStart();

    system("pause");
}

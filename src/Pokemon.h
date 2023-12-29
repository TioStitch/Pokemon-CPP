#include <string>

using namespace std;

class Pokemon {
    private:

    int hp;
    string name;
    string attacks[3];
    int attacksDamage[3];

    public:

    Pokemon(int h=0, string n="nothing") {
        hp = h;
        name = n;
    }

    int getHP() {
        return hp;
    }

    int setHP(int amount) {
        hp = amount;
    }

    string getName() {
        return name;
    }

    string getAttack(int attack) {
        return attacks[attack];
    }

    void setAttacks(const std::string& attack1, const std::string& attack2, const std::string& attack3) {
        attacks[0] = attack1;
        attacks[1] = attack2;
        attacks[2] = attack3;
    }

    void setAttacksDamage(int damage1, int damage2, int damage3) {
        attacksDamage[0] = damage1;
        attacksDamage[1] = damage2;
        attacksDamage[2] = damage3;
    }

    int getAttackDamage(int attack) {
        return attacksDamage[attack];
    }
};
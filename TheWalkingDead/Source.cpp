#include <iostream>
#include <string>
#include <ctime>
using namespace std;

enum class Weapon{FISTS, GUN, SHOTGUN, REVOLVER, SNIPER, MACHINE_GUN, MAX};

class Player;
class Zombie{
public:
	int distanceToPlayer;
	float speed;
	float damage;
	int life;
	void attack(Player &);
	bool isAlive();
	Zombie() : distanceToPlayer((20 + rand() % 180)), speed((float)(rand() % 20)), life(100) {};
};

class Player {
public:
	Weapon weapon;
	float precision;
	int life;
	void attack(Zombie &);
	bool isAlive();
	Player() : weapon((Weapon)(rand() % (int)(Weapon::MAX))), precision((float)(rand() % 1)), life(100) {};
};

void Player::attack(Zombie &z) {
	z.life = z.life - ((int)(Player::weapon)) * (Player::precision);
}

void Zombie::attack(Player &p) {
	if (distanceToPlayer <= 0) {
		p.life = p.life - ((int)(Zombie::damage));
	}
	else {
		distanceToPlayer--;
	}
}

bool Player::isAlive() {
	return life > 0;
}
bool Zombie::isAlive() {
	return life > 0;
}

void main() {
	srand(time(nullptr));
	Player player;
	const int nzomb = 10;
	Zombie zombies[nzomb];
	bool ZombiesAreAlive = true;
	do {
		ZombiesAreAlive = false;
		for (int i = 0; i < nzomb; i++) {
			if (zombies[i].isAlive() == true) {
				player.attack(zombies[i]);
				zombies[i].attack(player);
				ZombiesAreAlive = true;
			}
		}
	} while (player.isAlive() && ZombiesAreAlive == true);
	if (ZombiesAreAlive == true) {
		cout << "derrota!";
	}
	else {
		cout << "victoria!";
	}
}

//void attack(Zombie &)
// Class Player{
// void attack(Zombie &)
// }
// void Player::attack(Zombie &[Argumento]){}
#include <chrono>   // For time and progress bar
#include <cstdlib>  // for system()
#include <ctime>    // For randomization
#include <iostream> // For basic input and output to std
#include <thread>   // For progress bar
using namespace std;

// Handling return type of clear console to get system clear working in Repl
void ClearConsole() {
  int systemClear;
  systemClear = system("clear");
  if (systemClear == -1) {
    cout << "Error: system call failed" << endl;
  }
}

// -- PLAYER CLASS -- //
class Player {

private:
  int health;
  int attack;
  int defense;
  int healing;
  int damage;

  void setHealth(int healthValue) { health = healthValue; }
  void setAttackPower(int attackPower) { attack = attackPower; }
  void setDefensePower(int defensePower) { defense = defensePower; }
  void setHealingPower(int healingPower) { healing = healingPower; }
  void setDamagePerSecond(int damagePerSecond) { damage = damagePerSecond; }

public:
  int getHealth() { return health; }
  int getAttackPower() { return attack; }
  int getDefensePower() { return defense; }
  int getHealingPower() { return healing; }
  int getDamagePerSecond() { return damage; }

  int GiveDamage(int damagePerSecond) {
    srand(time(0));
    int randomDamage = (rand() % (damagePerSecond - 0 + 2)) + 1;
    cout << "Player has dealt " << randomDamage << " points of damage." << endl;
    return randomDamage;
  }

  void TakeDamage(int incomingDamage) {

    cout << "Player has received " << incomingDamage << " points of damage."
         << endl;

    health -= incomingDamage;
  }
  void Heal(int healingPower) {
    srand(time(0));
    int randomHealing = (rand() % (healingPower - 0 + 3)) + 5;
    health += randomHealing;
    cout << "Healing player by " << randomHealing << " points." << endl;
    cout << "Player's current health is: " << health << endl;
  }

  Player() {

    setHealth(100);
    setHealingPower(25);
    setAttackPower(10);
    setDefensePower(7);
    setDamagePerSecond(20);

    cout << "------------------------" << endl;
    cout << "The Legend of The Ghost" << endl;
    cout << "------------------------" << endl;

    cout << "Once upon a time, there was a legend, of a warrior so fierce, "
            "that the people of the town feared saying his very name!"
         << endl;
    cout << "The name of the legend was Kobayashi, the Great Warrior.";
    cout << "Born to a dragon and forged in the fire of Koabara! to the "
            "townsfolk, he was simply known as The Ghost."
         << endl;
  }
};
// -- END OF PLAYER CLASS --//

// ENEMY CLASS --//
class Enemy {
private:
  int health;
  int attack;
  int defense;
  int damage;

  void setHealth(int healthValue) { health = healthValue; }
  void setAttackPower(int attackPower) { attack = attackPower; }
  void setDefensePower(int defensePower) { defense = defensePower; }
  void setDamagePerSecond(int damagePerSecond) { damage = damagePerSecond; }

public:
  int getHealth() { return health; }
  int getAttackPower() { return attack; }
  int getDefensePower() { return defense; }
  int getDamagePerSecond() { return damage; }

  int GiveDamage(int damagePerSecond) {
    srand(time(0));
    int randomDamage = (rand() % (damagePerSecond - 0 + 2)) + 1;
    cout << "Enemy has dealt " << randomDamage << " points of damage." << endl;
    return randomDamage;
  }

  void TakeDamage(int incomingDamage) {

    cout << "Enemy has received " << incomingDamage << " points of damage."
         << endl;

    health -= incomingDamage;
  }

  Enemy() {

    setHealth(100);
    setAttackPower(20);
    setDefensePower(2);
    setDamagePerSecond(25);

    cout << "------------------------" << endl;
    cout << "The Monster of The Kurawasi" << endl;
    cout << "------------------------" << endl;

    cout << "In the same town as our hero, existed a monster who was "
            "undefeated,a legend,that no man had ever beaten !"
         << endl;
    cout << "No one knew the real name of this monster.";
    cout << "The townsfolk only referred to the legend as The Monster of the "
            "Kurawasi"
         << endl;
  }
};
// -- END OF ENEMY CLASS --

// -- GAME STORY -- //
void GameStory() {
  cout << "#############" << endl;
  cout << "## Genesis ##" << endl;
  cout << "#############" << endl << endl;

  cout
      << "Once upon a time, there was a young boy, living in a land far away..."
      << endl
      << endl;
  cout
      << "He was a very curious boy, always wondering what was beyond the land."
      << endl;
  cout << "This boy was not just a simple little boy! He was special." << endl
       << endl;
  cout << "You see, this boy wasn't raised like us. He wasn't raised by "
          "humans, no!"
       << endl;
  cout << "He was raised by a special creature, a Dragon!" << endl << endl;

  cout << "A dragon so fierce, it could burn and scorch the entire village "
          "with a single breath from it's fiery nostrils. The entire village "
          "trembled at the sight and the sound of this majestic "
          "creature."
       << endl
       << endl;

  cout << "One day, as he was getting older, the little boy had grown tired of "
          "being in the cave."
       << endl;
  cout << "He wanted to step out, he wanted to explore." << endl << endl;
  cout << "So he did, and he found a village, a village that was not like any "
          "other."
       << endl
       << endl;

  cout << "But little did he know, that this curiosity of his will start a "
          "journey spanning many adventures and tackling many perils."
       << endl
       << endl;

  cout << "Little did he know, he would change not only his destiny, but the "
          "destinies of every single member of the village!"
       << endl
       << endl;
}
// -- END OF GAME STORY -- //

// -- METHOD FOR HANDLING PROGRESS -- //
void ShowLoadingProgress(string message) {

  for (int i = 0; i <= 100; i += 50) {
    ClearConsole();
    cout << message << " : " << i << "%" << endl;
    // Simulate loading delay for 3 seconds
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
  ClearConsole();
}
// -- END OF METHOD FOR HANDLING PROGRESS -- //

// -- Player Stats Handling
void GetPlayerStats(Player player) {
  // Get player stats
  cout << "-----------------------------------" << endl;
  cout << "Player Stats" << endl;
  cout << "-----------------------------------" << endl;
  cout << "Player health: " << player.getHealth() << endl;
  cout << "Player attack power: " << player.getAttackPower() << endl;
  cout << "Player defense power: " << player.getDefensePower() << endl;
  cout << "Player healing power: " << player.getHealingPower() << endl;
  cout << "Player damage per second: " << player.getDamagePerSecond() << endl;
  cout << "-----------------------------------" << endl;
}

// -- Enemy Stats Handling -- //
void GetEnemyStats(Enemy enemy) {
  // Get Enemy Stats
  cout << "-----------------------------------" << endl;
  cout << "Enemy Stats" << endl;
  cout << "-----------------------------------" << endl;
  cout << "Enemy health: " << enemy.getHealth() << endl;
  cout << "Enemy attack power: " << enemy.getAttackPower() << endl;
  cout << "Enemy defense power: " << enemy.getDefensePower() << endl;
  cout << "Enemy damage per second: " << enemy.getDamagePerSecond() << endl;
  cout << "-----------------------------------" << endl;
}

// Initialize Player
Player InitializePlayer() {

  ShowLoadingProgress("Spawning Player...");

  Player player;

  GetPlayerStats(player);

  cout << "Press any key to continue...";
  cin.get(); // This should now wait properly.
  return player;
}

// Initialize Enemy
Enemy InitializeEnemy() {

  ShowLoadingProgress("Spawning Enemy...");

  Enemy enemy;

  GetEnemyStats(enemy);

  cout << "Press any key to continue...";
  cin.get(); // This should now wait properly.
  return enemy;
}

void GameOver() {
  cout << "-----------------------------------" << endl;
  cout << "Game Over" << endl;
}

void BattleLoop(Player player, Enemy enemy) {

  ClearConsole();

  ShowLoadingProgress("Preparing for battle...");

  do {

    char battleInput;

    // Battle progresses here
    cout << endl << "(Press 'A' to Attack or 'H' to heal)" << endl;
    cin >> battleInput;

    if (battleInput == 'A' || battleInput == 'a') {

      ShowLoadingProgress("Player Attacks. Processing turn...");
      // Player attacks
      cout
          << endl
          << "Player: Huzzah, here, take this you big bad unwieldy monster!!..."
          << endl;
      enemy.TakeDamage(player.GiveDamage(player.getDamagePerSecond()));
      cout << "Enemy health: " << enemy.getHealth() << endl;

      cout << endl
           << "Enemy: Hahaha! You took your shot. Now it is my turn!" << endl;

      // Enemy attacks
      player.TakeDamage(enemy.GiveDamage(enemy.getDamagePerSecond()));
      cout << "Player health: " << player.getHealth() << endl;

    } else if (battleInput == 'H' || battleInput == 'h') {
      ClearConsole();

      ShowLoadingProgress("Player Heals. Processing turn...");

      if (player.getHealth() < 100) {
        player.Heal(player.getHealingPower());
        cout << "Player has healed themselves. Current health: "
             << player.getHealth() << endl;

        // Enemy attacks
        cout << endl
             << "Enemy: Oh! You think you can scurry away and escape. Just you "
                "wait.... Bwahahahah!!"
             << endl;
        player.TakeDamage(enemy.GiveDamage(enemy.getDamagePerSecond()));
        cout << "Player health: " << player.getHealth() << endl;

      } else {
        cout << "Player is already at full health. Skipping turn." << endl;
      }
    }

  } while (player.getHealth() > 0 && enemy.getHealth() > 0);

  if (player.getHealth() <= 0) {
    cout << "You have been defeated by the enemy." << endl;
  }

  else if (enemy.getHealth() <= 0) {
    cout << "You have defeated the enemy." << endl;
  }

  GameOver();
}
// Initialize Game
void StartGame() {

  // Write a while loop to run the game story until the user presses s to start
  // the game
  char startGameInput;
  do {

    GameStory();

    cout << "So, warrior! Are you ready to begin your journey?" << endl << endl;

    cout << "Are you ready for your Genesis?" << endl;
    cout << "Press 's' to start the game: ";

    cin >> startGameInput;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    ClearConsole();

  } while (startGameInput != 's' && startGameInput != 'S');

  // Start the battle loop
  BattleLoop(InitializePlayer(), InitializeEnemy());
}

// End the game
void EndGame() {

  cout << "Uh oh! I understand. A warrior has other things to do as well."
       << endl;
  cout << "If you do decide to resume your mission, you know where to find me!"
       << endl;
}

// Main
int main() {

  ClearConsole();

  ShowLoadingProgress("Booting game");

  string name;
  char input;

  cout << "Hello there Traveller, what's your name: ";
  cin >> name;

  ClearConsole();

  cout << "Magnificent!! A name worthy of a true warrior, " << name << "!"
       << endl;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << "Press any key to continue...";
  cin.get(); // This should now wait properly.

  ClearConsole();

  cout << "So " << name << ", Can I tell you a story...? (y/n) ";
  cin >> input;

  ClearConsole();

  if (input == 'y' || input == 'Y') {
    StartGame();
  } else {
    // End the game
    EndGame();
  }
}
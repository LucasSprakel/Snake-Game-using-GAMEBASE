#include <iostream>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
#include <WinUser.h>


#define HEIGHT 15
#define WIDTH 30

using namespace std;

int x = 0, y = 1;
int fx = 2, fy = 5;
string player = "0";

class GAMEBASE {

private:
	void board() {

		for (int i = 0; i < HEIGHT; i++) {
			cout << "\t\t\t\t#";
			for (int j = 0; j < WIDTH; j++) {
				if (i == 0 || i == HEIGHT - 1) cout << '#';
				else if (i == y && j == x) cout << player;
				else if (y == 0 || y == 14 || x < 0 || x == 30) {
					cout << "YOU LOST";
					exit(1);
				}
				else if (i == fy && j == fx) cout << 'g';
				else cout << ' ';
			}
			cout << "#\n";
		}

	}
public:
	void Start() {

		board(); //chama o void board()

		while (true) {
			if (x == fx && y == fy) { // se player for igual a food (COMER)

				//GERA A COMIDA EM UM LUGAR ALEATORIO DO MAPA
				srand(time(0));
				for (int t = 0; t < 28; t++) {
					fx = (rand() % 28) + 1;
					for (int p = 0; p < 14; p++) {
						fy = (rand() % 14) + 1;
					}
				}

				//AUMENTA TAMANHO DO PLAYER
				player = player + "0";

			}

			if (GetKeyState(VK_DOWN) & 0x8000) {
			vk_down:
				while (y < 14) {
					if (GetKeyState(VK_RIGHT) & 0x8000) {
						break;
						goto vk_right;
					}
					else if (GetKeyState(VK_LEFT) & 0x8000) {
						break;
						goto vk_left;
					}
					else if (GetKeyState(VK_UP) & 0x8000) {
						break;
						goto vk_up;
					}
					else {
						y = y + 1;
						system("cls");
						board();
						Sleep(40);
					}
				}
			}

			if (GetKeyState(VK_UP) & 0x8000) {
			vk_up:
				while (y > 0) {
					if (GetKeyState(VK_RIGHT) & 0x8000) {
						break;
						goto vk_right;
					}
					else if (GetKeyState(VK_LEFT) & 0x8000) {
						break;
						goto vk_left;
					}
					else if (GetKeyState(VK_DOWN) & 0x8000) {
						break;
						goto vk_down;
					}
					else {
						y = y - 1;
						system("cls");
						board();
						Sleep(40);
					}
				}
			}

			if (GetKeyState(VK_LEFT) & 0x8000) {
			vk_left:
				while (x >= 0) {
					if (GetKeyState(VK_RIGHT) & 0x8000) {
						break;
						goto vk_right;
					}
					else if (GetKeyState(VK_DOWN) & 0x8000) {
						break;
						goto vk_down;
					}
					else if (GetKeyState(VK_UP) & 0x8000) {
						break;
						goto vk_up;
					}
					else {
						x = x - 1;
						system("cls");
						board();
						Sleep(40);
					}
				}
			}

			if (GetKeyState(VK_RIGHT) & 0x8000) {
			vk_right:
				while (x < 30) {
					if (GetKeyState(VK_DOWN) & 0x8000) {
						break;
						goto vk_down;
					}
					else if (GetKeyState(VK_LEFT) & 0x8000) {
						break;
						goto vk_left;
					}
					else if (GetKeyState(VK_UP) & 0x8000) {
						break;
						goto vk_up;
					}
					else {
						x = x + 1;
						system("cls");
						board();
						Sleep(40);
					}
				}
			}
		}




	}


};

int main() {

	GAMEBASE base;
	base.Start();

	return 0;
}

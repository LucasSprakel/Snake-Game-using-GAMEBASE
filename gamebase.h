#ifndef GAMEBASE_H
#define GAMEBASE_H

#include <iostream>
#include <Windows.h>
#include <WinUser.h>

#define HEIGHT 15
#define WIDTH 30

using namespace std;

int x = 0, y = 1;

class GAMEBASE{

	private:
		void board() {

			for (int i = 0; i < HEIGHT; i++) {
				cout << "\t\t\t\t#";
				for (int j = 0; j < WIDTH; j++) {
					if (i == 0 || i == HEIGHT - 1) cout << '#';
					else if (i == y && j == x) cout << '0';
					else cout << ' ';
				}
				cout << "#\n";
			}

		}
    public:
		void Start() {

			board();

			while (true) {


				if (GetKeyState(VK_DOWN) & 0x8000) {
					if (y == HEIGHT - 2) {

					}
					else {
						y = y + 1;
						system("cls");
						board();
						Sleep(50);
					}
				}
				if (GetKeyState(VK_UP) & 0x8000) {
					if (y == 1) {

					}
					else {
						y = y - 1;
						system("cls");
						board();
						Sleep(50);
					}
				}
				if (GetKeyState(VK_LEFT) & 0x8000) {
					if (x == 0) {

					}
					else {
						x = x - 1;
						system("cls");
						board();
						Sleep(50);
					}
				}
				if (GetKeyState(VK_RIGHT) & 0x8000) {
					if (x == WIDTH - 1) {

					}
					else {
						x = x + 1;
						system("cls");
						board();
						Sleep(50);
					}
				}

			}


		}


	};

#endif






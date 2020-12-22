#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>

void draw_rectangle(int row, int col);
void game_control(int* hit, int rnd);
void game_control2(int* hit, int* rnd);
void game_control3(int* hit, int* rnd, int* obs, int* obs2);
void gotoxy(int x, int y);
void title(void);
void movement(int* pos, int* dir, int flo, int shp, int time);
void movement2(int* pos, int* dir);


int main()
{
	int ranNum, hit = 0, i = 3, count = 1, obs, obs2;
	int level = 0;

	title();
	_getch();
	system("cls");

	while (1) {

		printf("Choose level. \n");
		printf("1.Easy 2.Normal 3.Hard\n\n");
		printf("select: ");
		scanf_s("%d", &level);
		system("cls");

		draw_rectangle(20, 20);
		gotoxy(42, 2);
		printf("Press space key to shoot");
		//gotoxy(42, 3);
		//printf("미사일이 발사됩니다.");
		gotoxy(42, 5);
		printf("Count : %d", count);
		gotoxy(42, 6);
		printf("Shot : %d", hit);

		if (level == 1) {
			while (1) {

				gotoxy(50, 5);
				printf("%d", count);

				srand((unsigned)time(NULL));
				ranNum = 2 * ((rand() % 18) + 1) + 1;
				gotoxy(ranNum, 2);
				printf("□");	//target
				
				game_control(&hit, ranNum);

				if (count == 10)
					break;

				gotoxy(1, 22);
				printf("Press any key to continue ...");
				_getch();
				gotoxy(1, 22);
				printf("                              ");
				gotoxy(ranNum, 2);
				printf("  ");
				count++;
			}

			gotoxy(42, 8);
			printf("Final score : %d", hit);

			gotoxy(1, 22);
			break;
		}

		else if (level == 2) {
			while (1) {

				gotoxy(50, 5);
				printf("%d", count);

				srand((unsigned)time(NULL));
				ranNum = 2 * ((rand() % 18) + 1) + 1;
				gotoxy(ranNum, 2);
				printf("□");	//target
				
				game_control2(&hit, &ranNum);

				if (count == 10)
					break;

				gotoxy(1, 22);
				printf("Press any key to continue ...");
				_getch();
				gotoxy(1, 22);
				printf("                              ");
				gotoxy(ranNum, 2);
				printf("  ");
				count++;
			}

			gotoxy(42, 8);
			printf("Final score : %d", hit);

			gotoxy(1, 22);
			break;
		}

		else if (level == 3) {
			while (1) {

				gotoxy(50, 5);
				printf("%d", count);

				srand((unsigned)time(NULL));
				ranNum = 2 * ((rand() % 18) + 1) + 1;
				gotoxy(ranNum, 2);
				printf("□");	// target
				

				srand((unsigned)time(NULL));
				obs = 2 * ((rand() % 9) + 1) + 1;
				gotoxy(obs, 5);
				printf("¤");

				srand((unsigned)time(NULL));
				obs2 = 2 * ((rand() % 9) + 1) + 19;
				gotoxy(obs2, 8);
				printf("¤");

				game_control3(&hit, &ranNum, &obs, &obs2);

				if (count == 10)
					break;

				gotoxy(1, 22);
				printf("Press any key to continue ...");
				_getch();
				gotoxy(1, 22);
				printf("                              ");
				gotoxy(ranNum, 2);
				printf("  ");
				gotoxy(obs, 5);
				printf("  ");
				gotoxy(obs2, 8);
				printf("  ");
				count++;
			}

			gotoxy(42, 8);
			printf("Final score : %d", hit);

			gotoxy(1, 22);
			break;
		}

		else {
			printf("Enter again.");
			continue;
		}
	}
	return 0;
}


void title(void)
{
	printf("[Shooting game] \n\n");
	printf("Moving rocket, shot target(□).\n");
	printf("To shoot, press space key.\n\n");
	printf("Press any key to start.");
}

void gotoxy(int x, int y)
{
	COORD Pos = { (short)x - 1, (short)y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void draw_rectangle(int row, int col)
{
	int i, j, k, l;
	printf("┌");
	for (i = 0; i < row * 2 - 2; i++)
		printf("─");
	printf("┐\n");
	for (j = 0; j < col - 2; j++) {
		printf("│");
		for (k = 0; k < row - 1; k++)
			printf("　");
		printf("│\n");
	}
	printf("└");
	for (l = 0; l < row * 2 - 2; l++)
		printf("─");
	printf("┘\n");
}

void movement(int* pos, int* dir, int flo, int shp, int time) {

	if (*dir == 0) {
		if (*pos == 3) {
			gotoxy(*pos, flo);
			if (shp == 1)
				printf("▲");
			else if (shp == 2)
				printf("□");
			else
				printf("¤");
			gotoxy(*pos + 2, flo);
			printf("  ");
			Sleep(time);
		}
		if (*pos >= 5 && *pos <= 37) {
			gotoxy(*pos, flo);
			if (shp == 1)
				printf("▲");
			else if (shp == 2)
				printf("□");
			else
				printf("¤");
			gotoxy(*pos - 2, flo);
			printf("  ");
			Sleep(time);
		}
	}
	if (*dir == 1) {
		if (*pos >= 3 && *pos <= 35) {
			gotoxy(*pos, flo);
			if (shp == 1)
				printf("▲");
			else if (shp == 2)
				printf("□");
			else
				printf("¤");
			gotoxy(*pos + 2, flo);
			printf("  ");
			Sleep(time);
		}
	}
}

void movement2(int* pos, int* dir) {
	if (*pos == 37)
		*dir = 1;
	else if (*pos == 3)
		*dir = 0;
	if (*dir == 0)
		*pos += 2;
	else
		*pos -= 2;
}

void game_control(int* hit, int rnd)
{
	int i = 3, j, k = 0;
	char ch;

	while (1) {

		movement(&i, &k, 19, 1, 100);

		if (_kbhit()) {
			ch = _getch();
			if (ch == 32) {
				j = 18;
				while (1) {
					gotoxy(i, j);
					printf("↑");
					while (1) {
						gotoxy(i, j);
						printf("  ");
						gotoxy(i, j - 1);
						printf("↑");
						Sleep(50);
						j--;
						if (j == 2)
							break;
					}
					gotoxy(i, 2);
					printf("  ");
					break;
				}
				/*발사*/
				if (i == rnd) {
					gotoxy(i, 2);
					printf("☆");
					/*별표로 바뀜*/
					gotoxy(42, 8);
					printf("Shot!");
					*hit += 1;
					gotoxy(49, 6);
					printf("%d", *hit);
					/*횟수, 성공횟수 증가*/
					gotoxy(i, 19);
					printf("  ");
				}
				else {
					gotoxy(42, 8);
					printf("Fail       ");
					gotoxy(i, 19);
					printf("  ");
				}
				break;
			}
		}

		movement2(&i, &k);
	}
}

void game_control2(int* hit, int* rnd)
{
	int i = 3, j, k = 0, r = 0;
	char ch;

	while (1) {
		movement(&i, &k, 19, 1, 100);
		//rocket movement

		movement(&*rnd, &r, 2, 2, 10);
		movement2(&*rnd, &r);
		//target movement1
		movement(&*rnd, &r, 2, 2, 10);
		//target movement2

		if (_kbhit()) {
			ch = _getch();
			if (ch == 32) {
				j = 18;
				while (1) {
					gotoxy(i, j);
					printf("↑");
					while (1) {
						gotoxy(i, j);
						printf("  ");
						gotoxy(i, j - 1);
						printf("↑");
						Sleep(50);
						j--;
						if (j == 2)
							break;
					}
					gotoxy(i, 2);
					printf("  ");
					break;
				}
				/*발사*/
				if (i == *rnd) {
					gotoxy(i, 2);
					printf("☆");
					/*별표로 바뀜*/
					gotoxy(42, 8);
					printf("Shot!");
					*hit += 1;
					gotoxy(49, 6);
					printf("%d", *hit);
					/*횟수, 성공횟수 증가*/
					gotoxy(i, 19);
					printf("  ");
				}
				else {
					gotoxy(42, 8);
					printf("Fail       ");
					gotoxy(i, 19);
					printf("  ");
				}
				break;
			}
		}

		movement2(&i, &k);	//rocket movement
		

		movement2(&*rnd, &r);	//target movement2
			
	}
}

void game_control3(int* hit, int* rnd, int* obs, int* obs2)
{
	int i = 3, j, k = 0, r = 0, a = 0, b = 0;
	char ch;

	while (1) {
		movement(&i, &k, 19, 1, 50);   //rocket movement

		movement(&*rnd, &r, 2, 2, 5);  //target movement1
		movement2(&*rnd, &r);          //target movement1

		movement(&*obs, &a, 5, 3, 5);  //obstacle1 movement1
		movement2(&*obs, &a);          //obstacle1 movement1

		movement(&*obs2, &b, 8, 3, 5); //obstacle2 movement1
		movement2(&*obs2, &b);         //obstacle2 movement1

		movement(&*rnd, &r, 2, 2, 5);  //rocket movement2
		movement2(&*rnd, &r);          //rocket movement2

		movement(&*obs, &a, 5, 3, 5);  //obstacle1 movement2

		movement(&*obs2, &b, 8, 3, 5); //obstacle2 movement2

		movement(&*rnd, &r, 2, 2, 5);  //rocket movement3

		if (_kbhit()) {
			ch = _getch();
			if (ch == 32) {
				j = 18;
				while (1) {
					gotoxy(i, j);
					printf("↑");
					while (1) {
						gotoxy(i, j);
						printf("  ");
						gotoxy(i, j - 1);
						printf("↑");
						Sleep(50);
						j--;
						if (j == 2)
							break;
						if (j == 5 && i == *obs)
							break;
						if (j == 8 && i == *obs2)
							break;
					}
					gotoxy(i, 2);
					printf("  ");
					break;
				}
				/*발사*/
				if (i == *rnd && j == 2) {
					gotoxy(i, 2);
					printf("☆");
					/*별표로 바뀜*/
					gotoxy(42, 8);
					printf("Shot!");
					*hit += 1;
					gotoxy(49, 6);
					printf("%d", *hit);
					/*횟수, 성공횟수 증가*/
					gotoxy(i, 19);
					printf("  ");
				}
				else if (i == *obs && j == 5) {
					gotoxy(i, 5);
					printf("BOOM");
					gotoxy(42, 8);
					printf("Fail       ");
					gotoxy(i, 19);
					printf("  ");
				}
				else if (i == *obs2 && j == 8) {
					gotoxy(i, 8);
					printf("BOOM");
					gotoxy(42, 8);
					printf("Fail       ");
					gotoxy(i, 19);
					printf("  ");
				}
				else {
					gotoxy(42, 8);
					printf("Fail       ");
					gotoxy(i, 19);
					printf("  ");
				}
				break;
			}
		}

		movement2(&i, &k);             //rocket movement

		movement2(&*obs, &a);          //obstacle1 movement2

		movement2(&*obs2, &b);         //obstacle2 movement2

		movement2(&*rnd, &r);          //target movement3
	}
}

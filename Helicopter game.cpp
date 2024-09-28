#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;

const int width = 40;
const int height = 20;
int helicopterX = 2, helicopterY = height / 2;
bool gameOver = false;
vector<int> obstacles;

void setup() {
    for (int i = 0; i < width; i++) {
        if (i % 4 == 0) {
            int gapPosition = rand() % height;
            obstacles.push_back(gapPosition);
        } else {
            obstacles.push_back(-1);
        }
    }
}

void draw() {
    system("clear"); // On Linux/Unix or MacOS (use "cls" for Windows)
    for (int i = 0; i < width; i++) {
        cout << "#";
    }
    cout << endl;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (x == helicopterX && y == helicopterY) {
                cout << "H";
            } else if (x < width - 1 && obstacles[x] != -1 && (y < obstacles[x] - 2 || y > obstacles[x] + 2)) {
                cout << "#";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    for (int i = 0; i < width; i++) {
        cout << "#";
    }
    cout << endl;
    cout << "Use 'w' to move up and 's' to move down. Avoid the obstacles!" << endl;
}

void input() {
    if (_kbhit()) {
        char ch = _getch();
        if (ch == 'w' && helicopterY > 0) {
            helicopterY--;
        } else if (ch == 's' && helicopterY < height - 1) {
            helicopterY++;
        }
    }
}

void logic() {
    for (int i = 0; i < width - 1; i++) {
        obstacles[i] = obstacles[i + 1];
    }
    int newGapPosition = rand() % height;
    obstacles[width - 1] = newGapPosition;
    if (obstacles[helicopterX] != -1 && (helicopterY < obstacles[helicopterX] - 2 || helicopterY > obstacles[helicopterX] + 2)) {
        gameOver = true;
    }
}

int main() {
    setup();
    while (!gameOver) {
        draw();
        input();
        logic();
        this_thread::sleep_for(chrono::milliseconds(100));  // Sleep for 100 ms
    }
    cout << "Game Over!" << endl;
    return 0;
}

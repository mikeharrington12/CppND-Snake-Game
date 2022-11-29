#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <algorithm>

class Menu {
    public:
        Menu() { readFile(); }

        // destructor
        ~Menu() { writeFile(); }

        // move constructor
        Menu(Menu &&menu)
        {
            names = menu.getNames();
            scores = menu.getScores();
        }

        // move assignment operator
        Menu &operator=(Menu &&menu)
        {
            names = menu.getNames();
            scores = menu.getScores();

            return *this;
        }

        // copy constructor
        Menu(const Menu &);

        // copy assignment operator
        Menu &operator=(const Menu &);

        void readFile();
        void writeFile();
        void sortScores();
        bool manageMenu();
        void addScore(int s);
        void addName(std::string n);

        //Helper functions
        void quickSort(int low, int high);
        int partition (int low, int high);

        std::vector<std::string> getNames() { return names; }
        std::vector<int> getScores() { return scores; }

        int getHighScore() { return scores.back(); }

    private:
        std::vector<std::string> names;
        std::vector<int> scores;
};


#endif

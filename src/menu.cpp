#include "menu.h"

void Menu::readFile() {
    std::fstream filestream("../src/highscores.txt");

    std::string line; 
    std::string name; 
    int score;

    if(filestream.is_open())
    {
        while(std::getline(filestream, line))
        {
            std::istringstream linestream(line);

            while(linestream >> name >> score)
            {
                names.emplace_back(name);
                scores.emplace_back(score);
            }
        }
    }
    else
    {
        std::cout << "Something went wrong. File did not open.\n";
    }
    sortScores();
    
    filestream.close();

}

void Menu::writeFile() {
    std::fstream filestream;
    filestream.open("../src/highscores.txt", std::ofstream::out | std::ofstream::trunc);
    std::string line;
    
    if(filestream.is_open())
    {
        for(int i = 0; i < names.size(); i++)
        {
            line = names.at(i) + " " + std::to_string(scores.at(i)) + "\n";
            filestream << line;
        }
    }
    else
    {
        std::cout << "Something went wrong. File did not open.\n";
    }
    
    filestream.close();
}

void Menu::sortScores() {
    if(scores.size() == 1) // No need to sort if the file for one entry.
        return;

    quickSort(0, scores.size() - 1);
}

void Menu::addScore(int s) {

    scores.emplace_back(s);
}

void Menu::addName(std::string n) {

    names.emplace_back(n);

}

bool Menu::manageMenu() { // Need to print game title, high scores, and menu options. Needs to read user input.
    std::string choice;
    
    std::cout << "\n\n\n-------- SNAKE GAME --------\n";
    std::cout << "                          \n";
    std::cout << "                          \n";
    std::cout << "     High Scores:         \n";
    for(int i = scores.size() - 1; i >= 0; i--)
    {
        std::cout << "     " << names.at(i) << " " << scores.at(i) << "\n";
    }
    std::cout << "                          \n";
    std::cout << "                          \n";
    std::cout << "     (1) New Game         \n";
    std::cout << "     (5) Exit             \n";
    std::cout << "---------------------------\n";
    std::cout << "\nUser Input: ";

    while(choice != "1" || choice != "5")
    {
        std::cin >> choice;

        if(choice == "1") // Start the snake game
            return true;
        else if (choice == "5") // Exit the snake game
            return false;
        else
            std::cout << "Please type either (1) for new game or (5) to exit.\n"; // Loop for correct input 
    }
}

// Helper fucntions for sorting the names and scores at the same time
int Menu::partition (int low, int high) 
{ 
    int pivot = scores.back();    // pivot 
    int i = (low - 1);   
   
    for (int j = low; j <= high - 1; j++) 
    { 
        if (scores.at(j) <= pivot) 
        { 
            i++;    
            std::swap(scores.at(i), scores.at(j)); // Swapping both names and scores since they're paired
            std::swap(names.at(i), names.at(j));
        } 
    } 
    std::swap(scores.at(i + 1), scores.at(high)); 
    std::swap(names.at(i + 1), names.at(high));
    return (i + 1); 
}

void Menu::quickSort(int low, int high) 
{ 
    if (low < high) 
    { 
        int pivot = partition(low, high); 

        quickSort(low, pivot - 1); 
        quickSort(pivot + 1, high); 
    } 
}
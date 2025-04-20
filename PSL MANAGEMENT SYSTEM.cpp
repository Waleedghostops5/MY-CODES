#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// A CODE BY MUHAMMAD WALEED REHAN
const int SIZE = 100;

void addPlayer() {
    char name[SIZE], team[SIZE], role[SIZE];
    int runs, wickets;

    ofstream file("players.txt", ios::app); 

    cout << "Enter name: ";
    cin.ignore(); 
    cin.getline(name, SIZE);

    cout << "Enter team: ";
    cin.getline(team, SIZE);

    cout << "Enter role (Batsman/Bowler/All-rounder): ";
    cin.getline(role, SIZE);

    cout << "Enter runs: ";
    cin >> runs;

    cout << "Enter wickets: ";
    cin >> wickets;

    file << name << "," << team << "," << role << "," << runs << "," << wickets << "\n";
    file.close();

    cout << "Player added.\n";
}

void viewPlayers() {
    ifstream file("players.txt");
    char line[200];
    cout << "\nAll Players:\n";
    while (file.getline(line, 200)) {
        cout << line << endl;
    }
    file.close();
}

void searchPlayer() {
    char keyword[SIZE], line[200];
    bool found = false;

    cout << "Enter player name or team: ";
    cin.ignore();
    cin.getline(keyword, SIZE);

    ifstream file("players.txt");
    while (file.getline(line, 200)) {
        if (strstr(line, keyword)) {
            cout << line << endl;
            found = true;
        }
    }
    file.close();

    if (!found) {
        cout << "Player not found.\n";
    }
}

void updatePlayer() {
    char line[200], name[SIZE], allData[100][200];
    int count = 0;
    bool found = false;

    ifstream file("players.txt");
    while (file.getline(line, 200)) {
        strcpy(allData[count], line);
        count++;
    }
    file.close();

    cout << "Enter player name to update: ";
    cin.ignore();
    cin.getline(name, SIZE);

    for (int i = 0; i < count; i++) {
        if (strstr(allData[i], name)) {
            char newRuns[10], newWickets[10];
            int commas = 0, j = 0;

            // Find where to replace
            while (allData[i][j] != '\0') {
                if (allData[i][j] == ',') commas++;
                if (commas == 3) break;
                j++;
            }

            allData[i][j + 1] = '\0'; 

            cout << "Enter new runs: ";
            cin.getline(newRuns, 10);
            cout << "Enter new wickets: ";
            cin.getline(newWickets, 10);

            strcat(allData[i], newRuns);
            strcat(allData[i], ",");
            strcat(allData[i], newWickets);

            found = true;
            break;
        }
    }

    ofstream fileOut("players.txt");
    for (int i = 0; i < count; i++) {
        fileOut << allData[i] << "\n";
    }
    fileOut.close();

    if (found)
        cout << "Player updated.\n";
    else
        cout << "Player not found.\n";
}

void deletePlayer() {
    char name[SIZE], line[200], allData[100][200];
    int count = 0;
    bool found = false;

    ifstream file("players.txt");
    while (file.getline(line, 200)) {
        strcpy(allData[count], line);
        count++;
    }
    file.close();

    cout << "Enter player name to delete: ";
    cin.ignore();
    cin.getline(name, SIZE);

    ofstream fileOut("players.txt");
    for (int i = 0; i < count; i++) {
        if (!strstr(allData[i], name)) {
            fileOut << allData[i] << "\n";
        }
        else {
            found = true;
        }
    }
    fileOut.close();

    if (found)
        cout << "Player deleted.\n";
    else
        cout << "Player not found.\n";
}

int main() {
    int choice;

    do {
        cout << "\n--- PSL Management Menu ---\n";
        cout << "1. Add Player\n";
        cout << "2. View All Players\n";
        cout << "3. Search Player\n";
        cout << "4. Update Player\n";
        cout << "5. Delete Player\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) addPlayer();
        else if (choice == 2) viewPlayers();
        else if (choice == 3) searchPlayer();
        else if (choice == 4) updatePlayer();
        else if (choice == 5) deletePlayer();
        else if (choice == 6) cout << "Goodbye!\n";
        else cout << "Invalid choice.\n";

    } while (choice != 6);

    return 0;
}
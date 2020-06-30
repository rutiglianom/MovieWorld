// Rutigliano, Matthew
// pa4.cpp
// 6/5/20

// Description: "Welcome to My Movie World! Scan in a .csv file
// of movie information, and let the binge watch begin! My Movie
// World allows you to view the entire list, search for more information
// about a specific movie, display all the movies under a genre of your
// choice, or remove a movie from the playlist after watching it. Using
// the magic of a Seperate-Chained Hash Table, My Movie World will be 
// running so fast you can barely watch fast enough! Who needs a GUI?"
// -Excerpt from manual found in dumpster

// Assumptions: "movies.csv" is formatted 
// "ID,Title,Genre,Year,Rating,Tagline,Director" and has semicolons in place
// of commas. The initial line will be discarded.

// Sources: Dr. Kong's "formatting.txt"
// "Lecture11-Hashing II.pdf"

#include <iostream>
#include <cstring>
#include <fstream>
#include "movie.h"
#include "hash.h"

using namespace std;

string replaceSemi(string);
// Replaces semicolons in string with commas
// Pre: None
// Post: String has been returned with commas in place of semicolons

int main() {
  
  string filename = "movies.csv";
  
  HashTable table;
  
  // Scanning list into table
  cout << "Scanning movies.csv file\n";
  string data[5];
  string id, year;
  ifstream infile;
  infile.open(filename);
  if (infile){
    infile.ignore(256, '\n');
    while(!infile.eof()){
      getline(infile, id, ',');
      getline(infile, data[0], ',');
      getline(infile, data[1], ',');
      getline(infile, year, ',');
      getline(infile, data[2], ',');
      getline(infile, data[3], ',');
      getline(infile, data[4]);
      if (id != ""){   // Avoids whitespace
        data[3] = replaceSemi(data[3]);
        data[4] = replaceSemi(data[4]);
        Movie film(data, stol(id), stoi(year));
        table.addToPlaylist(stol(id), film);
      }
    }
  } else {
    cout << "Error reading file." << endl;
  }
  infile.close();
  
  cout << "Welcome to my movie world! What would you like to do?\n";
  
  int choice = 1;
  string search = "";
  
  // Main Loop
  while(choice != 0){
    cout << "1. Browse all movies, 2. Browse by genre, 3. Watch a movie,\n" 
     << "4. View more information about a movie, 0. Exit: ";
    cin >> choice;
    cout << endl;
    
    // Display all
    if (choice == 1){
      table.displayAll();
    }
    
    // Display Genre
    else if (choice == 2){
      cout << "What genre are you looking for? ";
      cin >> search;
      table.displayGenre(search);
    }
    
    // Watch movie
    else if (choice == 3){
      cout << "Enter the ID of the movie to watch: ";
      cin >> search;
      if(!table.watchMovie(stol(search)))
        cout << "Sorry, movie " + search + " is not on the playlist\n\n";
    }
    
    // Display movie
    else if (choice == 4){
      cout << "Enter the ID of the movie to search: ";
      cin >> search;
      table.displayMovie(stol(search));
    }
   
    // Incorrect number
    else if (choice != 0){
      cout << "Number should be between 0 and 4!\n";
    }
    
    cout << "*************************\n";
  }
  
  // Closing
  cout << "Hope you enjoyed the movies. Goodbye!\n";
  
  return 0;
}

string replaceSemi(string orig){
  for (ulong i = 0; i < orig.length(); i++){
    if (orig[i] == ';')
      orig[i] = ',';
  }
  return orig;
}
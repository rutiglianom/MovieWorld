// Rutigliano, Matthew
// hash.h
// 6/5/20

// Description: The HashTable class creates a Hash table holding Movie
// objects. The table is of set size 31, and uses seperate chaining
// for collision resolution. Included are functions to watch a movie
// and remove it from the list, add a movie to the list, search and
// display a movie with a certain ID, display all the movies in the list,
// and display all movies of a certain genre.

// Assumptions: None

// Sources: Dr. Kong's "formatting.txt"
// "Lecture11-Hashing II.pdf"

#include <iostream>
#include <cstring>
#include "movie.h"

using namespace std;

#ifndef HASHTABLE_H
#define HASHTABLE_H

class HashTable {
  private:
  
    // Movie Node structure for seperate chaining
    struct MovieNode {
      long key;   // IMDB ID
      Movie value;
      MovieNode* next;
    };
  
    // Set Size of table
    int SIZE = 31;
    
    // Table
    MovieNode *playlist[31];
    
    int hashFunc(long);
    // Hash function
    // Pre: None
    // Post: Hash value of node has been returned
    
  public:
    HashTable();
    // Default Constructor
    // Pre: None
    // Post: HashTable has been initialized
    
    ~HashTable();
    // Destructor
    // Pre: HashTable has been initialized
    // Post: Memory has been deallocated
    
    void addToPlaylist(long, Movie);
    // Add movie with specified ID to hash table
    // Pre: HashTable has been initialized
    // Post: Movie has been sorted into table
    
    bool watchMovie(long);
    // Remove movie with specified ID from hash table
    // Pre: HashTable has been initialized
    // Post: Success of operation is returned as boolean
    
    void displayMovie(long);
    // Display information of movie with specified ID
    // Pre: HashTable has been initialized
    // Post: Information has been printed if movie was found
    
    void displayAll();
    // Display list of all movies IDs and titles
    // Pre: HashTable has been initialized
    // Post: Information has been printed
    
    void displayGenre(string);
    // Display list of all movies under a certain genre
    // Pre: HashTable has been initialized
    // Post: Movies have been printed
  
};

#endif // HASHTABLE_H
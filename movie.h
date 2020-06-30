// Rutigliano, Matthew
// movie.h
// 6/5/20

// Description: The Movie class creates a Movie object, holding a title, genre,
// IMDB ID, content rating, tagline, director and year. There are two print
// functions to print information in two levels of detail.

// Assumptions: None

// Sources: Dr. Kong's "formatting.txt"

#include <iostream>
#include <cstring>

using namespace std;

#ifndef MOVIE_H
#define MOVIE_H

class Movie {
  private:
    string title, genre, contentRating, tagline, director;
    long id;
    int year;
    
  public:
    Movie();
    // Default Constructor
    // Pre: None
    // Post: Movie has been initialized
    
    Movie(string[], long, int);
    // Parameterized Constructor
    // Pre: None
    // Post: Movie has been initialized with passed-in contents
    
    Movie(const Movie&);
    // Copy Constructor
    // Pre: Movie object has been intialized
    // Post: Second movie has been created, identical to the first
    
    Movie& operator=(const Movie&);
    // Overloaded Assignment Operator
    // Pre: Two Movie objects have been initialized
    // Post: Second Movie has been made identical to the first
    
    long getID();
    // ID Getter
    // Pre: Movie has been initialized
    // Post: ID has been returned
    
    string getGenre();
    // Genre Getter
    // Pre: Movie has been initialized
    // Post: Genre has been returned
    
    string getTitle();
    // Title Getter
    // Pre: Movie has been initialized
    // Post: Title has been returned
    
    void display();
    // Displays all information about Movie (for ID search)
    // Pre: Movie has been initialized
    // Post: Information has been printed
    
    void displayShort();
    // Displays ID and Name of Movie (For list & genre search)
    // Pre: Movie has been initialized
    // Post: Information has been printed

};

#endif // MOVIE_H
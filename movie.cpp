// Rutigliano, Matthew
// movie.cpp
// 6/5/20

// Description: Implementation of Movie class

// Assumptions: None

// Sources: Dr. Kong's "formatting.txt"

#include "movie.h"

// Default Constructor
Movie::Movie(){
  title = "";
  genre = "";
  contentRating = "";
  tagline = "";
  director = "";
  id = 0;
  year = 0;
}

// Parameterized Constructor
Movie::Movie(string info[], long iden, int yr){
  title = info[0];
  genre = info[1];
  contentRating = info[2];
  tagline = info[3];
  director = info[4];
  id = iden;
  year = yr;
}

// Copy Constructor
Movie::Movie(const Movie &obj){
  title = obj.title;
  genre = obj.genre;
  contentRating = obj.contentRating;
  tagline = obj.tagline;
  director = obj.director;
  id = obj.id;
  year = obj.year;
}

// Overloaded Assignment Operator
Movie& Movie::operator=(const Movie &obj){
  if (this != &obj){
    title = obj.title;
    genre = obj.genre;
    contentRating = obj.contentRating;
    tagline = obj.tagline;
    director = obj.director;
    id = obj.id;
    year = obj.year;
  }
  return *this;
}

// ID Getter
long Movie::getID(){
  return id;
}

// Genre Getter
string Movie::getGenre(){
  return genre;
}

// Title Getter
string Movie::getTitle(){
  return title;
}

// Display Function
void Movie::display(){
  cout << "IMDB id: " << id << "\nTitle: " + title + "\nDirector: " + director
   + "\nGenre: " + genre + "\nTagline: " + tagline + "\nYear: " << year <<
   + "\nRating: " + contentRating + "\n\n";
}

// Abridged Display Function
void Movie::displayShort(){
  cout << "IMDB id: " << id << "\nTitle: " + title + "\n\n";
}
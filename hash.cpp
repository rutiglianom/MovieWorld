// Rutigliano, Matthew
// hash.cpp
// 6/5/20

// Description: Implementation of HashTable class

// Assumptions: None

// Sources: Dr. Kong's "formatting.txt"
// "Lecture11-Hashing II.pdf"

#include "hash.h"

// Default Constructor
HashTable::HashTable(){
  for (int i = 0; i < SIZE; i++)
    playlist[i] = nullptr;
}

// Destuctor
HashTable::~HashTable(){
  MovieNode* temp;
  for (int i = 0; i < SIZE; i++){
    while(playlist[i]){
      temp = playlist[i];
      playlist[i] = playlist[i]->next;
      delete temp;
    }
  }
}

// Hash Function
int HashTable::hashFunc(long key){
  return key % SIZE;
}

// Add to hash table
void HashTable::addToPlaylist(long key, Movie value){
  int hashKey = hashFunc(key);
  MovieNode* newNode = new MovieNode;
  newNode->value = value;
  newNode->key = key;
  newNode->next = playlist[hashKey];
  playlist[hashKey] = newNode;
}

// Remove from hash table
bool HashTable::watchMovie(long key){
  int hashKey = hashFunc(key);
  MovieNode* lead = playlist[hashKey];
  MovieNode* trail = nullptr;
  bool found = false;
  while(lead && !found){
    if (lead->key == key){
      cout << "Watched " + lead->value.getTitle()
       + ". Removing it from playlist.\n\n";
      if (trail)
        trail->next = lead->next;
      else
        playlist[hashKey] = lead->next;
      delete lead;
      found = true;
    }
    if (lead && !found){
      trail = lead;
      lead = lead->next;
    }
  }
  return found;
}

// Display specific movie
void HashTable::displayMovie(long key){
  int val = hashFunc(key);
  MovieNode* temp = playlist[val];
  bool found = false;
  while(temp && !found){
    if (temp->key == key){
      temp->value.display();
      found = true;
    }
    temp = temp->next;
  }
  if (!found)
    cout << "Sorry, movie " << key << " is not on your playlist\n";
}

// Display all movies
void HashTable::displayAll(){
  MovieNode* temp;
  for(int i = 0; i < SIZE; i++){
    temp = playlist[i];
    while(temp){
      temp->value.displayShort();
      temp = temp->next;
    }
  }
}

// Display all movies of a certain genre
void HashTable::displayGenre(string genre){
  MovieNode* temp;
  for(int i = 0; i < SIZE; i++){
    temp = playlist[i];
    while(temp){
      if (temp->value.getGenre() == genre)
        temp->value.displayShort();
      temp = temp->next;
    }
  }
}


//*****************************************************************************
// COMSC-210 | Lab 19 | Gabriel Marquez
// Description: this program abstracts lab 18 by one layer, automates it such
// that review comments are read from an external file, and the movie rating is
// a random double between 1.0 and 5.0..
//*****************************************************************************

#include <iostream>
#include <string>
#include <vector>
#include <random>
using namespace std;

const int NUM_MOVIES = 4, NUM_REVIEWS = 3;
//for random ratings
const int MAX = 50, MIN = 10;
const double TENTH_MOD = 10;

struct Node {
    double rating;
    string comment;
    Node *next;
};

class Movie {
    string title;
    Node reviews;

    public:
    //getters and setters
    string getTitle() const {return this->title;}
    Node getReviews() const {return this->reviews;}
    void setTitle(string str) {this->title = str;}
    void setReviews(Node r) {this->reviews = r;}
};

int main () {
    double n = (rand() % (MAX - MIN + 1) + MIN) / TENTH_MOD;
    
    

    return 0;
}
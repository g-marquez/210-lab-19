//*****************************************************************************
// COMSC-210 | Lab 19 | Gabriel Marquez
// Description: this program abstracts lab 18 by one layer, automates it such
// that review comments are read from an external file, and the movie rating is
// a random double between 1.0 and 5.0..
//*****************************************************************************

#include <iostream>
#include <string>
using namespace std;

const int NUM_MOVIES = 4, NUM_REVIEWS = 3;
const double MAX = 5.0, MIN = 1.0;

struct Node {
    double rating;
    string comment;
    Node *next;
};

class Movie {
    string title;
    Node reviews;

    public:

};
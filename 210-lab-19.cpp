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
const int MAX = 5, MIN = 1, TENTH_MOD = 10; //for random ratings

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

double getRandRating();

int main () {
    
    

    return 0;
}

double getRandRating() {
    srand(time(0)); //setting seed value for rand()
    int n = rand() % (MAX - MIN + 1) + MIN; //value 1-5 for whole number
    int t = rand() % TENTH_MOD; //value 0-9 for tenth place
    //convert random ints to strings
    string nString = to_string(n);
    string tString = to_string(t);
    //concatenate strings together and convert to double
    string full = nString + "." + tString;
    double randN = stod(full);
    return randN;
}
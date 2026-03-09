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
#include <fstream>
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
    //Movie constructor
    Movie(string str) {this->title = str;}
    //getters and setters
    string getTitle() const {return this->title;}
    Node getReviews() const {return this->reviews;}
    void setTitle(string str) {this->title = str;}
    void setReviews(Node r) {this->reviews = r;}
};

int main () {
    srand(time(0)); //setting seed value for rand()
    vector<Movie> movies; //create empty vector of Movie objects
    //create individual Movie instances and push into movies vector
    Movie movie1("Movie 1");
    movies.push_back(movie1);
    Movie movie2("Movie 2");
    movies.push_back(movie2);
    Movie movie3("Movie 3");
    movies.push_back(movie3);
    Movie movie4("Movie 4");
    movies.push_back(movie4);

    //populate each movie in movies with reviews
    ifstream fin("reviews.txt");
    if (fin.good( )) {
        for (Movie m : movies) {
            Node *head = nullptr;
            for (int i = 0, i < NUM_REVIEWS, ++i) {

            }
        }

        fin.close( );
    }
    else {
        cout << "ERROR! Please verify file name/directory and restart program.";
        return 1;
    }
    double n = (rand() % (MAX - MIN + 1) + MIN) / TENTH_MOD;
    

    return 0;
}

//description: addAtHead() adds a node with a rating and comment entered by the
//user to the head of a linked list
//arguments: a pointer to the head of a linked list passed by reference
//returns: void
void addAtHead(Node *&head) {
    double reviewRating;
    string reviewComment;
    ifstream fin("reviews.txt");
    if (fin.good( )) {
        for (Movie m : movies) {
            Node *head = nullptr;
            for (int i = 0, i < NUM_REVIEWS, ++i) {

            }
        }

        fin.close( );
    }
    else {
        cout << "ERROR! Please verify file name/directory and restart program.";
        return 1;
    }

    //create new Node and populate with rating and comment
    Node *newReview = new Node; 
    if (!head) {
        head = newReview;
        newReview->next = nullptr;
        newReview->rating = reviewRating;
        newReview->comment = reviewComment;
    }
    else {
        newReview->next = head;
        newReview->rating = reviewRating;
        newReview->comment = reviewComment;
        head = newReview;
    }
}
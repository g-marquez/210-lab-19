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
#include <iomanip>
using namespace std;

const int NUM_REVIEWS = 3;
const int MAX = 50, MIN = 10; //for random ratings generation
const double TENTH_MOD = 10;

struct Node {
    double rating;
    string comment;
    Node *next;
};

class Movie {
    string title;
    Node *reviews;

    public:
    //Movie constructor
    Movie(string str) {this->title = str, reviews = nullptr;}
    //getters and setters
    string getTitle() const {return this->title;}
    Node* getReviews() const {return this->reviews;}
    void setTitle(string str) {this->title = str;}
    void setReviews(Node *r) {this->reviews = r;}
};

void addAtHead(Node *&, double, string);
void output(Node *);

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

    //populate each movie in movies with reviews via file input
    ifstream fin("reviews.txt");
    if (fin.good( )) {
        //pass by reference to change movies container itself
        for (Movie &m : movies) {
            Node *head = nullptr;
            for (int i = 0; i < NUM_REVIEWS; ++i) {
                double reviewRating = (rand() % (MAX - MIN + 1) + MIN) / TENTH_MOD;
                string reviewComment;
                getline(fin, reviewComment);
                addAtHead(head, reviewRating, reviewComment);
            }
            m.setReviews(head); //set reviews to this specific movie
        }
        fin.close( );
    }
    else {
        cout << "ERROR! Please verify file name/directory and restart program.";
        return 1;
    }
    cout << "Outputting movie reviews: " << endl;
    //pass by constant reference because it's a complex object
    for (const Movie &m : movies) {
        cout << "Movie: " << m.getTitle() << endl;
        Node *head = m.getReviews();
        output(head);
    }
    return 0;
}

//description: addAtHead() adds a node with a rating and comment to a linked list
//arguments: a pointer to the head of a linked list passed by reference, a
//double reviewRating, and a string reviewComment
//returns: void
void addAtHead(Node *&head, double reviewRating, string reviewComment) {
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

//description: output() outputs the contents of a linked list and the average 
//rating from all reviews to the console
//arguments: a pointer to the head of a linked list
//returns: void
void output(Node *head) {
    cout << "Outputting all reviews:" << endl;
    if (!head) {
        cout << "\t> Empty list.\n";
        return;
    }
    int count = 0;
    double sumRatings = 0;
    Node *current = head;
    while (current) {
        cout << "\t> Review #" << count + 1 << ": " << current->rating
             << ": " << current->comment << endl;
        sumRatings += current->rating;
        current = current->next;
        count++;
    }
    cout << "\t> Average: " << fixed << setprecision(1)
         << sumRatings/count << endl;
    cout << endl;
}
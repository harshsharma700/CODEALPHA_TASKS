#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <map>

using namespace std;

struct Question {
    string question;
    vector<string> options;
    int correctOption; // Index of the correct option (0-based)
};

struct User {
    string name;
    int score;
};

// Function to display a single question and capture user response
int askQuestion(const Question& q, int questionNumber) {
    cout << "\nQuestion " << questionNumber + 1 << ": " << q.question << "\n";
    for (size_t i = 0; i < q.options.size(); ++i) {
        cout << i + 1 << ". " << q.options[i] << "\n";
    }
    cout << "Enter your answer (1-" << q.options.size() << "): ";

    int userAnswer;
    while (!(cin >> userAnswer) || userAnswer < 1 || userAnswer > q.options.size()) {
        cin.clear(); // Clear input error
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        cout << "Invalid input! Please enter a number between 1 and " << q.options.size() << ": ";
    }
    return userAnswer - 1; // Convert to 0-based index
}

// Function to display the correct answers at the end of the quiz
void displayCorrectAnswers(const vector<Question>& questions) {
    cout << "\nCorrect Answers:\n";
    for (size_t i = 0; i < questions.size(); ++i) {
        cout << "Q" << i + 1 << ": " << questions[i].question << "\n";
        cout << "Correct Answer: " << questions[i].options[questions[i].correctOption] << "\n\n";
    }
}

// Main function
int main() {
    // Predefined questions
    vector<Question> questionBank = {
        {"What is the capital of France?", {"Paris", "Berlin", "Madrid", "Rome"}, 0},
        {"Who wrote 'Hamlet'?", {"Mark Twain", "William Shakespeare", "Charles Dickens", "Leo Tolstoy"}, 1},
        {"Which planet is known as the Red Planet?", {"Earth", "Mars", "Jupiter", "Saturn"}, 1},
        {"What is the square root of 64?", {"6", "7", "8", "9"}, 2},
        {"What is the largest ocean on Earth?", {"Atlantic", "Indian", "Arctic", "Pacific"}, 3}
    };

    // User registration
    User user;
    cout << "Welcome to the Online Quiz Game!\n";
    cout << "Enter your name to start: ";
    getline(cin, user.name);
    user.score = 0;

    cout << "\nHello, " << user.name << "! Let's start the quiz.\n";

    // Quiz logic
    for (size_t i = 0; i < questionBank.size(); ++i) {
        int userAnswer = askQuestion(questionBank[i], i);

        if (userAnswer == questionBank[i].correctOption) {
            cout << "Correct!\n";
            user.score += 10; // Award 10 points for a correct answer
        } else {
            cout << "Wrong! The correct answer was: " << questionBank[i].options[questionBank[i].correctOption] << "\n";
        }
    }

    // Display user score
    cout << "\nQuiz Completed! Your Score: " << user.score << "/" << questionBank.size() * 10 << "\n";

    // Display correct answers
    displayCorrectAnswers(questionBank);

    cout << "Thank you for playing, " << user.name << "!\n";
    return 0;
}

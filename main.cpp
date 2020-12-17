#include <iostream>
#include <algorithm>   
#include <vector>   
#include <stdio.h>
#include <stdlib.h>
#include <random>
#include <fstream>
#include <ctime>
#include <cstdlib>


using namespace std;

int result=0;


class Question{
  public:

  void make_question(string text, string ans1, string ans2, string ans3, int answer_number, int score);// creates the question with answers
  void ask();//print the question
  void file_read(); //reads a question from a txt file
  void file_print();//prints a question to the file
  string file_report();//returns the question to be printed in report
  void add(); //adds a new question
  void cal_score();//calculate score
  private:
  int answer; //answer number 
  string q; //question text
  string a1; //first answer
  string a2; // second answer
  string a3; // third answer
  int score; // score value
};


void Question:: make_question(string text, string ans1, string ans2, string ans3, int answer_number, int score_value){

  q = text;
  a1 = ans1;
  a2 = ans2;
  a3 = ans3;
  answer = answer_number;
  score = score_value;

}

void Question :: ask(){

  int users_answer;

  cout<< "Question: " << q<< "\n";
  cout<<"1)"<<a1;
  cout<<"\n2)"<<a2;
  cout<<"\n3)"<<a3;
  cout<<"\nEnter your answer: ";
  cin>>users_answer;

  if(users_answer==answer){
    cout<<"\nGood Job, you got it right!!\n";
    cal_score();
    cout<<"\nScore is "<<score<<" of 1\n";
  }
  else{
    cout<<"\nWrong answer! Try again next time!\n";
    cout<<"\nScore is "<<score<<" of 1\n";
  }
}

void Question :: add(){

  string ques, an1, an2, an3;
  int right_ans;

  cout<< "\nInput the Question: ";
  cin.ignore(); //Allows to use getline as it was not working
  getline (cin, ques );

  q = ques;     //Maybe this is not needed

  cout<< "\nInput the first Answer: ";
  getline (cin, an1);

  a1 = an1;

  cout<< "\nInput the second Answer: ";
  getline (cin, an2);

  a2 = an2;

  cout<< "\nInput the third Answer: ";
  getline (cin, an3);

  a3 = an3;

  cout<< "\nQuestion: " << ques << "\n";
  cout<< "Answers: " << "\n";
  cout<< "1)"<<an1<<"\n";
  cout<< "2)"<<an2<<"\n";
  cout<< "3)"<<an3<<"\n";
  cout<< "Input the number of the correct answer, it will be saved: ";
  cin>>right_ans;

  answer = right_ans;

  make_question(ques, an1, an2, an3, right_ans, 0);

}

void Question:: file_read(){
  string question,answ1,answ2,answ3;
  int right_answ;
  ifstream file;

  file.open("file.txt");

  if (!file) {
    cerr << "Unable to open the file";
  }
  else{
  
  getline(file,question);
  getline(file,answ1);
  getline(file,answ2);
  getline(file,answ3);
  file>>right_answ;


  file.close();
  
  cout<<"\n\nThe question from the file is: "<<question<<"\n";
  cout<<"The first answer is: "<<answ1<<"\n";
  cout<<"The second answer is: "<<answ2<<"\n";
  cout<<"The third answer is: "<<answ3<<"\n";
  cout<<"The number of the right answer is: "<<right_answ<<"\n";

  make_question(question, answ1, answ2, answ3, right_answ, 1);


  cout<<"\n\nNow you can answer this question!\n\n";
  }

}

void Question:: file_print(){
  string question,answ1,answ2,answ3;
  int right_answ;
  ofstream file;
  file.open ("file1.txt");
    if (!file) {
    cerr << "Unable to open the file";
  }
  else{
    
    cout<<"\n\n Input the question, which you would like to save in the file: ";
    cin.ignore(); //Allows to use getline as it was not working
    getline(cin,question);
    cout<<"\nInput the first answer: ";
    getline(cin,answ1);
    cout<<"\nInput the second answer: ";
    getline(cin,answ2);
    cout<<"\nInput the third answer: ";
    getline(cin,answ3);

    file<<question<<"\n";
    file<<"1) "<<answ1<<"\n";
    file<<"2) "<<answ2<<"\n";
    file<<"3) "<<answ3<<"\n";

  file.close();
  }
}

string Question:: file_report(){
  
return q;

}


void Question::cal_score(){

  score+=1;
  result+=1;

}

void tutorial();
int my_random(int f);
void menu();

int main() {

  tutorial();

}

int my_random(int f){
  srand((unsigned) time(0));//set fully random number generator, which takes current time 
  return std::rand()%f;
}


void tutorial(){
  int choise;

  cout << "\n";
  cout << "\n";
  cout << "                Welcome to the Quiz!!!\n\n";
  cout << "Here is a short guide of how to use this app:\n";
  cout<<"In the main menu you can select one of 6 options\n";
  cout<<"By pressing 1, you can test the quiz with default questions\n";
  cout<<"By pressing 2, you can add up to 5 questions yourself and play.";
  cout<<"After finnishing the quiz, you can print a report of the questions to the file\n";
  cout<<"By pressing 3, you can read a question from the file. You can input any question there and the app will read it.\n"; 
  cout<<"Yet you have to print it in a specific order:\n\n";
  cout<<"Question\n";
  cout<<"First Answer\n";
  cout<<"Second Answer\n";
  cout<<"Third Answer\n";
  cout<<"The number of the correct answer\n\n";
  cout<<"By pressing 4, you can print your question to the file(file1.txt)\n";
  cout<<"By pressing 5, you can return to this tutorial page\n";
  cout<<"By pressing 6, you will exit the app.\n";
  cout<<"\n\nShort rules of the quizz:";
  cout<<"\n Each game you get 5 randomly shuffled questions with three different answers.\n";
  cout<<"Only one of these answers is correct, you need to input the number of this question\n";
  cout<<"\n\nGood luck!!!\n\n";


  cout<< "Input 1 to continue to the main menu: ";
  cin>> choise;

  if (choise ==1){
    menu();
  }
  else{
    cout<<"Wrong input, try again";
    tutorial();
  }

}

void menu(){
  
  int i = 0;
  int des,count,rep;
  vector <Question> vec;
  

  Question First_Question;
  Question Second_Question;
  Question Third_Question;
  Question Fourth_Question;
  Question Fifth_Question;
  Question Empty_Question1;
  Question Empty_Question2;
  Question Empty_Question3;
  Question Empty_Question4;
  Question Empty_Question5;


  First_Question.make_question("How many legs does a spider have?", "6", "4", "8", 3, 0);
  Second_Question.make_question("What grade will Keijo give me for this period?", "2", "5", "4", 2, 0);
  Third_Question.make_question("How many planets are there in our Solar System?", "7", "8", "9", 2, 0);
  Fourth_Question.make_question("What is the average length of female humpback whale im meters?", "10-12", "14-15", "15-16", 3, 0);
  Fifth_Question.make_question("What is the most common male name in the world?", "James", "John", "Robert", 1, 0);


  //add values to the vector

  vec.push_back(First_Question);
  vec.push_back(Second_Question);
  vec.push_back(Third_Question);
  vec.push_back(Fourth_Question);
  vec.push_back(Fifth_Question);


  
  //Main menu

    cout << "\n\nMain Menu:\n\n";
    cout<< "⊚ Input 1 to play the quiz with default questions\n";
    cout<< "⊚ Input 2 to add your questions and play\n";
    cout<< "⊚ Input 3 to read question from the file\n";
    cout<< "⊚ Input 4 to save questions to the file\n";
    cout<< "⊚ Input 5 to read tutorial again\n";
    cout<< "⊚ Input 6 to exit\n\n";
    cout<< "Your input: ";
    cin>> des;

      if(des==1){

          random_shuffle ( vec.begin(), vec.end(), my_random);//shuffle randomly the vector objects
          
        	for (auto n : vec) {
		         n.ask();
        	}

          cout<<"\nWell done, practice is over now, going back to the main menu!\n";
          menu();
      }
      else if(des ==2){
      cout<<"\nHow many questions would you like to input?\n";
      cout<<"Your input: ";
      cin>>count;

        if(count==1){
        Empty_Question1.add();
        vec.push_back(Empty_Question1);
        random_shuffle ( vec.begin(), vec.end(), my_random);
        random_shuffle ( vec.begin(), vec.end(), my_random);

        cout<<"\n\n Now lets strt the quiz!!\n\n";
        	for (auto n : vec) {
            
		         n.ask();
             i++;
             if(i==5){
               cout<<"\n\nFinal score is: "<<result<<" out of 5\n";
               cout<<"\n\nWould you like to print a question report into a file?\n";
               cout<<"Enter 1 to print\n";
               cout<<"Enter 2 to skip\n";
               cout<<"Your input: ";
               cin>>rep;

                  if(rep==1){
                      ofstream file;
                      file.open ("report.txt");
                        if (!file) {
                             cerr << "Unable to open the file";
                        }
                        else{
    
                              for (auto n : vec) {
                                file<<n.file_report()<<"\n";
                              }
                              file.close();
                              break;
                        }
                  }
                  else if(rep==2){
                      cout<<"\nThis is the end of the quizz, come again!!!";
                      break;
                  }
                  else{
                    cout<<"\nWrong input!";
                    break;
                  }
             }
        	}
        
        }
        else if(count==2){

        Empty_Question1.add();
        vec.push_back(Empty_Question1);
        Empty_Question2.add();
        vec.push_back(Empty_Question2);

        random_shuffle ( vec.begin(), vec.end(), my_random);
        random_shuffle ( vec.begin(), vec.end(), my_random);

        cout<<"\n\n Now lets strt the quiz!!\n\n";
        	for (auto n : vec) {
            
		         n.ask();
             i++;
             if(i==5){
               cout<<"\n\nWould you like to print a question report into a file?\n";
               cout<<"Enter 1 to print\n";
               cout<<"Enter 2 to skip\n";
               cout<<"Your input: ";
               cin>>rep;

                  if(rep==1){
                      ofstream file;
                      file.open ("report.txt");
                        if (!file) {
                             cerr << "Unable to open the file";
                        }
                        else{
    
                              for (auto n : vec) {
                                file<<n.file_report()<<"\n";
                              }
                              file.close();
                              break;
                        }
                  }
                  else if(rep==2){
                      cout<<"\nThis is the end of the quizz, come again!!!";
                      break;
                  }
                  else{
                    cout<<"\nWrong input!";
                    break;
                  }
             }
        	}

        }

        else if(count==3){

        Empty_Question1.add();
        vec.push_back(Empty_Question1);
        Empty_Question2.add();
        vec.push_back(Empty_Question2);
        Empty_Question3.add();
        vec.push_back(Empty_Question3);

        random_shuffle ( vec.begin(), vec.end(), my_random );
        random_shuffle ( vec.begin(), vec.end(), my_random);

        cout<<"\n\n Now lets strt the quiz!!\n\n";
        	for (auto n : vec) {
            
		         n.ask();
             i++;
             if(i==5){
               cout<<"\n\nWould you like to print a question report into a file?\n";
               cout<<"Enter 1 to print\n";
               cout<<"Enter 2 to skip\n";
               cout<<"Your input: ";
               cin>>rep;

                  if(rep==1){
                      ofstream file;
                      file.open ("report.txt");
                        if (!file) {
                             cerr << "Unable to open the file";
                        }
                        else{
    
                              for (auto n : vec) {
                                file<<n.file_report()<<"\n";
                              }
                              file.close();
                              break;
                        }
                  }
                  else if(rep==2){
                      cout<<"\nThis is the end of the quizz, come again!!!";
                      break;
                  }
                  else{
                    cout<<"\nWrong input!";
                    break;
                  }
             }
        	}

        }

        else if(count==4){

        Empty_Question1.add();
        vec.push_back(Empty_Question1);
        Empty_Question2.add();
        vec.push_back(Empty_Question2);
        Empty_Question3.add();
        vec.push_back(Empty_Question3);
        Empty_Question4.add();
        vec.push_back(Empty_Question4);

        random_shuffle ( vec.begin(), vec.end(), my_random);
        random_shuffle ( vec.begin(), vec.end(), my_random);

        cout<<"\n\n Now lets strt the quiz!!\n\n";
        	for (auto n : vec) {
            
		         n.ask();
             i++;
             if(i==5){
               cout<<"\n\nWould you like to print a question report into a file?\n";
               cout<<"Enter 1 to print\n";
               cout<<"Enter 2 to skip\n";
               cout<<"Your input: ";
               cin>>rep;

                  if(rep==1){
                      ofstream file;
                      file.open ("report.txt");
                        if (!file) {
                             cerr << "Unable to open the file";
                        }
                        else{
    
                              for (auto n : vec) {
                                file<<n.file_report()<<"\n";
                              }
                              file.close();
                              break;
                        }
                  }
                  else if(rep==2){
                      cout<<"\nThis is the end of the quizz, come again!!!";
                      break;
                  }
                  else{
                    cout<<"\nWrong input!";
                    break;
                  }
             }
        	}

        }

        else if(count==5){

        Empty_Question1.add();
        vec.push_back(Empty_Question1);
        Empty_Question2.add();
        vec.push_back(Empty_Question2);
        Empty_Question3.add();
        vec.push_back(Empty_Question3);
        Empty_Question4.add();
        vec.push_back(Empty_Question4);
        Empty_Question5.add();
        vec.push_back(Empty_Question5);

        random_shuffle ( vec.begin(), vec.end(), my_random);
        random_shuffle ( vec.begin(), vec.end(), my_random);

        cout<<"\n\n Now lets strt the quiz!!\n\n";
        	for (auto n : vec) {
            
		         n.ask();
             i++;
             if(i==5){
               cout<<"\n\nWould you like to print a question report into a file?\n";
               cout<<"Enter 1 to print\n";
               cout<<"Enter 2 to skip\n";
               cout<<"Your input: ";
               cin>>rep;

                  if(rep==1){
                      ofstream file;
                      file.open ("report.txt");
                        if (!file) {
                             cerr << "Unable to open the file";
                        }
                        else{
    
                              for (auto n : vec) {
                                file<<n.file_report()<<"\n";
                              }
                              file.close();
                              break;
                        }
                  }
                  else if(rep==2){
                      cout<<"\nThis is the end of the quizz, come again!!!";
                      break;
                  }
                  else{
                    cout<<"\nWrong input!";
                    break;
                  }
             }
        	}

        }
        else{
          cout<<"\n\nWrong input!!!\n\n";
          menu();
        }
      
      }
      else if(des ==3){

        Empty_Question1.file_read();
        Empty_Question1.ask();
      }

      else if(des ==4){

        Empty_Question1.file_print();
      }

      else if(des ==5){
        tutorial();
      }
      else if(des==6){
        cout<<"\n\nThank you!!! Good Bye!!!";
      }
      else{
        cout<<"\n\nWrong input, start again!!!";
        
      }

}
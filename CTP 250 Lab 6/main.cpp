#include <iostream>
#include "QueueArray.h"
#include "LinkedQueue.h"
#include <string>
#include <fstream>

using namespace std;

void removeString(LinkedQueue<string>, string);
string userInput();

int main(){

    //opening file
    ifstream infile("carMake.csv");

    //checking that file is open
    if(!infile.is_open()){
        cout << "file not open for input...program terminating" << endl;
        exit(0);
    }

    //queue that holds all the strings in carMake.csv
    LinkedQueue<string> carMakes;

    string carMake = "";

    while(getline(infile, carMake)){
        transform(carMake.begin(), carMake.end(), carMake.begin(), ::tolower);
        /*for(int i = 0; i < carMake.length(); i ++){
            //tolower(carMake[i]);
        }
         */
        carMakes.enqueue(carMake);
    }


    removeString(carMakes, userInput());

    cout << "\nRemove another? (Y/N): ";
    string answer = "";
    getline(cin, answer);

    if(answer[0] == 'Y' || answer[0] == 'y'){
        removeString(carMakes,userInput() );
    }
    else if (answer[0] == 'N' || answer[0] == 'n'){
        cout << "program done... " << endl;
    }
    else{
        cout << "answer not understood..." << endl;
        cout << "program terminated...";
    }

    return 0;
}//end main()

/* Method that takes user input string and looks for it in the queue;
 * if string found, it is removed.
 * @param LinkedQueue<string> is the queue
 * @param str is the user input string
 */
void removeString(LinkedQueue<string> carMakes, string str){
    //queue to temporarily store elements
    LinkedQueue<string> temp;

    //finding the str to remove
    while(!carMakes.isEmpty()){
        if (str!= carMakes.peek()){
            temp.enqueue(carMakes.peek());
            carMakes.dequeue();
        }
    }

    //if element is not found
    if (carMakes.isEmpty()){
        cout << "\nString not found in Queue..." << endl;
        while (!temp.isEmpty()){
            carMakes.enqueue(temp.peek());
            temp.dequeue();
        }
    }

    //if element is found
    else{
        cout << "\nFound and Removed: " << str << endl;
        carMakes.dequeue();
        while(!temp.isEmpty()){
            carMakes.enqueue(temp.peek());
            temp.dequeue();
        }
    }

    //displaying CarMakes Queue
    cout << "\nThe current Queue: " << endl;
    if(temp.isEmpty()){
        while(!carMakes.isEmpty()){
            cout << carMakes.peek() << endl;
            temp.enqueue(carMakes.peek());
            carMakes.dequeue();
        }
    }
    else if(carMakes.isEmpty()){
        while(!temp.isEmpty()){
            cout << temp.peek() << endl;
            carMakes.enqueue(temp.peek());
            temp.dequeue();
        }
    }

}//end removeString()

/* method that prompts user for string
 * the string is read and converted to lower-case
 */
string userInput(){

    string str = "";
    cout << "Enter string to remove: ";
    getline(cin, str);
    transform(str.begin(), str.end(), str.begin(), ::tolower);

    return str;

}//end userInput()

//front - peek
//back (newest item)
//push - enqueue
//pop - dequeue

/* checking that file data was in queue
for(int i = 0; i < numOfCarMakes; i++){
while(!carMakes.isEmpty()){
   cout << carMakes.peek() << endl;
   carMakes.dequeue();
}
}


//
cout << carMakes.peek() << endl;
carMakes.dequeue();

cout << "current string: " << carMakes.peek() << endl;
cout << "remove string: "<< removeStr << endl;


if ( removeStr == carMakes.peek() ){
   cout << "match";
}
else
   cout << "no match";
//

*/


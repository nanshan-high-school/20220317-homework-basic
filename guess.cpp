#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(){
    int mode , score = 1 , max = 1000 , min = 0;
    
    srand(time(0));
    int Ans = rand() % 1000 + 1;
    int human , bot[10];
    string checkhuman = "false" , checkbot = "false";
    bool humancheck = false , botcheck = false;


    rule : {
        cout << "You have to guess the answer faster than our IQ99999 AIbot" << endl;
        this_thread::sleep_for(std::chrono::seconds(2));
        cout << "You have only 10 rounds...gl" << endl;
        this_thread::sleep_for(std::chrono::seconds(2));
        cout << "btw we have 2 mode to choose" << endl;
        this_thread::sleep_for(std::chrono::seconds(2));
        goto modechoose;
    };
    modechoose : {
        system("clr")
        cout << "1.e z mode" << endl;
        this_thread::sleep_for(std::chrono::seconds(2));
        cout << "2.hard mode" << endl;
        this_thread::sleep_for(std::chrono::seconds(2));
        cout << "mode:";
        cin >> mode;
        max = 1000;
        min = 0;
    };
    
    if(mode == 1){
        for(int i = 0 ; i < 10 ; i++){
            int noobbot = rand() % 1000 + 1;
            bot[i] = noobbot;
            if(noobbot == Ans){
                botcheck = true;
                checkbot = "True!";
            }
        }
    }else if(mode == 2){
        int probot = 500 , min1 = 1000 , max1 = 0;

        for(int i = 0 ; i < 10 ; i++){
            if(Ans < probot){
                min1 = probot;   
            }else if(Ans > probot){
                max1 = probot;
            }
            bot[i] = probot;
            probot = (min1 + max1) / 2;
        }
    }

    for(int i = 0 ; i < 10 ; i++){ // human's guess
        cout << "Round " << i + 1 << endl;
        cout << min << " ~ " << max << endl;
        cout << "Your guess : ";
        cin >> human;
        if(bot[i] == Ans){
                botcheck = true;
                checkbot = "True";
                cout << "bot's guess : " << bot[i] << " " << checkbot << endl;
                cout << "your guess : " << checkhuman << endl;
                goto grade;
            }
        if(human != Ans){
            if(human < Ans){
                if(min < human){
                    min = human;
                    cout << "bot's guess : " << bot[i] << " " << checkbot << endl;
                    cout << "your guess : " << checkhuman << endl;
                    cout << endl;
                }else if(min > human){
                    cout << "you weird" << endl;
                    cout << "bot's guess : " << bot[i] << " " << checkbot << endl;
                    cout << "your guess : " << checkhuman << endl;
                    cout << endl;
                }
            }else if(human > Ans){
                if(max > human){
                    max = human;
                    cout << "bot's guess : " << bot[i] << " " << checkbot << endl;
                    cout << "your guess : " << checkhuman << endl;
                    cout << endl;
                }else if(max < human){
                cout << "you weird" << endl;
                cout << "bot's guess : " << bot[i] << " " << checkbot << endl;
                cout << "your guess : " << checkhuman << endl;
                cout << endl;
                }
            }
        }else if(human == Ans){
            checkhuman = "True!";
            humancheck = true;
            cout << "bot's guess : " << bot[i] << " " << checkbot << endl;
            cout << "your guess : " << checkhuman << endl;
            cout << endl;
            goto grade;
        }
        score += 1;
    }
    grade:{
        if(humancheck && !botcheck){
            if(score >= 7){
                cout << "1 star" << endl;
                cout << "Congrats" << endl;
                cout << endl;
                this_thread::sleep_for(std::chrono::seconds(5));
            }else if(score < 7 && score >= 4){
                cout << "2 stars" << endl;
                cout << "woah woah woah" << endl;
                cout << endl;
            }else if(score < 4){
                cout << "3 stars" << endl;
                cout << "HACKER";
                cout << endl;
            }
            this_thread::sleep_for(std::chrono::seconds(7));
            goto modechoose;
        }else if(botcheck && !humancheck){
            cout << "HAHAHA U LOSE!" << endl;
            cout << endl;
            this_thread::sleep_for(std::chrono::seconds(7));
            goto modechoose;
        }else if(!botcheck && !humancheck){
            cout << "hmm seems we need a better bot..." << endl;
            cout << endl;
            this_thread::sleep_for(std::chrono::seconds(7));
            goto modechoose;
        }
    };
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: james
 *
 * Created on October 2, 2019, 5:11 PM
 */

#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

char** inputFunc (int c,int r);

class Field{
public:
    int r,c;
    char **arr;

};
void output(vector<Field*> v);

/*
 *
 */
int main(int argc, char** argv) {

    Field *f;
    vector<Field*> vf;


    int c,r;
    c=1999;


    while(c!=0){

        cin>>r;
        cin>>c;
        if(c==0){break;}
        char **array;
        array = inputFunc(r,c);
        f=new Field();
        f->c=c;
        f->r=r;

        f->arr=array;
        vf.push_back(f);
    };
    cout<<endl;
    output(vf);



    return 0;
}

char** inputFunc (int r,int c){
    char** array = 0;
    array=new char*[r];
    for (int x = 0; x < r; x++){
        array[x]=new char[c];
        for (int y = 0; y < c; y++){
            cin>>array[x][y];
        }
    }
    return array;

}


void output(vector<Field*> v){
    Field *f;
    int c,r;

    for(int i=0;i<v.size();i++){
        char** array;
        f=v[i];
        r=f->r;
        c=f->c;

        cout<<"Field #"<<i+1<<":"<<endl;




        array=f->arr;

//
        for(int x = 0; x < r; x++){
                for(int y = 0; y < c; y++){

                    if (array[x][y] != '*'){  //Only loops if point is not a bomb
                    int count = 0;          //Keeps track of number of bombs for each point
                    int startX = x-1;       //Starting point of 3x3 for x

                    for(int p = 0; p < 3; p++){
                        int startY = y-1;   //Starting point of 3x3 for y
                        for (int i = 0; i < 3; i++){

                            //Checks that the window is moving within the range of the grid
                            if (startX>=0 and startY>=0 and startX<r and startY<c){
                                if (array[startX][startY]=='*'){
                                    count++;
                                }
                            }
                            startY++; //Moves to next column of 3x3
                        }
                    startX++;         //Moves to next row of 3x3
                    }
                    //End of calculating bombs for this specific point

                    array[x][y] = '0'+count; //Assigns point on grid to number of bombs found
                 }

                }

            }


                for (int x = 0; x < r; x++){
                    for (int y = 0; y < c; y++){
                        cout<<array[x][y];
                    }
                    cout<<endl;
                }


                cout<<endl;

            }



}
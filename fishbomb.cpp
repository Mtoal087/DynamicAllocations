/*
Name:       Matt Toal
Section:    103
*/

#include <iostream>
using namespace std;

/*
Desc: Create a 2D array
Pre: Must know rows and columns (int)
Post: Returns int** that points to the array
*/
int** creating_array(const int rows, const int columns){
    int** arr = new int*[rows];
    for(int i = 0; i < rows; i++){
        arr[i] = new int[columns];
        for(int j = 0; j < columns; j++){
            cin >> arr[i][j];
        }
    }
    return arr;
}

/*
Desc: Calculates the number of fish caught within the blast radius
Pre: Must have array, rows, and columns
Post: returns number of fish (int) that were caught
*/
int explosion(int** arr, const int rows, const int columns){
    int fish = 0;
    int dynamite = 3;
    int x, y;
    while(dynamite != 0){
        cin >> x >> y;

        for(int i = -2; i <= 2; i++){
            fish += arr[x][y+i];          //include (x,y)
            arr[x][y+i] = 0;                //changes y-values
        }

        for(int i = -2; i <= 2; i++){        //left and right, changes x-values
            if(i != 0){
                fish += arr[x+i][y];
                arr[x+i][y] = 0;
            }
        }

        //bottom right quadrant of blast-radius
        fish += arr[x+1][y+1];
        arr[x+1][y+1] = 0;
        fish += arr[x+1][y+2];
        arr[x+1][y+2] = 0;
        fish += arr[x+2][y+1];
        arr[x+2][y+1] = 0;
        fish += arr[x+2][y+2];
        arr[x+2][y+2] = 0;

        //bottom left quadrant
        fish += arr[x-1][y+1];
        arr[x-1][y+1] = 0;
        fish += arr[x-1][y+2];
        arr[x-1][y+2] = 0;
        fish += arr[x-2][y+1];
        arr[x-2][y+1] = 0;
        fish += arr[x-2][y+2];
        arr[x-2][y+2] = 0;

        //top right quadrant
        fish += arr[x+1][y-1];
        arr[x+1][y-1] = 0;
        fish += arr[x+1][y-2];
        arr[x+1][y-2] = 0;
        fish += arr[x+2][y-1];
        arr[x+2][y-1] = 0;
        fish += arr[x+2][y-2];
        arr[x+2][y-2] = 0;

        //top left quadrant
        fish += arr[x-1][y-1];
        arr[x-1][y-1] = 0;
        fish += arr[x-1][y-2];
        arr[x-1][y-2] = 0;
        fish += arr[x-2][y-1];
        arr[x-2][y-1] = 0;
        fish += arr[x-2][y-2];
        arr[x-2][y-2] = 0;

        dynamite--;
    }

    return fish;
}

/*
Desc: Deletes dynamic allocated arrays
Pre: Uses int** array and int rows as conditions
Post: Void function
*/
void deleting_array(int** arr, const int rows){
    for(int i = 0; i < rows; i++){
        delete [] arr[i];
        arr[i] = NULL;
    }
    delete [] arr;
    arr = NULL;
}


int main(){

    int tests, tested;
    tested = 0;
    cin >> tests;

    while(tests != 0){
        int rows, columns, fish;
        cin >> rows;
        cin >> columns;

        int** arr = creating_array(rows, columns);

        fish = explosion(arr, rows, columns);
        cout << "#" << tested << ": Bender catches " << fish << " fish" << endl;

        tests--;
        tested++;

        deleting_array(arr, rows);
    }
    return 0;
}

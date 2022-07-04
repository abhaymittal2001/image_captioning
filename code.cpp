#include <bits/stdc++.h>
using namespace std;


long long score;
int board[4][4]={};
int empcells;

/*
    Arguments: take in a list of (x, y) coordinates of all the empty cells
    Return: returns a value (80% : 2, 20% : 4) along with a Randomly (Pseudo)
    selected cell out of the empty cells
    pair<int, pair<int, int>> --> <value, <x, y>>
*/

pair<int, int> getempcell(vector<pair<int, int>> &emptyCells)
{
    int mini = 0, maxi = (int)emptyCells.size() - 1;
    int pos = (rand() % (maxi - mini + 1)) + mini;

    sort(emptyCells.begin(), emptyCells.end());

    return  emptyCells[pos];
}

/*
    Prints the configuration of the board
*/
void printBoard()
{
    cout << "score = " << score <<"\n";
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] == 0)
                cout << "-";
            else
                cout << board[i][j];
            cout << "\t";
        }
        cout << "\n";
    }
}


/*
   gravity function takes the vector and push all the numbers to right leaving no zeroes
*/
void gravity(vector<int> &arr)
{
    int firstEmpty = 0;
    for (int i = 0; i < 4; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[firstEmpty]);
            firstEmpty++;
        }
    }
}

/*
    merge function takes an vector and merges the consecutive element if they are equal
*/
void merge(vector<int> &arr)
{
    for (int i = 1; i < 4; i++)
    {
        if (arr[i] == arr[i - 1] && arr[i] != 0)
        {
            score +=2 * arr[i - 1];
            arr[i - 1] = 2 * arr[i - 1];
            arr[i] = 0;
            empcells++;
        }
    }
}

/*
    pushtleft function pushes the values of vector to left if possible
    if it's possible then returns true 
*/
bool pushtoleft(vector<int> &arr)
{
    vector<int> copyArr(arr);
    gravity(arr);
    merge(arr);
    gravity(arr);
    for (int i = 0; i < 4; i++)
    {
        if (copyArr[i] != arr[i])
            return true;
    }
    return false;
}

/*
    move function pushes the board numbers in given direction
*/
bool move(int direction)
{
    bool change = false;
    vector<int> curr;

    // Left
    if (direction == 1)
    {
        for (int i = 0; i < 4; i++)
        {

            // copy the values in a particular direction
            for (int j = 0; j < 4; j++)
                curr.push_back(board[i][j]);

            // push to left and check if anything has changed
            change |= pushtoleft(curr);

            // copy the changed values back to original
            for (int j = 3; j >= 0; j--)
            {
                board[i][j] = curr.back();
                curr.pop_back();
            }
        }
    }

    // Down
    else if (direction == 2)
    {
        for (int j = 0; j < 4; j++)
        {

            // copy the values in a particular direction
            for (int i = 3; i >= 0; i--)
                curr.push_back(board[i][j]);

            // push to left and check if anything has changed
            change = change| pushtoleft(curr);

            // copy the changed values back to original
            for (int i = 0; i < 4; i++)
            {
                board[i][j] = curr.back();
                curr.pop_back();
            }
        }
    }

    // Right
    else if (direction == 3)
    {
        for (int i = 0; i < 4; i++)
        {

            // copy the values in a particular direction
            for (int j = 3; j >= 0; j--)
                curr.push_back(board[i][j]);

            // push to left and check if anything has changed
            change |= pushtoleft(curr);

            // copy the changed values back to original
            for (int j = 0; j < 4; j++)
            {
                board[i][j] = curr.back();
                curr.pop_back();
            }
        }
    }

    // Up
    else
    {
        for (int j = 0; j < 4; j++)
        {

            // copy the values in a particular direction
            for (int i = 0; i < 4; i++)
                curr.push_back(board[i][j]);

            // push to left and check if anything has changed
            change |= pushtoleft(curr);

            // copy the changed values back to original
            for (int i = 3; i >= 0; i--)
            {
                board[i][j] = curr.back();
                curr.pop_back();
            }
        }
    }
    return change;
}

/*
    Randomly selects a cell (using getRandomEmptyCellAndValue() function) 
    and assigns a value to it
*/
void populateRandomCell()
{
    vector<pair<int, int>> emptyCells;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] == 0)
                emptyCells.push_back({i, j});
        }
    }
    auto Coord = getempcell(emptyCells);
     
    int val = rand() % 10;

    if (val <= 8)
        val = 2;
        else val = 4;
    
    int x = Coord.first, y = Coord.second;
    board[x][y] = val;
    empcells--;
}

/*
  
        0 for Game Over (You lose / No more possible moves left)
        1 for Game Over and You win
        2 for Game in progress (Valid moves left)
   
*/
int checkGameStatus()
{
    bool moveAvailable = false;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] == 2048)
                return 1;
            if (i < 3 && board[i][j] == board[i + 1][j])
                moveAvailable = true;
            if (j < 3 && board[i][j] == board[i][j + 1])
                moveAvailable = true;
        }
    }
    if (empcells == 0 && (!moveAvailable))
        return 0;
    return 2;
}

/*
    Used to Initialize the Board and other values required by the game
*/
void initialize()
{
   
    empcells = 16;
    populateRandomCell();
    populateRandomCell();
}

    void play()
    {
        cout << "Direction Value	1	2	3	4" <<"\n";
        cout << "Move to perform	Left	Down	Right	Up" <<"\n";
         cout << "write down total No. of moves" <<"\n";

        int n; cin >> n;
        
        initialize();
        printBoard();

        for(int i=0; i<n; i++)
        {
           
            int moveDir;
            cin >> moveDir;
            bool validMove = move(moveDir);

            if (!validMove)
            {
                cout << "invalid move try different direction \n " ;
                continue;
            }

            populateRandomCell();
            printBoard();

            int gameStatus = checkGameStatus();

            if (gameStatus == 0)
            {
                cout << "Game Over, You Lose "<< "\n";
                return;
            }
            else if (gameStatus == 1)
            {
                cout <<"Game Over, You Win " << "\n";
                return;
            }
        }
    }

int main()
{
     ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    score=0;
    play();

    return 0;
}

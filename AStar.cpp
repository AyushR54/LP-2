#include <iostream>
#include <cmath>
using namespace std;
int g = 0;
void print(int puzzle[])
{
    for (int i = 0; i < 9; i++)
    {
        if (i % 3 == 0)
        {
            cout << "\n";
        }

        if (puzzle[i] == -1)
        {
            cout << "-"
                 << " ";
        }
        else
        {
            cout << puzzle[i] << " ";
        }
    }
}

bool isSolvable(int puzzle[])
{
    int invr = 0;
    for (int i = 0; i < 9; i++)
    {
        if (puzzle[i] == -1)
            continue;

        for (int j = i + 1; j < 9; j++)
        {
            if (puzzle[j] == -1)
                continue;
            if (puzzle[i] > puzzle[j])
                invr++;
        }
    }

    return invr & 1 ? false : true;
}

void copy(int arr1[], int start[])
{
    for (int i = 0; i < 9; i++)
    {
        arr1[i] = start[i];
    }
}

void moveUp(int arr[], int position)
{
    swap(arr[position], arr[position - 3]);
}
void moveDown(int arr[], int position)
{
    swap(arr[position], arr[position + 3]);
}
void moveLeft(int arr[], int position)
{
    swap(arr[position], arr[position - 1]);
}
void moveRight(int arr[], int position)
{
    swap(arr[position], arr[position + 1]);
}

int heuristic(int query[], int goal[])
{
    int h = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (query[i] == goal[j] && query[i] != -1)
            {

                h += abs((j - i) / 3) + abs((j - i) % 3);
            }
        }
    }

    return h + g;
}
void moveTile(int start[], int goal[])
{
    int emptyAt = 0;
    for (int i = 0; i < 9; i++)
    {
        if (start[i] == -1)
        {
            emptyAt = i;
        }
    }

    int row = (emptyAt) / 3;
    int col = emptyAt % 3;

    int t1[9], t2[9], t3[9], t4[9], f1 = 1000, f2 = 1000, f3 = 1000, f4 = 1000;
    copy(t1, start);
    copy(t2, start);
    copy(t3, start);
    copy(t4, start);

    if ((col + 1) < 3)
    {
        moveRight(t1, emptyAt);
        f1 = heuristic(t1, goal);
    }
    if ((col - 1) >= 0)
    {
        moveLeft(t2, emptyAt);
        f2 = heuristic(t2, goal);
    }
    if ((row + 1) < 3)
    {
        moveDown(t3, emptyAt);
        f3 = heuristic(t3, goal);
    }
    if ((row - 1) >= 0)
    {
        moveUp(t4, emptyAt);
        f4 = heuristic(t4, goal);
    }

    if (f1 <= f2 && f1 <= f3 && f1 <= f4)
    {
        moveRight(start, emptyAt);
    }

    if (f2 <= f1 && f2 <= f3 && f2 <= f4)
    {
        moveLeft(start, emptyAt);
    }

    if (f3 <= f1 && f3 <= f2 && f3 <= f4)
    {
        moveDown(start, emptyAt);
    }

    if (f4 <= f1 && f4 <= f2 && f4 <= f3)
    {
        moveUp(start, emptyAt);
    }
}

void solveEight(int start[], int goal[])
{

    g++;
    moveTile(start, goal);
    cout << "Changing State\n";
    bool isGoalState = true;
    print(start);
    cout << "\n";
    for (int i = 0; i < 9; i++)
    {
        if (start[i] != goal[i])
        {
            isGoalState = false;
            break;
        }
    }

    if (isGoalState == true)
    {
        cout << "Solved in " << g << " moves";
        return;
    }
    else
    {
        solveEight(start, goal);
    }
}

int main()
{
    int start[9];
    int goal[9];

    cout << "Enter the start state.(Enter -1 for empty)";
    for (int i = 0; i < 9; i++)
    {
        cin >> start[i];
    }

    cout << "Enter the goal state:(Enter -1 for empty):";
    for (int i = 0; i < 9; i++)
    {
        cin >> goal[i];
    }

    cout << "Start State\n";
    print(start);
    cout << "Goal State\n";

    print(goal);
    if (isSolvable(start))
    {
        solveEight(start, goal);
    }
    else
    {
        cout << "Not solvable";
    }
}
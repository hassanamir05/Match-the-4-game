#include<iostream>
#include<stdlib.h>
using namespace std;
int arr[7][8] = { {0} };
int solution(int arr[][8])
{
	int flag = 0;
	//HORIZONTAL SOLUTION
	for (int rows = 6; rows >= 1; rows--)
	{
		for (int i = 1; i <= 4; i++)
		{
			if (arr[rows][i]!=0 && arr[rows][i] == arr[rows][i + 1] && arr[rows][i + 1] == arr[rows][i + 2] 
			&& arr[rows][i + 2] == arr[rows][i + 3])
			{
				flag = 1;
				break;
			}
		}
	}
	//VERTICAL SOLUTION
	for (int column = 1; column <= 7; column++)
	{
		for (int i = 6; i >= 4; i--)
		{
			if (arr[i][column] != 0 && arr[i][column] == arr[i - 1][column] && arr[i - 1][column] == arr[i - 2][column] && arr[i - 2][column] == arr[i - 3][column])
			{
				flag = 1;
				break;
			}
		}
	}

	// RIGHT DIOGNAL SOLUTION
	for (int column = 1; column <= 4; column++)
	{
		for (int rows = 6; rows >= 4; rows--)
		{
			if (arr[rows][column] != 0 && arr[rows][column] == arr[rows - 1][column + 1] && arr[rows - 1][column + 1] == arr[rows - 2][column + 2] && arr[rows - 2][column + 2] == arr[rows - 3][column + 3])
			{
				flag = 1;
				break;
			}
		}
	}

	// LEFT DIOGNAL SOLUTION
	for (int column = 7; column >= 4; column--)
	{
		for (int rows = 6; rows >= 4; rows--)
		{
			if (arr[rows][column] != 0 && arr[rows][column] == arr[rows - 1][column - 1] && arr[rows - 1][column - 1] == arr[rows - 2][column - 2] && arr[rows - 2][column - 2] == arr[rows - 3][column - 3])
			{
				flag = 1;
				break;
			}
		}
	}
	return flag;
}

int fill(int arr[][8], int column, int player)
{
	int flag = 0;
	for (int i = 6; i >= 1; i--)
	{
		if (arr[i][column] == 0)
		{
			arr[i][column] = player;
			flag = 1;
			break;
		}
	}
	return flag;
}

void display()
{
	
	cout<<"\n\n\n\n\n\n\n\n\n";
	cout<< "                                        Column No.s -->   1     2     3     4     5     6     7  " <<endl;
	cout<<"\n\n";
	for (int rows = 1; rows <= 6; rows++)
	{
		cout<<"                                                       ";
		for (int column = 1; column <= 7; column++)
		{
			cout<<" ";
			if (arr[rows][column] == 0)
				cout<< "  .  ";
			else if (arr[rows][column] == 1)
				cout << "  o  ";
			else if (arr[rows][column] == 2)
				cout << "  x  ";
			
		}
		cout<<endl;
		cout << endl;
		
	}
	
}

int main()
{
	int i;
	int x, temporary = 0;
	display();
	while (!temporary)
	{
		
		//PLAYER 1
		cout<<endl;
		cout << "  Player 1 Turn!"<<endl;
		cout<<"  Enter the Column Number : ";
		cin >> x;
		cout << endl;

	    i = fill(arr, x, 1);
		while (!i)
		{
			cout << "ERROR! Column is full try another column!";
			cin >> x;
			cout << endl;
			i = fill(arr, x, 1);
		}
		system("CLS");
		temporary = solution(arr);
		display();
		if (temporary == 1)
		{
			cout <<endl<< "**WINNER WINNER **" << endl<<" Player 1 wins ";
			break;
		}

		//PLAYER 2
		cout<<endl;
		cout << "  Player 2 Turn!"<<endl;
		cout<<"  Enter the Column Number : ";
		cin >> x;
		cout << endl;

	    i = fill(arr, x, 2);
		while (!i)
		{
			cout << "ERROR! Column is full try another column!";
			cin >> x;
			cout << endl;
			i = fill(arr, x, 2);
		}
		system("CLS");
		temporary = solution(arr);
		display();
		if (temporary == 1)
		{
			cout << endl << "**WINNER WINNER **" << endl << " Player 2 wins ";
			break;
		}
		
	}

	return 0;
}



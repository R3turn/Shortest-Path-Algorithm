//Name: Christopher Tuncap
//Date: 2/21/2018 
//CSCI 4270
//Assignment 4 - Block Path
//This program will find the shortest path in a matrix and will display the routes using X with the original matrix.
#include <iostream>
using namespace std;

int main()
{
	int numberOfRows = 0;
	int numberOfColumns = 0;
	cout << "Blockpatch Algorithm By Chris Tuncap" << endl;

	cout << "Number of rows: ";
	cin >> numberOfRows;
	cout << "Number of columns: ";
	cin >> numberOfColumns;

	//Build Normal Matrix
	int** matrix = new int*[numberOfRows];
	//Build Path Matrix
	int** pathMatrix = new int*[numberOfRows];
	for (int i = 0; i < numberOfRows; i++)
	{
		matrix[i] = new int[numberOfColumns];
		pathMatrix[i] = new int[numberOfColumns];
	}

	for (int i = 0; i < numberOfRows; i++)
	{
		for (int j = 0; j < numberOfColumns; j++)
		{
			cout << "Enter a number for your matrix in row " << i <<
			" and column: " << j << ": ";
			cin >> matrix[i][j];
		}
	}

	cout << endl;

	cout << "Algorithm Time!" << endl;
	pathMatrix[numberOfRows - 1][numberOfColumns - 1] = matrix[numberOfRows - 1][numberOfColumns - 1];

	for (int i = (numberOfRows - 1); i >= 0; i--)
	{
		for (int j = (numberOfColumns - 1); j >= 0; j--)
		{
			if (i == (numberOfRows - 1) && j < (numberOfColumns - 1))
			{
				pathMatrix[i][j] = matrix[i][j] + pathMatrix[i][j + 1];
			}
			else
				if (i < (numberOfRows - 1) && j == (numberOfColumns - 1))
				{
					pathMatrix[i][j] = matrix[i][j] + pathMatrix[i + 1][j];
				}
				else if (i == (numberOfRows - 1) && j == 0)
				{
					pathMatrix[i][j] = matrix[i][j] + pathMatrix[i][j + 1];

				}
				else if (i == 0 && j == (numberOfColumns - 1))
				{
					pathMatrix[i][j] = matrix[i][j] + pathMatrix[i + 1][j];
				}
				else
					if (i < (numberOfRows - 1) && j < (numberOfColumns - 1))
					{
						if (pathMatrix[i][j + 1] < pathMatrix[i + 1][j])
						{
							pathMatrix[i][j] = matrix[i][j] + pathMatrix[i][j + 1];
						}
						else
							pathMatrix[i][j] = matrix[i][j] + pathMatrix[i + 1][j];
					}
		}

	}



	int distance = pathMatrix[0][0];

	int row = 0;
	int col = 0;

	matrix[row][col] = 0;
	matrix[numberOfRows - 1][numberOfColumns - 1] = 0;


	while (row <= numberOfRows - 1 && col <= numberOfColumns - 1)
	{
		if (row == numberOfRows - 1)
		{
			matrix[row][col + 1] == 0;
			col++;
		}
		else if (col == numberOfColumns - 1)
		{
			matrix[row + 1][col] = 0;
			row++;
		}
		else if (pathMatrix[row + 1][col] < pathMatrix[row][col + 1])
		{
			matrix[row + 1][col] = 0;
			row++;
		}
		else
		{
			matrix[row][col + 1] = 0;
			col++;
		}
	}


	for (int i = 0; i < numberOfRows; i++)
	{
		for (int j = 0; j < numberOfColumns; j++)
		{
			if (matrix[i][j] == 0)
			{
				cout << "X ";
			}
			else
				cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	cout << "Min Distance: " << distance << endl;


	system("pause");
	return 0;
}


#!/bin/bash

blue="\033[36m"


echo -e $blue "\n\t\t\tWelcome to the ZO_Sudoku Software.\n\t\033[0mThis little software uses a slightly modified version of \033[33mCaDiCaL\033[0m Solver\nto generate you a Random Sudoku NxNxNxN grid, or provide you with a solution to \nyour sudoku problem if it has any..\n-Type 1 to generate a random grid..\n-Type 2 to load the file containing your problem.."
read choice
if [ $choice = 1 ]
then
	./Baker.sh
elif [ $choice = 2 ] 
	then
	./Predef.sh
	else
		echo "Anyway, I hope you have a nice day.."
fi
	echo -e "\n\033[33mAUTHOR\n\t Written by Zaidi Omar in /Sep/2020,"
	
	
# Github/OmarZos/

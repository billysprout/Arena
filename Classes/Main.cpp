#include <iostream>
#include "Unit.hpp"
#include "Knight.hpp"
#include "Marksman.hpp"
#include "Priest.hpp"
#include "Frostbinder.hpp"
#include "Board.hpp"

using namespace std;
/*	DEFINITIONS
	atkType 0 = physical
	atkType 1 = magical
	side 0 = front
	side 1 = side
	side 2 = back
	*/
/*	LEGAL
	All CODE, IDEAS and COMMENTS are the copyright of Billy Sprout, 2015.
	Please contact sprout.billy@gmail.com with any questions.
	*/
void main()
{
	cout << "+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+\n";
	cout << " -----------------------------------------------------------------------------|\n";
	cout << "+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+\n";
	cout << "      `@@@        @@@@@@@@@@     @@@@@@@@@@@@   @@'       @@@        @@@\n";
	cout << "      @@@@+       @@@@@@@@@@@#   @@@@@@@@@@@@   @@@`      @@@       @@@@@ \n";
	cout << "     @@@;@@:      @@@      `@@@  @@@            @@@@@     @@@      +@@;@@+\n";
	cout << "     @@@ @@@      @@@       @@@  @@@            @@@@@@    @@@      @@@ @@@\n";
	cout << "    +@@, #@@.     @@@       '@@  @@@            @@@@@@;   @@@     :@@; ;@@:\n";
	cout << "    @@@   @@@     @@@       @@@  @@@,,,,,,,,,   @@@ @@@`  @@@     @@@   @@@\n";
	cout << "   :@@'   @@@     @@@      #@@@  @@@@@@@@@@@@   @@@ `@@@  @@@    .@@@   @@@.\n";
	cout << "   @@@    `@@@    @@@@@@@@@@@@`  @@@@@@@@@@@@   @@@  ;@@@ @@@    @@@     @@@\n";
	cout << "  .@@@     @@@    @@@@@@@@@@@    @@@            @@@   @@@#@@@    @@@     @@@\n";
	cout << "  @@@@@@@@@@@@#   @@@,,,@@@#     @@@            @@@    @@@@@@   @@@@@@@@@@@@@\n";
	cout << "  @@@@@@@@@@@@@   @@@    @@@'    @@@            @@@     @@@@@   @@@@@@@@@@@@@\n";
	cout << " @@@@@@@@@@@@@@;  @@@     @@@,   @@@            @@@     .@@@@  #@@@@@@@@@@@@@#\n";
	cout << " @@@         @@@  @@@      @@@`  @@@@@@@@@@@@   @@@      +@@@  @@@         @@@\n";
	cout << "#@@:         @@@, @@@      `@@@  @@@@@@@@@@@@   @@@       @@@ ;@@+         +@@;\n";
	cout << "@@@           @@@ @@@       ,@@@ @@@@@@@@@@@@   @@@        @@ @@@           @@@\n";
	cout << "+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+\n";
	cout << " -----------------------------------------------------------------------------|\n";
	cout << "+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+\n";
	//create board
	Board b = Board();

	b.toString();
	system("PAUSE");
}
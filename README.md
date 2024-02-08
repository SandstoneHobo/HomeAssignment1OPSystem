# HomeAssignment1OPSystem

This application runs basic shell commands in a windows operating system

To use the program you need to run HomeAssignment1OPSystem.exe file in the repository

The menu is displayed as such

1. List directory contents
2. Print working directoy
3. Create a new directory
4. Display a message
5. Concatenate and display content of a file
6. Exit


Option 1:
	If the user inputs 1 in the menu prompt above, the program will execute the dir command and print the contents of the directory the program is running in

Option 2:
	If the user inputs 2 in the menu prompt, the program will execute cd, which in windows will print the current working directory of the program.

Option 3:
	If the user inputs 3 in the menu prompt, they will then be prompted for a name i.e.
		"What do you want to name the new directory?:"
	This prompt will accept a string from the user for the new directory's name, which will then be run in a command as mkdir <name given>

Option 4:
	If the user inputs 4 in the menu prompt, they will be prompted for a message i.e
		"What message do you want to display?: "
	This prompt will accept a string from the user for the message to be displayed, which will be executed in a command as echo <message given>

Option 5:
	If the user inputs 5 in the menu prompt, they will be prompted for a mode i.e
		"Do you want to display a file (d) or concatenate a file(c)? (q to quit): "
	The prompt accepts a character, and if it is not d, c, or q, the prompt will be displayed again. If the input is q the user will be returned to the main menu. 
	If the user inputs d they will be prompted for a file name i.e.
			"What file do you want to display?: "
		The prompt will accept a string for the name of the file the user wants display, then the program will execute cat <file name>

	If the user inputs c they will be prompted for a file name i.e
			"Enter a file you want to add to the list of concatenations (next to move on or back to remove the most recent file entered): "
		The prompt will accept strings until the user inputs next or back
			If the user inputs back, the program will remove the most recent file input, or if there are no files left in the list it will return them to the menu prompt
			If the user inputs any string other than next or back it will be added to the list of file names
			If the user inputs next, the program will move to the next prompt
				"Enter the name of the file you want the output to be: "
			This prompt will accept a string name for the output file, when given the program will append all the files given in the previous prompt to this output file with a command in the form of cat <file list> >> <output name>

Option 6:
	If the user inputs 6 in the menu prompt, the program will halt

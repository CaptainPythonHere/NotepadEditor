# NotepadEditor
## Features ##
A simple text editor with following features:
Under ‘Files’:
1.	New file
2.	Open File
3.	Save
4.	Save As
5.	Print
Under ‘Edit’:
1.	Redo
2.	Undo
3.	Cut
4.	Copy 
5.	Paste
Under ‘Format’:
1.	Bold
2.	Un-Bold
3.	Italics
4.	Un-Italics
5.	Underline
6.	Un-Underline
And last ‘About Me’

## How to run ##
1.	First install qt5
  >  $ Sudo apt-get install qt5-default
2.	Download the zip file
3.	Extract all files
4.	Open terminal
  >  $ cd NotepadEditor\
  >  $ qmake MyNotepad.pro\
  >  $ make
5.  To run the code:
  >  $ ./MyNotepad
  
## What has been done? ##
Each feature mentioned above has a purpose as its name. The features Bold/Un-Bold, Italics/Un-Italics, Underline/Un-Underline only affect text highlighted by the cursor, be it a character, word, line or an entire document. Their icons are saved in Resources/Images. There also exits another feature i.e., About Me that reads an HTML file and displays it in a dialog box. The entire process has been divided into mainly three files:
notepad.ui, main.cpp,  and notepad.cpp.
1.	notepad.ui contains the entire layout of the application. Basically, how you want to style and make it look is what is done here. You define the menu bar, tool bar, size of the text editor and placements of buttons here.
2.	main.cpp contains the main function.
3.	Notepad.cpp contains all the methods that are triggered by clicking on to these buttons of the features. These methods are also refereed to as slots of the buttons, widgets etc.

## Challenges ##
1.	One should be familiar with CPP and OOP.
2.	In depth knowledge and understanding of documentation of qt.
3.	Things might get confusing if not named properly.

![Screenshot (607)](https://github.com/CaptainPythonHere/NotepadEditor/blob/main/Screenshot%20(606).png)

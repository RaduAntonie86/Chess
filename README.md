# Chess
Simple chess game I created for a college project for a better understanding of Object Oriented Programming.
The entire interface was created for Embarcadero's RADStudio. This was my first ever project, having written the entire code myself, so the game itself is understandibly quite buggy and unfinished.
Not every rule of chess is properly implemented.

# Classes
Since it was created from an Object Oriented Programming perspective, every type of piece is part of the Piece class, the classes for each piece type being derived from this one. I have used polymorphism to easily reuse the methods of the Piece class for every piece, regardless of type. 
Looking back, having a Game class, which contained variables for the board and every piece would have resulted in far cleaner code, as the functions for checking whether or not a piece can move in a specific direction or not are contained within the interface itself, which made the whole project into a mess.

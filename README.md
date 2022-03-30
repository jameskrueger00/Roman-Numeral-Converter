# Roman-Numeral-Converter
#convert.exe is run from the command line with 2 additional arguments

Usage: `convert [-dtr/-rtd] <value>`
---
- -dtr: decimal to roman
- -rtd: roman to decimal
- value: valid roman numeral (ALL CAPS)/integer (0 < value < 4000)

- The program will display this usage info if (the wrong number of arguments are specified) OR (either the flag or the input is invalid)

  
 Misc
 ---
- I wrote my code on a linux machine and then tested my program with the minGW compiler on my windows machine to ensure compatibility.

- I spent all 4 hours on the challenge. 

- I prioritized a working solution over optimizing my conversion code. 

- If I had more time, I believe I could work out an algorithm that would determine the proper roman numeral symbol without hard coding each place value in RomanNumeral::toRoman(). The challenge document mentioned a certain (10x+1) relationship that I considered for a bit before I decided to move forward with my approach.

- That potential algorithm could also be implemented in my RomanNumeral::isValidRomanNumeral() function to make my symbol checking slightly more mathematically rigerous instead of hard coding each of the symbol relations. This would be more readable and time efficient than my current approach.

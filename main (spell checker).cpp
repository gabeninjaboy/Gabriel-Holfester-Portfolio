/*
 * Name: Gabriel Holfester
 * Date Submitted: 2/27/2025
 * Lab Section: 003
 * Assignment Name: Lab 5: Spell Checker Using a Hash Table
 */
 
 #include "stringset.h"
 #include <iostream>
 #include <fstream>
 
 void testStringset(Stringset& words);
 void loadStringset(Stringset& words, string filename);
 vector<string> spellcheck(const Stringset& words, string word);


/*
 int main()
 {
     Stringset wordlist;
     testStringset(wordlist);
     return 0;
 }
*/
 void testStringset(Stringset& words)
 {
     string choice;
     string word;
     do
     {
         cout << "I: insert word" << endl;
         cout << "F: find word" << endl;
         cout << "R: remove word" << endl;
         cout << "P: print words in stringset" << endl;
         cout << "Q: quit" << endl;
         cin >> choice;
         switch (choice[0])
         {
             case 'I':
             case 'i':
                cout << "Enter word to insert: ";
                cin >> word;
                words.insert(word);
                break;
             case 'F':
             case 'f':
                cout << "Enter word to find: ";
                cin >> word;
                if (words.find(word))
                {
                    cout << word << " in stringset" << endl;
                }
                else
                {
                    cout << word << " not in stringset" << endl;
                }
                break;
             case 'R':
             case 'r':
                cout << "Enter word to remove: ";
                cin >> word;
                words.remove(word);
                break;
             case 'P':
             case 'p':
                vector<list<string>> t = words.getTable();
                int numWords = words.getNumElems();
                int tSize = words.getSize();
                for(int i=0; i<tSize; ++i)
                {
                    list<string>::iterator pos;
                    for (pos = t[i].begin(); pos != t[i].end(); ++pos)
                    {
                        cout << *pos << endl;
                    }
                }
                cout << "Words: " << numWords << endl;
         }
     } while (choice[0] != 'Q' && choice[0] != 'q');
 }
 
 void loadStringset(Stringset& words, string filename)
 {
   // Creates a file to open and a string to follow and inserts each word from the file into words //
   
   ifstream infile(filename);
   string word;

   while(getline(infile, word))
     {
       words.insert(word);
     }
 }
 
 vector<string> spellcheck(const Stringset& words, string word)
 {
   // Creates a vector to store the alternate words //
   
   vector<string> alternates;

   // If you find the word, go through each character in the string and change it by each letter in the alphabet and see if it is an alternate, if so add it to the alternates array //
   
   if(words.find(word))
     {
       for(int i = 0; i < word.length(); i++)
	 {
	   for(char letter = 'a'; letter <= 'z'; letter++)
	     {
	       string newWord = word;
	       newWord[i] = letter;

	       // If you find the newWord in the words array and the new word is not a duplicate, add the new word to the alternates array //

	       if(words.find(newWord) && newWord != word)
		 { 
		   alternates.push_back(newWord);
		 }
	       
	     }
	   //	   cout<<alternates[i]<<endl;
	 }
     }

   return alternates;
 }

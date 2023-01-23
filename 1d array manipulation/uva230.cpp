#include <bits/stdc++.h>

using namespace std;

bool sortbyAuthor(const pair<pair<string,string>,bool> &a,
              const pair<pair<string,string>,bool> &b)
{
    if(a.first.second == b.first.second) {
      return (a.first.first < b.first.first);
    }
    return (a.first.second < b.first.second);
}

bool sortbyAuthorReturnedBooks(const pair<string,string> &a,
              const pair<string,string> &b)
{
    if(a.second == b.second) {
      return (a.first < b.first);
    }
    return (a.second < b.second);
}

int main()
{
  vector<pair<pair<string, string>, bool>> books;
  string input;
  cin.tie(NULL);
  while (getline(cin,input)) {
    if (input == "END") break;
    pair<string, string> authorBook;
    for(int i = 1; i < input.length(); i++) {
      if (input.at(i) == '"') {
        authorBook.first = input.substr(0,i+1);
        authorBook.second = input.substr(i+5, input.length()-i-5);
        break;
      }
    }
    pair<pair<string,string>, bool> authorBookInShelf;
    authorBookInShelf.first = authorBook;
    authorBookInShelf.second = true;
    books.push_back(authorBookInShelf);
  }
  sort(books.begin(), books.end(), sortbyAuthor);
  vector<string> Instructions;
  vector<pair<string, string>> returnedBooks;
  while (getline(cin,input)) {
    if (input == "END") break;
    string bookBorrowed, bookReturned;
    switch (input.at(0)) {
      case 'B':
        bookBorrowed = input.substr(7,input.length()-7);
        for(int i = 0; i < books.size(); i++) {
          if(books[i].first.first == bookBorrowed) {
            books[i].second = false;
            break;
          }
        }
        break;
      case 'R':
        bookReturned = input.substr(7,input.length()-7);
        for(int i = 0; i < books.size(); i++) {
          if(books[i].first.first == bookReturned) {
            returnedBooks.push_back(books[i].first);
            break;
          }
        }
        sort(returnedBooks.begin(), returnedBooks.end(), sortbyAuthorReturnedBooks);
        break;
      case 'S':
        for(int i = 0; i < returnedBooks.size(); i++){
          for(int j = 0; j < books.size(); j++) {
            if(books[j].first == returnedBooks[i]) {
              books[j].second = true;
              int indexBefore = -1;
              for(int k = j-1; k >= 0; k--) {
                if(books[k].second) {
                  indexBefore = k;
                  break;
                }
              }
              if(indexBefore > -1) {
                Instructions.push_back("Put "+returnedBooks[i].first+" after "+books[indexBefore].first.first+"\n");
              } else {
                Instructions.push_back("Put "+returnedBooks[i].first+" first\n");
              }
              break;
            }
          }
        }
        Instructions.push_back("END\n");
        returnedBooks.clear();
        break;    
      default:
        break;
    }
  }
  for(int i = 0; i < Instructions.size(); i++) {
    cout<<Instructions[i];
  }
  return 0;
}

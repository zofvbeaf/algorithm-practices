#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

struct Book{
    char id[8],tittle[82],author[82],publisher[82],year[5];
    vector<string> keywords;
};

vector<Book> books;

bool comp(Book a, Book b){
    if(strcmp(a.id, b.id) > 0) return 0;
    else return 1;
}

void query(char num[], char s[]){
    int flag = 0,i,j;
    if(num[0] == '1') for(i=0; i<books.size(); i++){
        if(strcmp(s, books[i].tittle) == 0) { cout<<books[i].id<<endl; flag = 1;}
    }
    else if(num[0] == '2') for(i=0; i<books.size(); i++){
        if(strcmp(s, books[i].author) == 0) { cout<<books[i].id<<endl; flag = 1;}
    }
    else if(num[0] == '3') for(i=0; i<books.size(); i++) for(j=0; j<books[i].keywords.size(); j++){
        if(s == books[i].keywords[j]) { cout<<books[i].id<<endl; flag = 1;}
    }
    else if(num[0] == '4') for(i=0; i<books.size(); i++){
        if(strcmp(s, books[i].publisher) == 0) { cout<<books[i].id<<endl; flag = 1;}
    }
    else if(num[0] == '5') for(i=0; i<books.size(); i++){
        if(strcmp(s, books[i].year) == 0) { cout<<books[i].id<<endl; flag = 1;}
    }
    if(flag == 0) cout<<"Not Found"<<endl;
}

int main(){
    int n,m;
    cin>>n;
    cin.ignore();
    while(n--){
        Book book;
        gets(book.id);
        gets(book.tittle);
        gets(book.author);
        char key[12];
        while(cin>>key){
            book.keywords.push_back(key);
            if(cin.get() == '\n') break;
        }
        gets(book.publisher);
        gets(book.year);
        books.push_back(book);
    }
    sort(books.begin(),books.end(),comp);
    cin>>m;
    char num[3],s[82];
    while(m--){
        cin>>num;
        cin.ignore();
        gets(s);
        cout<<num<<" "<<s<<endl;
        query(num,s);
    }
    return 0;
}

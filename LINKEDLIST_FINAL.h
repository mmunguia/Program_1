// Author: Marcos Munguia

#ifndef LINKEDLIST_FINAL
#define LINKEDLIST_FINAL


class myList{
private:
    struct node{
    int data;
    node *next;
    };
    node *head;
    node *curr;
    int sizeCount = 0;
public:
    myList();
    ~myList();
    void PutItem(int);
    void PrintList(std::string);
    int GetLength();
    void DeleteItem(int);
    int GetItem(int,std::string);
    void Quit();
    bool IsFull();
    void MakeEmpty();
};
#endif // LINKEDLIST_FINAL

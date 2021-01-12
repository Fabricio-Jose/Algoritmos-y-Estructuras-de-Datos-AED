#ifndef H_VideoListType
#define H_VideoListType

#include <iostream>
#include "unorderedLinkedList.h"
#include "videoType.h"

using namespace std;

class videoListType:public unorderedLinkedList<videoType>
{
public:
    bool videoSearch(string title) const;
    bool isVideoAvailable(string title) const;
    void videoCheckOut(string title);
    void videoCheckIn(string title);
    bool videoCheckTitle(string title) const;
    void videoUpDateInStock(string title, int num);
    void videoSetCopiesInStock(string title, int num);
    void videoPrintTitle() const;
private:
    void searchVideoList(string title, bool& found, nodeType<videoType>* &current) const;
};

void videoListType::searchVideoList(string title, bool& found, nodeType<videoType>* &current) const
{
    found = false;
    current = first;
    while (current != NULL && !found)
        if (current->info.checkTitle(title))
            found = true;
        else
            current = current->link;
}

bool videoListType::isVideoAvailable(string title) const
{
    bool found;
    nodeType<videoType> *location;
    searchVideoList(title, found, location);
    if(found)
        found = (location->info.getNoOfCopiesInStock() > 0);
    else
        found = false;
    return found;
}

void videoListType::videoCheckIn(string title)
{
    bool found = false;
    nodeType<videoType> *location;
    searchVideoList(title, found, location);
    if (found)
        location->info.checkIn();
    else
        cout << "The store does not carry " << title << endl;
}

void videoListType::videoCheckOut(string title)
{
    bool found = false;
    nodeType<videoType> *location;
    searchVideoList(title, found, location);
    if(found)
        location->info.checkOut();
    else 
        cout << "The store does not carry " << title << endl;
}

bool videoListType::videoCheckTitle(string title) const
{
    bool found = false;
    nodeType<videoType> *location;
    searchVideoList(title, found, location);
    return found;
}

void videoListType::videoUpDateInStock(string title, int num)
{
    bool found = false;
    nodeType<videoType> *location;
    searchVideoList(title, found, location);
    if(found)
        location->info.updateInStock(num);
    else
        cout << "The store does not carry " << title << endl;
}

void videoListType::videoSetCopiesInStock(string title, int num)
{
    bool found = false;
    nodeType<videoType> *location;
    searchVideoList(title, found, location);

    if(found)
        location->info.setCopiesInStock(num);
    else 
        cout << "The store does not carry " << title << endl;
}

bool videoListType::videoSearch(string title) const
{
    bool found = false;
    nodeType<videoType> * location;
    searchVideoList(title, found, location);
    return found;
}

void videoListType::videoPrintTitle() const
{
    nodeType<videoType>* current;
    current = first;
    while (current != NULL)
    {
        current->info.printTitle();
        current = current->link;
    }
    
}
#endif


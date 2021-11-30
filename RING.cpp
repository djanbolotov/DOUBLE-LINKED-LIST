#include <iostream>
using namespace std;

struct List {
    int value;
    List* next;
    List* previous;
};

void initialize(List**, List**, int);
void clear(List**);

void insert(List**, List**, int);
void insertBefore(List**, List**, int, int);
void insertAfter(List**, List**, int, int);
void insertBeforePosition(List**, List**, int, int);
void insertAfterPosition(List**, List**, int, int);

void deleteValue(List**, List**, int);
void deleteBefore(List**, List**, int);
void deleteAfter(List**, List**, int);
void deleteBeforeIndex(List**, List**, int);
void deleteAfterIndex(List**, List**, int);

void searchValue(List*, int);
void searchBefore(List*, int);
void searchAfter(List*, int);
void searchBeforeIndex(List*, int);
void searchAfterIndex(List*, int);

void printFromStart(List*);
void printFromEnd(List*);

void sort(List**, List**);
void exchange(List**, List**, int, int);

int getVariant(int);
int getValue();
int getSecondValue();
int getPosition();
int getElement();

void printMainMenu();
void printSearchMenu();
void printInsertMenu();
void printDeleteMenu();
void printOutputMenu();
void printSrcMenu();

void incorrectPosition();
void elementNotFound();
void elementsAreNotAdjacent();
void listIsEmpty();
void listIsAlreadyInitialized();
void deletedElement(int value);

int main()
{
    List* start = NULL;
    List* stop = NULL;
    int value, position, element, value2;
    int menu, search, del, select_insert, print, src;
    do {
        system("CLS");
        printMainMenu();
        menu = getVariant(8);
        if (menu < 7)
        {
            if(start != NULL)
                cout << "ADDRESSES:\nstart = " << start << ", stop.next = " << stop->next << endl;
            printFromStart(start);
        }
        switch (menu) 
        {
        case 1:
            value = getValue();
            initialize(&start, &stop, value);
            break;
        case 2:
            printInsertMenu();
            select_insert = getVariant(5);
            switch (select_insert)
            {
            case 1:
                value = getValue();
                insert(&stop, &start, value);
                break;
            case 2:
                element = getElement();
                value = getValue();
                insertBefore(&start, &stop, element, value);
                break;
            case 3:
                element = getElement();
                value = getValue();
                insertAfter(&start, &stop, element, value);
                break;
            case 4:
                position = getPosition();
                value = getValue();
                insertBeforePosition(&start, &stop, position, value);
                break;
            case 5:
                position = getPosition();
                value = getValue();
                insertAfterPosition(&start, &stop, position, value);
                break;
            }
            break;
        case 3:
            printDeleteMenu();
            del = getVariant(5);
            switch (del)
            {
            case 1:
                value = getValue();
                deleteValue(&start, &stop, value);
                break;
            case 2:
                value = getValue();
                deleteBefore(&start, &stop, value);
                break;
            case 3:
                value = getValue();
                deleteAfter(&start, &stop, value);
                break;
            case 4:
                position = getPosition();
                deleteBeforeIndex(&start, &stop, position);
                break;
            case 5:
                position = getPosition();
                deleteAfterIndex(&start, &stop, position);
                break;
            }
            break;
        case 4:
            printSearchMenu();
            search = getVariant(5);
            switch (search)
            {
            case 1:
                value = getValue();
                searchValue(start, value);
                break;
            case 2:
                value = getValue();
                searchBefore(stop, value);
                break;
            case 3:
                value = getValue();
                searchAfter(start, value);
                break;
            case 4:
                position = getPosition();
                searchBeforeIndex(start, position);
                break;
            case 5:
                position = getPosition();
                searchAfterIndex(start, position);
                break;
            }
            break;
        case 5:
            clear(&start);
            stop = start;
            break;
        case 6:
            printSrcMenu();
            src = getVariant(2);
            switch (src)
            {
            case 1:
                value = getValue();
                value2 = getSecondValue();
                exchange(&start, &stop, value, value2);
                break;
            case 2:
                sort(&start, &stop);
                break;
            }
            break;
        case 7:
            printOutputMenu();
            print = getVariant(2);
            switch (print)
            {
            case 1:
                printFromStart(start);
                break;
            case 2:
                printFromEnd(stop);
                break;
            }
            break;
        }
        if (menu < 7)
        {
            if(start != NULL)
                cout << "ADDRESSES:\nstart = " << start << ", stop.next = " << stop->next << endl;
            printFromStart(start);
        }
        if (menu < 8)
        {
            system("pause");
        }
    } while (menu != 8);
    return 0;
}

//get values
int getElement()
{
    int element;
    cout << "Enter element value: ";
    cin >> element;
    return element;
}
int getValue()
{
    int value;
    cout << "Enter value: ";
    cin >> value;
    return value;
}
int getSecondValue()
{
    int value;
    cout << "Enter second value: ";
    cin >> value;
    return value;
}
int getPosition()
{
    int position;
    cout << "Enter position: ";
    cin >> position;
    return position;
}
int getVariant(int maxvalue)
{
    int variant;
    cin >> variant;
    while (variant < 1 || variant > maxvalue)
    {
        cout << "Incorrect input. Try again: ";
        cin >> variant;
    }
    return variant;
}

//menu
void printMainMenu()
{
    cout << "(1: INITIALIZE, 2: INSERT, 3: DELETE, 4: SEARCH, 5: CLEAR, 6: SRC, 7: PRINT, 8: EXIT)" << endl;
    cout << "Select any value you want:";
}
void printSearchMenu()
{
    cout << "(1: SEARCH VALUE, 2: SEARCH BEFORE, 3: SEARCH AFTER, 4: SEARCH BEFORE INDEX, 5: SEARCH AFTER INDEX)" << endl;
    cout << "Which search we will use:";
}
void printInsertMenu()
{
    cout << "(1: INSERT VALUE, 2: INSERT BEFORE, 3: INSERT AFTER, 4: INSERT BEFORE INDEX, 5: INSERT AFTER INDEX)" << endl;
    cout << "Which insert we will use:";
}
void printDeleteMenu()
{
    cout << "(1: DELETE VALUE, 2: DELETE BEFORE, 3: DELETE AFTER, 4: DELETE BEFORE INDEX, 5: DELETE AFTER INDEX)" << endl;
    cout << "Which delete we will use:";
}
void printOutputMenu()
{
    cout << "(1: FROM BEGINING, 2: FROM ENDING)" << endl;
    cout << "Which print we will use:";
}
void printSrcMenu()
{
    cout << "(1: CHANGE ELEMENTS, 2: SORT ELEMENTS)" << endl;
    cout << "Choose the method that we will use:";
}

//messages
void incorrectPosition()
{
    cout << "You entered incorrect position!" << endl;
}
void elementNotFound()
{
    cout << "Element not found!" << endl;
}
void elementsAreNotAdjacent()
{
    cout << "Adjacent elements not found!" << endl;
}
void listIsEmpty()
{
    cout << "List is empty!" << endl;
}
void listIsAlreadyInitialized()
{
    cout << "List is already initialized!" << endl;
}
void deletedElement(int value)
{
    cout << "Deleted element is: " << value << endl;
}

//initialize
void initialize(List** start, List** stop, int value)
{
    if (*start == NULL && *stop == NULL)
    {
        List* pv = new List;
        pv->value = value;
        pv->next = pv;
        pv->previous = pv;
        *start = pv;
        *stop = pv;
    }
    else
    {
        listIsAlreadyInitialized();
    }
}
void clear(List** start)
{
    if (start != NULL)
    {
        List* current_element = *start, * pv;
        do
        {
            pv = current_element->next;
            *current_element = {};
            current_element = pv;
        } while (current_element != *start);
        current_element->next = current_element;
        current_element->previous = current_element;
        *start = current_element;
    }
}

//print
void printFromStart(List* start)
{
    if (start != NULL)
    {
        List* pv = start;
        do
        {
            cout << "L(" << pv->value << "), ";
            pv = pv->next;
        } while (pv != start);
        cout << endl;
    }
    else
    {
        listIsEmpty();
    }
}
void printFromEnd(List* stop)
{
    if (stop != NULL)
    {
        List* pv = stop;
        do
        {
            cout << "L(" << pv->value << "), ";
            pv = pv->previous;
        } while (pv != stop);
        cout << endl;
    }
    else
    {
        listIsEmpty();
    }
}

//insert
void insert(List** stop, List** start, int value)
{
    if (*stop != NULL)
    {
        List* pv = new List;
        pv->value = value;
        pv->next = *start;
        pv->previous = *stop;
        (*stop)->next = pv;
        (*start)->previous = pv;
        *stop = pv;
    }
}
void insertBefore(List** start, List** stop, int element, int value)
{
    if (*start != NULL)
    {
        List* prev = *start;
        bool found = false;
        do
        {
            if (prev->value == element)
            {
                found = true;
                break;
            }
            prev = prev->next;
        } while (prev != *start);
        if (found)
        {
            List* pv = new List;
            pv->value = value;
            if (prev->previous == *stop)
            {
                pv->next = prev;
                pv->previous = *stop;
                (*stop)->next = pv;
                prev->previous = pv;
                *start = pv;
            }
            else
            {
                pv->next = prev;
                pv->previous = prev->previous;
                prev->previous = pv;
                prev = pv->previous;
                prev->next = pv;
            }
        }
        else
        {
            elementNotFound();
        }
    }
}
void insertAfter(List** start, List** stop, int element, int value)
{
    if (*stop != NULL)
    {
        List* nex = *stop;
        bool found = false;
        do
        {
            if (nex->value == element)
            {
                found = true;
                break;
            }
            nex = nex->previous;
        } while (nex != *stop);
        if (found)
        {
            List* pv = new List;
            pv->value = value;
            if (nex->next == *start)
            {
                pv->previous = nex;
                pv->next = *start;
                (*start)->previous = pv;
                nex->next = pv;
                *stop = pv;
            }
            else
            {
                pv->previous = nex;
                pv->next = nex->next;
                nex->next = pv;
                nex = pv->next;
                nex->previous = pv;
            }
        }
        else
        {
            elementNotFound();
        }
    }
}
void insertBeforePosition(List** start, List** stop, int position, int value)
{
    if (*start != NULL)
    {
        if (position > 0)
        {
            List* prev = *start;
            int iterator = 1;
            while (iterator != position)
            {
                prev = prev->next;
                iterator++;
            }
            List* pv = new List;
            pv->value = value;
            if (prev->previous == *stop)
            {
                pv->next = prev;
                pv->previous = *stop;
                (*stop)->next = pv;
                prev->previous = pv;
                *start = pv;
            }
            else
            {
                pv->next = prev;
                pv->previous = prev->previous;
                prev->previous = pv;
                prev = pv->previous;
                prev->next = pv;
            }
        }
        else
        {
            incorrectPosition();
        }
    }
}
void insertAfterPosition(List** start, List** stop, int position, int value)
{
    if (start != NULL)
    {
        if (position > 0)
        {
            List* nex = *start;
            int iterator = 1;
            while (iterator != position)
            {
                nex = nex->next;
                iterator++;
            }
            List* pv = new List;
            pv->value = value;
            if (nex->next == *start)
            {
                pv->previous = nex;
                pv->next = *start;
                (*start)->previous = pv;
                nex->next = pv;
                *stop = pv;
            }
            else
            {
                pv->previous = nex;
                pv->next = nex->next;
                nex->next = pv;
                nex = pv->next;
                nex->previous = pv;
            }
        }
        else
        {
            incorrectPosition();
        }
    }
}

//delete
void deleteValue(List** start, List** stop, int value)
{
    if (*start != NULL)
    {
        List* pv = *start;
        bool found = false;
        do
        {
            if (pv->value == value)
            {
                found = true;
                break;
            }
            pv = pv->next;
        } while (pv != *start);
        if (found)
        {
            if ((*start)->previous == *start)
            {
                if ((*start)->next == *start)
                {
                    deletedElement(pv->value);
                    delete pv;
                    pv = {};
                    *start = pv;
                    *stop = pv;
                }
            }
            else
            {
                pv->previous->next = pv->next;
                pv->next->previous = pv->previous;
                if (pv == *start)
                {
                    *start = pv->next;
                }
                else if (pv == *stop)
                {
                    *stop = pv->previous;
                }
                deletedElement(pv->value);
                delete pv;
            }
        }
        else
        {
            elementNotFound();
        }
    }
}
void deleteBefore(List** start, List** stop, int value)
{
    if (*start != NULL)
    {
        List* pv = *start;
        bool found = false;
        do
        {
            if (pv->value == value)
            {
                found = true;
                break;
            }
            pv = pv->next;
        } while (pv != *start);
        if (found)
        {
            if ((*start)->previous == *start)
            {
                if ((*start)->next == *start)
                {
                    deletedElement(pv->value);
                    delete pv;
                    pv = {};
                    *start = pv;
                    *stop = pv;
                }
            }
            else
            {
                pv = pv->previous;
                pv->previous->next = pv->next;
                pv->next->previous = pv->previous;
                if (pv == *start)
                {
                    *start = pv->next;
                }
                else if (pv == *stop)
                {
                    *stop = pv->previous;
                }
                deletedElement(pv->value);
                delete pv;
            }
        }
        else
        {
            elementNotFound();
        }
    }
}
void deleteAfter(List** start, List** stop, int value)
{
    if (*stop != NULL)
    {
        List* pv = *stop;
        bool found = false;
        do
        {
            if (pv->value == value)
            {
                found = true;
                break;
            }
            pv = pv->previous;
        } while (pv != *stop);
        if (found)
        {
            if ((*start)->previous == *start)
            {
                if ((*start)->next == *start)
                {
                    deletedElement(pv->value);
                    delete pv;
                    pv = {};
                    *start = pv;
                    *stop = pv;
                }
            }
            else
            {
                pv = pv->next;
                pv->previous->next = pv->next;
                pv->next->previous = pv->previous;
                if (pv == *start)
                {
                    *start = pv->next;
                }
                else if (pv == *stop)
                {
                    *stop = pv->previous;
                }
                deletedElement(pv->value);
                delete pv;
            }
        }
        else
        {
            elementNotFound();
        }
    }
}
void deleteBeforeIndex(List** start, List** stop, int position)
{
    if (*start != NULL)
    {
        if (position > 0)
        {
            List* pv = *start;
            int iteration = 1;
            while (iteration != position)
            {
                pv = pv->next;
                iteration++;
            }
            if ((*start)->previous == *start)
            {
                if ((*start)->next == *start)
                {
                    deletedElement(pv->value);
                    delete pv;
                    pv = {};
                    *start = pv;
                    *stop = pv;
                }
            }
            else
            {
                pv = pv->previous;
                pv->previous->next = pv->next;
                pv->next->previous = pv->previous;
                if (pv == *stop)
                {
                    *stop = pv->previous;
                }
                else if (pv == *start)
                {
                    *start = pv->next;
                }
                deletedElement(pv->value);
                delete pv;
                pv = {};
            }
        }
        else
        {
            incorrectPosition();
        }
    }
}
void deleteAfterIndex(List** start, List** stop, int position)
{
    if (start != NULL)
    {
        if (position > 0)
        {
            List* pv = *start;
            int iteration = 1;
            while (iteration != position)
            {
                pv = pv->next;
                iteration++;
            }
            if ((*start)->next == *start)
            {
                deletedElement(pv->value);
                delete pv;
                pv = {};
                *start = pv;
                *stop = pv;
            }
            else
            {
                pv = pv->next;
                pv->previous->next = pv->next;
                pv->next->previous = pv->previous;
                if (pv == *stop)
                {
                    *stop = pv->previous;
                }
                else if (pv == *start)
                {
                    *start = pv->next;
                }
                deletedElement(pv->value);
                delete pv;
                pv = {};
            }
        }
        else
        {
            incorrectPosition();
        }
    }
}

//search
void searchValue(List* start, int value)
{
    if (start != NULL)
    {
        List* pv = start;
        int iterator = 1;
        bool found = false;
        do
        {
            if (pv->value == value)
            {
                found = true;
                cout << "Value that you searched is found at index: " << iterator << endl;
            }
            pv = pv->next;
            iterator++;
        } while (pv != start);
        if (!found)
        {
            elementNotFound();
        }
    }
}
void searchBefore(List* stop, int value)
{
    if (stop != NULL)
    {
        List* pv = stop;
        bool found = false;
        do
        {
            if (pv->value == value)
            {
                cout << "Element before " << value << " is: L(" << pv->previous->value << ")" << endl;
                found = true;
            }
            pv = pv->previous;
        } while (pv != stop);
        if (!found)
        {
            elementNotFound();
        }
    }
}
void searchAfter(List* start, int value)
{
    if (start != NULL)
    {
        List* pv = start;
        bool found = false;
        do
        {
            if (pv->value == value)
            {
                cout << "Element after " << value << " is: L(" << pv->next->value << ")" << endl;
                found = true;
            }
            pv = pv->next;
        } while (pv != start);
        if (!found)
        {
            elementNotFound();
        }
    }
}
void searchBeforeIndex(List* start, int position)
{
    if (start != NULL)
    {
        List* pv = start;
        int iterator = 1;
        if (position > 0)
        {
            while (iterator != position)
            {
                pv = pv->next;
                iterator++;
            }
            cout << "Element before index " << position << " is: L(" << pv->previous->value << ")" << endl;
        }
        else
        {
            incorrectPosition();
        }
    }
}
void searchAfterIndex(List* start, int position)
{
    if (start != NULL)
    {
        List* pv = start;
        int iterator = 1;
        if (position > 0)
        {
            while (iterator != position)
            {
                pv = pv->next;
                iterator++;
            }
            cout << "Element after index " << position << " is: L(" << pv->next->value << ")" << endl;
        }
        else
        {
            incorrectPosition();
        }
    }
}

////change two elements
void exchange(List** start, List** stop, int value, int value2)
{
    if ((*start)->next != *start)
    {
        List* first = *start, * second;
        bool found = false;
        do
        {
            if (first->value == value)
            {
                found = true;
                break;
            }
            first = first->next;
        } while (first != *start);
        if (found)
        {
            if (first->next->value == value2)
            {
                second = first->next;
            }
            else if (first->previous->value == value2)
            {
                second = first;
                first = first->previous;
            }
            else
            {
                elementsAreNotAdjacent();
                return;
            }
            if (first->previous != *stop && second->next != *start)
            {
                first->next = second->next;
                second->next->previous = first;
                second->previous = first->previous;
                first->previous->next = second;
                second->next = first;
                first->previous = second;
                if (first == *stop && second == *start)
                {
                    *start = first;
                    *stop = second;
                }
            }
            else if (first->previous == *stop && second->next == *start)
            {
                *start = second;
                *stop = first;
            }
            else if (first->previous == *stop)
            {
                first->previous = second;
                first->next = second->next;
                second->next->previous = first;
                second->previous = *stop;
                (*stop)->next = second;
                second->next = first;
                *start = second;
            }
            else
            {
                second->next = first;
                second->previous = first->previous;
                first->previous->next = second;
                first->next = *start;
                (*start)->previous = first;
                first->previous = second;
                *stop = first;
            }
        }
        else
        {
            elementsAreNotAdjacent();
        }
    }
}

//sort
void sort(List** start, List** stop)
{
    if (start != NULL)
    {
        if ((*start)->next != *start)
        {
            List* current = *start, * first, * second;
            do
            {
                first = *start;
                while (first->next != *start)
                {
                    second = first->next;
                    if (first->value >= second->value)
                    {
                        if (first->previous != *stop && second->next != *start)
                        {
                            first->next = second->next;
                            second->next->previous = first;
                            second->previous = first->previous;
                            first->previous->next = second;
                            second->next = first;
                            first->previous = second;
                            if (first == *stop && second == *start)
                            {
                                *start = first;
                                *stop = second;
                            }
                        }
                        else if (first->previous == *stop && second->next == *start)
                        {
                            *start = second;
                            *stop = first;
                        }
                        else if (first->previous == *stop)
                        {
                            first->previous = second;
                            first->next = second->next;
                            second->next->previous = first;
                            second->previous = *stop;
                            (*stop)->next = second;
                            second->next = first;
                            *start = second;
                        }
                        else
                        {
                            second->next = first;
                            second->previous = first->previous;
                            first->previous->next = second;
                            first->next = *start;
                            (*start)->previous = first;
                            first->previous = second;
                            *stop = first;
                        }
                        first = second;
                    }
                    first = first->next;
                }
                current = current->next;
            } while (current != (*stop)->previous);
        }
    }
}
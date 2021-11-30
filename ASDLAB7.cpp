#include <iostream>
using namespace std;

struct List {
    int value;
    List* next;
    List* previous;
};

void initialize(List**, List**, int);
void clear(List*);

void insert(List**, int);
void insertBef(List**, List*, int);
void insertBefore(List**, int, int);
void insertAft(List**, List*, int);
void insertAfter(List**, int, int);
void insertBeforePosition(List**, int, int);
void insertAfterPosition(List*, List**, int, int);

void deleteValue(List**, List**, int);
void deleteBef(List**, List*);
void deleteAft(List**, List*);
void deleteBefore(List**, int);
void deleteAfter(List**, List*, int);
void deleteBeforeIndex(List**, int);
void deleteAfterIndex(List*, List**, int);

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
                insert(&stop, value);
                break;
            case 2:
                element = getElement();
                value = getValue();
                insertBefore(&start, element, value);
                break;
            case 3:
                element = getElement();
                value = getValue();
                insertAfter(&stop, element, value);
                break;
            case 4:
                position = getPosition();
                value = getValue();
                insertBeforePosition(&start, position, value);
                break;
            case 5:
                position = getPosition();
                value = getValue();
                insertAfterPosition(start, &stop, position, value);
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
                deleteBefore(&start, value);
                break;
            case 3:
                value = getValue();
                deleteAfter(&stop, start, value);
                break;
            case 4:
                position = getPosition();
                deleteBeforeIndex(&start, position);
                break;
            case 5:
                position = getPosition();
                deleteAfterIndex(start, &stop, position);
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
            clear(start);
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
    cout << "(1: INITIALIZE, 2: INSERT, 3: DELETE, 4: SEARCH, 5: CLEAR, 6: SRS, 7: PRINT, 8: EXIT)" << endl;
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
        pv->next = NULL;
        pv->previous = NULL;
        *start = pv;
        *stop = pv;
    }
    else
    {
        listIsAlreadyInitialized();
    }
}
void clear(List* start)
{
    if (start != NULL)
    {
        List* current_element = start, * pv;
        while (current_element != NULL)
        {
            pv = current_element->next;
            *current_element = {};
            current_element = pv;
        }
    }
}

//print
void printFromStart(List* start)
{
    if (start != NULL)
    {
        List* pv = start;
        while (pv != NULL)
        {
            cout << "L(" << pv->value << "), ";
            pv = pv->next;
        }
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
        while (pv != NULL)
        {
            cout << "L(" << pv->value << "), ";
            pv = pv->previous;
        }
        cout << endl;
    }
    else
    {
        listIsEmpty();
    }
}

//insert
void insert(List** stop, int value)
{
    if (*stop != NULL)
    {
        List* pv = new List;
        pv->value = value;
        pv->next = NULL;
        pv->previous = *stop;
        (*stop)->next = pv;
        *stop = pv;
    }
}
void insertBef(List** start, List* prev, int value)
{
    List* pv = new List;
    pv->value = value;
    pv->next = prev;
    if (prev->previous == NULL)
    {
        pv->previous = NULL;
        prev->previous = pv;
        *start = pv;
    }
    else
    {
        pv->previous = prev->previous;
        prev->previous = pv;
        prev = pv->previous;
        prev->next = pv;
    }
}
void insertAft(List** stop, List* nex, int value)
{
    List* pv = new List;
    pv->value = value;
    pv->previous = nex;
    if (nex->next == NULL)
    {
        pv->next = NULL;
        nex->next = pv;
        *stop = pv;
    }
    else
    {
        pv->next = nex->next;
        nex->next = pv;
        nex = pv->next;
        nex->previous = pv;
    }
}
void insertBefore(List** start, int element, int value)
{
    if (*start != NULL)
    {
        List* prev = *start;
        while (prev != NULL)
        {
            if (prev->value == element)
            {
                break;
            }
            prev = prev->next;
        }
        if (prev != NULL)
        {
            insertBef(start, prev, value);
        }
        else
        {
            elementNotFound();
        }
    }
}
void insertAfter(List** stop, int element, int value)
{
    if (*stop != NULL)
    {
        List* nex = *stop;
        while (nex != NULL)
        {
            if (nex->value == element)
            {
                break;
            }
            nex = nex->previous;
        }
        if (nex != NULL)
        {
            insertAft(stop, nex, value);
        }
        else
        {
            elementNotFound();
        }
    }
}
void insertBeforePosition(List** start, int position, int value)
{
    if (*start != NULL)
    {
        List* prev = *start;
        int iterator = 1;
        while (prev != NULL)
        {
            if (iterator == position)
            {
                break;
            }
            prev = prev->next;
            iterator++;
        }
        if (prev != NULL)
        {
            insertBef(start, prev, value);
        }
        else
        {
            incorrectPosition();
        }
    }
}
void insertAfterPosition(List* start, List** stop, int position, int value)
{
    if (start != NULL)
    {
        List* nex = start;
        int iterator = 1;
        while (nex != NULL)
        {
            if (iterator == position)
            {
                break;
            }
            nex = nex->next;
            iterator++;
        }
        if (nex != NULL)
        {
            insertAft(stop, nex, value);
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
        while (pv != NULL)
        {
            if (pv->value == value)
            {
                break;
            }
            pv = pv->next;
        }
        if (pv != NULL)
        {
            if (pv->next == NULL && pv->previous == NULL)
            {
                delete pv;
                pv = {};
                *start = pv;
                *stop = pv;
            }
            else if (pv->next == NULL && pv->previous != NULL)
            {
                pv->previous->next = NULL;
                *stop = pv->previous;
                delete pv;
                pv = {};
            }
            else if (pv->next != NULL && pv->previous == NULL)
            {
                pv->next->previous = NULL;
                *start = pv->next;
                delete pv;
                pv = {};
            }
            else
            {
                pv->next->previous = pv->previous;
                pv->previous->next = pv->next;
                delete pv;
                pv = {};
            }
        }
        else
        {
            elementNotFound();
        }
    }
}
void deleteBef(List** start, List* pv)
{
    pv = pv->previous;
    if (pv->previous != NULL)
    {
        pv->previous->next = pv->next;
    }
    else
    {
        *start = pv->next;
    }
    pv->next->previous = pv->previous;
    deletedElement(pv->value);
    delete pv;
}
void deleteAft(List** stop, List* pv)
{
    pv = pv->next;
    pv->previous->next = pv->next;
    if (pv->next == NULL)
    {
        *stop = pv->previous;
    }
    else
    {
        pv->next->previous = pv->previous;
    }
    deletedElement(pv->value);
    delete pv;
}
void deleteBefore(List** start, int value)
{
    if (*start != NULL)
    {
        List* pv = *start;
        while (pv != NULL)
        {
            if (pv->value == value)
            {
                break;
            }
            pv = pv->next;
        }
        if (pv != NULL)
        {
            if (pv->previous == NULL)
            {
                elementNotFound();
            }
            else
            {
                deleteBef(start, pv);
            }
        }
        else
        {
            elementNotFound();
        }
    }
}
void deleteAfter(List** stop, List* start, int value)
{
    if (*stop != NULL)
    {
        List* pv = start;
        while (pv != NULL)
        {
            if (pv->value == value)
            {
                break;
            }
            pv = pv->next;
        }
        if (pv != NULL)
        {
            if (pv->next == NULL)
            {
                elementNotFound();
            }
            else
            {
                deleteAft(stop, pv);
            }
        }
        else
        {
            elementNotFound();
        }
    }
}
void deleteBeforeIndex(List** start, int position)
{
    if (*start != NULL)
    {
        List* pv = *start;
        int iteration = 1;
        while (pv != NULL)
        {
            if (iteration == position)
            {
                break;
            }
            pv = pv->next;
            iteration++;
        }
        if (pv != NULL)
        {
            if (pv->previous == NULL)
            {
                incorrectPosition();
            }
            else
            {
                deleteBef(start, pv);
            }
        }
        else
        {
            incorrectPosition();
        }
    }
}
void deleteAfterIndex(List* start, List** stop, int position)
{
    if (start != NULL)
    {
        List* pv = start;
        int iteration = 1;
        while (pv != NULL)
        {
            if (iteration == position)
            {
                break;
            }
            pv = pv->next;
            iteration++;
        }
        if (pv != NULL)
        {
            if (pv->next == NULL)
            {
                incorrectPosition();
            }
            else
            {
                deleteAft(stop, pv);
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
        while (pv != NULL)
        {
            if (pv->value == value)
            {
                found = true;
                cout << "Value that you searched is found at index: " << iterator << endl;
            }
            pv = pv->next;
            iterator++;
        }
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
        while (pv != NULL)
        {
            if (pv->value == value && pv->previous != NULL)
            {
                cout << "Element before " << value << " is: L(" << pv->previous->value << ")" << endl;
                found = true;
            }
            pv = pv->previous;
        }
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
        while (pv != NULL)
        {
            if (pv->value == value && pv->next != NULL)
            {
                cout << "Element after " << value << " is: L(" << pv->next->value << ")" << endl;
                found = true;
            }
            pv = pv->next;
        }
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
        while (pv != NULL)
        {
            if (iterator == position && pv->previous != NULL)
            {
                cout << "Element before index " << position << " is: L(" << pv->previous->value << ")" << endl;
                break;
            }
            pv = pv->next;
            iterator++;
        }
        if (pv == NULL)
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
        while (pv != NULL)
        {
            if (iterator == position && pv->next != NULL)
            {
                cout << "Element after index " << position << " is: L(" << pv->next->value << ")" << endl;
                break;
            }
            pv = pv->next;
            iterator++;
        }
        if (pv == NULL)
        {
            incorrectPosition();
        }
    }
}

//change two elements
void exchange(List** start, List** stop, int value, int value2)
{
    if (*start != NULL)
    {
        List* first = *start, * second;
        while (first != NULL)
        {
            if (first->value == value)
            {
                break;
            }
            first = first->next;
        }
        if (first != NULL)
        {
            if (first->next != NULL && first->next->value == value2)
            {
                second = first->next;
            }
            else if (first->previous != NULL && first->previous->value == value2)
            {
                second = first;
                first = first->previous;
            }
            else
            {
                elementsAreNotAdjacent();
                return;
            }
            if (first->previous != NULL && second->next != NULL)
            {
                first->next = second->next;
                second->next->previous = first;
                second->previous = first->previous;
                first->previous->next = second;
                second->next = first;
                first->previous = second;
            }
            else if (first->previous == NULL && second->next == NULL)
            {
                second->previous = NULL;
                first->next = NULL;
                second->next = first;
                first->previous = second;
                *start = second;
                *stop = first;
            }
            else if (first->previous == NULL)
            {
                first->previous = second;
                first->next = second->next;
                second->next->previous = first;
                second->previous = NULL;
                second->next = first;
                *start = second;
            }
            else
            {
                second->next = first;
                second->previous = first->previous;
                first->previous->next = second;
                first->next = NULL;
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
        if ((*start)->next != NULL)
        {
            List* current = *start, * first, * second;
            while (current != NULL)
            {
                first = *start;
                while (first->next != NULL)
                {
                    second = first->next;
                    if (first->value >= second->value)
                    {
                        if (first->previous != NULL && second->next != NULL)
                        {
                            first->next = second->next;
                            second->next->previous = first;
                            second->previous = first->previous;
                            first->previous->next = second;
                            second->next = first;
                            first->previous = second;
                        }
                        else if (first->previous == NULL && second->next == NULL)
                        {
                            second->previous = NULL;
                            first->next = NULL;
                            second->next = first;
                            first->previous = second;
                            *start = second;
                            *stop = first;
                        }
                        else if (first->previous == NULL)
                        {
                            first->previous = second;
                            first->next = second->next;
                            second->next->previous = first;
                            second->previous = NULL;
                            second->next = first;
                            *start = second;
                        }
                        else
                        {
                            second->next = first;
                            second->previous = first->previous;
                            first->previous->next = second;
                            first->next = NULL;
                            first->previous = second;
                            *stop = first;
                        }
                        first = second;
                    }
                    first = first->next;
                }
                current = current->next;
            }
        }
    }
}
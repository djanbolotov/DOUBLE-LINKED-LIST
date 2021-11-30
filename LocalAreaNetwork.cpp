//#include <iostream>
//using namespace std;
//
//struct List {
//    string value;
//    string income;
//    List* next;
//};
//
//void print(List*, int);
//
//List* insertPosition(List*, int, int, int*);
//int filterPosition(int, int);
//
//List* deletePosition(List*, int, int*);
//List* deleteValue(List*, int, int*);
//void searchPosition(List*, int);
//void searchValue(List*, int);
//
//List* Create(List*, int, int*);
//List* Clear(List*, int*);
//
//int getVariant(int);
//int getValue();
//int getPosition();
//
//void printMenu();
//void printDeleteMenu();
//void printSearchMenu();
//
//void incorrectPosition();
//void elementNotFound();
//void listIsEmpty();
//void listIsAlreadyInitialized();
//void deletedElement(int value);
//
//int main()
//{
//    List* head = NULL;
//    int position, size = 0;
//    string value;
//    int select_menu, select_delete, select_search;
//    do {
//        system("CLS");
//        printMenu();
//        select_menu = getVariant(7);
//        if (select_menu < 6)
//        {
//            print(head, size);
//        }
//        switch (select_menu)
//        {
//        case 1:
//            value = getValue();
//            head = Create(head, value, &size);
//            break;
//        case 2:
//            position = getPosition();
//            value = getValue();
//            head = insertPosition(head, position, value, &size);
//            break;
//        case 3:
//            printDeleteMenu();
//            select_delete = getVariant(2);
//            switch (select_delete)
//            {
//            case 1:
//                position = getPosition();
//                position = filterPosition(position, size);
//                head = deletePosition(head, position, &size);
//                break;
//            case 2:
//                value = getValue();
//                head = deleteValue(head, value, &size);
//                break;
//            }
//            break;
//        case 4:
//            printSearchMenu();
//            select_search = getVariant(2);
//            switch (select_search)
//            {
//            case 1:
//                value = getValue();
//                searchValue(head, value);
//                break;
//            case 2:
//                position = getPosition();
//                position = filterPosition(position, size);
//                searchPosition(head, position);
//                break;
//            }
//            break;
//        case 5:
//            head = Clear(head, &size);
//            break;
//        case 6:
//            print(head, size);
//            break;
//        }
//        if (select_menu < 6)
//        {
//            print(head, size);
//        }
//        if (select_menu != 7)
//        {
//            system("pause");
//        }
//    } while (select_menu != 7);
//    return 0;
//}
//
////get values
//int getValue()
//{
//    int value;
//    cout << "Enter value: ";
//    cin >> value;
//    return value;
//}
//int getPosition()
//{
//    int position;
//    cout << "Enter position: ";
//    cin >> position;
//    return position;
//}
//int getVariant(int maxvalue)
//{
//    int variant;
//    cin >> variant;
//    while (variant < 1 || variant > maxvalue)
//    {
//        cout << "Incorrect input. Try again: ";
//        cin >> variant;
//    }
//    return variant;
//}
////menu
//void printMenu()
//{
//    cout << "(1: INITIALIZE, 2: INSERT, 3: DELETE, 4: SEARCH, 5: CLEAR, 6: PRINT, 7: EXIT)" << endl;
//    cout << "Select any value you want:";
//}
//void printDeleteMenu()
//{
//    cout << "(1: DELETE POSITION, 2: DELETE VALUE)" << endl;
//    cout << "Which delete we will use:";
//}
//void printSearchMenu()
//{
//    cout << "(1: SEARCH VALUE, 2: SEARCH POSITION)" << endl;
//    cout << "Which search we will use: ";
//}
////messages
//void incorrectPosition()
//{
//    cout << "You entered incorrect position!" << endl;
//}
//void elementNotFound()
//{
//    cout << "Element not found!" << endl;
//}
//void listIsEmpty()
//{
//    cout << "List is empty!" << endl;
//}
//void listIsAlreadyInitialized()
//{
//    cout << "List is already initialized!" << endl;
//}
//void deletedElement(int value)
//{
//    cout << "Deleted element is: " << value << endl;
//}
////create
//List* Create(List* head, int value, int* size)
//{
//    if (*size == 0)
//    {
//        List* pv = new List;
//        pv->value = value;
//        pv->next = pv;
//        *size = 1;
//        head = pv;
//    }
//    else
//    {
//        listIsAlreadyInitialized();
//    }
//    return head;
//}
////print
//void print(List* head, int size)
//{
//    if (head != NULL)
//    {
//        cout << "Address of first element: " << head << endl;
//        List* pv = head;
//        do {
//            cout << "L(v:" << pv->value << "), ";
//            pv = pv->next;
//        } while (pv != head);
//        cout << endl;
//        cout << "Address of last element next: " << pv << endl;
//    }
//    else
//    {
//        listIsEmpty();
//    }
//}
////insert
//List* insertPosition(List* head, int position, int value, int* size)
//{
//    if (head != NULL)
//    {
//        if (position > 0 && position <= *size + 1)
//        {
//            List* pv = new List;
//            pv->value = value;
//            if (position == 1)
//            {
//                pv->next = head;
//                head = pv;
//                List* current_element = head;
//                do {
//                    current_element = current_element->next;
//                } while (current_element->next != head->next);
//                current_element->next = head;
//            }
//            else
//            {
//                List* current_element = head;
//                for (int i = 1; i < position - 1; i++)
//                {
//                    current_element = current_element->next;
//                }
//                pv->next = current_element->next;
//                current_element->next = pv;
//            }
//            *size += 1;
//        }
//        else
//        {
//            incorrectPosition();
//        }
//    }
//    return head;
//}
////delete
//List* deletePosition(List* head, int position, int* size)
//{
//    if (head != NULL)
//    {
//        if (position > 0 && position <= *size)
//        {
//            List* current_element = head;
//            List* pv = head->next;
//            int value;
//            if (position == 1)
//            {
//                value = head->value;
//                if (*size != 1)
//                {
//                    head = pv;
//                    do {
//                        pv = pv->next;
//                    } while (pv->next != current_element);
//                    pv->next = current_element->next;
//                    delete current_element;
//                }
//                else
//                {
//                    head = NULL;
//                }
//            }
//            else
//            {
//                for (int i = 1; i < position - 1; i++)
//                {
//                    current_element = current_element->next;
//                }
//                pv = current_element;
//                current_element = current_element->next;
//                List* link = current_element->next;
//                value = current_element->value;
//                delete current_element;
//                pv->next = link;
//            }
//            deletedElement(value);
//            *size -= 1;
//        }
//        else
//        {
//            incorrectPosition();
//        }
//    }
//    return head;
//}
//List* deleteValue(List* head, int value, int* size)
//{
//    if (head != NULL)
//    {
//        List* current_element = head;
//        int position = 1;
//        bool found = false;
//        while (current_element->next != head)
//        {
//            if (current_element->value == value)
//            {
//                found = true;
//                break;
//            }
//            position++;
//            current_element = current_element->next;
//        }
//        if (found)
//        {
//            head = deletePosition(head, position, size);
//        }
//        else
//        {
//            elementNotFound();
//        }
//    }
//    return head;
//}
////clear
//List* Clear(List* head, int* size)
//{
//    if (head != NULL)
//    {
//        List* pv = head;
//        List* current_element = head;
//        int current_position = 1;
//        do
//        {
//            current_element = pv->next;
//            *pv = {};
//            pv = current_element;
//            current_position++;
//        } while (current_position < *size);
//        *size = 1;
//    }
//    head->next = head;
//    return head;
//}
////filter
//int filterPosition(int position, int size)
//{
//    int iteration = 1;
//    while (position > size)
//    {
//        iteration++;
//        position -= size;
//    }
//    cout << "Quality of iterations = " << iteration << endl;
//    return position;
//}
////search
//void searchValue(List* head, int value)
//{
//    if (head != NULL)
//    {
//        List* pv = head;
//        int position = 0;
//        bool found = false;
//        do {
//            position++;
//            if (pv->value == value)
//            {
//                found = true;
//                cout << "Value that you entered is found at index: " << position << " = L(v:" << pv->value << ")" << endl;
//            }
//            pv = pv->next;
//        } while (pv != head);
//        if (!found)
//        {
//            elementNotFound();
//        }
//    }
//}
//void searchPosition(List* head, int position)
//{
//    if (head != NULL)
//    {
//        List* pv = head;
//        int current_position = 0;
//        do {
//            current_position++;
//            if (position == current_position)
//            {
//                cout << "Position that you entered is found: " << "L(v:" << pv->value << ")" << endl;
//            }
//            pv = pv->next;
//        } while (pv != head);
//    }
//}
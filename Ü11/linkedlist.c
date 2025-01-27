#include "linkedlist.h"

/* Repraesentierung eines Listenknotens */
typedef struct node node_t;
struct node
{
    int value;
    node_t *next;
};

/* Repraesentierung einer Liste als Pointer auf das erste Element */
typedef struct linked_list linked_list_t;
struct linked_list
{
    node_t *first;
};

/* Testet, ob die Liste leer ist */
bool list_is_empty(linked_list_t *ll)
{
    return ll->first == NULL;
}

/* Fuegt ein Element hinten in die Liste ein */
void list_append_elem(linked_list_t *ll, int i)
{
    // Alloziere neue Knoten-Struktur
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL)
    {
        printf("Couldn't allocate new node");
        exit(-1);
    }
    // Initialisiere den neuen Knoten
    new_node->value = i;
    new_node->next = NULL;

    if (ll->first == NULL)
    {
        ll->first = new_node;
    }
    else
    {
        // Iteriere ueber die Liste bis zum Ende
        node_t *current = ll->first;
        while (current->next != NULL)
        {
            current = current->next;
        }
        // Fuege den neuen Knoten am Ende ein
        current->next = new_node;
    }
}

/* Fuegt ein Element vorne in die Liste ein */
void list_add_elem_front(linked_list_t *ll, int i)
{
    // Alloziere neue Knoten-Struktur
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL)
    {
        printf("Couldn't allocate new node");
        exit(-1);
    }
    // Initialisiere den neuen Knoten
    new_node->value = i;
    new_node->next = ll->first;
    ll->first = new_node;
}

/* Entfernt das Element an Position pos, falls vorhanden */
void list_remove_elem(linked_list_t *ll, int pos)
{
    // Aus der leeren Liste kann nichts entfernt werden
    if (ll->first == NULL)
    {
        return;
    }
    // Entfernt das erste Listenelement, falls vorhanden
    if (pos == 0)
    {
        node_t *n = ll->first;
        ll->first = ll->first->next;
        free(n);
    }
    else
    {
        node_t *prev = ll->first;
        pos--;
        while (pos > 0 && prev->next != NULL)
        {
            pos--;
            prev = prev->next;
        }
        if (pos == 0)
        {
            node_t *n = prev->next;
            prev->next = prev->next->next;
            free(n);
        }
    }
}

/* Gibt die Elemente der Liste durch Komma getrennt aus */
void list_print(linked_list_t *ll)
{
    for (node_t *n = ll->first; n; n = n->next)
    {
        if (n != ll->first)
        {
            printf(", ");
        }
        printf("%d", n->value);
    }
    printf("\n");
}

/* Erstellt eine neue leere Liste */
linked_list_t *list_new(void)
{
    // Alloziere Speicher auf dem Heap fuer die Listen-Struktur
    linked_list_t *ll = malloc(sizeof(linked_list_t));
    if (ll == NULL)
    {
        printf("Couldn't allocate linked_list");
        exit(-1);
    }
    else
    {
        // Initialisiere die Liste
        ll->first = NULL;
        return ll;
    }
}

/* Entfernt die Liste mit allen Knoten und den Speicherplatz wieder frei */
void list_free(linked_list_t *ll)
{
    reset(ll); //Ruft Funktion reset unten auf
    // Entferne zuletzt die Listen-Struktur
    free(ll);
}

/*********************************** AUFGABEN ********************************************/

/* Ermittelt den groessten in der Liste gespeicherten Wert, bei leerer Liste soll INT_MIN zurueckgegeben werden */
int max(linked_list_t *ll)
{
    int biggest = 0;
    node_t *pointer = NULL;
    if(ll->first == NULL){
        return INT_MIN;
    }else{
        pointer = ll->first;
        while(pointer != NULL){
            if(pointer->value > biggest){
                biggest = pointer->value;
                pointer = pointer->next;
            }else{
                pointer = pointer->next;
            }}
            return biggest;
    }
}

/* Erstellt eine List mit Eintraegen aus einem Array unter Beibehaltung der Reihenfolge */
linked_list_t *from_array(int *ar, int size)
{
    int index = 0;
    node_t *pointerA = NULL;
    node_t *pointerB = NULL;
    linked_list_t *ll = malloc(sizeof(linked_list_t));

    ll->first = malloc(sizeof(node_t));
    ll->first->value = ar[index];
    pointerA = ll->first;
    index++;

    while(index<size){
        pointerB = malloc(sizeof(node_t));
        pointerB->value = ar[index];
        pointerA->next = pointerB;
        pointerA = pointerB;
        index++;
    }

    pointerA->next = NULL;
    return ll;

}

/* Entfernt alle Knoten aus einer Liste */
void reset(linked_list_t *ll)
{
    node_t *pointer = ll->first;
    
    if(ll->first==NULL){

    }else{
        while(ll->first!=NULL){
            pointer = ll->first;
            ll->first = ll->first->next;
            free(pointer);
        }
        
    }

}

/* Testet, ob die Liste Elemente mehrfach enthaelt */
bool list_has_duplicates(linked_list_t *ll)
{
    int *array_values = NULL; //Enthält die Werte aus der Liste
    node_t *pointerA = ll->first;

    int max_index = 0;
    int index = 0;

    while(pointerA != NULL){
        if(pointerA->next != NULL){
            max_index++;
            pointerA = pointerA->next;
        }else{
            pointerA = NULL;
        }
    }

    array_values = calloc(max_index+1, sizeof(int));
    pointerA = ll->first;
    while(index<max_index+1){
        array_values[index] = pointerA->value;
        pointerA = pointerA->next;
        index++;
    }


    for(int a = 0; a<max_index;++a){
        index = a+1;
        if(index<=max_index){
            while(index<=max_index){
            if(array_values[a] == array_values[index]){
                free(array_values);
                return true;
            }else{
                index++;
            }
        }
        }
        
    }
    free(array_values);
    return false;



}
    

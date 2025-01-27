#include "linkedlist.h"

// Makro zum Testen
#define assertEquals(Description, Expected, Actual)                        \
    if ((Expected) == (Actual))                                            \
    {                                                                      \
        printf("PASSED " #Description ": " #Expected " == " #Actual "\n"); \
    }                                                                      \
    else                                                                   \
    {                                                                      \
        printf("FAILED " #Description ": " #Expected " == " #Actual        \
               "\n   expected: %d"                                         \
               "\n   actual  : %d\n",                                      \
               (Expected), (Actual));                                      \
    }

int main(void)
{
    {
        int vals[] = {1, 2, 3};
        linked_list_t *l = from_array(vals, sizeof(vals) / sizeof(int));
        assertEquals("max", 3, max(l));
        list_free(l);
    }

    {
        int vals[] = {3, 2, 1};
        linked_list_t *l = from_array(vals, sizeof(vals) / sizeof(int));
        assertEquals("max", 3, max(l));
        list_free(l);
    }

    {
        int vals[] = {};
        linked_list_t *l = from_array(vals, sizeof(vals) / sizeof(int));
        assertEquals("max", INT_MIN, max(l));
        list_free(l);
    }

    {
        int vals[] = {1, 2, 3};
        linked_list_t *l = from_array(vals, sizeof(vals) / sizeof(int));
        reset(l);
        assertEquals("reset", true, list_is_empty(l));
        list_free(l);
    }
    {
        int vals[] = {};
        linked_list_t *l = from_array(vals, sizeof(vals) / sizeof(int));
        reset(l);
        assertEquals("reset", true, list_is_empty(l));
        list_free(l);
    }
}
